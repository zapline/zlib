/********************************************************************
    created:    2012.4.7  22:16
    file path:  e:\ZLib\basic_lib\NumberProgressBarTest.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "NumberProgressBarTest.h"
#include <iostream>
using namespace std;


CNumberProgressBarTest::CNumberProgressBarTest(void)
{
}


CNumberProgressBarTest::~CNumberProgressBarTest(void)
{
}

DWORD CNumberProgressBarTest::GetRealValue()
{
    static DWORD i = 0;
    return (i++) / 100;
}

void CNumberProgressBarTest::OnDisplayValue( LPVOID lpData )
{
    system("cls");
    char *pStr = (char *)lpData;
    cout << pStr;
}

void CNumberProgressBarTest::OnProgressEnd()
{
    cout << "end" << endl;
}

void CNumberProgressBarTest::Test()
{
    m_Bar.SetCallback(this);
    m_Bar.ProgressBegin(NULL, 0, 100);

}