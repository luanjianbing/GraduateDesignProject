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
		//// �������Ҫ���µ�����ȫ��ת��Ϊvector + string��Ϊ�н�
		// ���в���һ������
		void insertSingleRowData(const char *table, std::vector<std::string> &data);
		// ɾ�����е���������
		void deleteAllData(const char *table);
		// ɾ�����е��������ݲ����
		void deleteAndReplaceNewData(const char *table, std::vector<std::vector<std::string>> &data);
		// ɾ�����з����������������ݲ����
		void deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data, 
			const char *factorColName, std::string &factorColValue);
		void deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data,
			const char *factorColName, int &factorColValue);
		// ��ȡ���е��������ݣ�����һ����ά����
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum);
		// ���ݸ����������������Ĭ��ȫ����int����
		void createTargetTable(const char *tableName, std::vector<std::string> &colName);
		// ɾ��ĳ����
		void deleteTabel(const char *table);
		// ��ѯ��ǰdatabase����û��ĳ�ű�
		bool findTargetTable(const char *table);
		// ��ѯĳ�ű��ж�����
		int findColNumsFromTargetTable(const char *table);
		// ��������ѯĳ�ű�Ĭ�ϰ�id����
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum, 
			const char *factorColName, std::string &factorColValue, const char *orderColNum);
		// ��ѯ����
		std::vector<std::vector<std::string>> queryAllData(const char * table, const int colNum, const char *orderColNum);

	private:

	};
}

#endif