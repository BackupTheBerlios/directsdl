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
/* some handy routines often used */
#include "ddraw.h"

/* converts a WinAPI RECT structure to a SDL_Rect structure */
void RECT2SDL(LPRECT sRect, SDL_Rect *dRect)
{
	dRect->x = sRect->left;
	dRect->y = sRect->top;
	dRect->w = sRect->right-sRect->left;
	dRect->h = sRect->bottom-sRect->top;
};
