#pragma once

#define MUTEXLOCK_EXPORTS
#ifdef MUTEXLOCK_EXPORTS
#define MUTEXLOCK_API __declspec(dllexport)
#else
#define MUTEXLOCK_API __declspec(dllimport)
#endif

#if defined  _WIN32              //Windows                            
#include <Windows.h>
#define Mutex_Type				HANDLE
#define Mutex_Init(_mutex)		(_mutex = CreateSemaphore(NULL,1,1,NULL))
#define Mutex_Lock(_mutex)		(WaitForSingleObject(_mutex, INFINITE))
#define Mutex_UnLock(_mutex)	(ReleaseSemaphore(_mutex,1,NULL))
#define Mutex_Destroy(_mutex)	(CloseHandle(_mutex))

#elif defined __linux            //Linux                               
#include <pthread.h>
#define Mutex_Type				pthread_mutex_t
#define Mutex_Init(_mutex)		(pthread_mutex_init(&_mutex, NULL))
#define Mutex_Lock(_mutex)		(pthread_mutex_lock(&_mutex))
#define Mutex_UnLock(_mutex)	(pthread_mutex_unlock(&_mutex))
#define Mutex_Destroy(_mutex)	(pthread_mutex_destroy(&_mutex))
#endif

//============================================================================
// Name        : MutexLock
// Author      : XF_Shaw
// Version     : 2016/7/17
// Copyright   : 
// Description : The MutexLock is a tool for controlling access to a shared
//				 resorce by multiple threads. Only one thread can access the
//				 lock at a time.
//============================================================================

class MUTEXLOCK_API MutexLock
{
public:
	MutexLock()		{ Mutex_Init(_mutex)	; }
	~MutexLock()	{ Mutex_Destroy(_mutex)	; }

	void lock()		{ Mutex_Lock(_mutex)	; }
	void unLock()	{ Mutex_UnLock(_mutex)	; }

private:
	Mutex_Type _mutex;
};