/*
 * WafPage.h
 *
 *  Created on: Sep 8, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_WAFROUTERPAGE_H_
#define CPPWAF_WAFROUTERPAGE_H_

#include "CTAS/HttpRequest.h"
#include "CTAS/HttpResponse.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "UI.h"
//#include "WafSession.h"

namespace cwaf {
class WafRouterPage {
public:
	ctas::HttpResponse<WafSession<UI>> HandleRequest(
			ctas::HttpRequest<WafSession<UI>> &request) {
		ctas::HttpResponse<WafSession<UI>> resp;

		/*
		 rapidjson::StringBuffer buffer;
		 rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

		 writer.StartObject();
		 writer.Key("name");
		 writer.String("Peter");
		 writer.Key("age");
		 writer.Int(30);
		 writer.EndObject();

		 resp.Body(buffer.GetString());
		 */
		if (!request.HasSession()) {
			resp.ResponseCode(ctas::RESPONSE_CODE::TEAPOT_418);
			resp.Body("Nothing to see here");
		} else {
			auto &headers = resp.HeaderFields();
			headers["Content-Type"] = "text/json";
			const std::string &body = request.Body();

			rapidjson::Document inDoc;
			inDoc.Parse(body.data());
			rapidjson::Value &reqType = inDoc["type"];
			if (!reqType.IsInt()) {
				resp.ResponseCode(ctas::RESPONSE_CODE::ERROR_500);
				resp.Body("RequestType wrong");
				return resp;
			}
			WafSession<UI> *session = request.CurrentSession();
			UI &ui = session->getUI();
			int reqTypeId = reqType.GetInt();
			if (reqTypeId == 0) {
				std::vector<OutCommand> &outCmds = ui.getInitCommands();

				resp.Body(outCmdsToString(outCmds));
				outCmds.clear();
			} else {
				rapidjson::Value &inCmds = inDoc["cmds"];
				if (inCmds.IsArray()) {
					std::vector<InCommand> distrCmds;

					for (rapidjson::SizeType i = 0; i < inCmds.Size(); i++) {
						rapidjson::Value &inCmdVal = inCmds[i];
						InCommand inCmd;

						inCmd.setComponentId(inCmdVal["id"].GetInt());
						inCmd.setType(
								static_cast<IN_COMMAND_TYPE>(inCmdVal["cmdType"].GetInt()));

						distrCmds.push_back(std::move(inCmd));
					}

					ui.distributeCommands(distrCmds);
					std::vector<OutCommand> &outCmds = ui.getOutCommands();
					resp.Body(outCmdsToString(outCmds));
					outCmds.clear();
				}
			}

		}

		return resp;
	}

	std::string outCmdsToString(std::vector<OutCommand> &outCmds) {
		rapidjson::Document outDoc;
		outDoc.SetObject();
		rapidjson::Document::AllocatorType& allocator = outDoc.GetAllocator();

		rapidjson::Value outCmdArr(rapidjson::kArrayType);

		for (OutCommand &outCmd : outCmds) {
			rapidjson::Value outCmdVal;
			outCmdVal.SetObject();
			outCmdVal.AddMember("id", outCmd.getComponentId(), allocator);
			outCmdVal.AddMember("propId", outCmd.getPropertyId(), allocator);
			outCmdVal.AddMember("cmdType", outCmd.getCommandType(), allocator);
			outCmdVal.AddMember("type", outCmd.getComponentTypeId(), allocator);
			outCmdVal.AddMember("custom", rapidjson::Value(outCmd.getCustomOutput().c_str(), allocator), allocator);
			if(!outCmd.getSubCommands().empty()){
				rapidjson::Value outSubCmdArr(rapidjson::kArrayType);

				for(OutCommand &subCommand : outCmd.getSubCommands()){
					rapidjson::Value outSubCmdVal;
					outSubCmdVal.SetObject();
					outSubCmdVal.AddMember("id", subCommand.getComponentId(), allocator);
					outSubCmdVal.AddMember("propId", subCommand.getPropertyId(), allocator);
					outSubCmdVal.AddMember("cmdType", subCommand.getCommandType(), allocator);
					outSubCmdVal.AddMember("type", subCommand.getComponentTypeId(), allocator);
					outSubCmdVal.AddMember("custom", rapidjson::Value(subCommand.getCustomOutput().c_str(), allocator), allocator);
					outSubCmdArr.PushBack(outSubCmdVal, allocator);
				}
				outCmdVal.AddMember("subCmds", outSubCmdArr, allocator);
			}
			outCmdArr.PushBack(outCmdVal, allocator);
		}
		outDoc.AddMember("cmds", outCmdArr, allocator);

		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		outDoc.Accept(writer);

		return buffer.GetString();
	}
};
}

#endif /* CPPWAF_WAFROUTERPAGE_H_ */
