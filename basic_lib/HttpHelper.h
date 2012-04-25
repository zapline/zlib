/********************************************************************
    created:    2012.4.17  11:03
    file path:  E:\ZLib\basic_lib\HttpHelper.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once

enum 
{
	INTERNET_ERROR_OPENURL = 1,
	INTERNET_ERROR_FILEOPEN,
	INTERNET_ERROR_READFILE,
	INTERNET_ERROR_OPEN
};



class CHttpHelper
{
private:
	bool	m_bProxy;
	CString m_strProxy;
	CString	m_strPort;
	bool	m_bAuth;
	CString m_strUserName;
	CString m_strPassword;
	
	bool	m_bStop;			// «∑ÒÕ£÷πœ¬‘ÿ

public:
	CHttpHelper(void);
	~CHttpHelper(void);

	static CHttpHelper& Instance()
	{
		static CHttpHelper _obj;
		return _obj;
	}

	BOOL isConnected();
	BOOL isConnected2();
	BOOL GetUrlInfo( LPCTSTR lpszURL, char* szBuff, int nCount );
	void LoadProxyConfig();
	void Stop();
};
