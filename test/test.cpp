#include<stdlib.h>
#include"windows.h"
#include"ddraw.h"

// globals (ugh)
LPDIRECTDRAW lpDD; // DirectDraw object defined in DDRAW.H

/*
 * Function to initialize DirectDraw
 * Demonstrates:
 *   1) Creating the Direct Draw Object
 *   2) Setting the Cooperative level
 *   3) Setting the Display mode
 *
 */
bool WindowProc()
{
	return true;
};

bool DirectDrawInit(HWND hwnd)
{
    HRESULT ddrval;

   /*
    * Create the main DirectDraw object.
    *
    * This function takes care of initializing COM and Constructing
    * the DirectDraw object.
    */
    ddrval = DirectDrawCreate( NULL, &lpDD, NULL );
    if( ddrval != DD_OK )
    {
        return(false);
    }

   /*
    * The cooperative level determines how much control we have over the
    * screen. This must at least be either DDSCL_EXCLUSIVE or DDSCL_NORMAL
    *
    * DDSCL_EXCLUSIVE allows us to change video modes, and requires
    * the DDSCL_FULLSCREEN flag, which will cause the window to take over
    * the fullscreen. This is the preferred DirectDraw mode because it allows
    * us to have control of the whole screen without regard for GDI.
    *
    * DDSCL_NORMAL is used to allow the DirectDraw app to run windowed.
    */
    ddrval = lpDD->SetCooperativeLevel( hwnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN );
    if( ddrval != DD_OK )
    {
        lpDD->Release();
        return(false);
    }

   /*
    * Set the video mode to 640x480x8
    * This is allowed because we have set exclusive mode above
    */
    ddrval = lpDD->SetDisplayMode( 640, 480, 8);
    if( ddrval != DD_OK )
    {
        lpDD->Release();
        return(false);
    }

    return(true);
}

BOOL APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{ 
	WNDCLASS wc;
	HWND hwnd;
	MSG msg;

	wc.lpszClassName = "TestDDraw";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (void*)WindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_BACKGROUND + 1);
	wc.lpszMenuName = NULL; 
	RegisterClass(&wc);
	hwnd = CreateWindow ("TestDDraw", "Test DirectDraw Fenster", WS_OVERLAPPED, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow (hwnd, SW_SHOW);
		
	UpdateWindow(hwnd); 
	
	DirectDrawInit(hwnd);
	
	// DES GEHT NO NED!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	/*while (GetMessage(&msg, NULL, 0, 0)) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}*/
	// WinAPI nachbilden!!!! 
	 
	return msg.wParam;
};



