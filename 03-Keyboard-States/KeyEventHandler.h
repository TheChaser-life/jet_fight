#pragma once

#include <Windows.h>

/*
	Abstract class to define keyboard event handlers
*/
class CKeyEventHandler
{
public:
	virtual void KeyState(BYTE* state) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;

};

typedef CKeyEventHandler* LPKEYEVENTHANDLER;

class CMouseEventHandler
{
public:
	virtual void OnMouseDown() = 0;
	virtual void OnMouseUp() = 0;
};
typedef CMouseEventHandler* LPMOUSEEVENTHANDLER;
