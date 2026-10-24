#include "Bullet.h"


void Bullet::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
	x_bullet = x;
	y_bullet = y;

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) isExist = false;
	if (vx < 0 && x < 0) isExist = false;
	if (vy > 0 && y > 210) isExist = false;
	if (vy < 0 && y < 0) isExist = false;
}

void Bullet::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = ID_ANI_BULLET;

	// Mario is still on air check, this will not work when Mario is just stand up

	animations->Get(aniId)->Render(x, y);
}

void Bullet::SetState(int state)
{
	switch (state)
	{
	case BULLET_LEFT:
		vx = -BULLET_SPEED;
		vy = 0;
		break;
	case BULLET_RIGHT:
		vx = BULLET_SPEED;
		vy = 0;
		break;
	case BULLET_UP:
		vx = 0;
		vy = -BULLET_SPEED;
		break;
	case BULLET_DOWN:
		vx = 0;
		vy = BULLET_SPEED;
		break;
	}



	CGameObject::SetState(state);
}

