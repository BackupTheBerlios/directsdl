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
#ifndef _OPENDX_H_
#define _OPENDX_H_

/* include some C standard headers */
#include <stdio.h>
#include <stdlib.h>

/* include SDL */
#include <SDL.h>

/* include headers for "Windows" compatibility */
#include "windows.h"

/* include the "notimplemented" feature */
#include "notimplemented.h"

/* holds the surface for the screen */
extern SDL_Surface *screen;

/* flags from SetCooperateLevel */
extern int cooperate_flags;

/* holds the windowname given at CreateWindow() */
extern char *pWindowCaption;

typedef int HANDLE;

/* MS always typed that FAR...we don't need this */
#define FAR

#define IID_IDirectDraw7 NULL

#endif
