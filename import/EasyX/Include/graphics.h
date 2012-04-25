/******************************************************
 * EasyX Library for C++ (Ver:v20120304(beta))
 * http://www.easyx.cn
 *
 * graphics.h
 * �� VC ��ģ�� Borland BGI ��ͼ�⣬ʵ�ּ򵥵Ļ�ͼ
 ******************************************************/

#pragma once

#ifndef WINVER
#define WINVER 0x0400			// Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500		// Specifies that the minimum required platform is Windows 95/NT4.
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410	// Specifies that the minimum required platform is Windows 98.
#endif

#if defined(UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphicswu.lib")
#elif !defined(UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphicsw.lib")
#elif defined(UNICODE)
	#pragma comment(lib,"graphicsu.lib")
#elif !defined(UNICODE)
	#pragma comment(lib,"graphics.lib")
#endif


#include <windows.h>
#include <tchar.h>

// Ϊ�˼��� Borland C++ 3.1 �����������嶨��
#define DETECT 0
#define VGA	0
#define VGAHI 0

// ��ͼ������ʼ������
#define SHOWCONSOLE		1		// ����ͼ��ģʽʱ����������̨����ʾ

// ��ɫ
#define	BLACK			0
#define	BLUE			0xA80000
#define	GREEN			0x00A800
#define	CYAN			0xA8A800
#define	RED				0x0000A8
#define	MAGENTA			0xA800A8
#define	BROWN			0x0054A8
#define	LIGHTGRAY		0xA8A8A8
#define	DARKGRAY		0x545454
#define	LIGHTBLUE		0xFC5454
#define	LIGHTGREEN		0x54FC54
#define	LIGHTCYAN		0xFCFC54
#define	LIGHTRED		0x5454FC
#define	LIGHTMAGENTA	0xFC54FC
#define	YELLOW			0x54FCFC
#define	WHITE			0xFCFCFC

// ������ɫת����
#define BGR(color)	( (((color) & 0xFF) << 16) | ((color) & 0xFF00FF00) | (((color) & 0xFF0000) >> 16) )

// ���ģʽ
#define	NULL_FILL			1		// �����
#define	SOLID_FILL			2		// ��ָ����ɫ��ȫ���
#define	BDIAGONAL_FILL		3		// /// ��� (��ͨһ��)
#define	CROSS_FILL			4		// +++ ���
#define	DIAGCROSS_FILL		5		// xxx ���
#define	DOT_FILL			6		// ... ���
#define	FDIAGONAL_FILL		7		// \\\ ���
#define	HORIZONTAL_FILL		8		// --- ���
#define	VERTICAL_FILL		9		// ||| ���
#define	BDIAGONAL2_FILL		10		// /// ��� (�ܼ�һ��)
#define	CROSS2_FILL			11		// +++ ���
#define	DIAGCROSS2_FILL		12		// xxx ���
#define	DOT2_FILL			13		// ... ���
#define	FDIAGONAL2_FILL		14		// \\\ ���
#define	HORIZONTAL2_FILL	15		// --- ���
#define	VERTICAL2_FILL		16		// ||| ���
#define	BDIAGONAL3_FILL		17		// /// ��� (����һ��)
#define	CROSS3_FILL			18		// +++ ���
#define	DIAGCROSS3_FILL		19		// xxx ���
#define	DOT3_FILL			20		// ... ���
#define	FDIAGONAL3_FILL		21		// \\\ ���
#define	HORIZONTAL3_FILL	22		// --- ���
#define	VERTICAL3_FILL		23		// ||| ���
#define	INTERLEAVE_FILL		24		// xxx ��� (ʮ����)
#define	PATTERN_FILL		25		// ��ָ��ͼ�����



// ��ͼģʽ��غ���

HWND initgraph(int Width, int Height, int Flag = NULL);	// ��ʼ��ͼ�λ���
HWND initgraph(int* gdriver, int* gmode, char* path);	// ���� Borland C++ 3.1 �����أ�Ĭ�� 640x480
void closegraph();										// �ر�ͼ�λ���



// ��ͼ��������

void cleardevice();					// ����
void setcliprgn(HRGN hrgn);			// ���õ�ǰ��ͼ�豸�Ĳü���
void clearcliprgn();				// ����ü�������Ļ����

void getlinestyle(int *plinestyle, WORD *pupattern = NULL, int *pthickness = NULL);	// ��ȡ��ǰ����
void setlinestyle(int linestyle, WORD upattern = NULL, int thickness = 1);			// ���õ�ǰ����
void getfillstyle(COLORREF *pcolor, int *ppattern = NULL, char *pupattern = NULL);			// ��ȡ�������
void setfillstyle(COLORREF color, int pattern = SOLID_FILL, const char *pupattern = NULL);	// �����������

void setorigin(int x, int y);							// ��������ԭ��
void getaspectratio(float *pxasp, float *pyasp);		// ��ȡ��ǰ��������
void setaspectratio(float xasp, float yasp);			// ���õ�ǰ��������

void setwritemode(int mode);				// ���û�ͼλ����ģʽ

void graphdefaults();						// �������л�ͼ����ΪĬ��ֵ

COLORREF getcolor();				// ��ȡ��ǰ��ͼǰ��ɫ
void setcolor(COLORREF color);		// ���õ�ǰ��ͼǰ��ɫ
COLORREF getbkcolor();				// ��ȡ��ǰ��ͼ����ɫ
void setbkcolor(COLORREF color);	// ���õ�ǰ��ͼ����ɫ
void setbkmode(int iBkMode);		// ���ñ������ģʽ

// ��ɫģ��ת������
COLORREF RGBtoGRAY(COLORREF rgb);
void RGBtoHSL(COLORREF rgb, float *H, float *S, float *L);
void RGBtoHSV(COLORREF rgb, float *H, float *S, float *V);
COLORREF HSLtoRGB(float H, float S, float L);
COLORREF HSVtoRGB(float H, float S, float V);


// ��ͼ����

COLORREF getpixel(int x, int y);				// ��ȡ�����ɫ
void putpixel(int x, int y, COLORREF color);	// ����

void moveto(int x, int y);						// �ƶ���ǰ��(��������)
void moverel(int dx, int dy);					// �ƶ���ǰ��(�������)

void line(int x1, int y1, int x2, int y2);		// ����
void linerel(int dx, int dy);					// ����(���������)
void lineto(int x, int y);						// ����(����������)

void rectangle(int left, int top, int right, int bottom);	// ������

void circle(int x, int y, int radius);													// ��Բ
void ellipse(int left, int top, int right, int bottom);									// ����Բ
void arc(int left, int top, int right, int bottom, double stangle, double endangle);	// ����Բ��(��ʼ�ǶȺ���ֹ�Ƕ�Ϊ������)
void fillcircle(int x, int y, int radius);												// �����Բ
void fillellipse(int left, int top, int right, int bottom);								// �������Բ
void pie(int left, int top, int right, int bottom, double stangle, double endangle);	// �������Բ����(��ʼ�ǶȺ���ֹ�Ƕ�Ϊ������)

void bar(int left, int top, int right, int bottom);										// ���ޱ߿�������
void bar3d(int left, int top, int right, int bottom, int depth, bool topflag);			// ���б߿���ά������

void drawpoly(int numpoints, const int *polypoints);	// �������
void fillpoly(int numpoints, const int *polypoints);	// �����Ķ����
void floodfill(int x, int y, int border);				// �������



// ������غ���

void outtext(LPCTSTR str);					// �ڵ�ǰλ������ַ���
void outtext(TCHAR c);						// �ڵ�ǰλ������ַ�
void outtextxy(int x, int y, LPCTSTR str);	// ��ָ��λ������ַ���
void outtextxy(int x, int y, TCHAR c);		// ��ָ��λ������ַ�
int textwidth(LPCTSTR str);					// ��ȡ�ַ���ռ�õ����ؿ�
int textwidth(TCHAR c);						// ��ȡ�ַ�ռ�õ����ؿ�
int textheight(LPCTSTR str);				// ��ȡ�ַ���ռ�õ����ظ�
int textheight(TCHAR c);					// ��ȡ�ַ�ռ�õ����ظ�
int drawtext(LPCTSTR str, RECT* pRect, UINT uFormat);	// ��ָ����������ָ����ʽ����ַ���
int drawtext(TCHAR c, RECT* pRect, UINT uFormat);		// ��ָ����������ָ����ʽ����ַ�

// ���õ�ǰ������ʽ(�������)
//		nHeight: �ַ���ƽ���߶ȣ�
//		nWidth: �ַ���ƽ�����(0 ��ʾ����Ӧ)��
//		lpszFace: �������ƣ�
//		nEscapement: �ַ�������д�Ƕ�(��λ 0.1 ��)��
//		nOrientation: ÿ���ַ�����д�Ƕ�(��λ 0.1 ��)��
//		nWeight: �ַ��ıʻ���ϸ(0 ��ʾĬ�ϴ�ϸ)��
//		bItalic: �Ƿ�б�壻
//		bUnderline: �Ƿ��»��ߣ�
//		bStrikeOut: �Ƿ�ɾ���ߣ�
//		fbCharSet: ָ���ַ�����
//		fbOutPrecision: ָ�����ֵ�������ȣ�
//		fbClipPrecision: ָ�����ֵļ������ȣ�
//		fbQuality: ָ�����ֵ����������
//		fbPitchAndFamily: ָ���Գ��淽ʽ�������������ϵ�С�
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace);
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut);
void setfont(int nHeight, int nWidth, LPCTSTR lpszFace, int nEscapement, int nOrientation, int nWeight, bool bItalic, bool bUnderline, bool bStrikeOut, BYTE fbCharSet, BYTE fbOutPrecision, BYTE fbClipPrecision, BYTE fbQuality, BYTE fbPitchAndFamily);
void setfont(const LOGFONT *font);	// ���õ�ǰ������ʽ
void getfont(LOGFONT *font);		// ��ȡ��ǰ������ʽ



// ͼ������

// ����ͼ�����
class IMAGE
{
private:
	HBITMAP m_hBmp;
	HDC m_hMemDC;
	int m_Width, m_Height;
	int m_MemCurX;			// ��ǰ��X����
	int m_MemCurY;			// ��ǰ��Y����
	float m_data[6];
	COLORREF	m_Color;			// ��ǰ��ɫ
	COLORREF	m_BkColor;			// ��ǰ������ɫ
	DWORD*		m_pBuffer;			// ��ͼ�����ڴ�

	struct{
		int		linestyle;
		WORD	upattern;		// �Զ�������
		int		thickness;
	}	m_LineType;				// ����

	struct{
		int pattern;
		char upattern[8];		// �Զ����������
		int color;
	}	m_FillType;									// �������
	virtual void SetDefault();						// ����ΪĬ��״̬

public:
	IMAGE(int width = 0, int height = 0);			// ����ͼ��
	IMAGE(const IMAGE &img);						// �������캯��
	IMAGE& operator = (const IMAGE &img);			// ��ֵ��������غ���
	virtual ~IMAGE();
	virtual void Resize(int width, int height);		// �����ߴ�
};

void loadimage(IMAGE *pDstImg, LPCTSTR pImgFile, int nWidth = 0, int nHeight = 0, bool bResize = false);					// ��ͼƬ�ļ���ȡͼ��(bmp/jpg/gif/emf/wmf)
void loadimage(IMAGE *pDstImg, LPCTSTR pResType, LPCTSTR pResName, int nWidth = 0, int nHeight = 0, bool bResize = false);	// ����Դ�ļ���ȡͼ��(bmp/jpg/gif/emf/wmf)
void saveimage(LPCTSTR pImgFile, IMAGE* pImg = NULL);	// ����ͼ��
void getimage(IMAGE *pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);				// �ӵ�ǰ��ͼ�豸��ȡͼ��
void putimage(int dstX, int dstY, const IMAGE *pSrcImg, DWORD dwRop = SRCCOPY);							// ����ͼ����Ļ
void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);	// ����ͼ����Ļ(ָ�����)
void Resize(IMAGE* pImg, int width, int height);	// ������ͼ�豸�Ĵ�С
DWORD* GetImageBuffer(IMAGE* pImg = NULL);			// ��ȡ��ͼ�豸���Դ�ָ��
IMAGE* GetWorkingImage();							// ��ȡ��ǰ��ͼ�豸
void SetWorkingImage(IMAGE* pImg = NULL);			// ���õ�ǰ��ͼ�豸
HDC GetImageHDC(IMAGE* pImg = NULL);				// ��ȡ��ͼ�豸���(HDC)


// ��������

int	getwidth();			// ��ȡ��ͼ�����
int	getheight();		// ��ȡ��ͼ���߶�
int	getx();				// ��ȡ��ǰ x ����
int	gety();				// ��ȡ��ǰ y ����

void BeginBatchDraw();	// ��ʼ��������
void FlushBatchDraw();	// ִ��δ��ɵĻ�������
void FlushBatchDraw(int left, int top, int right, int bottom);	// ִ��ָ��������δ��ɵĻ�������
void EndBatchDraw();	// �����������ƣ���ִ��δ��ɵĻ�������
void EndBatchDraw(int left, int top, int right, int bottom);	// �����������ƣ���ִ��ָ��������δ��ɵĻ�������

HWND GetHWnd();								// ��ȡ��ͼ���ھ��(HWND)
TCHAR* GetEasyXVer();						// ��ȡ EasyX ��ǰ�汾

// ��ȡ�û�����
bool InputBox(LPTSTR pString, int nMaxCount, LPCTSTR pPrompt = NULL, LPCTSTR pTitle = NULL, LPCTSTR pDefault = NULL, int width = 0, int height = 0, bool bOnlyOK = true);



// �����Ϣ
// ֧��������Ϣ��
//		WM_MOUSEMOVE		����ƶ�
//		WM_MOUSEWHEEL		�����ֲ���
//		WM_LBUTTONDOWN		�������
//		WM_LBUTTONUP		�������
//		WM_LBUTTONDBLCLK	���˫��
//		WM_MBUTTONDOWN		�м�����
//		WM_MBUTTONUP		�м�����
//		WM_MBUTTONDBLCLK	�м�˫��
//		WM_RBUTTONDOWN		�Ҽ�����
//		WM_RBUTTONUP		�Ҽ�����
//		WM_RBUTTONDBLCLK	�Ҽ�˫��
struct MOUSEMSG
{
	UINT uMsg;				// ��ǰ�����Ϣ
	bool mkCtrl;			// Ctrl ���Ƿ���
	bool mkShift;			// Shift ���Ƿ���
	bool mkLButton;			// �������Ƿ���
	bool mkMButton;			// ����м��Ƿ���
	bool mkRButton;			// ����Ҽ��Ƿ���
	short x;				// ��ǰ��� x ����
	short y;				// ��ǰ��� y ����
	short wheel;			// �����ֹ���ֵ(120�ı���)
};

bool MouseHit();			// ����Ƿ���������Ϣ
MOUSEMSG GetMouseMsg();		// ��ȡһ�������Ϣ�����û�У��͵ȴ�
void FlushMouseMsgBuffer();	// ��������Ϣ������
