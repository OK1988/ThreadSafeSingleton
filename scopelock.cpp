#include <mutex>
#include "scopelock.hpp"

namespace ok
{
	
scopelock::scopelock(std::mutex & mtx ) : scope_lock_mtx(mtx) 
{ 
	scope_lock_mtx.lock();  //lock the mutex in the constructor
}
scopelock::~scopelock() 
{ 
	scope_lock_mtx.unlock(); //unlock the mutex in the constructor
}

} //end of namespace

