#include "DirectXManager.h"

HWND window = NULL;

std::unique_ptr<DirectXManager> DXManager( new DirectXManager( ) );

void DirectXManager::Init( HWND hWnd )
{
	pD3D = Direct3DCreate9( D3D_SDK_VERSION );
	D3DPRESENT_PARAMETERS pParams;

	ZeroMemory( &pParams, sizeof( D3DPRESENT_PARAMETERS ) );
	pParams.Windowed = TRUE;
	pParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pParams.hDeviceWindow = hWnd;
	pParams.BackBufferFormat = D3DFMT_X8R8G8B8;
	pParams.BackBufferWidth = SCREEN_WIDTH;
	pParams.BackBufferHeight = SCREEN_HEIGHT;

	pD3D->CreateDevice( D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&pParams,
		&pD3DDevice );

	Construct( );
}

void DirectXManager::Render( )
{
	pD3DDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 0, 0, 0 ), 1.0f, 0 );
	pD3DDevice->BeginScene( );

	pD3DDevice->SetFVF( CUSTOMFVF );
	pD3DDevice->SetStreamSource( 0, pBuffer, 0, sizeof( CUSTOMVERTEX ) );
	pD3DDevice->DrawPrimitive( D3DPT_TRIANGLELIST, 0, 1 );

	pD3DDevice->EndScene( );
	pD3DDevice->Present( NULL, NULL, NULL, NULL );
}

void DirectXManager::Free( )
{
	pBuffer->Release( );
	pD3DDevice->Release( );
	pD3D->Release( );
}

void DirectXManager::Construct( )
{
	CUSTOMVERTEX vertices[] =
	{
		{ 400.0f, 62.5f, 0.5f, 1.0f, D3DCOLOR_XRGB( 0, 0, 255 ), },
		{ 650.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB( 0, 255, 0 ), },
		{ 150.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB( 255, 0, 0 ), },
	};

	pD3DDevice->CreateVertexBuffer( 3 * sizeof( CUSTOMVERTEX ),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&pBuffer,
		NULL );

	void* pVoid;

	pBuffer->Lock( 0, 0, &pVoid, 0 );
	memcpy( pVoid, vertices, sizeof( vertices ) );
	pBuffer->Unlock( );
}