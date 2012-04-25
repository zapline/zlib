/********************************************************************
    created:    2012.4.16  21:46
    file path:  e:\ZLib\basic_lib\AppPath.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class CAppPath
{
private:
    CAppPath(void);
    ~CAppPath(void);

    BOOL m_bInited;
    void _Init();

    CString m_CurrentPath;
    CString m_CurrentDir;

public:
    static CAppPath& Instance()
    {
        static CAppPath inst;
        return inst;
    }

    CString GetCurrentPath();
    CString GetCurrentDir();

};

