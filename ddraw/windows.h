/*
 	SDLDX - A wrapper, which provides DirectX functionality on top of the SDL library
    Copyright (C) 2004	Sebastian Steinhauer <steini@steini-welt.de>
						
						
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


	SDLDX is a wrapper, which provides DirectX functionality on top of the 
	Simple Direct Media Layer (SDL) library. Using SDLDX enables you to easily 
	port DirectX applications (for example games) to any platform supported 
	by the SDL library.
	
*/

/*	windows.h

	Header to reach Windows compatibility.
	
*/

#ifndef _FAKE_WINDOWS_H_
#define _FAKE_WINDOWS_H_

#include <SDL.h>

/* define some very important Windows data types */
typedef Uint8 BYTE;
typedef Uint16 WORD;
typedef Uint32 DWORD;
typedef unsigned long LONG;
typedef void* LPVOID;
typedef int GUID;


/* window data */
typedef int HWND;

/* OLD STUFF !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* THIS HAS TO BE REWRITTEN COMPLETLY !!!!!! */
/* BECAUSE IT WAS WRITTEN FOR TESTING !!!!!! */
/* ONLY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
typedef int HRESULT;
typedef int HINSTANCE;
typedef char* LPSTR;
typedef int BOOL;

typedef int PAINTSTRUCT;

#define APIENTRY
#define HBRUSH int

#define true -1
#define TRUE true
#define false 0
#define FALSE false

enum {
	CS_HREDRAW, CS_VREDRAW, IDI_APPLICATION, IDC_ARROW, COLOR_BACKGROUND, WS_OVERLAPPED, 
	CW_USEDEFAULT, SW_SHOW, MB_OK
};

enum {
	WM_PAINT,
	WM_DESTROY
};

typedef struct __WNDCLASS {
	char *lpszClassName;
	int style;
	void *lpfnWndProc;
	int cbClsExtra, cbWndExtra;
	HINSTANCE hInstance;
	int hIcon;
	int hCursor;
	int hbrBackground;
	char *lpszMenuName;
} WNDCLASS; 

typedef struct __MSG {
	int wParam;
} MSG;

int LoadIcon(void*, int);
int LoadCursor(void*, int);
int RegisterClass(WNDCLASS*);
HWND CreateWindow(char*,char*,int,int,int,int,int,void*,void*,HINSTANCE,void*);
int ShowWindow(HWND,int);
int UpdateWindow(HWND);
int GetMessage(MSG*, void*, int, int);
int MessageBox(int,char*,char*,int);
int Sleep(long millis);
extern int BeginPaint(PAINTSTRUCT*, HWND);
extern int EndPaint(PAINTSTRUCT*, HWND);


#endif
