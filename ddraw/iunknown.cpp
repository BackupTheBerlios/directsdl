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
/*	functions for the IUnknown interface from DirectDraw 7 */
#include "ddraw.h"

IUnknown::IUnknown(void){};
IUnknown::~IUnknown(void){};

/* unknown function. MSDN said for debugging puposes only...seems not to be
very important */
int IUnknown::AddRef(void)
{
	return DD_OK;
};

/*	this querys a DirectX object.
	It will always return successful and always create a DD7 object
*/
int IUnknown::QueryInterface(LPVOID interface, LPVOID *object)
{
	/* allocate the IDirectDraw7 object */
	LPDIRECTDRAW7 ddraw = new IDirectDraw7;
	
	/* write back to pointer */
	(LPVOID)object = ddraw;

	/* all ok */
	return DD_OK;
};

/*	IUnknown::Release - apollo11's statement for delete this;
	<apollo11> steini: es geht schon
	<apollo11> nur
	<apollo11> ich würde es nicht machen
	<apollo11> ich halt's für schlechtes konzept */
int IUnknown::Release(void)
{
	delete this;
	return DD_OK;
};
