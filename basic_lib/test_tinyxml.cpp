#define TIXML_USE_STL

#include "test_tinyxml.h"
#include "tinyxml\tinyxml.h"

void CreatXmlFile(std::string strFilePath)
{
    TiXmlDocument *pDoc = new TiXmlDocument;
    TiXmlNode *pNode = pDoc->FirstChild();
    delete pDoc;
}

void LoadXmlFile(std::string strFilePath)
{
    TiXmlDocument *pDoc = new TiXmlDocument;
    pDoc->LoadFile(strFilePath.c_str());

    TiXmlNode *pNode = pDoc->FirstChild();
    std::cout << pNode->Type() << std::endl;

    delete pDoc;
}

void LoadXmlData(std::string strXmlData)
{

}