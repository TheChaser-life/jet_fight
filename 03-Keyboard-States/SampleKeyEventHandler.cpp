#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "Bullet.h"
#include "Mob.h"

extern CMario* mario;
extern std::vector<LPGAMEOBJECT> objects;


void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	if (KeyCode == DIK_LEFT || KeyCode == DIK_RIGHT)
	{
		mario->SetState(MARIO_STATE_IDLE_HORIZONTAL);
	}
	if (KeyCode == DIK_UP || KeyCode == DIK_DOWN)
	{
		mario->SetState(MARIO_STATE_IDLE_VERTICAL);
	}
}
void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();
	int movingHorizontal = (game->IsKeyDown(DIK_RIGHT)? 1 : 0) - (game->IsKeyDown(DIK_LEFT)? 1 : 0);
	if (movingHorizontal == 1)
	{
		mario->SetState(MARIO_STATE_WALKING_RIGHT);
	}
	else if (movingHorizontal == -1)
	{
		mario->SetState(MARIO_STATE_WALKING_LEFT);
	}

	int movingVertical = (game->IsKeyDown(DIK_DOWN) ? 1 : 0) - (game->IsKeyDown(DIK_UP) ? 1 : 0);
	if (movingVertical == 1)
	{
		mario->SetState(MARIO_STATE_WALKING_DOWN);
	}
	else if (movingVertical == -1)
		mario->SetState(MARIO_STATE_WALKING_UP);
}

void CSampleMouseHandler::OnMouseDown()
{
	if (attackTimer > 0) {
		attackTimer -= 0.15f;
		return;
	}
	attackTimer = attackCooldown;
	DebugOut(L"[INFO] MouseDown: %d, %d\n");
	float x, y; 
	mario->GetLocation(x, y);
	x += 15;
	Bullet* bullet = new Bullet(x, y);
	bullet->SetState(100);
	objects.push_back(bullet);
	if (bullet->isExist == false) {
		objects.erase(std::remove(objects.begin(), objects.end(), bullet), objects.end());
	}
}

void CSampleMouseHandler::OnMouseUp()
{
	DebugOut(L"[INFO] MouseUp: %d, %d\n");
}