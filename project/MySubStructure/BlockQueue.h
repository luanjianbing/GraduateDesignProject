#pragma once

#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <iostream>
#include <condition_variable>
#include <mutex>

namespace Model {
	// �������У�������־���ģ��
	template <class T>
	class BlockQueue {
	public:
		BlockQueue(int max_size = 1000) {
			if (max_size <= 0){
				std::cout << "Block Queue max_size Error" << std::endl;
				exit(-1);
			}

			m_max_size = max_size;
			m_array = new T[max_size];
			m_size = 0;
			m_front = -1;
			m_back = -1;
		}

		void clear()
		{
			m_mutex.lock();
			m_size = 0;
			m_front = -1;
			m_back = -1;
			m_mutex.unlock();
		}

		~BlockQueue() {
			m_mutex.lock();
			if (m_array != NULL)
				delete[] m_array;

			m_mutex.unlock();
		}

		//�ж϶����Ƿ�����
		bool full()
		{
			m_mutex.lock();
			if (m_size >= m_max_size)
			{

				m_mutex.unlock();
				return true;
			}
			m_mutex.unlock();
			return false;
		}

		//�ж϶����Ƿ�Ϊ��
		bool empty()
		{
			m_mutex.lock();
			if (0 == m_size)
			{
				m_mutex.unlock();
				return true;
			}
			m_mutex.unlock();
			return false;
		}

		//���ض���Ԫ��
		bool front(T &value)
		{
			m_mutex.lock();
			if (0 == m_size)
			{
				m_mutex.unlock();
				return false;
			}
			value = m_array[m_front];
			m_mutex.unlock();
			return true;
		}

		//���ض�βԪ��
		bool back(T &value)
		{
			m_mutex.lock();
			if (0 == m_size)
			{
				m_mutex.unlock();
				return false;
			}
			value = m_array[m_back];
			m_mutex.unlock();
			return true;
		}

		int size()
		{
			int tmp = 0;

			m_mutex.lock();
			tmp = m_size;

			m_mutex.unlock();
			return tmp;
		}

		int max_size()
		{
			int tmp = 0;

			m_mutex.lock();
			tmp = m_max_size;

			m_mutex.unlock();
			return tmp;
		}

		//���������Ԫ�أ���Ҫ������ʹ�ö��е��߳��Ȼ���
		//����Ԫ��push������,�൱��������������һ��Ԫ��
		//����ǰû���̵߳ȴ���������,����������
		bool push(const T &item)
		{

			m_mutex.lock();
			if (m_size >= m_max_size)
			{

				m_cond.notify_all();
				m_mutex.unlock();
				return false;
			}

			m_back = (m_back + 1) % m_max_size;
			m_array[m_back] = item;

			m_size++;

			m_cond.notify_all();
			m_mutex.unlock();
			return true;
		}

		//popʱ,�����ǰ����û��Ԫ��,����ȴ���������
		bool pop(T &item)
		{

			//m_mutex.lock();
			std::unique_lock <std::mutex> lck(m_mutex);
			while (m_size <= 0)
			{
				m_cond.wait(lck);
				//if (!m_cond.wait(m_mutex.get()))
				//{
				//	m_mutex.unlock();
				//	return false;
				//}
			}

			m_front = (m_front + 1) % m_max_size;
			item = m_array[m_front];
			m_size--;
			//m_mutex.unlock();
			return true;
		}

	private:
		std::mutex m_mutex;
		std::condition_variable m_cond;

		T *m_array;
		int m_size;
		int m_max_size;
		int m_front;
		int m_back;
	};
}

#endif