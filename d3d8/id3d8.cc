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
/* IDirect3D8 class implementation
*/

#include <SDL.h>
#include "d3d8.h"

// std c'tor d'tor
IDirect3D8::IDirect3D8(void)
{
};

IDirect3D8::~IDirect3D8(void)
{
};

// this methods should check the hardware for the requested features....
// this is just a dummy function...
bool IDirect3D8::CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
	return true;
};

bool IDirect3D8::CreateDevice(UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice8** ppReturnedDeviceInterface)
{
	int flags = SDL_OPENGL;
	int depth;
	
	// check if fullscreen is wanted
	if(!pPresentationParameters->Windowed) flags|=SDL_FULLSCREEN;
	
	// choose video pixel depth
	// there are much more video formats to do....
	// we just enable 16bit because it's the best for OpenGL in Linux :)
	switch(pPresentationParameters->BackBufferFormat){
		case D3DFMT_R5G6B5: depth = 16; break;
		default: depth = 16; break;
	};
	
	// set videomode using SDL :)
	SDL_SetVideoMode(	pPresentationParameters->BackBufferWidth,
				pPresentationParameters->BackBufferHeight,
				depth,flags);
	
	// create a new DeviceInterface
	*ppReturnedDeviceInterface = new IDirect3DDevice8;
	
	return true;
};
