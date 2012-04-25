/********************************************************************
    created:    2012.4.16  12:13
    file path:  e:\ZLib\basic_lib\ConfigMgr.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "ConfigMgr.h"
#include "ComfigMgrDef.h"

CConfigMgr::CConfigMgr(void)
{
}

CConfigMgr::~CConfigMgr(void)
{
}

BOOL CConfigMgr::_GetConfigFileName(LPCTSTR lpszCfgName, CString& strFileName)
{
    strFileName =  lpszCfgName;
    ::SetFileAttributes(strFileName, FILE_ATTRIBUTE_NORMAL);
    return TRUE;
}

BOOL CConfigMgr::_LoadConfig(LPCTSTR lpszCfgName, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, int &nValue, int nDefault)
{
    CString strPath;

    BOOL bRet = _GetConfigFileName(lpszCfgName, strPath);
    if (!bRet)
        return FALSE;

    nValue = (int)::GetPrivateProfileInt(lpszKeyName, lpszValueName, nDefault, strPath);

    return TRUE;
}

BOOL CConfigMgr::_LoadConfigStr(LPCTSTR lpszCfgName, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, CString &strVal, LPCTSTR szDefault )
{
    if(szDefault)
        strVal = szDefault;

    CString strPath;
    BOOL bRet = _GetConfigFileName(lpszCfgName, strPath);
    if (!bRet)
        return FALSE;

    TCHAR buf[MAX_PATH] = {0};
    GetPrivateProfileString(lpszKeyName, lpszValueName, szDefault, buf, MAX_PATH-1, strPath );
    strVal = buf;

    return TRUE;
}

BOOL CConfigMgr::_SaveConfig(LPCTSTR lpszCfgName, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, int nValue)
{
    CString strPath, strValue;

    BOOL bRet = _GetConfigFileName(lpszCfgName, strPath);
    if (!bRet)
        return FALSE;

    strValue.Format(L"%d", nValue);

    return ::WritePrivateProfileString(lpszKeyName, lpszValueName, strValue, strPath);
}

BOOL CConfigMgr::_SaveConfigStr(LPCTSTR lpszCfgName, LPCTSTR lpszKeyName, LPCTSTR lpszValueName, LPCTSTR szValue)
{
    CString strPath;

    BOOL bRet = _GetConfigFileName(lpszCfgName, strPath);
    if (!bRet)
        return FALSE;

    return ::WritePrivateProfileString(lpszKeyName, lpszValueName, szValue, strPath);
}

int	CConfigMgr::Get_VALUE_AUTO_EXAM()
{
    int	nValue = 0;
    _LoadConfig( 
        CFG_FILENAME, 
        CFG_KEY_OPTION,
        CFG_VALUE_AUTO_EXAM, 
        nValue, 
        0 );
    return	nValue;
}

void CConfigMgr::Set_VALUE_AUTO_EXAM( int nValue )
{
    _SaveConfig(
        CFG_FILENAME, 
        CFG_KEY_OPTION, 
        CFG_VALUE_AUTO_EXAM, 
        nValue);
}

int	CConfigMgr::Get_CFG_VALUE_AUTO_ONCE_EXAM()
{
    int	nValue = 0;
    _LoadConfig( 
        CFG_FILENAME, 
        CFG_KEY_OPTION,
        CFG_VALUE_AUTO_ONCE_EXAM, 
        nValue, 
        0 );
    return	nValue;
}

void CConfigMgr::Set_CFG_VALUE_AUTO_ONCE_EXAM( int nValue )
{
    _SaveConfig(
        CFG_FILENAME, 
        CFG_KEY_OPTION, 
        CFG_VALUE_AUTO_ONCE_EXAM, 
        nValue);
}