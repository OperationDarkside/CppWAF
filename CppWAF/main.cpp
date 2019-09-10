#include "WafServer.h"

int main (){

	cwaf::WafServer server;
	server.start(1337);

	return 0;
}
