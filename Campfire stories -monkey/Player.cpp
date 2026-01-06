#include "Player.h"

PlayerMonkey::PlayerMonkey() : PlayerBox{ 1000.0f, 800.0f,80.0f, 150.0f },
	mainCamera{ { 1920.0 / 2, 720.0f}, { 1920 / 2, 1080 * 0.75f }, 0.0f, 1.0f },
	jumpProgress{ 0.0f }, jumpProgressDoubleJump{ 0.0f }, jumpPower{ 250.0f }, doubleJumpPower{ 150.0f },
	dashCooldown{ 0.0f }, dashPower{ 150.0f },
	idlePlayerImageRight1(LoadImage("spritesMonkey/IdleAnim/right/idleRight1.png")),
	idlePlayerImageRight2(LoadImage("spritesMonkey/IdleAnim/right/idleRight2.png")),
	idlePlayerImageLeft1(LoadImage("spritesMonkey/IdleAnim/left/idleLeft1.png")),
	idlePlayerImageLeft2(LoadImage("spritesMonkey/IdleAnim/left/idleLeft2.png")),

	walkPlayerImageRight1(LoadImage("spritesMonkey/runAnim/runRight/run1.png")),
	walkPlayerImageRight2(LoadImage("spritesMonkey/runAnim/runRight/run2.png")),
	walkPlayerImageRight3(LoadImage("spritesMonkey/runAnim/runRight/run3.png")),
	walkPlayerImageRight4(LoadImage("spritesMonkey/runAnim/runRight/run4.png")),
	walkPlayerImageRight5(LoadImage("spritesMonkey/runAnim/runRight/run5.png")),
	walkPlayerImageRight6(LoadImage("spritesMonkey/runAnim/runRight/run6.png")),
	walkPlayerImageRightArr{ walkPlayerImageRight1, walkPlayerImageRight2, walkPlayerImageRight3,
								walkPlayerImageRight4,walkPlayerImageRight5,walkPlayerImageRight6 },

	walkPlayerImageLeft1(LoadImage("spritesMonkey/runAnim/runLeft/runLeft1.png")),
	walkPlayerImageLeft2(LoadImage("spritesMonkey/runAnim/runLeft/runLeft2.png")),
	walkPlayerImageLeft3(LoadImage("spritesMonkey/runAnim/runLeft/runLeft3.png")),
	walkPlayerImageLeft4(LoadImage("spritesMonkey/runAnim/runLeft/runLeft4.png")),
	walkPlayerImageLeft5(LoadImage("spritesMonkey/runAnim/runLeft/runLeft5.png")),
	walkPlayerImageLeft6(LoadImage("spritesMonkey/runAnim/runLeft/runLeft6.png")),
	walkPlayerImageLeftArr{ walkPlayerImageLeft1, walkPlayerImageLeft2, walkPlayerImageLeft3,
								walkPlayerImageLeft4,walkPlayerImageLeft5,walkPlayerImageLeft6 },
	
	idleAnimRightArr{ idlePlayerImageRight1, idlePlayerImageRight2 },
	idleAnimLeftArr{ idlePlayerImageLeft1, idlePlayerImageLeft2 },
	currPlayerTexture(LoadTextureFromImage(idlePlayerImageRight2)), currPlayerImage(idlePlayerImageRight2),
	currentMoveSpeed(0), walkSpeed(5.0f), sprintSpeed(10.0f),
	facingRight(true), animTimeRight(0.0f), animTimeLeft(0.0f), animRight(0), animLeft(0),
	maxHealth(300.0f),  currHealth(maxHealth), 
	maxStamina(260.0f), currStamina(maxStamina), staminaRegenRate(6.0f), regenStamina(true),
	healthBarOutline{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, 304.0f, 30.0f },
	healthBar{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, currHealth, 30.0f },
	staminaBarOutline{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, 264.0f, 30.0f },
	staminaBar{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, currStamina, 30.0f }
	, TAG{"PLAYER"}
	{}
// Handlers
// Movement handler
void PlayerMonkey::handleMovement() {
	if (IsKeyPressed(KEY_MINUS)) {
		mainCamera.zoom -= 0.5f;
	}
	if (IsKeyPressed(KEY_EQUAL)) {
		mainCamera.zoom += 0.5f;
	}

	if (IsKeyDown(KEY_D)) {
		animLeft = 0;
		animTimeLeft = 0.0f;

		currPlayerImage = walkPlayerImageRightArr[animRight];
		animTimeRight += GetFrameTime();
		if (animTimeRight > 0.2f) {
			animRight++;
			if (animRight >= 6) animRight = 0;
			animTimeRight = 0.0f;
		}
		
		
		UpdateTexture(currPlayerTexture, currPlayerImage.data);

		
		this->PlayerBox.x += currentMoveSpeed;
		facingRight = true;

	}
	if (IsKeyDown(KEY_A)) {
		animRight = 0;
		animTimeRight = 0.0f;

		currPlayerImage = walkPlayerImageLeftArr[animLeft];
		animTimeLeft += GetFrameTime();
		if (animTimeLeft > 0.2f) {
			animLeft++;
			if (animLeft >= 6) animLeft = 0;
			animTimeLeft = 0.0f;
		}
		

		UpdateTexture(currPlayerTexture, currPlayerImage.data);
		
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
				this->currStamina -= 15.0f;
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
			this->currStamina -= 20.0f;
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
			this->currStamina -= 30.0f;
		}
		
	}else {
		dashCooldown += GetFrameTime();
	}

	if (IsKeyDown(KEY_LEFT_SHIFT)) {
		regenStamina = false;
		currentMoveSpeed = sprintSpeed;
		currStamina -= 5.0f * GetFrameTime();// decrease stamina over time 
											 // cuss your running
	}
	else {
		regenStamina = true;
		currentMoveSpeed = walkSpeed;
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
	staminaBar.width = currStamina;
	if (currStamina < maxStamina && regenStamina) 
		currStamina += staminaRegenRate * GetFrameTime();// regenerate stamina over time
	
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