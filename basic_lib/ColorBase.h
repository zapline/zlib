/********************************************************************
    created:    2012.4.24  10:22
    file path:  E:\ZLib\basic_lib\ColorBase.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

static const float OneThird = 1.0f / 3;

static void RGBtoHSL(DWORD ARGB, float* H, float* S, float* L);
static void HSLtoRGB(DWORD* ARGB, float H, float S, float L);

static COLORREF PixelAlpha(
    COLORREF clrSrc,
    double src_darken,
    COLORREF clrDest,
    double dest_darken);

static BOOL WINAPI AlphaBitBlt(
    HDC hDC,
    int nDestX, int nDestY, int dwWidth, int dwHeight,
    HDC hSrcDC,
    int nSrcX, int nSrcY, int wSrc, int hSrc,
    BLENDFUNCTION ftn);