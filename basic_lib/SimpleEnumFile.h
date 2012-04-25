/********************************************************************
    created:    2012.4.13  11:32
    file path:  e:\ZLib\basic_lib\SimpleEnumFile.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
#include <atlstr.h>

class CSimpleEnumFile
{
private:
    CSimpleEnumFile(void);

public:
    ~CSimpleEnumFile(void)
    {

    }

    class FileInfo  
    {
    public:
        FileInfo(){}
        ~FileInfo(){}

        CString m_strFileName;
        DWORD   m_nSize;

        operator CString&()
        {
            return m_strFileName;
        }

        CString& GetStr()
        {
            return m_strFileName;
        }
    };

    CSimpleEnumFile(LPCTSTR lpDirName, LPCTSTR lpPost=_T("*.*"))
    {
        CString strSearch;

        strSearch=lpDirName;

        if (strSearch.Right(1)!=_T("\\"))
            strSearch.Append(_T("\\"));
        strSearch.Append(lpPost);
        m_strDir = lpDirName;

        WIN32_FIND_DATA wfd = {0};
        HANDLE          hFind = ::FindFirstFile(strSearch,&wfd);

        if (hFind != INVALID_HANDLE_VALUE)
        {
            do
            {
                FileInfo    fi;
                CString     strFileName = wfd.cFileName;

                if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                    if (    strFileName.CompareNoCase(_T(".")) == 0 
                        ||  strFileName.CompareNoCase(_T("..")) == 0
                        )
                        continue;

                    m_listDirs.Add(strFileName);
                }
                else
                {
                    fi.m_strFileName    = strFileName;
                    fi.m_nSize          = wfd.nFileSizeLow;	
                    m_listFiles.Add(fi);
                }

            }while ( ::FindNextFile(hFind, &wfd) );

            FindClose( hFind );
        } 
    }

    // �ļ�����
    int GetFileCount()
    {
        return m_listFiles.GetSize();
    }

    // Ŀ¼����
    int GetDirCount()
    {
        return m_listDirs.GetSize();
    }

    // �ļ���
    CString& GetFileName(int i)
    {
        return m_listFiles[i].GetStr();
    }

    // �ļ���С
    DWORD GetFilesize(int i)
    {
        return m_listFiles[i].m_nSize;
    }

    // ��Ŀ¼·��
    CString& GetDirName(int i)
    {
        return m_listDirs[i];
    }

    // �ļ�·����
    CString	GetFileFullPath(int i)
    {
        CString	strFull = m_strDir;
        strFull.Append(_T("\\"));
        strFull.Append(m_listFiles[i].GetStr());
        return strFull;
    }

    // ��Ŀ¼����·��
    CString GetDirFullPath(int i)
    {
        CString	strFull = m_strDir;
        strFull.Append(_T("\\"));
        strFull.Append(m_listDirs[i]);
        return strFull;
    }

protected:
    CSimpleArray<FileInfo>  m_listFiles;
    CSimpleArray<CString>   m_listDirs;
    CString                 m_strDir;
};

