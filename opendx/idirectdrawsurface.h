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
/*	class prototype of IDirectDrawSurface7
*/

class IDirectDrawSurface7 : public IUnknown
{
	public:
		IDirectDrawSurface7(LPDDSURFACEDESC2 lpDDSurfaceDesc2, DWORD dwCaps);
		IDirectDrawSurface7(int width, int height);
		~IDirectDrawSurface7(void);
		int Release(void);
		int IsLost(void);
		int Restore(void);
		int Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc);
		int Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags,                        
  			LPDDBLTFX lpDDBltFx);
  		int Lock(LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent);
  		int Unlock(LPRECT lpRect);
  		int GetAttachedSurface(LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE7 FAR *lplpDDAttachedSurface);
  		int Flip(LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags);
		SDL_Surface	*surface;
	private:
		void createsurface(int width, int height);
		SDL_Surface *locked_surface;
		DWORD dwCaps, dwFlags;
};
