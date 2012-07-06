#include "stdafx.h"
#include "test_include.h"
#include "test_tinyxml.h"
#include "PoolT.h"
#include "test_aes.h"
#include "test_lock.h"
#include "BasicObject.h"
#include "test_inteface.h"
#include "pinyin.h"
#include "test_OperaterProgressBar.h"
#include "test_file.h"
#include "test_string.h"
#include "test_CongfigMgr.h"
#include "URLEncode.h"
#include "test_path.h"
#include "test_time.h"
#include "test_net.h"
#include "test_system.h"
#include "test_luaplus.h"
#include "test_unzip.h"
#include "Picture.h"

void test_test()
{
    //LoadXmlFile(std::string("..\\import\\tinyxml\\utf8test.xml"));

//     CIntResPool *xInt = new CIntResPool;
//     cout << xInt->GetRes(1) << endl;
//     cout << xInt->GetRes(3) << endl;
//     cout << xInt->GetCount() << endl;
//     delete xInt;

    //testaes();

    //test_lock();

    //test_inteface();

//     string s1 = "你",s2;
//     CPinyin::GetWenziPinyin(s1, s2);
//     cout<<s1<<"  "<<s2<<endl;
//     s1 = "你d的a的";
//     CPinyin::GetPinyin(s1, s2);
//     cout<<s1<<"  "<<s2<<endl;
//     s1 = "社会主义好12345";
//     CPinyin::GetPinyin(s1, s2);
//     cout<<s1<<"  "<<s2<<endl;

    //test_graphics();

    //test_SimpleEnumFile();
    //test_CFileVersionInfo();
    // 

    //test_Wildcard();

    //test_ConfigMgr();

    //wcout<<CURLEncode::URLEncode(L"http://www.baidu.com/s?wd=傻逼").GetString();

    //test_DownLoadSize();

    //test_AppPath();

    //test_CheckExpired();

    //test_HttpHelper();

    //test_OSVersion();

    //test_SystemInfo();

    //test_MemoryFile();

    //test_luaplus();

    //test_unzip();

    //testStringPool();

    char *pp[] = {"hello", "world", "zapline"};
    CPicture p(pp, 3);
    cout<<p<<endl;

    CPicture q = Frame(p);
    cout<<q<<endl;

    CPicture r = p | q;
    cout<<r<<endl;

    CPicture s = q & r;
    cout<<s<<endl<<Frame(s)<<endl;

    cout<<Frame(q & ( p | q ))<<endl;
}

int main()
{
    test_test();

    getchar();
    return 0;
}