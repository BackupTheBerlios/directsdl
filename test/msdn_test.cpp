/* 	To create an instance of a DirectDraw object, your application should use the DirectDrawCreateEx 
	function as shown in the doInit sample function of the DDEx1 program. DirectDrawCreateEx contains 
	four parameters. The first parameter takes a globally unique identifier (GUID) that represents the 
	display device. The GUID, in most cases, is set to NULL, which means DirectDraw uses the default 
	display driver for the system. The second parameter contains the address of a pointer that 
	identifies the location of the DirectDraw object if it is created. The third parameter is the 
	reference identification for the IDirectDraw7 interface, this parameter must be set 
	to IID_IDirectDraw7. The fourth parameter is always set to NULL and is included for future expansion.

	The following example shows how to create the DirectDraw object and how to determine if the creation was 
	successful or not:
*/
#include"ddraw.h"
BOOL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
        MessageBox(0,"Yes, you can see a messagebox :)", "test", 1);
	
	HRESULT ddrval;
	LPDIRECTDRAW lpDD;
	
	ddrval = DirectDrawCreateEx(NULL, &lpDD, IID_IDirectDraw7, NULL); 
	if(ddrval == DD_OK) 
	{ 
    	// lpDD is a valid DirectDraw object.
		printf("lpDD is a valid DirectDraw object\n");
	} 
	else 
	{ 
    	// The DirectDraw object could not be created.
    	printf("The DirectDraw object could not be created\n");
		return false; 
	}
	
	
	/* we haven't created any window...so we fake here a bit... */
	HWND hwnd;
 
	ddrval = lpDD->SetCooperativeLevel(hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN); 
	if(ddrval == DD_OK) 
	{ 
    	// Exclusive mode was successful.
		printf("Exclusive mode was successful\n");
	} 
	else 
	{ 
    	// Exclusive mode was not successful. 
    	// The application can still run, however.
		printf("Exclusive mode was not successful\n");
		return false;
	}; 
 
 	ddrval = lpDD->SetDisplayMode(640, 480, 8); 
	if(ddrval == DD_OK) 
	{ 
    	// The display mode changed successfully.
		printf("The display mode changed successfully\n"); 
	} 
	else 
	{ 
    	// The display mode cannot be changed. 
    	// The mode is either not supported or 
    	// another application has exclusive mode.
    	printf("The display mode cannot be changed\n");
    	return false;
	} 

	// Create the primary surface with one back buffer. 
	DDSURFACEDESC2 ddsd;
	LPDIRECTDRAWSURFACE7 lpDDSPrimary;
	
	ddsd.dwSize = sizeof(ddsd); 
	ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT; 
	ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX;
	ddsd.dwBackBufferCount = 1; 

	ddrval = lpDD->CreateSurface(&ddsd, &lpDDSPrimary, NULL); 
	if(ddrval == DD_OK) 
	{ 
    	// lpDDSPrimary points to the new surface.
		printf("lpDDSPrimary points to the new surface\n");
	} 
	else 
	{ 
    	// The surface was not created.
		printf("The surface was not created\n");
    	return FALSE; 
	}
 
 	/* NOW WE DO SOMETHING WICH CAN'T BE DONE IN DirectX !!! WE'LL GOING TO RENDER TO THE PRIMARY SURFACE */
 	/* ONLY A HACK BECAUSE ddrval = lpDDSPrimary->GetAttachedSurface(&ddcaps, &lpDDSBack); IS'NT IMPLEMENTED YET */
 	
 	
	Sleep(1000);
	
	lpDDSPrimary->Release();
	lpDD->Release();
	printf("\nWe reached the end without any segfaults...cool *fg\n");

	return true;
};
