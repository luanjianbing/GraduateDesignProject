#include "Log.h"

namespace Model {
	Log *Log::uniqueInstance = NULL;
	std::mutex Log::mMutex;

	int gettimeofday(struct timeval *tp, void *tzp) {
		time_t clock;
		struct tm tm;
		SYSTEMTIME wtm;
		GetLocalTime(&wtm);
		tm.tm_year = wtm.wYear - 1900;
		tm.tm_mon = wtm.wMonth - 1;
		tm.tm_mday = wtm.wDay;
		tm.tm_hour = wtm.wHour;
		tm.tm_min = wtm.wMinute;
		tm.tm_sec = wtm.wSecond;
		tm.tm_isdst = -1;
		clock = mktime(&tm);
		tp->tv_sec = clock;
		tp->tv_usec = wtm.wMilliseconds * 1000;
		return (0);

	}

	Log::Log(int max_queue_size, int m_log_buf_size) {
		if (max_queue_size >= 1)
		{
			m_log_queue = new BlockQueue<std::string>(max_queue_size);

			// 初始化缓冲区
			m_buf = new char[m_log_buf_size];

			// 构建日志写线程
			std::thread mLogThread = std::thread(&flush_log_thread, this);
			mLogThread.detach();

			// 初始化数据库接口对象
			std::cout << "日志模块尝试连接数据库: ";
			mDataBaseInterFace = new DataBaseInterface();

			std::cout << "日志模块初始化完毕" << std::endl;
		}
	}

	void Log::write_log(int level, const char *format, ...) {
		struct timeval now = { 0, 0 };
		gettimeofday(&now, NULL);
		time_t t = now.tv_sec;
		struct tm *sys_tm = localtime(&t);
		struct tm my_tm = *sys_tm;
		char s[16] = { 0 };
		switch (level)
		{
		case 0:
			strcpy(s, "[debug]:");
			break;
		case 1:
			strcpy(s, "[info]:");
			break;
		case 2:
			strcpy(s, "[warn]:");
			break;
		case 3:
			strcpy(s, "[erro]:");
			break;
		default:
			strcpy(s, "[info]:");
			break;
		}
		
		va_list valst;
		va_start(valst, format);

		std::string log_str;

		// 写入的具体时间内容格式
		int n = _snprintf(m_buf, 48, "%d-%02d-%02d %02d:%02d:%02d %s ",
			my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday,
			my_tm.tm_hour, my_tm.tm_min, my_tm.tm_sec, s);
		
		int m = _vsnprintf(m_buf + n, m_log_buf_size - 1, format, valst);
		m_buf[n + m] = '\n';
		m_buf[n + m + 1] = '\0';
		log_str = m_buf;

		if (!m_log_queue->full())
		{
			m_log_queue->push(log_str);
		}
	}


	Log::~Log() {
		if (m_log_queue != NULL) {
			delete m_log_queue;
		}

		if (m_buf != NULL) {
			delete m_buf;
		}

		if (uniqueInstance != NULL) {
			delete uniqueInstance;
		}
	}
}