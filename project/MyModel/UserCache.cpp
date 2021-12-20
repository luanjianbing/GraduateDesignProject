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
		return mCurrentUser.userAttributesNum;
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

	void UserCacheInterface::setCurrentUser(std::map<std::string, std::string> userInfo) {
		try {
			mCurrentUser.userID = userInfo.at("userID");
			mCurrentUser.userTrueName = userInfo.at("userTrueName");
			mCurrentUser.userProductionLine = userInfo.at("userProductionLine");

			int authorityIndex = -1;
			for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
				if (mUserAuthorityStr[i] == userInfo.at("userAuthority")) {
					authorityIndex = i;
					break;
				}
			}
			if (authorityIndex == -1) {
				std::cout << "无此权限级别" << std::endl;
			}
			else
				mCurrentUser.userAuthority = static_cast<UserAuthority>(authorityIndex);

			std::cout << "设置当前用户 : " << std::endl;
			std::cout << "User ID : " << mCurrentUser.userID << std::endl;
			std::cout << "User True Name : " << mCurrentUser.userTrueName << std::endl;
			std::cout << "User Production Line : " << mCurrentUser.userProductionLine << std::endl;
			std::cout << "User Authority : " << mCurrentUser.userAuthority << std::endl;

		}
		catch (const std::exception &e) {
			std::cout << "setCurrentUser: " << e.what() << std::endl;
		}
	}

	std::map<std::string, std::string> UserCacheInterface::getCurrentUser() {
		try
		{
			std::map<std::string, std::string> tmpCurrentUserInfo;

			tmpCurrentUserInfo.insert({ "userID", mCurrentUser.userID });
			tmpCurrentUserInfo.insert({ "userTrueName", mCurrentUser.userTrueName });
			tmpCurrentUserInfo.insert({ "userProductionLine", mCurrentUser.userProductionLine });
			tmpCurrentUserInfo.insert({ "userAuthority", mUserAuthorityStr[static_cast<int>(mCurrentUser.userAuthority)] });

			return tmpCurrentUserInfo;
		}
		catch (const std::exception &e)
		{
			std::cout << "getCurrentUser: " << e.what() << std::endl;
			return{};
		}
		return{};
	}
}