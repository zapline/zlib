/********************************************************************
    created:    2012.4.24  12:26
    file path:  e:\ZLib\basic_lib\OperFile.h
    author:     zapline<278998871@qq.com>
*********************************************************************/

#pragma once
class COperFile
{
private:
    COperFile(void);
    ~COperFile(void);

public:
	/*
	* @funcn							--- FileIsEixst
	* @brief							--- �ж��ļ��Ƿ����	
	* @param strFilePath				--- �ļ����ļ��е�·��
	* @return 
	*							   FALSE--- �ļ�������
	*							   TRUE	--- �ļ�����
	*/
	static BOOL FileIsEixst(IN const std::wstring& strFilePath);

	/*
	* @funcn							--- GetFileSize
	* @brief							--- ��ȡ�ļ��Ĵ�С	
	* @param strFilePath				--- �ļ��ľ���·��
	* @param uFileSize					--- �õ����ļ��Ĵ�С
	* @return 
	*							   FALSE--- ʧ�ܣ�����ԭ�����ļ���ʧ�ܣ��򣬻�ȡ�ļ���Сʧ��
	*							   TRUE	--- �ļ�����
	*/
	static int GetFileSize(IN const std::wstring& strFilePath, OUT size_t& uFileSize);

	/*
	* @funcn							--- ReadFileData
	* @brief							--- ��ȡ�ļ�	
	* @param strFilePath				--- ��Ҫ��ȡ���ļ��ľ���·��
	* @param nMode						--- ���뷽ʽ��1-ansi 2-utf8 3-unicode
	* @param strFileData				--- ��ȡ���ļ�������
	* @return 
	*							   FALSE--- ���ļ�ʧ��
	*							   TRUE	--- ���ļ��ɹ�
	*/
	static int ReadFileData(IN const std::wstring& strFilePath, OUT int& nMode, OUT std::wstring& strFileData);
	//static int ReadFileData(IN const std::wstring& strFilePath, OUT std::wstring& strFileData);
    static int ReadFileBinaryData( IN const std::wstring& strFilePath, OUT std::string& strFileData, OUT DWORD& dwFileSize);

	/*
	* @funcn							--- WriteFileData
	* @brief							--- д���ļ�	
	* @param strFilePath				--- ��Ҫд����ļ��ľ���·��
	* @param nMode						--- ���뷽ʽ��1-ansi 2-utf8 3-unicode
	* @param strFileData				--- ��Ҫд����ļ�������
	* @return 
	*							   FALSE--- д�ļ�ʧ��
	*							   TRUE	--- ���ļ��ɹ�
	*/
	static int WriteFileData(IN const std::wstring& strFilePath, IN int nMode, IN std::wstring strFileData);

	/*
	* @funcn							--- DelteFile
	* @brief							--- ɾ���ļ��������趨�Ƿ�����ɾ��	
	* @param strFilePath				--- ��Ҫɾ�����ļ��ľ���·��
	* @param bRebootMoveIfFail			--- �趨�Ƿ�������ɾ��
	* @return 
	*							   FALSE--- ɾ��ʧ�ܣ�����������ʧ��
	*							   TRUE	--- ɾ���ɹ��������������ɹ�
	*/
	static int DelFile(IN const std::wstring& strFilePath, IN BOOL bRebootMoveIfFail = TRUE);

	/*
	* @funcn							--- FileCopy
	* @brief							--- �����ļ�	
	* @param strSrcFilePath				--- Դ�ļ���·��
	* @param strDesFilePath				--- Ҫ���������ļ�·��
	* @param bFailIfExists				--- �趨���ļ�����ʱ���Ƿ񸲸�
	* @return 
	*							   FALSE--- �ļ�����ʧ��
	*							   TRUE	--- �ļ������ɹ�
	*/
	static int FileCopy(IN const std::wstring& strSrcFilePath, IN const std::wstring& strDesFilePath, IN BOOL bFailIfExists);
};
