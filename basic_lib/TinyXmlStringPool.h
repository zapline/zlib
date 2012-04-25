/********************************************************************
    created:    2012.4.25  15:11
    file path:  E:\zlib\basic_lib\CTinyXmlStringPool.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include "StringPool.h"

class CTinyXmlStringPool : public CStringPool<long, std::string>
{
public:
    // 0，正常加载
    // 1，文件不存在
    // 2，xml加载错误
    int LoadXmlFile(std::string strFilePath);

};