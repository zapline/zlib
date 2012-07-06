#pragma once

#include <iostream>
using namespace std;

class CPicture
{
public:
    CPicture(void);
    CPicture(const char* const*, int);
    CPicture(const CPicture&);
    ~CPicture(void);

    CPicture& operator=(const CPicture&);
    int GetMaxW( const char* const* arr, int n );

    char& Pos(int x, int y);

    int h, w;
    char* data;
private:

    void Init( const char* const* arr, int n);
};

ostream& operator<<(ostream&, CPicture&);

CPicture Frame(CPicture&);
CPicture operator&(CPicture&, CPicture&);
CPicture operator|(CPicture&, CPicture&);

