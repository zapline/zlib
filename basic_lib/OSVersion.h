/********************************************************************
    created:    2012.4.17  12:17
    file path:  e:\ZLib\basic_lib\OSVersion.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class COSVersion
{
private:
    COSVersion(void);
    ~COSVersion(void);

    OSVERSIONINFO m_VersionInfo;

public:
    static COSVersion& Instance()
    {
        static COSVersion inst;
        return inst;
    }

    const OSVERSIONINFO& GetOSVersionInfo();

    BOOL IsWinXp();
    BOOL IsWinXpOrLater();
    BOOL IsWinVista();
    BOOL IsWinVistaOrLater();
    BOOL IsWin7();
    BOOL IsWin8();
    CString GetOsName();
};

