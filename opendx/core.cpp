/*
    opendx - A wrapper, which provides DirectX functionality on top of the SDL library
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


    opendx is a wrapper, which provides DirectX functionality on top of the 
    Simple Direct Media Layer (SDL) library. Using opendx enables you to easily 
    port DirectX applications (for example games) to any platform supported 
    by the SDL library.
	
*/
#include"ddraw.h"

/*	The DirectDrawCreate function creates an instance of a DirectDraw object. A DirectDraw object created with 
	this function does not support the newest set of Direct3D interfaces. To create a DirectDraw object capable 
	of exposing the new features of Direct3D, use the DirectDrawCreateEx function. */
int DirectDrawCreate(GUID FAR *lpGUID, LPDIRECTDRAW FAR *lplpDD, void FAR *pUnkOuter  )
{
	/* 	Allows for future compatibility with COM aggregation features. Presently, however, this method returns 
		an error if this parameter is anything but NULL. */
	if(pUnkOuter) return DD_FALSE;
	
	/* create the DD-object */
	LPDIRECTDRAW ddInterface = new IDirectDraw7;
	
	/* write back pointer */
	(LPVOID)lplpDD = ddInterface;
	
	/* all ok */
	return DD_OK;
	
};

/*	The DirectDrawCreateEx function creates an instance of a DirectDraw object that supports the newest set of 
	Direct3D interfaces. To use the new features of Direct3D in DirectX 7.0, create a DirectDraw object with this
	function. For more information about the relationship between DirectDraw and Direct3D see The DirectDraw Object 
	and Direct3D and Accessing Direct3D topics.
	
	
	Not implemented. No 3D!!! Internally calls DirectDrawCreate() */
int DirectDrawCreateEx(GUID FAR *lpGUID, LPDIRECTDRAW *lplpDD, void *a, void FAR *pUnkOuter)
{
	/* 	Allows for future compatibility with COM aggregation features. Presently, however, this method returns 
		an error if this parameter is anything but NULL. */
	if(pUnkOuter) return DD_FALSE;
	
	/* create the DD-object */
	LPDIRECTDRAW ddInterface = new IDirectDraw7;
	
	/* write back pointer */
	(LPVOID)lplpDD = ddInterface;
	
	/* all ok */
	return DD_OK;
};
