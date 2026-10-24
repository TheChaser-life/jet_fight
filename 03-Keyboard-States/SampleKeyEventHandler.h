#pragma once

#include "KeyEventHandler.h"

class CSampleKeyHandler: public CKeyEventHandler
{
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

class CSampleMouseHandler : public CMouseEventHandler
{
	float attackCooldown = 1.0f;
	float attackTimer = 1.0f;
	virtual void OnMouseDown();
	virtual void OnMouseUp();
};
