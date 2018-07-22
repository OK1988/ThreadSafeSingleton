#ifndef __SINGLETON_HPP_TMPL__
#define __SINGLETON_HPP_TMPL__

#include <mutex>
#include "singleton.hpp"
#include "scopelock.hpp"

namespace ok
{

template <typename T>
T* singleton<T>::m_instance = nullptr;

template <typename T>
T* singleton<T>::GetInstance() 
{
	if (m_instance == nullptr) //Double-Checked Locking Pattern
	{
		static std::mutex mtx;
		scopelock x(mtx);
		
		if (m_instance == nullptr)
		{
			m_instance = new T;
			static singletondestructor sd;
		}
	}
	
	return m_instance;
}

template <typename T>
singleton<T>::singletondestructor::~singletondestructor()
{
	delete m_instance;
}
}

#endif //__SINGLETON_HPP_TMPL__
