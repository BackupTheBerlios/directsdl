/*
    opendx - A wrapper, which provides DirectX functionality on top of the SDL library
    Copyright (C) 2004 Rene Roessler <rene@freshx.de>
						
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

void notimplemented(char*);
int notimplementedInt(char*,int);
bool notimplementedBool(char*,bool);
char notimplementedChar(char*,char*);

//functions which are not yet implemented:

//tutorials:

/*
 ----- msdn_test -----
*/

//functions
#define bla(a)		notimplemented("bla")

/*
 ----- ps2 -----
*/

//functions
#define ZeroMemory(a,b) notimplemented("ZeroMemory")
#define D3DPS_VERSION(a,b) notimplemented("D3DPS_VERSION")
#define D3DXCreateTextureFromFile(a,b,c) notimplemented("D3DXCreateTextureFromFile")
#define memcpy(a,b,c) notimplemented("memcpy")
#define D3DCOLOR_COLORVALUE(a,b,c,d) notimplemented("D3DCOLOR_COLORVALUE")
#define FAILED(a) notimplementedBool("FAILED",true)

//misc
#define D3DCAPS9(a)	notimplemented("D3DCAPS9")
#define d3dcaps9(a)	notimplemented("d3dcaps9")
#define D3DADAPTER_DEFAULT(a) notimplemented("D3DADAPTER_DEFAULT")
#define D3D_SDK_VERSION(a) notimplemented("D3D_SDK_VERSION")
#define Direct3DCreate9(a) notimplemented("Direct3DCreate9")
#define D3DDEVTYPE_REF(a) notimplemented("D3DDEVTYPE_REF")
#define D3DDISPLAYMODE(a) notimplemented("D3DDISPLAYMODE")
#define displayMode(a) notimplemented("displayMode")
#define D3DPRESENT_PARAMETERS(a) notimplemented("D3DPRESENT_PARAMETERS")
#define d3dpp(a) notimplemented("d3dpp")
#define D3DSWAPEFFECT_DISCARD(a) notimplemented("D3DSWAPEFFECT_DISCARD")
#define D3DFMT_D24S8(a) notimplemented("D3DFMT_D24S8")
#define D3DUSAGE_WRITEONLY(a) notimplemented("D3DUSAGE_WRITEONLY")
#define D3DFVF_XYZRHW(a) notimplemented("D3DFVF_XYZRHW")
#define D3DFVF_DIFFUSE(a) notimplemented("D3DFVF_DIFFUSE")
#define D3DFVF_TEX1(a) notimplemented("D3DFVF_TEX1")
#define D3DPOOL_DEFAULT(a) notimplemented("D3DPOOL_DEFAULT")
#define LPD3DXBUFFER(a) notimplemented("LPD3DXBUFFER")
#define pErrorMsgs(a) notimplemented("pErrorMsgs")
#define D3DRS_LIGHTING(a) notimplemented("D3DRS_LIGHTING")
#define D3DCLEAR_TARGET(a) notimplemented("D3DCLEAR_TARGET")
#define D3DCLEAR_ZBUFFER(a) notimplemented("D3DCLEAR_ZBUFFER")
#define D3DPT_TRIANGLEFAN(a) notimplemented("D3DPT_TRIANGLEFAN")
