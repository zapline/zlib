/********************************************************************
    created:    2012.4.24  10:07
    file path:  e:\ZLib\basic_lib\RenderClip.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class CRenderClip
{
public:
    CRenderClip(void);
    ~CRenderClip(void);

private:
    RECT rcItem;
    HDC hDC;
    HRGN hRgn;
    HRGN hOldRgn;

public:
    static void GenerateClip(HDC hDC, RECT rc, CRenderClip& clip);
    static void GenerateRoundClip(
        HDC hDC,
        RECT rc,
        RECT rcItem,
        int width,
        int height,
        CRenderClip& clip);
    static void UseOldClipBegin(HDC hDC, CRenderClip& clip);
    static void UseOldClipEnd(HDC hDC, CRenderClip& clip);
};

