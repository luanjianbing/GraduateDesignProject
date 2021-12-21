#pragma once

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <mutex>
#include <thread>
#include <time.h>

#include "../MySubStructure/BlockQueue.h"
#include "DataBase.h"

namespace Model {
	class Log {
	public:
		Log(int max_queue_size = 1000, int m_log_buf_size = 8192);
		~Log();

		static void flush_log_thread(void *args)
		{
			Log::get_instance()->async_write_log();
		}

		static Log *get_instance() {
			if (uniqueInstance == nullptr) {
				std::unique_lock<std::mutex> lock(mMutex);
				if (uniqueInstance == nullptr) {   // ��Ϊ�յ�ʱ�򣬴���һ��
					uniqueInstance = new Log();
				}
			}
			return uniqueInstance; // ���ش����������
		}

		void write_log(int level, const char *format, ...);

	private:
		void async_write_log()
		{
			std::string single_log;
			//������������ȡ��һ����־string��д���ļ�
			while (m_log_queue->pop(single_log))
			{
				m_mutex.lock();

				std::vector<std::string> log_str;
				log_str.push_back("0");
				log_str.push_back(single_log);
				mDataBaseInterFace->insertSingleRowData("system_log", log_str);

				m_mutex.unlock();
			}
		}
	private:
		DataBaseInterface *mDataBaseInterFace;

		BlockQueue<std::string> *m_log_queue; //��������
		char *m_buf;	// ��־������
		std::mutex m_mutex;
		int m_log_buf_size; //��־��������С

		static std::mutex mMutex;
		static Log *uniqueInstance;
	};
}

#define LOG_DEBUG(format, ...) {Model::Log::get_instance()->write_log(0, format, ##__VA_ARGS__);}
#define LOG_INFO(format, ...) {Model::Log::get_instance()->write_log(1, format, ##__VA_ARGS__);}
#define LOG_WARN(format, ...) {Model::Log::get_instance()->write_log(2, format, ##__VA_ARGS__); }
#define LOG_ERROR(format, ...) {Model::Log::get_instance()->write_log(3, format, ##__VA_ARGS__); }

#endif