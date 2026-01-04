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
	Texture2D idleTexture = LoadTextureFromImage(IdlePlayerImage1);

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


		DrawTexture(idleTexture, PlayerBox.x, PlayerBox.y + 28, WHITE);

	}

	inline void handleCamera() { this->mainCamera.target.x = { this->PlayerBox.x }; }
	void handleMovement();
	void handleCollisionsGroundObjects(GroundObject object);// Collision 
public:
	PlayerMonkey();

	// Handlers
	void handleUpdates(World world);// for vars that need to be updated every frame
	void handlePlayer();// visuals

	// Collision with rectangle objects
	void CollisionWithRectangle(GroundObject object);

	// getters	
	inline Rectangle& getRectangle() { return PlayerBox; } // Non-const getter
	inline Camera2D& getCamera() { return mainCamera; } // Non-const getter
};

