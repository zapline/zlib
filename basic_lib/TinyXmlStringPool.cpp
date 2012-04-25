/********************************************************************
    created:    2012.4.25  15:19
    file path:  E:\zlib\basic_lib\TinyXmlStringPool.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "TinyXmlStringPool.h"
#include <string>
#include "tinyxml\tinyxml.h"

int CTinyXmlStringPool::LoadXmlFile(std::string strFilePath)
{
    if (::PathFileExistsA( (LPCSTR)strFilePath.c_str() ) == FALSE )
    {
        return 1;
    }
    TiXmlDocument *pDoc = new TiXmlDocument;
    if (pDoc->LoadFile(strFilePath.c_str()) == false)
        return 2;
    TiXmlElement *pXmlStringRootElem = pDoc->RootElement();
    if (!pXmlStringRootElem || strcmp(pXmlStringRootElem->Value(), "str") != 0)
        return 2;

    for (TiXmlElement* pXmlChild = pXmlStringRootElem->FirstChildElement("s"); NULL != pXmlChild; pXmlChild = pXmlChild->NextSiblingElement("s"))
    {
        const char *psId = pXmlChild->Attribute("id");
        if (!psId)
            continue;
        Add(::StrToIntA(psId), pXmlChild->GetText());
    }
    delete pDoc;
    return 0;
}