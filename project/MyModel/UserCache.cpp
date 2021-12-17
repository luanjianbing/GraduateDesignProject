#include "UserCache.h"

namespace Model {
	UserCacheInterface::UserCacheInterface() {

	}

	UserCacheInterface::~UserCacheInterface() {

	}

	std::vector<std::string> UserCacheInterface::getUserAuthorities() {
		return mUserAuthorityStr;
	}

	int UserCacheInterface::getUserAttributesNum() {
		return mUser.userAttributesNum;
	}

	bool UserCacheInterface::checkAuthority(std::string firstAuthority, std::string secondAuthority) {
		int firstAuthorityIndex = -1;
		int secondAuthorityIndex = -1;

		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			if (mUserAuthorityStr[i] == firstAuthority) {
				firstAuthorityIndex = i;
				break;
			}
		}

		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			if (mUserAuthorityStr[i] == secondAuthority) {
				secondAuthorityIndex = i;
				break;
			}
		}

		if (firstAuthorityIndex == -1 || secondAuthorityIndex == -1) {
			std::cout << "无此权限级别" << std::endl;
			return false;
		}
		else {
			return (secondAuthorityIndex < firstAuthorityIndex);
		}
	}
}