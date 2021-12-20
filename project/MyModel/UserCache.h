#pragma once

#ifndef USERCACHE_H
#define USERCACHE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

namespace Model {
	class UserCacheInterface {
	private:
		enum UserAuthority
		{
			SuperAdministrator,		// ��������Աֻ��һ����������Ա��
			SystemAdministrator,	// ϵͳ����Ա
			TechnicalStaff,		// ����������Ա�������޸�һЩ�趨
			CommonStaff,		// ��ͨ������Ա��ֻ�������в������޸�
		};

		std::vector<std::string> mUserAuthorityStr = {
			"SuperAdministrator",
			"SystemAdministrator",
			"TechnicalStaff",
			"CommonStaff",
		};

		struct User {
			int userAttributesNum = 5;		// user���Ը���

			std::string userID = "";
			std::string userPassward = "";
			std::string userTrueName = "";
			std::string userProductionLine = "";
			UserAuthority userAuthority = UserAuthority::CommonStaff;
		};

	public:
		UserCacheInterface();
		~UserCacheInterface();

		// ���ַ������鷵������Ȩ������
		std::vector<std::string> getUserAuthorities();
		// ����User���û����Ը���
		int getUserAttributesNum();
		// �ж�Ȩ�޴�С������һ��Ȩ���Ƿ���Բ���ǰ���Ȩ��
		bool checkAuthority(std::string firstAuthority, std::string secondAuthority);
		// ���õ�ǰ��¼�������û���һЩ��Ϣ
		void setCurrentUser(std::map<std::string, std::string> userInfo);
		// ��Map��ʽ���ص�ǰϵͳ�û��������Ϣ
		std::map<std::string, std::string> getCurrentUser();

	private:
		User mCurrentUser;	// ��ǰϵͳ�û�
	};
}

#endif USERCACHE_H