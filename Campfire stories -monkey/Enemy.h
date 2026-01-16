#pragma once
#include "Player.h"
#include "World.h"
#include <string>
#include <map>
class PlayerMonkey;

class Enemy{
	Rectangle enemyBox;
	Rectangle healhBar;
	float enemyTimeInAir;
	float hp;
	float speed;
	float damage;
	std::string TAG;
	float inlvincibilityTime;
	float maxInvincibilityTime;

	std::map <std::string, Rectangle> currentCollisionTags;

	void DrawEnemy() {
		DrawRectangleRec(enemyBox, RED);

		DrawRectangleRec(healhBar, LIME);// health
	}
	public:
		Enemy(const float& x, const  float& y, const  float& width, const  float& hegiht, const float& hp, const  float& speed, const  float& damage);

		void handleEnemy() {
			this->DrawEnemy();
		}
		void handleUpdates(PlayerMonkey player, World world);

		void handleCollisionsGroundObjects(GroundObject object) {CollisionWithRectangle(object);}
		void handleCollisionsPlayer(PlayerMonkey& player) { CollisionWithRectangle(player); }

		

		void CollisionWithRectangle(GroundObject object);
		void CollisionWithRectangle(PlayerMonkey& player);

		inline float& getAirTime() { return enemyTimeInAir; }
		inline std::string getTag() const { return this->TAG; }
		inline float getDamage() const { return damage; }
		inline float getHp() const { return hp; }
		inline Rectangle& getRectangle() { return enemyBox; } // Non-const getter
		inline std::map<std::string, Rectangle> getCurrentCollisionTags() { return currentCollisionTags; } // Non-const getter
};
