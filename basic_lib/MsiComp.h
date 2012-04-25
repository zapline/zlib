#pragma once

#include <atlstr.h>
#include <atlcoll.h>

//
// ����Msi��������������
//
//@Remark
// һ.ע�����
// HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Installer\\UserData\\...\\Components\\...
// HKEY_LOCAL_MACHINE\\SOFTWARE\\Classes\\Installer\\Products\\GUID
//
// ��.����GUID��Installer�з�����Ŀ¼
// ���ܰ������Ŀ¼
//
class CMsiComp
{
public:
	// ע����б�
	typedef CAtlList<CStringW>	RegList;
	// �ļ��б�
	typedef RegList				DirList;

public:
	CMsiComp(const CStringW &guid);

public:
	// ����ע�����
	const RegList& GetRegList() const 
	{ return _regList; }

	// ������Ŀ¼
	const DirList& GetDirList() const 
	{ return _dirList; }

private:
	void EnumComponent(const CStringW &subkey);
	void ParseComponent(const CStringW &subkey);
	void MergeDirectory(LPCWSTR pBuff, size_t cchBuff);

private:
	RegList _regList;
	DirList _dirList;
	const CStringW &_guid;
};