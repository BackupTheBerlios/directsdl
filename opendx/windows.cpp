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

/*	windows.cpp

	Try to fake some WinAPI functions commonly used by games
*/
#include <SDL.h>
#include <string.h>
#include <stdlib.h>
#include "windows.h"

/* the name of our window */
char *pWindowCaption=NULL;

/* OLD STUFF !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
/* THIS HAS TO BE REWRITTEN COMPLETLY !!!!!! */
/* BECAUSE IT WAS WRITTEN FOR TESTING !!!!!! */
/* ONLY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */


// "Erzeugt" Fenster (jaja *g)
HWND CreateWindow(char *a,char *Caption ,int b,int c,int d,int e,int f,void *g, void *h, HINSTANCE i, void *j)
{
	char *msg = "Fake X Window";
	
	if(Caption){
		pWindowCaption = (char*)malloc(strlen(Caption));
		strcpy(pWindowCaption,Caption);
	} else {
		pWindowCaption = (char*)malloc(strlen(msg));
		strcpy(pWindowCaption,msg);
	};
};

// Dummy Funktionen *g
int LoadIcon(void *lala,int lulu)
{
	return 0;
};
int LoadCursor(void *lala,int lulu)
{
	return 0;
};
int RegisterClass(WNDCLASS *lala)
{
	return 0;
};
int ShowWindow(HWND lala, int lulu)
{
	return 0;
};
int UpdateWindow(HWND lala)
{
	return 0;
};
int GetMessage(MSG *dreck, void *scheiss, int muell, int grampf)
{	
	return 0;
};

int BeginPaint(PAINTSTRUCT* a, HWND b)
{
	return 0;
};
int EndPaint(PAINTSTRUCT* a, HWND b)
{
	return 0;
};
int Sleep(long millis)
{
	SDL_Delay(millis);
};

