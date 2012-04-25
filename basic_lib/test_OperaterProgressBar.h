/********************************************************************
    created:    2012.4.8  10:52
    file path:  E:\ZLib\basic_lib\test_OperaterProgressBar.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <graphics.h>

void test_graphics()
{
    initgraph(640, 480);
    setfont(16, 0, L"Consolas");

    static TCHAR XShow[50];
    for (int i = 0; i < 50; i++)
    {
        XShow[i] = L'-';
    }
    static int XStatusN = 0;
    const TCHAR XStatus[] = L"/-\\|";
    for (DWORD dwValue = 0; dwValue < 300; dwValue++)
    {
        DWORD nRealValue = dwValue / 6;
        XShow[nRealValue] = XStatus[XStatusN++];
        if (nRealValue > 0)
        {
            XShow[nRealValue - 1] = L'=';
        }
        XStatusN = XStatusN > 3 ? XStatusN % 4 : XStatusN;
        Sleep(100);
        system("cls");

        outtextxy(0, 0, XShow);
    }

    closegraph();
}