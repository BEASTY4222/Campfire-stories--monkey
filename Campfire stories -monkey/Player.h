#pragma once
#include <string>
#include <map>

#include "raylib.h"
#include "GroundObject.h"
#include "Enemy.h"
#include "World.h"

class Enemy;

class PlayerMonkey{
	// Player properties
	Rectangle PlayerBox;
	Camera2D mainCamera;
	// Player sprites
	Image currPlayerImage;
	float animTimeRight;
	float animTimeLeft;
	float idleAnimTime;
	float sprintAnimSpeed;
	float walkAnimSpeed;
	float curAnimSpeed;
	float animTimeHit1RightTime;
	float animTimeHit1LeftTime;
	int animRight;
	int animLeft;
	int animIdle;
	int animHit1Right;
	int animHit1Left;
	Image idleAnimRightArr[2];
	Image idleAnimLeftArr[2];
	Texture2D idleAnimRightTexArr[2];
	Texture2D idleAnimLeftTexArr[2];

	Image walkPlayerImageRightArr[6];
	Texture2D walkPlayerTextureRightArr[6];
	Image walkPlayerImageLeftArr[6];
	Texture2D walkPlayerTextureLeftArr[6];

	Image hit1PlayerImageRightArr[10];
	Texture2D hit1PlayerTextureRightArr[10];
	Image hit1PlayerImageLeftArr[10];
	Texture2D hit1PlayerTextureLeftArr[10];


	// Player Textures
	Texture2D currPlayerTexture;
	// Player stats
	bool alive;
	float maxInvincibilityTime;
	float currInvincibilityTime;
	float maxHealth;
	float currHealth;
	Rectangle healthBar;
	Rectangle healthBarOutline;
	bool regenStamina;
	float staminaRegenRate;
	float maxStamina;
	float currStamina;
	Rectangle staminaBar;
	Rectangle staminaBarOutline;
	// Direction vars
	bool facingRight;
	bool hitting;
	// Moving vars
	float timeInAir;
	float currentMoveSpeed;
	const float walkSpeed;
	const float sprintSpeed;
	const float hitWalkSpeed;
	bool notWalking;
	// Jump mechanics
	bool doubleJumpUsed = false;
	bool inAir = false;
	const float doubleJumpPower;
	const float jumpPower;
	float jumpProgress;
	float jumpProgressDoubleJump;
	// TAG
	const std::string TAG;
	// Dashig mechanics
	float dashProgress;
	float currDashPower;
	float dashCooldown;// seconds
	const float dashPower;
	// Collison
	std::map <std::string, Rectangle> currentCollisionTags;
	// Combat vars
	Rectangle lightAttackHitBox;
	float lightAttackDamage;

	inline void drawPlayer() {
		// Draw bars
		this->drawBars();

		DrawRectangleLinesEx(PlayerBox, 3, RED);// to see the playerBox
		DrawRectangleLinesEx(lightAttackHitBox, 3, GREEN);// to see the hitbox


		// Draw main character
		DrawTexture(currPlayerTexture, PlayerBox.x, PlayerBox.y + 10, WHITE);
	}
	inline void drawBars() {
		DrawRectangleRec(healthBar, LIME);// health
		DrawRectangleLinesEx(healthBarOutline, 4, BLACK);// health outline

		DrawRectangleRec(staminaBar, ORANGE);// stamina
		DrawRectangleLinesEx(staminaBarOutline, 4, BLACK);// stamina outline
	}

	inline void handleCamera() { this->mainCamera.target.x = { this->PlayerBox.x }; }
	void handleMovement();
	void handleCollisionsGroundObjects(GroundObject object);// Collision with ground objects
	void handleCollisionsEnemies(Enemy enemy);// Collision with enemies
public:
	PlayerMonkey();

	// Handlers
	void handleUpdates(World world, Enemy& enemy);// for vars that need to be updated every frame
	void handlePlayer();// visuals
	void handleBars();// stamina, hp, mana bars...

	// Collision with rectangle objects
	void CollisionWithRectangle(GroundObject object);
	void CollisionWithRectangle(Enemy enemy);
	// getters	
	inline float& getTimeInAir() { return timeInAir; }
	inline float getDamage() const { return lightAttackDamage; }
	inline Rectangle getLightAttackHitBox()const { return lightAttackHitBox; } // Non-const getter
	inline Rectangle& getRectangle() { return PlayerBox; } // Non-const getter
	inline Camera2D& getCamera() { return mainCamera; } // Non-const getter
	inline std::map<std::string, Rectangle> getCurrentCollisionTags() { return currentCollisionTags; } // Non-const getter
	inline std::string getTag() const { return this->TAG; }
};
 
