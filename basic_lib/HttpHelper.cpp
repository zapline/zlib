/********************************************************************
    created:    2012.4.17  11:07
    file path:  E:\ZLib\basic_lib\HttpHelper.cpp
    author:     zapline<278998871@qq.com>
*********************************************************************/

#include "stdafx.h"
#include "HttpHelper.h"
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")


CHttpHelper::CHttpHelper(void)
{
	m_bProxy = false;
	m_bAuth = false;
	m_bStop = false;

	LoadProxyConfig();
}

CHttpHelper::~CHttpHelper(void)
{
}


BOOL CHttpHelper::isConnected2()
{
	DWORD   dwFlags; 
	HINTERNET hOpen = NULL;
	HINTERNET hConnect = NULL;
	HINTERNET hRequest = NULL;

	InternetGetConnectedState(&dwFlags, 0); 

	TCHAR strAgent[64]; 
	wsprintf(strAgent, L"Agent%ld ", timeGetTime());

	CString strProxy = L"HTTP=HTTP://" + m_strProxy + L":" + m_strPort;
	hOpen = InternetOpen(strAgent, INTERNET_OPEN_TYPE_PROXY, strProxy.GetBuffer(), NULL, 0);
	if (!hOpen) 	return FALSE;

	hConnect = InternetConnect(hOpen, L"www.baidu.com", 80, NULL, NULL, INTERNET_SERVICE_HTTP, INTERNET_FLAG_NO_UI, NULL);
	if (!hConnect)
	{
		InternetCloseHandle(hOpen);
		return FALSE;
	}

	if (m_bAuth)
	{
		InternetSetOption(hConnect, INTERNET_OPTION_PROXY_USERNAME, m_strUserName.GetBuffer(), m_strUserName.GetLength()*2+1);
		InternetSetOption(hConnect, INTERNET_OPTION_PROXY_PASSWORD, m_strPassword.GetBuffer(), m_strPassword.GetLength()*2+1);
	}

    static LPCTSTR s_szAcceptTypes[] = { _T("*/*"), NULL };
    hRequest = HttpOpenRequest(
        hConnect, _T("GET"), 
        L"/", 
        _T("HTTP/1.1"), NULL,
        s_szAcceptTypes, 
        INTERNET_FLAG_NO_UI | INTERNET_FLAG_KEEP_CONNECTION, 
        NULL);

	if (!hRequest)
	{
		InternetCloseHandle(hConnect);
		InternetCloseHandle(hOpen);
		return FALSE;
	}

	BOOL nRet = HttpSendRequest(hRequest, 0, 0, NULL, 0);

	InternetCloseHandle(hRequest);
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hOpen);


	return nRet;
}


BOOL CHttpHelper::isConnected()
{
	DWORD   dwFlags; 
	HINTERNET hOpen = NULL;
	HINTERNET hConnect = NULL;

	InternetGetConnectedState(&dwFlags, 0); 

	TCHAR strAgent[64]; 
	wsprintf(strAgent, L"Agent%ld ", timeGetTime());

	if (m_bProxy)
	{
		return isConnected2();
	}
	else if (!(dwFlags & INTERNET_CONNECTION_PROXY)) 
		hOpen = InternetOpen(strAgent, INTERNET_OPEN_TYPE_DIRECT/*INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY*/, NULL, NULL, 0); 
	else 
		hOpen = InternetOpen(strAgent, INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	if (!hOpen) 	return FALSE; 

	if (!(hConnect = InternetOpenUrl(hOpen, L"http://www.baidu.com", NULL, 0, INTERNET_FLAG_DONT_CACHE, 0))) 
	{ 
		InternetCloseHandle(hOpen); 
		return FALSE;
	}

	InternetCloseHandle(hConnect);
	InternetCloseHandle(hOpen);

	return TRUE;
}


BOOL CHttpHelper::GetUrlInfo( LPCTSTR lpszURL, char* szBuff, int nCount )
{
	DWORD   dwFlags; 
	DWORD   dwResult = INTERNET_ERROR_OPEN;
	HINTERNET hOpen = NULL;
	HINTERNET hConnect = NULL;
	HINTERNET hRequest = NULL;

	memset(szBuff, 0, nCount);

	InternetGetConnectedState(&dwFlags, 0); 

	TCHAR strAgent[64]; 
	wsprintf(strAgent, L"Agent%ld ", timeGetTime());

	CString strProxy = L"http=http://" + m_strProxy + L":" + m_strPort;
	hOpen = InternetOpen(strAgent, INTERNET_OPEN_TYPE_PROXY, strProxy, NULL, NULL);

	if (!hOpen)
	{
		CString strError;
		strError.Format( TEXT("连接服务异常: 1"));
		return FALSE;
	}

	DWORD dwTimeout = 3000;
	InternetSetOption(hOpen, INTERNET_OPTION_CONNECT_TIMEOUT, &dwTimeout, sizeof(DWORD));

	//////////////////////////////
	CString strUrl = lpszURL;
	int nPos = strUrl.Find(L"/", 8);
	CString strHost = strUrl.Mid(7, nPos-7);
	strUrl = strUrl.Right(strUrl.GetLength()-nPos);
	//////////////////////////////

	hConnect = InternetConnect(hOpen, strHost, 80, NULL, NULL, INTERNET_SERVICE_HTTP, INTERNET_FLAG_NO_UI, NULL);
	if (!hConnect)
	{
		CString strError;
		strError.Format( TEXT("连接服务异常: 2"));

		InternetCloseHandle(hOpen);
		return FALSE;
	}

	if (m_bAuth)
	{
		InternetSetOption(hConnect, INTERNET_OPTION_PROXY_USERNAME, m_strUserName.GetBuffer(), m_strUserName.GetLength()*2+1);
		InternetSetOption(hConnect, INTERNET_OPTION_PROXY_PASSWORD, m_strPassword.GetBuffer(), m_strPassword.GetLength()*2+1);
	}

    static LPCTSTR s_szAcceptTypes[] = { _T("*/*"), NULL };

    hRequest = HttpOpenRequest(
        hConnect, _T("GET"), 
        strUrl, 
        _T("HTTP/1.1"), NULL,
        s_szAcceptTypes, 
        INTERNET_FLAG_NO_UI | INTERNET_FLAG_KEEP_CONNECTION, 
        NULL);

	if (!hRequest)
	{
		CString strError;
		strError.Format( TEXT("连接服务异常: 3"));

		InternetCloseHandle(hConnect);
		InternetCloseHandle(hOpen);
		return FALSE;
	}

   HttpSendRequest(hRequest, 0, 0, NULL, 0);

	int nBlockSize = 16384;
	if (nBlockSize >= nCount)
		nBlockSize = nCount-1;

	int nReadBytes = 0;
	char* pBuffer = szBuff;

	while (!m_bStop && (nReadBytes+nBlockSize) < nCount)
	{
		DWORD dwSize = 0; 
		if ( !InternetReadFile(hRequest, pBuffer, nBlockSize, &dwSize) ) 
		{
			CString strError;
			strError.Format( TEXT("连接服务异常: 4"));

			InternetCloseHandle(hRequest);
			InternetCloseHandle(hConnect);
			InternetCloseHandle(hOpen);
			return FALSE; 
		} 

		if (!dwSize) 
			break;     //   Condition   of   dwSize=0   indicate   EOF.   Stop. 

		nReadBytes += dwSize;
		pBuffer += dwSize; 

	}

	*pBuffer = 0;

	InternetCloseHandle(hRequest);
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hOpen);

	return TRUE;
}

void CHttpHelper::LoadProxyConfig()
{
	int nProxyType = 0;
    // 先不处理代理
	
	if (!m_strProxy.IsEmpty())
	{
		if (nProxyType == 1)
		{
			m_bProxy = true;

			if (!m_strUserName.IsEmpty())
				m_bAuth = true;
			else
				m_bAuth = false;
		}
		else
			m_bProxy = false;
	}
	else
	{
		m_bProxy = false;
	}
}

void CHttpHelper::Stop()
{
	m_bStop = true;
}