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
/*	member functions for IDirectDrawSurface7
*/
#include "ddraw.h"

/*	create a IDirectDrawSurface7 */
IDirectDrawSurface7::IDirectDrawSurface7(LPDDSURFACEDESC2 lpDDSurfaceDesc2, DWORD dwCaps)
{
	Uint32 rmask,gmask,bmask,amask;
	/* SDL interprets each pixel as a 32-bit number, so our masks must depend
	on the endianness (byte order) of the machine */
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    	rmask = 0xff000000;
    	gmask = 0x00ff0000;
    	bmask = 0x0000ff00;
    	amask = 0x000000ff;
	#else
    	rmask = 0x000000ff;
    	gmask = 0x0000ff00;
    	bmask = 0x00ff0000;
    	amask = 0xff000000;
	#endif
    
	/* if the user requested a primary surface we don't need to create one, we just point to the screen */
	if(dwCaps & DDSCAPS_PRIMARYSURFACE){
		// point to the screen...
		surface = screen;
	};
		
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, lpDDSurfaceDesc2->dwWidth, lpDDSurfaceDesc2->dwHeight, 
				32, rmask, gmask, bmask, amask);
	
	this->locked_surface = NULL;
};

/*	frees a DirectDrawSurface7
*/
int IDirectDrawSurface7::Release(void)
{
	// check if our surface was the "primary surface"
	// because screen can't be freed!
	if(surface!=screen)	SDL_FreeSurface(surface);
	return DD_OK;
};

/* 	The IDirectDrawSurface7::Initialize method initializes a DirectDrawSurface object.
	This method is provided for compliance with the Component Object Model (COM). Because the 
	DirectDrawSurface object is initialized when it is created, this method always returns 
	DDERR_ALREADYINITIALIZED. */
int IDirectDrawSurface7::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
	/* we do like the MSDN says */
	return DDERR_ALREADYINITIALIZED;
};

/*	The IDirectDrawSurface7::IsLost method determines whether the surface memory associated with 
	a DirectDrawSurface object has been freed.
	
	Dummy Function!! */
int IDirectDrawSurface7::IsLost(void)
{
	return DD_OK;
};

/*	The IDirectDrawSurface7::Restore method restores a surface that has been lost. This occurs when the surface memory 
	associated with the DirectDrawSurface object has been freed.

	Dummy Function!! */
int IDirectDrawSurface7::Restore(void)
{
	return DD_OK;
};

/*	The IDirectDrawSurface7::Blt method performs a bit block transfer (blit). This method does not support 
	z-buffering or alpha blending (see alpha channel) during blit operations. */

/*	Until now the flags and the LPDDBLTFX data will not be requested. Should change in future */
int IDirectDrawSurface7::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect,                     
  		DWORD dwFlags,                        
  		LPDDBLTFX lpDDBltFx)
{
	SDL_Rect sRect, dRect;
	
	/* convert WinAPI RECT to SDL_Rect */
	RECT2SDL(lpDestRect,&dRect);
	RECT2SDL(lpSrcRect,&sRect);
	
	/* blit the surface using SDL */
	SDL_BlitSurface(lpDDSrcSurface->surface,&sRect,this->surface,&dRect);
	
	/* return OK */
	return DD_OK;
};

/*  The IDirectDrawSurface7::Lock method obtains a pointer to the surface memory. */
int IDirectDrawSurface7::Lock(LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    Uint32 rmask,gmask,bmask,amask;
    
    /* if lpDestRect is NULL then the whole surface will be locked */
    if(lpDestRect==NULL){
        /* if the whole surface is locked we don't create a new one..set to this->surface */
        this->locked_surface = this->surface;
        /* to "emulate" DirectX give the user the ponter to the surface data */
        lpDDSurfaceDesc->lpSurface = this->surface->pixels;
        /* lock our surface */
        SDL_LockSurface(this->surface);
        /* return with OK */
        return DD_OK;
    };
    
    /* the user only wants a part of the surface */
    /* at the moment there can only one part of the surface be locked! */
    if(this->locked_surface){
    	/* this interface has already one locked surface! */
    	return DD_FALSE;
    };
    
    /* we must cut out the wanted rectangle and create a new SDL_Surface */
    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
	on the endianness (byte order) of the machine */
	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    	rmask = 0xff000000;
    	gmask = 0x00ff0000;
    	bmask = 0x0000ff00;
    	amask = 0x000000ff;
	#else
    	rmask = 0x000000ff;
    	gmask = 0x0000ff00;
    	bmask = 0x00ff0000;
    	amask = 0xff000000;
	#endif
	SDL_Surface *newsurf = SDL_CreateRGBSurface(SDL_SWSURFACE, 
							lpDestRect->right-lpDestRect->left,	/* I hate that RECT */ 
							lpDestRect->bottom-lpDestRect->top, 
							this->surface->format->BitsPerPixel, rmask, gmask, bmask, amask);
	/* our new and fresh SDL_Surface must now be filled with the original data from the "parent" surface */
	/* convert the damn RECT thing */
	SDL_Rect sdlRect;
	RECT2SDL(lpDestRect,&sdlRect);
	SDL_BlitSurface(this->surface,&sdlRect,newsurf,NULL);
    /* that's a really nasty hack...I don't want to know how this copystuff fucks the performance ;) */
    lpDDSurfaceDesc->lpSurface = newsurf->pixels;
    /* lock the new surface... */
    SDL_LockSurface(newsurf);
    /* save the new surface for later unlock */
    this->locked_surface = newsurf;
	/* return with ok ... hopefully... */	
    return DD_OK;
};

/* The IDirectDrawSurface7::Unlock method notifies DirectDraw that the direct surface manipulations are complete. */
int IDirectDrawSurface7::Unlock(LPRECT lpRect)
{
	/* is there a surface to unlock ? */
	if(!locked_surface) return DD_OK;	/* no, but say "all ok!" ;) */
	/* was the whole surface locked?? */
	if(locked_surface==surface){
		/* ok...now it's easy...just unlock the thing */
		SDL_UnlockSurface(surface);
		/* we don't have a locked surface anymore */
		locked_surface = NULL;
		/* quit positive */
		return DD_OK;
	};
	
	/* not the whole surface was locked... */
	SDL_Rect sdlRect;
	RECT2SDL(lpRect,&sdlRect);
	/* copy the manipulated surface back to our "main" surface */
	SDL_BlitSurface(locked_surface,NULL,surface,&sdlRect);
	/* free the temporary surface */
	SDL_FreeSurface(locked_surface);
	/* we don't have a locked surface anymore */
	locked_surface = NULL;
	/* quit positive */
	return DD_OK;
};
