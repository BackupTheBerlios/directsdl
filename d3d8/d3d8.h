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
/*  DirectGraphics (Direct3D 8) implementation
*/

#ifndef _D3D8_H_
#define _D3D8_H_

// define our Direct3D version
#ifndef DIRECT3D_VERSION
#define DIRECT3D_VERSION         0x0800
#endif  //DIRECT3D_VERSION

// define the SDK version
#define D3D_SDK_VERSION 120

// include our fake windows.h
#include <windows.h>

// include the D3D8 enums
#include "d3d8types.h"

// define long pointers to our classes
typedef class IDirect3D8*		LPDIRECT3D8;
typedef class IDirect3DDevice8*		LPDIRECT3DDEVICE8;


//
// dirty hack.... has to be included better!
//
#include "id3d8.h"
#include "id3ddevice.h"



#endif // d3d8.h
