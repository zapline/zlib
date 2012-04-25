/********************************************************************
    created:    2012.4.16  12:13
    file path:  e:\ZLib\basic_lib\ConfigMgr.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

class CConfigMgr
{
public:
    CConfigMgr(void);
    ~CConfigMgr(void);

    static int	Get_VALUE_AUTO_EXAM();

    static void Set_VALUE_AUTO_EXAM( int nValue );

    static int	Get_CFG_VALUE_AUTO_ONCE_EXAM();

    static void Set_CFG_VALUE_AUTO_ONCE_EXAM( int nValue );

private:

    static BOOL _GetConfigFileName(LPCTSTR lpszCfgName, CString& strFileName);

    static BOOL _LoadConfig(
        LPCTSTR lpszCfgName, 
        LPCTSTR lpszKeyName, 
        LPCTSTR lpszValueName, 
        int &nValue, 
        int nDefault);

    static BOOL _LoadConfigStr(
        LPCTSTR lpszCfgName, 
        LPCTSTR lpszKeyName, 
        LPCTSTR lpszValueName,
        CString &strVal, 
        LPCTSTR szDefault=NULL);


    static BOOL _SaveConfig(
        LPCTSTR lpszCfgName,
        LPCTSTR lpszKeyName, 
        LPCTSTR lpszValueName,
        int nValue);

    static BOOL _SaveConfigStr(
        LPCTSTR lpszCfgName,
        LPCTSTR lpszKeyName,
        LPCTSTR lpszValueName,
        LPCTSTR szValue);
};

