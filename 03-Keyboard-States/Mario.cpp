#include "Mario.h"

int ID_ANI_MARIO_LATEST = 504;
void CMario::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt; 


	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
	if (vy > 0 && y > 210) y = 210;
	if (vy < 0 && y < 0) y = 0;
}

void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	// Mario is still on air check, this will not work when Mario is just stand up
	if (vx > 0)
	{
		aniId = ID_ANI_MARIO_WALKING_RIGHT;
		ID_ANI_MARIO_LATEST = ID_ANI_MARIO_WALKING_RIGHT;
	}
	else if (vx < 0) // vx < 0
	{
		aniId = ID_ANI_MARIO_WALKING_LEFT;
		ID_ANI_MARIO_LATEST = ID_ANI_MARIO_WALKING_LEFT;
	}
	else if (vy > 0)
	{
		aniId = ID_ANI_MARIO_WALKING_DOWN;
		ID_ANI_MARIO_LATEST = ID_ANI_MARIO_WALKING_DOWN;
	}
	else if (vy < 0)
	{
		aniId = ID_ANI_MARIO_WALKING_UP;
		ID_ANI_MARIO_LATEST = ID_ANI_MARIO_WALKING_UP;
	}

	if (aniId == -1) aniId = ID_ANI_MARIO_IDLE;

	animations->Get(aniId)->Render(x, y);
}

void CMario::SetState(int state)
{
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		vy = 0;
		currentState = MARIO_STATE_WALKING_RIGHT;
		break;
	case MARIO_STATE_WALKING_LEFT:
		vx = -MARIO_WALKING_SPEED;
		vy = 0;
		currentState = MARIO_STATE_WALKING_LEFT;
		break;
	case MARIO_STATE_WALKING_UP:
		vx = 0;
		vy = -MARIO_WALKING_SPEED;
		currentState = MARIO_STATE_WALKING_UP;
		break;
	case MARIO_STATE_WALKING_DOWN:
		vx = 0;
		vy = MARIO_WALKING_SPEED;
		currentState = MARIO_STATE_WALKING_DOWN;
		break;
	case MARIO_STATE_IDLE_VERTICAL:
		vy = 0;
		break;
	case MARIO_STATE_IDLE_HORIZONTAL:
		vx = 0;
		break;
	}
	


	CGameObject::SetState(state);
}

