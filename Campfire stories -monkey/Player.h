#pragma once
#include <string>
#include <map>

#include "raylib.h"
#include "GroundObject.h"
#include "World.h"

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
	int animRight;
	int animLeft;
	int animIdle;
	Image idlePlayerImageRight1;
	Image idlePlayerImageRight2;
	Image idleAnimRightArr[2];

	Image walkPlayerImageRight1;
	Image walkPlayerImageRight2;
	Image walkPlayerImageRight3;
	Image walkPlayerImageRight4;
	Image walkPlayerImageRight5;
	Image walkPlayerImageRight6;
	Image walkPlayerImageRightArr[6];

	Image walkPlayerImageLeft1;
	Image walkPlayerImageLeft2;
	Image walkPlayerImageLeft3;
	Image walkPlayerImageLeft4;
	Image walkPlayerImageLeft5;
	Image walkPlayerImageLeft6;
	Image walkPlayerImageLeftArr[6];

	// Player Textures
	Texture2D currPlayerTexture;
	// Player stats
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
	// Moving vars
	float currentMoveSpeed;
	const float walkSpeed;
	const float sprintSpeed;
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
	float dashCooldown;// seconds
	const float dashPower;
	// Collison
	std::map <std::string, Rectangle> currentCollisionTags;

	inline void drawPlayer() {
		// Draw bars
		this->drawBars();

		DrawRectangleLinesEx(PlayerBox, 3, RED);// to see the box

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
	void handleCollisionsGroundObjects(GroundObject object);// Collision 
public:
	PlayerMonkey();

	// Handlers
	void handleUpdates(World world);// for vars that need to be updated every frame
	void handlePlayer();// visuals
	void handleBars();// stamina, hp, mana bars...

	// Collision with rectangle objects
	void CollisionWithRectangle(GroundObject object);

	// getters	
	inline Rectangle& getRectangle() { return PlayerBox; } // Non-const getter
	inline Camera2D& getCamera() { return mainCamera; } // Non-const getter
	inline std::map<std::string, Rectangle> getCurrentCollisionTags() { return currentCollisionTags; } // Non-const getter
};
 
