/********************************************************************
    created:    2012.4.5  19:20
    file path:  E:\ZLib\basic_lib\BasicObject.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

class NotCopyable
{
private:
    NotCopyable(const NotCopyable&)
    {

    }
    NotCopyable& operator=(const NotCopyable&)
    {
        return *this;
    }
public:
    NotCopyable()
    {

    }
};

class Interface : private NotCopyable
{
public:
    virtual ~Interface()
    {

    }
};