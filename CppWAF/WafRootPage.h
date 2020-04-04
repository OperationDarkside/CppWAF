/*
 * WafRootPage.h
 *
 *  Created on: Sep 8, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_WAFROOTPAGE_H_
#define CPPWAF_WAFROOTPAGE_H_

#include <iostream>
#include <fstream>
#include <streambuf>

#include "CTAS/HttpRequest.h"
#include "CTAS/HttpResponse.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include "UI.h"
#include "Button.h"
//#include "WafSession.h"

namespace cwaf {
class WafRootPage {
public:
	ctas::HttpResponse<WafSession<UI>> HandleRequest(
			ctas::HttpRequest<WafSession<UI>> &request) {
		ctas::HttpResponse<WafSession<UI>> resp;

		auto &headers = resp.HeaderFields();
		headers["Content-Type"] = "text/html";

		const std::string &body = request.Body();

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
		//resp.Body("dfklgjdlfkg");
		if (!request.HasSession()) {
			WafSession<UI> &newSession = resp.CreateSession();
			UI &ui = newSession.getUI();

			std::unique_ptr<Button> btn = std::make_unique<Button>();
			btn->setCaption("Blubberbla");
			btn->addClickListener([btn](const ClickEvent& event){
				btn->setCaption("Blaaaaaaaaaaaaaaa");
			});
			ui.setComponent(std::move(btn));

			std::streampos size;
			std::ifstream myfile("index.html", std::ios::in|std::ios::binary|std::ios::ate);
			size = myfile.tellg();
			myfile.seekg (0, std::ios::beg);

			std::string strOut;
			strOut.reserve(size);

			strOut.assign((std::istreambuf_iterator<char>(myfile)),
			            std::istreambuf_iterator<char>());

			resp.Body(strOut);
		} else {
			// for when refresh
			WafSession<UI> *session = request.CurrentSession();
			UI &ui = session->getUI();
			std::vector<OutCommand> &outCmds = ui.getInitCommands();
			// Serialize
		}

		return resp;
	}
};
}

#endif /* CPPWAF_WAFROOTPAGE_H_ */
