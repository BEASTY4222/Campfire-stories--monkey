#include "Enemy.h"

Enemy::Enemy(const float& x, const  float& y, const  float& width, const  float& height, const float& hp, const  float& speed, const  float& damage) :
	enemyBox{ x, y, width, height },
	healhBar{ x, y - 20.0f, width, 10.0f },
	hp(hp),
	speed(speed),
	damage(damage), maxInvincibilityTime(2.0f), inlvincibilityTime(0.0f),
	TAG{ "ENEMY" }, enemyTimeInAir(0.0f)
	{}

void Enemy::handleUpdates(PlayerMonkey player, World world) {
	healhBar.width = hp;
	healhBar.y = enemyBox.y - 20.0f;
	this->CollisionWithRectangle(world.getMainGround());
	this->CollisionWithRectangle(player);
	inlvincibilityTime += GetFrameTime();
}

void Enemy::CollisionWithRectangle(GroundObject object) {
	if (CheckCollisionRecs(this->enemyBox, object.getRectangle())) {
		currentCollisionTags[object.getTag()] = object.getRectangle();
		for (std::pair<std::string, Rectangle> tag : currentCollisionTags) {
			if (tag.first == "MAIN_GROUND") {
				// no vars to update yet
			}

			if (object.getRectangle().y < enemyBox.y) {
				currentCollisionTags.erase(tag.first);
			}
		}

	}
}
void Enemy::CollisionWithRectangle(PlayerMonkey& player) {
	if (CheckCollisionRecs(this->enemyBox, player.getLightAttackHitBox())) {
		currentCollisionTags[player.getTag()] = player.getRectangle();
		for (std::pair<std::string, Rectangle> tag : currentCollisionTags) {
			if (tag.first == "PLAYER" && inlvincibilityTime > maxInvincibilityTime) {
				hp -= player.getDamage();
			}


		}

	}
}