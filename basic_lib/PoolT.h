/********************************************************************
    created:    2012.4.4  11:12
    file path:  e:\ZLib\basic_lib\PoolT.h
    author:     zapline<278998871@qq.com>
*********************************************************************/
#pragma once
#include <map>
#include <algorithm>

template<typename ResKeyType, typename ResType>
class IProcessRes
{
public:
    virtual ResType CreateNew(ResKeyType ResKey) = 0;
    virtual void ReleaseRes(ResKeyType ResKey) = 0;
};

template<typename ResKeyType, typename ResType, typename IProcessRes>
class CResPoolT
{
protected:
    typedef std::map<ResKeyType, ResType> _TypeResPool;
    typedef std::pair<ResKeyType, ResType> _TypeResPoolPair;

    std::map<ResKeyType, ResType> m_ResMap;
    IProcessRes m_ProcessRes;

    struct DeletePair
    {
        void operator() (const _TypeResPoolPair &pr) const
        {
            if (pr.second)
                _Instance()->m_ProcessRes.ReleaseRes(pr.second);
        }
    };

    static CResPoolT* ms_pInstance;
    static CResPoolT* _Instance()
    {
        if (!ms_pInstance)
            ms_pInstance = new CResPoolT;
        return ms_pInstance;
    }

public:
    virtual ~CResPoolT()
    {
        for_each(m_ResMap.begin(), m_ResMap.end(), DeletePair());
        m_ResMap.clear();
    }

    static ResType GetRes(ResKeyType ResKey)
    {
        _TypeResPool::iterator iter = _Instance()->m_ResMap.find(ResKey);
        ResType ResRet = NULL;

        if(iter == _Instance()->m_ResMap.end())
        {
            ResRet = _Instance()->m_ProcessRes.CreateNew(ResKey);
            if (ResRet)
                _Instance()->m_ResMap[ResKey] = ResRet;
        }
        else
        {
            ResRet = iter->second;
        }
        return ResRet;
    }

    static size_t GetCount()
    {
        return _Instance()->m_ResMap.size();
    }

};

template<typename ResKeyType, typename ResType, typename IProcessRes>
__declspec(selectany) CResPoolT<ResKeyType, ResType, IProcessRes>* CResPoolT<ResKeyType, ResType, IProcessRes>::ms_pInstance = NULL;

class CIntProcess : public IProcessRes<int, int>
{
public:
    virtual int CreateNew(int ResKey)
    {
        return ResKey * 2;
    }
    virtual void ReleaseRes(int ResKey)
    {
        ;
    }
};
typedef CResPoolT<int, int, CIntProcess> CIntResPool;