/*
 * WafRootPage.h
 *
 *  Created on: Sep 8, 2019
 *      Author: coldfusion
 */

#ifndef CPPWAF_WAFROOTPAGE_H_
#define CPPWAF_WAFROOTPAGE_H_

#include "CTAS/HttpRequest.h"
#include "CTAS/HttpResponse.h"

class WafRootPage {
	HttpResponse<WafSession> HandleRequest (HttpRequest<WafSession>& request) {
			HttpResponse<WafSession> resp;

			auto& headers = resp.HeaderFields ();
			headers["Content-Type"] = "text/html";

			const std::string& body = request.Body();

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
			resp.Body("dfklgjdlfkg");

			return resp;
		}
};



#endif /* CPPWAF_WAFROOTPAGE_H_ */
