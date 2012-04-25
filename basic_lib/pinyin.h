/********************************************************************
    created:    2012.4.6  17:28
    file path:  E:\ZLib\basic_lib\pinyin.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <map>
#include <string>
#include "tinyxml/tinyxml.h"
using std::string;
using std::map;

const char *g_strPinyinLib = "..\\document\\pinyin.xml";

class CPinyin
{
public:
    typedef struct _TY_PINYIN
    {
        string strPinyin;
        string strSuoxie;
    }Pinyin, *PPinyin;


    static void GetWenziPinyin(string& strWenzi, string& strSuoxie)
    {
        map<string, Pinyin>::iterator iter;

        iter = _Instance().m_mapPinyin.find(strWenzi);
        while (iter != _Instance().m_mapPinyin.end())
        {
            strWenzi = iter->second.strPinyin;
            strSuoxie = iter->second.strSuoxie;
            break;
        }

    }

    static void GetPinyin(string& strPinyin, string& strSuoxie)
    {
        strSuoxie = "";
        if( strPinyin.empty() )
        {
            return ;
        }

        unsigned char Element;

        string str1Chs;
        string strChs, strEng, strPinyin1, strsuo;
        str1Chs = "11";

        unsigned nSrcLength = strPinyin.length();

        for(unsigned nCnt = 0; nCnt < nSrcLength;)
        {
            Element = (unsigned char)strPinyin.at(nCnt);
            if(Element < 128)
            {
                // 英文字符
                strEng = (char)Element;
                strPinyin1 += strEng;
                strSuoxie += strEng;
                nCnt++;
            }
            else
            {
                // 汉字
                str1Chs.at(0) = Element;
                str1Chs.at(1) = strPinyin.at(nCnt+1);
                strChs = str1Chs;
                GetWenziPinyin(strChs,strsuo);
                int n = strChs.find(" ");
                if(n > 0)
                {
                    // 多音字
                    // 使用第一个读音
                    string str2Fu = strChs;
                    str2Fu.erase(0, n+1);
                    strPinyin1 += strChs.substr(0, n);
                    str2Fu = strsuo;
                    str2Fu.erase(0, 2);
                    strSuoxie += strsuo.substr(0, 1);
                }
                else
                {
                    strPinyin1 +=strChs;
                    strSuoxie += strsuo;
                }
                nCnt += 2;
            }
        }
        strPinyin = strPinyin1;
    }


private:

    void LoadFont(const char *pLibFile)
    {
        TiXmlDocument plugins(pLibFile);
        plugins.LoadFile();

        TiXmlHandle hDoc(&plugins);
        TiXmlElement* pElem = NULL;
        TiXmlHandle hroot(NULL);
        pElem = hDoc.FirstChildElement().Element();
        hroot = TiXmlHandle(pElem);
        pElem = hroot.FirstChildElement().Element();

        TiXmlElement* pSign_elem = hroot.Element()->FirstChildElement("font");
        if ( !pSign_elem ) 
            return ;
        for(; pSign_elem; pSign_elem = pSign_elem->NextSiblingElement("font"))
        {
            Pinyin pinyin;	
            std::string strHanzi = pSign_elem->Attribute("c");
            pinyin.strPinyin = pSign_elem->Attribute("p");
            pinyin.strSuoxie = pSign_elem->Attribute("s");

            m_mapPinyin.insert( std::make_pair(strHanzi, pinyin) );
        }
    }

protected:
    
    static CPinyin& _Instance()
    {
        static CPinyin Inst;
        if (Inst.m_mapPinyin.empty())
        {
            Inst.LoadFont(g_strPinyinLib);
        }
        return Inst;
    }

    std::map<std::string, Pinyin> m_mapPinyin;

};
