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

/* class for IDirectDraw7 */

class IDirectDraw7 : public IUnknown
{
	public:
		IDirectDraw7(void);
		~IDirectDraw7(void);
		int Compact(void);
		int Initialize(GUID);
		int SetCooperativeLevel(HWND, DWORD);
		int TestCooperativeLevel(void);
		int CreateSurface(LPDDSURFACEDESC2 lpDDSurfaceDesc2,
			LPDIRECTDRAWSURFACE7 *lplpDDSurface,  
  			void *pUnkOuter);
  		int SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP);
  		int GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps);
  		int GetDisplayMode(LPDDSURFACEDESC2 lpDDSurfaceDesc2);
  		int GetVerticalBlankStatus(LPBOOL lpbIsInVB);
  		int GetScanLine(LPDWORD lpdwScanLine);
  		int GetMonitorFrequency(LPDWORD lpdwFrequency);
  		int WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent);
};
