#ifndef CPPWAF_WAFSERVER_H_
#define CPPWAF_WAFSERVER_H_

#include "CTAS/Server.h"

#include "WafSessionProvider.h"
#include "WafSession.h"
#include "UI.h"
#include "WafRootPage.h"
#include "WafRouterPage.h"

namespace cwaf {
class WafServer {
public:
	void start (int port) {

		server.registerPage<WafRootPage>("/");
		server.registerPage<WafRouterPage>("/r");
		server.start(port);
	}

private:
	ctas::Server<WafSessionProvider<UI>, WafSession<UI>> server;
};
}

#endif
