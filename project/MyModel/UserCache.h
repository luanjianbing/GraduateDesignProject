#pragma once

#ifndef USERCACHE_H
#define USERCACHE_H

#include <iostream>
#include <vector>
#include <map>

namespace Model {
	class UserCacheInterface {
	private:
		enum UserAuthority
		{
			SuperAdministrator,		// 超级管理员只有一个，开发人员用
			SystemAdministrator,	// 系统管理员
			TechnicalStaff,		// 技术工作人员，允许修改一些设定
			CommonStaff,		// 普通操作人员，只允许运行不允许修改
		};

		std::vector<std::string> mUserAuthorityStr = {
			"SuperAdministrator",
			"SystemAdministrator",
			"TechnicalStaff",
			"CommonStaff",
		};

		struct User {
			int userAttributesNum = 5;		// user属性个数

			std::string userID = "";
			std::string userPassward = "";
			std::string userTrueName = "";
			std::string userProductionLine = "";
			UserAuthority userAuthority = UserAuthority::CommonStaff;
		};

	public:
		UserCacheInterface();
		~UserCacheInterface();

		// 以字符串数组返回所有权限类型
		std::vector<std::string> getUserAuthorities();
		// 返回User的用户个数
		int getUserAttributesNum();
		// 判断权限大小，后面一个权限是否可以操作前面的权限
		bool checkAuthority(std::string firstAuthority, std::string secondAuthority);

	private:
		User mUser;	// 当前系统用户
	};
}

#endif USERCACHE_H