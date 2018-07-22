#ifndef __SCOPELOCK_H__
#define __SCOPELOCK_H__

#include <mutex>

namespace ok
{
class scopelock
{
public:
	scopelock(std::mutex & mtx );
	~scopelock();
	
	scopelock(const scopelock& other) = delete;                 /**not implement by design*/
    scopelock& operator=(const scopelock& other) = delete;	   /**not implement by design*/

private:	
	std::mutex & scope_lock_mtx;
};

} //end of namespace

#endif
