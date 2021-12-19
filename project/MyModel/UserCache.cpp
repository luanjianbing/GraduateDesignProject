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
			std::cout << "�޴�Ȩ�޼���" << std::endl;
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
				std::cout << "�޴�Ȩ�޼���" << std::endl;
			}
			else
				mCurrentUser.userAuthority = static_cast<UserAuthority>(authorityIndex);

			std::cout << "���õ�ǰ�û� : " << std::endl;
			std::cout << "User ID : " << mCurrentUser.userID << std::endl;
			std::cout << "User True Name : " << mCurrentUser.userTrueName << std::endl;
			std::cout << "User Production Line : " << mCurrentUser.userProductionLine << std::endl;
			std::cout << "User Authority : " << mCurrentUser.userAuthority << std::endl;

		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}