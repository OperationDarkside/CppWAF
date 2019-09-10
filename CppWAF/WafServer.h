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
		ctas::Server<WafSessionProvider<UI>, WafSession<UI>> server;
		server.registerPage<WafRootPage>("/");
		server.registerPage<WafRouterPage>("/r");
		server.start(port);
		//static_assert(IsSessionProviderBase<WafSessionProvider<UI>,WafSession<UI>>, "asdasd");
		//static_assert(!std::is_member_function_pointer<decltype(&WafRootPage::HandleRequest)>::value,"BLUBBER BLA");
	}

private:

};
}

#endif
