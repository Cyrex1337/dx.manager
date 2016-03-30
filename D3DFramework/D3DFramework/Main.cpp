#include "DirectXManager.h"

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	WindowManager::Setup( hInstance, nCmdShow, L"Test Window" );

	DXManager->Init( window );

	MSG msg;

	while ( true )
	{
		while ( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}

		if ( msg.message == WM_QUIT )
			break;

		DXManager->Render( );
	}

	DXManager->Free( );

	return msg.wParam;
}

LRESULT CALLBACK WindowProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch ( message )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;
		break;
	}

	return DefWindowProc( hWnd, message, wParam, lParam );
}