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
    // 0����������
    // 1���ļ�������
    // 2��xml���ش���
    int LoadXmlFile(std::string strFilePath);

};