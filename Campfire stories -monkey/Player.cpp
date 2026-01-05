#include "Player.h"

PlayerMonkey::PlayerMonkey() : PlayerBox{ 1000.0f, 800.0f,80.0f, 150.0f },
	mainCamera{ { 1920.0 / 2, 720.0f}, { 1920 / 2, 1080 * 0.75f }, 0.0f, 1.0f },
	jumpProgress{ 0.0f }, jumpProgressDoubleJump{ 0.0f }, jumpPower{ 250.0f }, doubleJumpPower{ 150.0f},
	dashCooldown{ 0.0f }, dashPower{ 150.0f },
	//IdlePlayerImage1(LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesMonkey\\IdleAnim\\idle1.png")),
	IdlePlayerImage1(LoadImage("C:\\Users\\USER69\\Desktop\\11B IG\\Informatik\\C++\\Campfire stories -monkey\\Campfire stories -monkey\\spritesMonkey\\IdleAnim\\idle1.png")),
	idleTexture(LoadTextureFromImage(IdlePlayerImage1)),
	currentMoveSpeed(0), walkSpeed(5.0f), sprintSpeed(10.0f),
	facingRight(true),
	health(200.0f), stamina(100.0f), 
	healthBarOutline{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, 304.0f, 30.0f },
	healthBar{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, 300.0f, 30.0f },
	staminaBarOutline{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, 264.0f, 30.0f },
	staminaBar{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, 260.0f, 30.0f }
	, TAG{"PLAYER"}
	{}
// Handlers
// Movement handler
void PlayerMonkey::handleMovement() {
	if (IsKeyDown(KEY_D)) {

		if (!facingRight) {
			ImageFlipHorizontal(&IdlePlayerImage1);
			UpdateTexture(idleTexture, IdlePlayerImage1.data);

		}
		this->PlayerBox.x += currentMoveSpeed;
		facingRight = true;

	}
	if (IsKeyDown(KEY_A)) {

		if (facingRight) {
			ImageFlipHorizontal(&IdlePlayerImage1);
			UpdateTexture(idleTexture, IdlePlayerImage1.data);
		}
		this->PlayerBox.x -= currentMoveSpeed;
		facingRight = false;

	}
	if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE)) {
		if (inAir) {
			if (!doubleJumpUsed) {
				if (jumpProgress != doubleJumpPower) {
					jumpProgressDoubleJump += doubleJumpPower;
					// SAME HERE, MAKE SMOOTHER
				}
				this->PlayerBox.y -= jumpProgress;
				doubleJumpUsed = true;
				return;
			}
		}
		else {
			if (jumpProgress != jumpPower) {
				jumpProgress += jumpPower; // NEEDS TO FIXED LATER
				// MAKE THE JUMP SMOOTHER 
			}
			this->PlayerBox.y -= jumpProgress;
			inAir = true;
		}
	}
	
	if (IsKeyPressed(KEY_Q)) {
		if (dashCooldown >= 2.0f) {
			if (IsKeyDown(KEY_E)) {
				this->PlayerBox.x += dashPower;
			}
			if (IsKeyDown(KEY_A)) {
				this->PlayerBox.x -= dashPower;
			}
			dashCooldown = 0.0f;
		}
		
	}else {
		dashCooldown += GetFrameTime();
	}

	if (IsKeyDown(KEY_LEFT_SHIFT)) {
		currentMoveSpeed = sprintSpeed;
	}
	else {
		currentMoveSpeed = walkSpeed;
	}

	// On ground zero all 
	if (PlayerBox.y == 1000.0f) {
		inAir = false;
		doubleJumpUsed = false;
		jumpProgress = 0.0f;
		jumpProgressDoubleJump = 0.0f;
	}
}
// Bars handler
void PlayerMonkey::handleBars() {
	healthBarOutline.x = mainCamera.target.x + 640.0f;
	healthBarOutline.y = mainCamera.target.y + 220.0f;
	healthBar.x = mainCamera.target.x + 640.0f;
	healthBar.y = mainCamera.target.y + 220.0f;

	staminaBarOutline.x = mainCamera.target.x + 680.0f;
	staminaBarOutline.y = mainCamera.target.y + 260.0f;
	staminaBar.x = mainCamera.target.x + 680.0f;
	staminaBar.y = mainCamera.target.y + 260.0f;
}
// Update handler
void PlayerMonkey::handleUpdates(World world) {// For vars that need to be updated every frame
	this->handleMovement();			// heavy on calculations so separated
	this->handleCamera();
	this->handleBars();// dependent on the camera x & y
	this->handleCollisionsGroundObjects(world.getMainGround());
}
// Draw handler
void PlayerMonkey::handlePlayer() {
	this->drawPlayer();

}
// Collision with rectangle objects
void PlayerMonkey::handleCollisionsGroundObjects(GroundObject object) {
	CollisionWithRectangle(object);
}

// Collison methods
void PlayerMonkey::CollisionWithRectangle(GroundObject object) {
	if (CheckCollisionRecs(this->PlayerBox, object.getRectangle())) {
		std::string objecttag = object.getTag();
		if (objecttag == "GROUND") {
			this->inAir = false;
			this->doubleJumpUsed = false;
			this->jumpProgress = 0.0f;
			this->PlayerBox.y = object.getRectangle().y - this->PlayerBox.height;
		}
	}
}