/********************************************************************
    created:    2012-07-23 22:32:12
    file path:  F:\code\zlib\basic_lib\itimeinterval.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#ifndef _ITIMEINTERVAL_H_
#define _ITIMEINTERVAL_H_

class ITimeInterval
{
public:
    virtual ~ITimeInterval()
    {

    }
public:
    ///> 开始计时
    virtual void Start() = 0;
    ///> 返回时间间隔（单位毫秒）
    virtual BOOL Stop(OUT double& dfTimeInterval) = 0;
};


#endif // _ITIMEINTERVAL_H_