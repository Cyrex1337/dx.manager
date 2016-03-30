#pragma once

#include "WindowManager.h"
#include <d3d9.h>

#pragma comment ( lib, "d3d9.lib" )

struct CUSTOMVERTEX { FLOAT X, Y, Z, RHW; DWORD COLOR; };
#define CUSTOMFVF ( D3DFVF_XYZRHW | D3DFVF_DIFFUSE )

class DirectXManager
{
private:
	IDirect3D9* pD3D;
	IDirect3DDevice9* pD3DDevice;
	IDirect3DVertexBuffer9* pBuffer;

public:
	DirectXManager( ) = default;

public:
	void Init( HWND hWnd );
	void Render( );
	void Free( );
	void Construct( );
};

extern std::unique_ptr<DirectXManager> DXManager;