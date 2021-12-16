#pragma once

#ifndef DATABASE_H
#define DATABASE_H

#include <winsock.h>
#include <mysql.h>
#include <iostream>
#include <vector>
#include <string>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "111111"
#define DB_DATABASE "db_model"

struct conn_info {
	char *host;
	char *user;
	char *password;
	char *database;
};

class SingleBaseDataBase {
public:
	SingleBaseDataBase();
	virtual ~SingleBaseDataBase();
private:
	virtual bool init();
	virtual bool close();
protected:
	MYSQL *mysql_conn;
	conn_info info;
	void mysqlOperation(char *sql_op);
};

namespace Model {
	class DataBaseInterface : public SingleBaseDataBase {
	public:
		DataBaseInterface();
		virtual ~DataBaseInterface();
		//// 如果有需要更新的数据全部转化为vector + string作为中介
		// 表中插入一行数据
		void insertSingleRowData(const char *table, std::vector<std::string> &data);
		// 删除表中的所有数据
		void deleteAllData(const char *table);
		// 删除表中的所有数据并替代
		void deleteAndReplaceNewData(const char *table, std::vector<std::vector<std::string>> &data);
		// 删除表中符合条件的所有数据并替代
		void deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data, 
			const char *factorColName, std::string &factorColValue);
		void deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data,
			const char *factorColName, int &factorColValue);
		// 读取表中的所有数据，返回一个二维数组
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum);
		// 根据给的列名创建出表格，默认全部是int的列
		void createTargetTable(const char *tableName, std::vector<std::string> &colName);
		// 删除某个表
		void deleteTabel(const char *table);
		// 查询当前database内有没有某张表
		bool findTargetTable(const char *table);
		// 查询某张表有多少列
		int findColNumsFromTargetTable(const char *table);
		// 按条件查询某张表，默认按id排序
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum, 
			const char *factorColName, std::string &factorColValue, const char *orderColNum);
		// 查询排序
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum, const char *orderColNum);

	private:

	};
}

#endif