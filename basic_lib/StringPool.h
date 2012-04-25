/********************************************************************
    created:    2012.4.25  14:42
    file path:  e:\zlib\basic_lib\StringPool.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

// 旨在将程序中用到的字符串独立出来

#pragma once
#include <map>

template<typename IndexT, typename StringT>
class CStringPool
{
public:
    CStringPool(void)
    {

    }
    ~CStringPool(void)
    {
        Clear();
    }

    typedef std::map<IndexT, StringT> _TypeResPool;
    typedef std::pair<IndexT, StringT> _TypeResPoolPair;

    void Clear()
    {
        m_Pool.clear();
    }

    bool Get(IndexT Index, StringT &Str)
    {
        _TypeResPool::iterator iter = m_Pool.find(Index);
        if(iter != m_Pool.end())
        {
            Str = iter->second;
            return true;
        }
        return false;
    }

    void Add(IndexT Index, StringT Str)
    {
        m_Pool[Index] = Str;
    }

    size_t Count()
    {
        return m_Pool.size();
    }

private:
    _TypeResPool m_Pool;
};

