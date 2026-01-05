#pragma once
#include <string>

#include "raylib.h"
#include "GroundObject.h"
#include "World.h"

class PlayerMonkey{
	// Player properties
	Rectangle PlayerBox;
	Camera2D mainCamera;
	// Player sprites
	Image IdlePlayerImage1;
	// Player Textures
	Texture2D idleTexture; //= LoadTextureFromImage(IdlePlayerImage1);
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

	inline void drawPlayer() {
		// Draw bars
		this->drawBars();


		// Draw main character
		DrawTexture(idleTexture, PlayerBox.x, PlayerBox.y + 10, WHITE);
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
};

