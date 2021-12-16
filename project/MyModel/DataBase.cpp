#include "DataBase.h"

SingleBaseDataBase::SingleBaseDataBase() {
	init();
}

SingleBaseDataBase::~SingleBaseDataBase() {
	close();
}

bool SingleBaseDataBase::init() {
	try {
		info.host = DB_HOST;
		info.user = DB_USER;
		info.password = DB_PASSWORD;
		info.database = DB_DATABASE;
		mysql_conn = mysql_init(NULL);	//mysql初始化函数，实例化一个新的对象（NULL为新的对象，否则为初始化以创建的对象)
		if (!mysql_real_connect(mysql_conn, info.host, info.user, info.password, info.database, 3306, NULL, 0)) {	//mysql_real_connect(MYSQL *mysql,const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag)
			std::cout << "Connection MySQL Error" << std::endl;
			exit(1);
		}
		std::cout << "Connection MySQL Success" << std::endl;
		mysql_query(mysql_conn, "set names utf8");		// 需要设置一下
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

bool SingleBaseDataBase::close() {
	try {
		mysql_close(mysql_conn);//断开连接
		delete mysql_conn;
		std::cout << "Disconnect from MySQL" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
	return true;
}

void SingleBaseDataBase::mysqlOperation(char *sql_op) {
	if (mysql_query(mysql_conn, sql_op)) {		//mysql_query()函数为对mysql进行操作，第一个参数为刚才实例化的对象，第二个位需要进行的操作
		printf("MySQL query error : %s", mysql_error(mysql_conn));
		getchar();
		exit(1);
	}
}

namespace Model {
	DataBaseInterface::DataBaseInterface() {

	}
	DataBaseInterface::~DataBaseInterface() {

	}

	void DataBaseInterface::insertSingleRowData(const char *table, std::vector<std::string> &data) {
		char cmd[1000];

		strcpy(cmd, "insert into ");
		strcat(cmd, table);
		strcat(cmd, " values (");

		for (int i = 0; i < data.size(); ++i) {
			strcat(cmd, "\"");
			strcat(cmd, data[i].c_str());
			strcat(cmd, "\"");
			if (i != data.size() - 1)
				strcat(cmd, ",");
		}

		strcat(cmd, ")");
		mysqlOperation(cmd);
	}

	void DataBaseInterface::deleteAllData(const char *table) {
		char cmd[100];

		strcpy(cmd, "delete from ");
		strcat(cmd, table);

		mysqlOperation(cmd);
	}

	void DataBaseInterface::deleteAndReplaceNewData(const char *table, std::vector<std::vector<std::string>> &data) {
		deleteAllData(table);

		char cmd[2000];

		if (!data.empty()) {
			strcpy(cmd, "insert into ");
			strcat(cmd, table);
			strcat(cmd, " values ");
			for (int i = 0; i < data.size(); ++i) {
				strcat(cmd, "(");
				for (int j = 0; j < data[i].size(); j++) {
					if (j != 0) strcat(cmd, ",");
					strcat(cmd, "\"");
					strcat(cmd, data[i][j].c_str());
					strcat(cmd, "\"");
				}
				if (i != (data.size() - 1))	strcat(cmd, "),");
				else strcat(cmd, ")");
			}
			mysqlOperation(cmd);
		}
	}

	void DataBaseInterface::deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data,
		const char *factorColName, std::string &factorColValue) {
		char cmdB[100];

		strcpy(cmdB, "delete from ");
		strcat(cmdB, table);
		strcat(cmdB, " where ");
		strcat(cmdB, factorColName);
		strcat(cmdB, "=");
		strcat(cmdB, factorColValue.c_str());
		mysqlOperation(cmdB);

		char cmd[2000];

		if (!data.empty()) {
			strcpy(cmd, "insert into ");
			strcat(cmd, table);
			strcat(cmd, " values ");
			for (int i = 0; i < data.size(); ++i) {
				strcat(cmd, "(");
				for (int j = 0; j < data[i].size(); j++) {
					if (j != 0) strcat(cmd, ",");
					strcat(cmd, "\"");
					strcat(cmd, data[i][j].c_str());
					strcat(cmd, "\"");
				}
				if (i != (data.size() - 1))	strcat(cmd, "),");
				else strcat(cmd, ")");
			}
			mysqlOperation(cmd);
		}
	}

	void DataBaseInterface::deleteAndReplaceSatisfiedNewData(const char *table, std::vector<std::vector<std::string>> &data,
		const char *factorColName, int &factorColValue) {
		char cmdB[100];

		strcpy(cmdB, "delete from ");
		strcat(cmdB, table);
		strcat(cmdB, " where ");
		strcat(cmdB, factorColName);
		strcat(cmdB, "=");
		strcat(cmdB, std::to_string(factorColValue).c_str());
		mysqlOperation(cmdB);

		char cmd[2000];

		if (!data.empty()) {
			strcpy(cmd, "insert into ");
			strcat(cmd, table);
			strcat(cmd, " values ");
			for (int i = 0; i < data.size(); ++i) {
				strcat(cmd, "(");
				for (int j = 0; j < data[i].size(); j++) {
					if (j != 0) strcat(cmd, ",");
					strcat(cmd, "\"");
					strcat(cmd, data[i][j].c_str());
					strcat(cmd, "\"");
				}
				if (i != (data.size() - 1))	strcat(cmd, "),");
				else strcat(cmd, ")");
			}
			mysqlOperation(cmd);
		}
	}

	std::vector<std::vector<std::string>> DataBaseInterface::queryAllData(const char *table, const int colNum) {
		char cmd[100];

		MYSQL_RES *res;
		MYSQL_ROW col;

		std::vector<std::vector<std::string>> vect;
		std::vector<std::string> _vect;

		res = NULL;//要先初始化，否则会报错

		strcpy(cmd, "select * from ");
		strcat(cmd, table);		//拼接指令

		mysql_free_result(res);
		mysqlOperation(cmd);
		res = mysql_store_result(mysql_conn);

		while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
		{
			for (int i = 0; i < colNum; i++) {
				_vect.push_back(col[i]);
			}
			vect.push_back(_vect);
			for (int i = 0; i < colNum; i++) {
				_vect.pop_back();
			}
		}

		return vect;
	}

	void DataBaseInterface::createTargetTable(const char *tableName, std::vector<std::string> &colName) {
		char cmd[1024];

		strcpy(cmd, "CREATE TABLE ");
		strcat(cmd, tableName);
		strcat(cmd, " (");

		for (int i = 0; i < colName.size(); ++i) {
			std::string tmpCmd = colName[i] + " INT UNSIGNED NOT NULL DEFAULT 0";
			if (i != colName.size() - 1)
				tmpCmd.append(",");
			strcat(cmd, tmpCmd.c_str());
		}

		strcat(cmd, ")ENGINE MYISAM CHARSET utf8");

		mysqlOperation(cmd);
	}

	void DataBaseInterface::deleteTabel(const char *table) {
		char cmd[100];

		strcpy(cmd, "DROP TABLE ");
		strcat(cmd, table);

		mysqlOperation(cmd);
	}

	bool DataBaseInterface::findTargetTable(const char *table) {
		char cmd[100];

		MYSQL_RES *res;
		MYSQL_ROW col;

		std::vector<std::vector<std::string>> vect;
		std::vector<std::string> _vect;

		res = NULL;//要先初始化，否则会报错

		strcpy(cmd, "SELECT table_name FROM information_schema.TABLES WHERE table_name =\'");
		strcat(cmd, table);		//拼接指令
		strcat(cmd, "\' LIMIT 0,1");

		mysql_free_result(res);
		mysqlOperation(cmd);
		res = mysql_store_result(mysql_conn);

		while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
		{
			for (int i = 0; i < 1; i++) {
				_vect.push_back(col[i]);
			}
			vect.push_back(_vect);
			for (int i = 0; i < 1; i++) {
				_vect.pop_back();
			}
		}

		return vect.size() == 1 ? true : false;
	}

	int DataBaseInterface::findColNumsFromTargetTable(const char *table) {
		char cmd[256];

		MYSQL_RES *res;
		MYSQL_ROW col;

		std::vector<std::vector<std::string>> vect;
		std::vector<std::string> _vect;

		res = NULL;//要先初始化，否则会报错

		strcpy(cmd, "SELECT COUNT(1) FROM information_schema.columns WHERE table_schema=\"");
		strcat(cmd, DB_DATABASE);
		strcat(cmd, "\" AND table_name=\"");
		strcat(cmd, table);		
		strcat(cmd, "\"");

		mysql_free_result(res);
		mysqlOperation(cmd);
		res = mysql_store_result(mysql_conn);

		while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
		{
			for (int i = 0; i < 1; i++) {
				_vect.push_back(col[i]);
			}
			vect.push_back(_vect);
			for (int i = 0; i < 1; i++) {
				_vect.pop_back();
			}
		}

		return atoi(vect.front().front().c_str());
	}

	std::vector<std::vector<std::string>> DataBaseInterface::queryAllData(const char * table, const int colNum,
		const char *factorColName, std::string &factorColValue, const char *orderColNum = "id") {
		char cmd[100];

		MYSQL_RES *res;
		MYSQL_ROW col;

		std::vector<std::vector<std::string>> vect;
		std::vector<std::string> _vect;

		res = NULL;//要先初始化，否则会报错

		strcpy(cmd, "select * from ");
		strcat(cmd, table);		//拼接指令
		strcat(cmd, " where ");
		strcat(cmd, factorColName);
		strcat(cmd, "=");
		strcat(cmd, factorColValue.c_str());
		strcat(cmd, " order by ");
		strcat(cmd, orderColNum);

		mysql_free_result(res);
		mysqlOperation(cmd);
		res = mysql_store_result(mysql_conn);

		while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
		{
			for (int i = 0; i < colNum; i++) {
				_vect.push_back(col[i]);
			}
			vect.push_back(_vect);
			for (int i = 0; i < colNum; i++) {
				_vect.pop_back();
			}
		}

		return vect;
	}

	std::vector<std::vector<std::string>> DataBaseInterface::queryAllData(const char * table, const int colNum, const char *orderColNum = "id") {
		char cmd[100];

		MYSQL_RES *res;
		MYSQL_ROW col;

		std::vector<std::vector<std::string>> vect;
		std::vector<std::string> _vect;

		res = NULL;//要先初始化，否则会报错

		strcpy(cmd, "select * from ");
		strcat(cmd, table);		//拼接指令
		strcat(cmd, " order by ");
		strcat(cmd, orderColNum);

		mysql_free_result(res);
		mysqlOperation(cmd);
		res = mysql_store_result(mysql_conn);

		while ((col = mysql_fetch_row(res)) != NULL)		// 每一行访问
		{
			for (int i = 0; i < colNum; i++) {
				_vect.push_back(col[i]);
			}
			vect.push_back(_vect);
			for (int i = 0; i < colNum; i++) {
				_vect.pop_back();
			}
		}

		return vect;
	}
}