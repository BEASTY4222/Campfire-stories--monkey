#include "Enemy.h"

Enemy::Enemy(const float& x, const  float& y, const  float& width, const  float& height, const float& maxHp, const  float& speed, const  float& damage, const float& walkingDistanceRight, const float& walkingDistanceLeft) :
	enemyBox{ x, y, width, height }, enemyBaseX(x), enemyBaseY(y),
	healthBar{ x, y - 20.0f, width, 10.0f },
	maxHp(maxHp), hp(maxHp),
	speed(speed),
	damage(damage),
	maxInvincibilityTime(2.0f), inlvincibilityTime(0.0f),
	TAG{ "ENEMY" }, enemyTimeInAir(0.0f), nHitsBeforeInvcincibility(8), hit(false), facingRight(true),
	animLeft(0), animRight(0), animTimeLeft(0.0f), animTimeRight(0.0f), standing(false), standTime(0.0f),
	animIdle(0), animIdleTime(0.0f), distanceToPlayer(0.0f), walkingDistanceRight(walkingDistanceRight), walkingDistanceLeft(walkingDistanceLeft),
	hitbox{ 0,0,0,0 }, hitting(false), animHitRight(0), animHitTimeRight(0.0f), animHitLeft(0), animHitTimeLeft(0.0f),
	playerSeen(false), closeDistanceToPlayer(0), attackCD(1.0f), rotate(true), viewDistanceFoward(300.0f), 
	viewDistanceBackwards(100.0f), inCombat(false), MaxWalkingDistanceLeft(walkingDistanceLeft), MaxWalkingDistanceRight(walkingDistanceRight), 
	alive(true)
	{}

void Enemy::playerSeenFunc(PlayerMonkey player) {
	// Default implementation does nothing, can be overridden in derived classes
}
void Enemy::handleAttacking() {
	// Default implementation does nothing, can be overridden in derived classes
}
void Enemy::handleStanding() {
	// Default implementation does nothing, can be overridden in derived classes
}

void Enemy::movement() {
	// Basic left-right patrol movement (can be overridden in derived classes)
	if (facingRight) {
		enemyBox.x += speed;
		if (enemyBox.x > 800.0f) // Example boundary
			facingRight = false;
	}
	else {
		enemyBox.x -= speed;
		if (enemyBox.x < 200.0f) // Example boundary
			facingRight = true;
	}
}

void Enemy::movement(PlayerMonkey player) {
	// Default movement does not react to player
	this->movement();
}

void Enemy::handleUpdates(PlayerMonkey player, World world) {
	this->movement(player);
	healthBar.width = hp;
	healthBar.y = enemyBox.y - 20.0f;
	healthBar.x = enemyBox.x - 25.0;
	this->CollisionWithRectangle(world.getMainGround());
	this->CollisionWithRectangle(player);
	inlvincibilityTime += GetFrameTime();
	if (attackCD < 2.0f && !hitting) {
		attackCD += GetFrameTime();
	}
		
	
	
}

void Enemy::CollisionWithRectangle(GroundObject object) {
	if (CheckCollisionRecs(this->enemyBox, object.getRectangle())) {
		currentCollisionTags[object.getTag()] = object.getRectangle();
		for (std::pair<std::string, Rectangle> tag : currentCollisionTags) {
			if (tag.first == "MAIN_GROUND") {
				// no vars to update yet
			}

			std::vector<std::string> keysToRemove;
			for (const auto& tag : currentCollisionTags) {
				if (object.getRectangle().y < enemyBox.y) {
					keysToRemove.push_back(tag.first);
				}
			}
			for (const auto& key : keysToRemove) {
				currentCollisionTags.erase(key);
			}
		}

	}
}
void Enemy::CollisionWithRectangle(PlayerMonkey& player) {
	if (CheckCollisionRecs(this->enemyBox, player.getLightAttackHitBox())) {
		currentCollisionTags[player.getTag()] = player.getRectangle();
		if (!hit) {
			for (std::pair<std::string, Rectangle> tag : currentCollisionTags) {
				if (tag.first == "PLAYER" && inlvincibilityTime > maxInvincibilityTime) {
					hp -= player.getDamage();
					if (nHitsBeforeInvcincibility == 0 || inlvincibilityTime >= 100.0f) {
						inlvincibilityTime = 0.0f;
						nHitsBeforeInvcincibility = 8;
					}
					else {
						nHitsBeforeInvcincibility--;
						hit = true;
					}

				}

			}
		}
	}
	else hit = false;
}


