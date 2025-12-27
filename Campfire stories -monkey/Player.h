#pragma once
#include <string>

#include "raylib.h"
#include "GroundObject.h"
#include "World.h"


class PlayerMonkey{
	// Player properties
	Rectangle PlayerBox;
	Camera2D mainCamera;
	// Player sprite
	Image IdlePlayerImage1;
	//Image IdlePlayerImage2;
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
		IdlePlayerImage1 = LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesMonkey\\IdleAnim\\idle1.png");
		DrawTexture(LoadTextureFromImage(IdlePlayerImage1), PlayerBox.x, PlayerBox.y + 20, WHITE);
		//ImageDrawRectangleRec(&IdlePlayerImage1, PlayerBox, WHITE);

		UnloadImage(IdlePlayerImage1);
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

