/********************************************************************
    created:    2012.4.27  13:58
    file path:  E:\zlib\zPanelLib\zPanelLib.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <map>
#include "tinyxml\tinyxml.h"

class CCCA
{
public:
    int a;
    void Do();
};

class PanelData
{
public:
    PanelData()
        : x1(0),x2(0),y1(0),y2(0)
    {

    }
    void SetPos(LPCSTR lpszPos);
protected:
    long x1,x2,y1,y2;
};

// 最基础的面板
class CPanelBase : public PanelData
{
public:
    CPanelBase()
    {
    }
    virtual ~CPanelBase()
    {
    }
    BOOL LoadXmlData(LPCSTR lpszXml);
    BOOL LoadXml( TiXmlElement *pElem );
    BOOL Show(HDC hdc);

    BOOL AddPanel(long nId, CPanelBase *pPanel);
    void Release();
private:
    std::map<long, CPanelBase *> m_ChildPanel;
};

// 绘图引擎
class CGraphEngine
{
public:
    static void DrawBox(HDC hdc, long x1, long y1, long x2, long y2);
};