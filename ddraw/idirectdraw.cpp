/*
 	OpenDX - A wrapper, which provides DirectX functionality on top of the SDL library
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


	OpenDX is a wrapper, which provides DirectX functionality on top of the 
	Simple Direct Media Layer (SDL) library. Using OpenDX enables you to easily 
	port DirectX applications (for example games) to any platform supported 
	by the SDL library.
	
*/
/*
	IDirectDraw7

	Applications use the methods of the IDirectDraw7 interface to create DirectDraw objects and work with system-level 
	variables. This section is a reference to the methods of this interface. For a conceptual overview, see 
	The DirectDraw Object.
	
*/
#include"ddraw.h"


/*	Contructor...Destructor... */
IDirectDraw7::IDirectDraw7(void)
{
};
IDirectDraw7::~IDirectDraw7(void)
{
};

/*	MSDN says: The IDirectDraw7::Compact method is not currently implemented. */
int IDirectDraw7::Compact(void)
{
	return DD_OK;
};

/* 	The IDirectDraw7::Initialize method initializes a DirectDraw object 
	that was created by using the CoCreateInstance COM function.
	
	I don't know what this means...but we'll cheat the program ;) */
int IDirectDraw7::Initialize(GUID guid)
{
	return DD_OK;
};

/*	Sets the CooperateLevel. We store the flags */
int IDirectDraw7::SetCooperativeLevel(HWND wndHandle, DWORD ddFlags)
{
	/* store flags internally */
	int flags = 0;
	
	/* "translate" the DirectDraw flags to SDL flags */
	if(ddFlags & DDSCL_FULLSCREEN) flags |= SDL_FULLSCREEN;
	
	/* store the flags in our global int */
	cooperate_flags = flags;
	
	return DD_OK;
};

/*	Test the current CooperateLevel. Don't know why we should implement something... */
int IDirectDraw7::TestCooperativeLevel(void)
{
	return DD_OK;
};

/*	CreateSurface. Creates a DirectDraw Surface */
int IDirectDraw7::CreateSurface(LPDDSURFACEDESC2 lpDDSurfaceDesc2,
			LPDIRECTDRAWSURFACE7 *lplpDDSurface,  
  			void *pUnkOuter)
{
	LPDIRECTDRAWSURFACE7 surface;
	
	/* Allows for future compatibility with COM aggregation features. Presently, however, this method 
	returns an error if this parameter is anything but NULL. */
	if(pUnkOuter) return DD_FALSE;

	/* create object */
	surface = new IDirectDrawSurface7(lpDDSurfaceDesc2, lpDDSurfaceDesc2->ddsCaps.dwCaps);
	
	/* write pointer back */
	*lplpDDSurface = surface;	
	
	return DD_OK;
};

/* sets the display mode */
int IDirectDraw7::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP)
{
	/* use SDL ... */
	screen = SDL_SetVideoMode(dwWidth, dwHeight, dwBPP, cooperate_flags);
	
	/* set window title */
	SDL_WM_SetCaption(pWindowCaption,NULL);
	
	/* return OK */
	return DD_OK;
};

/* The IDirectDraw7::GetCaps method fills in the capabilities of the device driver for the hardware 
and the hardware emulation layer (HEL). */
int IDirectDraw7::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
	/* only a dummy function...type working code later */
	return DD_OK;
};

/* The IDirectDraw7::GetDisplayMode method retrieves the current display mode. */
int IDirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 lpDDSurfaceDesc2)
{
	/* store with and height..other values may follow */
	lpDDSurfaceDesc2->dwWidth = screen->w;
	lpDDSurfaceDesc2->dwHeight = screen->h;
	return DD_OK;
};

/* The IDirectDraw7::GetScanLine method retrieves the scan line that is currently being drawn on the monitor. */
/*	I really don't know why this function is important...we return a nice number and say...all ok... */
int IDirectDraw7::GetScanLine(LPDWORD lpdwScanLine)
{
	// return some number...
	*lpdwScanLine = 234;
	// quit
	return DD_OK;
};

/* 	The IDirectDraw7::GetVerticalBlankStatus method retrieves the status of the vertical blank.
	Another method...really important! */
int IDirectDraw7::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
	*lpbIsInVB = true;
	return DD_OK;
};

/* 	The IDirectDraw7::GetMonitorFrequency method retrieves the frequency of the monitor being driven 
	by the DirectDraw object. */
int IDirectDraw7::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
	// fake a good monitor *g
	*lpdwFrequency = 85;
	return DD_OK;
};

/* 	The IDirectDraw7::WaitForVerticalBlank method helps the application synchronize itself with
	the vertical-blank interval. */
int IDirectDraw7::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)  
{
	// another useful function...perhaps working code will
	// be written later...
	return DD_OK;
};

