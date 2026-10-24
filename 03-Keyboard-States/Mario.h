#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_SHOOTING_SPEED	1f

#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_WALKING_UP		300
#define MARIO_STATE_WALKING_DOWN	400
#define MARIO_STATE_IDLE_VERTICAL	500
#define MARIO_STATE_IDLE_HORIZONTAL	600


#pragma region ANIMATION_ID

#define ID_ANI_MARIO_WALKING_RIGHT 500
#define ID_ANI_MARIO_WALKING_LEFT 501
#define ID_ANI_MARIO_WALKING_UP 502
#define ID_ANI_MARIO_WALKING_DOWN 503
#define ID_ANI_MARIO_IDLE 504

#pragma endregion


class CMario : public CGameObject
{
	float vx, vy;
	int currentState = MARIO_STATE_WALKING_LEFT;
public: 
	CMario(float x, float y) : CGameObject(x, y) {};
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
	void GetLocation(float& x, float& y) { x = this->x; y = this->y; }
	int GetCurrentState() { return currentState; }
};