#pragma once
#include "Player.h"
#include "World.h"
#include <string>
#include <map>
class PlayerMonkey;

class Enemy {
	// vars
protected:
	Image imageWalkRightArr[6];
	Image imageWalkLeftArr[6];
	Texture2D textureWalkRightArr[6];
	Texture2D textureWalkLeftArr[6];

	Image imageHitRightArr[4];
	Image imageHitLeftArr[4];
	Texture2D textureHitRightArr[4];
	Texture2D textureHitLeftArr[4];

	Image imageIdleRightArr[5];
	Image imageIdleLeftArr[5];
	Texture2D textureIdleRightArr[5];
	Texture2D textureIdleLeftArr[5];

	Texture2D currentTexture;

	Rectangle enemyBox;
	Rectangle healthBar;
	float enemyTimeInAir;
	float hp;
	float speed;
	float damage;
	std::string TAG;
	float inlvincibilityTime;
	float maxInvincibilityTime;
	int nHitsBeforeInvcincibility;
	bool hit;
	bool facingRight;
	int animIdle;
	int animLeft;
	int animRight;
	float animTimeLeft;
	float animTimeRight;
	float animIdleTime;
	bool standing;
	float standTime;
	float distanceToPlayer;
	float walkingDistanceRight;
	float walkingDistanceLeft;
	Rectangle hitbox;
	bool hitting;
	int animHitRight;
	float animHitTimeRight;
	int animHitLeft;
	float animHitTimeLeft;
	bool playerSeen;
	int closeDistanceToPlayer;
	float attackCD;
	bool rotate;
	float viewDistanceFoward;
	float viewDistanceBackwards;
	bool inCombat;

	std::map <std::string, Rectangle> currentCollisionTags;

	virtual void DrawEnemy() {
		DrawRectangleRec(enemyBox, RED);

		DrawRectangleRec(healthBar, LIME);// health
	}
	virtual void playerSeenFunc(PlayerMonkey player);

	virtual void handleAttacking();
	virtual void handleStanding();
public:
	Enemy(const float& x, const  float& y, const  float& width, const  float& hegiht, const float& hp, const  float& speed, const  float& damage);

	void handleEnemy() { this->DrawEnemy(); }
	void handleUpdates(PlayerMonkey player, World world);

	void handleCollisionsGroundObjects(GroundObject object) { CollisionWithRectangle(object); }
	void handleCollisionsPlayer(PlayerMonkey& player) { CollisionWithRectangle(player); }

	virtual void movement();
	virtual void movement(PlayerMonkey player); // Overloaded movement for enemies that react to player position

	void CollisionWithRectangle(GroundObject object);
	void CollisionWithRectangle(PlayerMonkey& player);

	inline float& getAirTime() { return enemyTimeInAir; }
	inline std::string getTag() const { return this->TAG; }
	inline float getDamage() const { return damage; }
	inline float getHp() const { return hp; }
	inline Rectangle& getRectangle() { return enemyBox; } // Non-const getter
	inline std::map<std::string, Rectangle> getCurrentCollisionTags() { return currentCollisionTags; } // Non-const getter
	inline Rectangle getHealhBar() const { return healthBar; }
	inline Rectangle getHitbox() const { return hitbox; }

};

