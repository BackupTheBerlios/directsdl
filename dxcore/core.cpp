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
/*	the core routines for FakeX
*/

#include <string.h>
#include <SDL.h>
#include "windows.h"

/* the SDL screen surface */
SDL_Surface *screen;

/* flags stored by SetCooperateLevel */
int cooperate_flags=0;

/* our WinMain() is extern */
extern int WinMain(HINSTANCE, HINSTANCE, LPSTR, int);

/* this is the main function called in a standart C program. Here we initialize SDL and call the
standard WinMain() function of a normal Windows application */
int main(int argc, char *argv[])
{
        /* initialize gtk */
        gtk_init (&argc, &argv);
	
	/* try to initialize SDL */
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)==-1){
		fprintf(stderr,"Can't initialize SDL: %s\n",SDL_GetError());
		return -1;
	};
	
	/* create one large command-line string as the WinMain() want's it */
	int arg_len = 0;
	for(int i=1;i<argc;i++){
		arg_len+=strlen(argv[i]);
	};
	char *command_line = new char[arg_len+1];
	*command_line = '\0';
	for(int i=1;i<argc;i++){
		strcat(command_line,argv[i]);
	};
	
	/* call our WinMain() */
	screen = NULL;
	WinMain(0,0,command_line,0);
	
	/* quit SDL */
	SDL_Quit();
	
	return 0;
};
