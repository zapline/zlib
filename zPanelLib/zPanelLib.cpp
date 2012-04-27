/********************************************************************
    created:    2012.4.27  14:08
    file path:  E:\zlib\zPanelLib\zPanelLib.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "zPanelLib.h"

void CCCA::Do()
{
    ::MessageBoxA(0, "1", "2", 0);
}


BOOL CPanelBase::LoadXmlData( LPCSTR lpszXml )
{
    TiXmlDocument xmlDoc;
    {
        xmlDoc.Parse(lpszXml, NULL, TIXML_ENCODING_UTF8);
    }

    if (xmlDoc.Error())
        return FALSE;

    TiXmlElement *pXmlRootElem = xmlDoc.RootElement();

    return LoadXml(pXmlRootElem);
}

BOOL CPanelBase::LoadXml( TiXmlElement *pElem )
{
    if (!pElem || strcmp(pElem->Value(), "panel") != 0)
        return FALSE;

    SetPos(pElem->Attribute("pos"));
    for (TiXmlElement* pXmlChild = pElem->FirstChildElement("panel"); NULL != pXmlChild; pXmlChild = pXmlChild->NextSiblingElement("panel"))
    {
        CPanelBase *pPanel = new CPanelBase;
        const char *psId = pXmlChild->Attribute("id");
        if (!psId)
            continue;
        AddPanel(::StrToIntA(psId), pPanel);
        pPanel->LoadXml(pXmlChild);
    }

    return TRUE;
}

BOOL CPanelBase::Show(HDC hdc)
{
    CGraphEngine::DrawBox(hdc, x1, y1, x2, y2);
    for (std::map<long, CPanelBase *>::iterator it=m_ChildPanel.begin();
        it!=m_ChildPanel.end();
        it++)
    {
        it->second->Show(hdc);
        delete it->second;
    }
    return TRUE;
}

BOOL CPanelBase::AddPanel( long nId, CPanelBase *pPanel )
{
    m_ChildPanel[nId] = pPanel;
    return TRUE;
}

void CPanelBase::Release()
{
    for (std::map<long, CPanelBase *>::iterator it=m_ChildPanel.begin();
        it!=m_ChildPanel.end();
        it++)
    {
        it->second->Release();
        delete it->second;
    }
}

void CGraphEngine::DrawBox( HDC hdc, long x1, long y1, long x2, long y2 )
{
    Rectangle(hdc, x1, y1, x2, y2);
}

void PanelData::SetPos( LPCSTR lpszPos )
{
    CStringA sPos(lpszPos);
    int nPos1 = sPos.Find(",");
    x1 = atoi(sPos.Left(nPos1));
    int nPos2 = sPos.Find(",", nPos1+1);
    y1 = atoi(sPos.Mid(nPos1+1, nPos2-nPos1));
    nPos1 = sPos.Find(",", nPos2+1);
    x2 = atoi(sPos.Mid(nPos2+1, nPos1-nPos2));
    y2 = atoi(sPos.Mid(nPos1+1));
}