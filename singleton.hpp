#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include <mutex>

namespace ok
{
	
template <typename T>
class singleton
{
public:
	static T* GetInstance();
	~singleton() = delete;
	singleton() = delete; 

	singleton(const singleton& other) = delete;                 /*not implement by design*/
    singleton& operator=(const singleton& other) = delete;	   /*not implement by design*/	
    
private:
	
	static T* m_instance;
	
	class singletondestructor
	{
	public:
		~singletondestructor();
	};
	

};

} //namespace ok

#endif //__SINGLETON_HPP__
