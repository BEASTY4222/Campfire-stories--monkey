#pragma once
#include "Enemy.h"
#include "raylib.h"

class EnemyGoblinBrute : public Enemy {
	void playerSeenFunc(PlayerMonkey player) override;
	void handleAttacking() override;
	void handleStanding() override;
public:
	EnemyGoblinBrute(const float& x, const float& y, const float& width, const float& hegiht, const float& hp, const float& speed, const float& damage, const float& walkingDistanceRight, const float& walkingDistanceLeft);

	void DrawEnemy() override;

	void handleUpdates(PlayerMonkey player, World world) override;

	void movement(PlayerMonkey player) override;

	~EnemyGoblinBrute();
};
