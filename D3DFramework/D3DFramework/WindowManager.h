#pragma once

#include <Windows.h>
#include <memory>
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

LRESULT CALLBACK WindowProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );

extern HWND window;

class WindowManager
{
public:
	static void Setup( HINSTANCE Instance, int CmdShow, const std::wstring& Title )
	{
		WNDCLASSEX wc;
		ZeroMemory( &wc, sizeof( WNDCLASSEX ) );

		wc.cbSize = sizeof( WNDCLASSEX );
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = Instance;
		wc.hCursor = LoadCursor( NULL, IDC_ARROW );
		wc.lpszClassName = Title.c_str( );

		RegisterClassEx( &wc );

		window = CreateWindowEx( NULL, Title.c_str( ), Title.c_str( ), WS_OVERLAPPEDWINDOW, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL, Instance, NULL );

		ShowWindow( window, CmdShow );
	}
};