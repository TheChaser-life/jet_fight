#pragma once
#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define MOB_SPEED	0.1f
#define ID_ANI_MOB	601
#define MOB_RIGHT	101
#define MOB_LEFT	201
#define MOB_UP		301
#define MOB_DOWN	401


#pragma endregion


class CMob : public CGameObject
{
	float vx, vy;
	float spawnCooldown = 3.0f;
	float spawnTimer = 3.0f;
public:
	float x_mob, y_mob;
	bool isExist = true;
	CMob(float x, float y) : CGameObject(x, y) {};
	void Update(DWORD dt);
	void Render();
	void spawnMob();
};