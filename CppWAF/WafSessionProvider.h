#ifndef CPPWAF_WAFSESSIONPROVIDER_H_
#define CPPWAF_WAFSESSIONPROVIDER_H_

#include <optional>
#include <string>
#include <unordered_map>

#include "WafSession.h"

namespace cwaf {
template<typename UI>
class WafSessionProvider {
public:

	const std::string CreateSession (WafSession<UI>&& session) {
		std::string session_id = std::to_string(++next_session_id);

		sessions.emplace (session_id, std::move(session));
		return session_id;
	}

	/*const std::string& CreateSession (SimpleSession&& session) {
		return "";
	}*/

	std::optional<WafSession<UI>*> GetSession (const std::string& session_id) {
		auto itSession = sessions.find(session_id);
		if(itSession == sessions.end()){
			return std::nullopt;
		}
		return &itSession->second;
	}

private:
	int next_session_id = 0;

	std::unordered_map<std::string, WafSession<UI>> sessions;
};
}

#endif
