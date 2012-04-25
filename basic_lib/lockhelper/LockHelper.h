/********************************************************************
    created:    2012.4.5  18:26
    file path:  E:\ZLib\basic_lib\lockhelper\LockHelper.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

#include <assert.h>

class CLock
{
public:
    CLock()
    {
        InitializeCriticalSection( &cs );
    }
    ~CLock()
    {
        DeleteCriticalSection( &cs );
    }

#if(_WIN32_WINNT>=0x0500)
    BOOL TryLock()
    {
        return TryEnterCriticalSection( &cs );
    }
#endif

    void Lock()
    {
        EnterCriticalSection(&cs);
    }
    void Release()
    {
        LeaveCriticalSection(&cs);
    }

    CRITICAL_SECTION &	GetCS()
    {
        return cs;
    }

    operator CRITICAL_SECTION& ()
    {
        return cs;
    }

private:
    CRITICAL_SECTION cs;
};


class CSimpleLock
{
public:
    CSimpleLock(CRITICAL_SECTION& cs) : _cs(cs)
    {
        EnterCriticalSection(&_cs);
    }

    ~CSimpleLock()
    {
        LeaveCriticalSection(&_cs);
    }

private:
    CRITICAL_SECTION& _cs;
};

#define CSimpleLock_(x)		CSimpleLock x##_(x)
#define CSimpleLock2_(x)	CSimpleLock tmpLock(x)


class CObjectLock
{
public:
    CObjectLock( CLock* pLock )
        : m_pLock( pLock )
    {
        assert( m_pLock );
        m_pLock->Lock();
    }

    ~CObjectLock()
    {
        assert( m_pLock );
        m_pLock->Release();
    }

protected:
    CLock* m_pLock;
};