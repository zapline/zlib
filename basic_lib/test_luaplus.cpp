/********************************************************************
    created:    2012.4.23  10:00
    file path:  E:\ZLib\basic_lib\test_luaplus.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "src_luaplus\LuaPlus.h"
//#pragma comment(lib,"luaplus.lib")
using namespace LuaPlus;

#include "stdafx.h"
#include "test_include.h"
#include "test_luaplus.h"
#include "AppPath.h"

int LS_PrintNumber(LuaState* state)
{
    LuaStack args(state);

    if (args[1].IsNumber())
    {
        cout<<args[1].GetNumber()<<endl;;
    }
    return 0;
}

void test_luaplus()
{
    LuaStateOwner state;
    state->GetGlobals().Register("PrintNumber", LS_PrintNumber);
    CStringA strPathFile( CAppPath::Instance().GetCurrentDir() );
    strPathFile += "..\\..\\document\\test_lua.lua";
    int iret = state->DoFile(strPathFile);
    int g_num = state->GetGlobal("g_num").GetInteger();
    LuaFunction <float> Add = state->GetGlobal("Add");
    float myRet = Add(3.14f, g_num);
}
