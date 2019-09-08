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

namespace cwaf {
class WafRouterPage {
public:
	ctas::HttpResponse<WafSession> HandleRequest (ctas::HttpRequest<WafSession>& request) {
		ctas::HttpResponse<WafSession> resp;

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
}


#endif /* CPPWAF_WAFROUTERPAGE_H_ */
