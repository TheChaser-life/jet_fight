#include "Mob.h"
extern std::vector<LPGAMEOBJECT> objects;

void CMob::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;


	// simple screen edge collision!!!
	if (vx > 0 && x > 290) isExist = false;
	if (vx < 0 && x < 0) isExist = false;
	if (vy > 0 && y > 210) isExist = false;
	if (vy < 0 && y < 0) isExist = false;
}

void CMob::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = ID_ANI_MOB;

	// Mario is still on air check, this will not work when Mario is just stand up

	animations->Get(aniId)->Render(x, y);
}

void CMob::spawnMob()
{
	if (spawnTimer > 0) {
		spawnTimer -= 0.03f;
		return;
	}
	spawnTimer = spawnCooldown;
	CMob* newMob = new CMob(400, 50);
	CMob* newMob2 = new CMob(400, 90);
	CMob* newMob3 = new CMob(400, 130);
	newMob -> vx = -MOB_SPEED;
	newMob->vy = 0;
	newMob2->vx = -MOB_SPEED;
	newMob2->vy = 0;
	newMob3->vx = -MOB_SPEED;
	newMob3->vy = 0;
	objects.push_back(newMob);
	objects.push_back(newMob2);
	objects.push_back(newMob3);
	
	if (newMob->isExist == false) {
		objects.erase(std::remove(objects.begin(), objects.end(), newMob), objects.end());
	}
	if (newMob2->isExist == false) {
		objects.erase(std::remove(objects.begin(), objects.end(), newMob2), objects.end());
	}
	if (newMob3->isExist == false) {
		objects.erase(std::remove(objects.begin(), objects.end(), newMob3), objects.end());
	}
}


