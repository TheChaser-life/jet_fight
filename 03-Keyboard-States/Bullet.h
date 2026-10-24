#pragma once
#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define BULLET_SPEED	1.0f
#define ID_ANI_BULLET 600
#define BULLET_RIGHT	100
#define BULLET_LEFT		200
#define BULLET_UP		300
#define BULLET_DOWN		400


#pragma endregion


class Bullet : public CGameObject
{
	float vx, vy;
public:
	float x_bullet, y_bullet;
	bool isExist = true;
	Bullet(float x, float y) : CGameObject(x, y) {};
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};