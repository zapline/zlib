#include "Picture.h"


CPicture::CPicture(void)
    : h(0)
    , w(0)
    , data(NULL)
{
}

CPicture::CPicture( const char* const* arr, int n)
{
    Init(arr, n);
}

void CPicture::Init( const char* const* arr, int n)
{
    h = n;
    w = GetMaxW(arr, n);
    data = new char[h*w];
    for (int i = 0; i < n; i++)
    {
        const char* s = arr[i];
        int l = strlen(s);
        int j = 0;
        while (j < l)
        {
            Pos(i, j) = s[j];
            j++;
        }
        while (j < w)
        {
            Pos(i, j) = ' ';
            j++;
        }
    }
}

CPicture::CPicture( const CPicture& x)
    : h(x.h)
    , w(x.w)
    , data(new char[x.h * x.w])
{
    memcpy(data, x.data, x.h * x.w);
}


CPicture::~CPicture(void)
{
    delete []data;
}

CPicture& CPicture::operator=( const CPicture& x )
{
    if (this != &x)
    {
        delete []data;
        w = x.w;
        h = x.h;
        data = new char[w * h];
        memcpy(data, x.data, w * h);
    }
    return *this;
}

int CPicture::GetMaxW( const char* const* arr, int n )
{
    int MaxW = 0;
    for (int i = 0; i < n; i++)
    {
        MaxW = max(MaxW, (int)strlen(arr[i]));
    }
    return MaxW;
}

char& CPicture::Pos( int x, int y )
{
    return data[x * w + y];
}

ostream& operator<<( ostream& o, CPicture& p)
{
    for (int i = 0; i < p.h; i++)
    {
        for (int j = 0; j < p.w; j++)
        {
            o << p.Pos(i, j);
        }
        o << endl;
    }
    return o;
}

CPicture Frame( CPicture& x)
{
    CPicture s;
    s.h = x.h + 2;
    s.w = x.w + 2;
    s.data = new char[s.h * s.w];
    for (int i = 0; i < s.h; i++)
    {
        for (int j = 0; j < s.w; j++)
        {
            if (i == 0 || i == s.h -1)
            {
                if (j == 0 || j == s.w - 1)
                    s.Pos(i, j) = '+';
                else
                    s.Pos(i, j) = '-';
                continue;
            }
            if (j == 0 || j == s.w - 1)
            {
                s.Pos(i, j) = '|';
                continue;
            }
            s.Pos(i, j) = x.Pos(i - 1, j - 1);
        }
    }
    return s;
}

CPicture operator&( CPicture& x, CPicture& y)
{
    CPicture s;
    s.h = x.h + y.h;
    s.w = max(x.w, y.w);
    s.data = new char[s.h * s.w];
    memset(s.data, ' ', s.h * s.w);
    int i, j;
    for (i = 0; i < x.h; i++)
    {
        for (j = 0; j < x.w; j++)
            s.Pos(i, j) = x.Pos(i, j);
    }
    for (i = x.h; i < s.h; i++)
    {
        for (j = 0; j < y.w; j++)
            s.Pos(i, j) = y.Pos(i - x.h, j);
    }
    return s;
}

CPicture operator|( CPicture& x, CPicture& y)
{
    CPicture s;
    s.h = max(x.h, y.h);
    s.w = x.w + y.w;
    s.data = new char[s.h * s.w];
    memset(s.data, ' ', s.h * s.w);
    int i, j;
    for (i = 0; i < x.h; i++)
    {
        for (j = 0; j < x.w; j++)
            s.Pos(i, j) = x.Pos(i, j);
    }
    for (i = 0; i < y.h; i++)
    {
        for (j = x.w; j < s.w; j++)
            s.Pos(i, j) = y.Pos(i, j - x.w);
    }
    return s;
}
