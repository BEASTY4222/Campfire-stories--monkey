#include "Player.h"

PlayerMonkey::PlayerMonkey() : PlayerBox{ 1000.0f, 800.0f,80.0f, 150.0f },
	mainCamera{ { 1920.0 / 2, 720.0f}, { 1920 / 2, 1080 * 0.75f }, 0.0f, 1.0f },
	jumpProgress{ 0.0f }, jumpProgressDoubleJump{ 0.0f }, jumpPower{ 250.0f }, doubleJumpPower{ 150.0f },
	dashCooldown{ 0.0f }, dashPower{ 150.0f },
	idleAnimRightArr{ LoadImage("spritesMonkey/IdleAnim/right/idleRight1.png"), LoadImage("spritesMonkey/IdleAnim/right/idleRight2.png") },

	walkPlayerImageRightArr{ LoadImage("spritesMonkey/runAnim/runRight/run1.png"), LoadImage("spritesMonkey/runAnim/runRight/run2.png"), 
								LoadImage("spritesMonkey/runAnim/runRight/run3.png"), LoadImage("spritesMonkey/runAnim/runRight/run4.png"),
								LoadImage("spritesMonkey/runAnim/runRight/run5.png"),LoadImage("spritesMonkey/runAnim/runRight/run6.png") },

	walkPlayerImageLeftArr{ LoadImage("spritesMonkey/runAnim/runLeft/runLeft1.png"), LoadImage("spritesMonkey/runAnim/runLeft/runLeft2.png"), 
								LoadImage("spritesMonkey/runAnim/runLeft/runLeft3.png"),LoadImage("spritesMonkey/runAnim/runLeft/runLeft4.png"), 
								LoadImage("spritesMonkey/runAnim/runLeft/runLeft5.png"),LoadImage("spritesMonkey/runAnim/runLeft/runLeft6.png") },
	
	hit1PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight8.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight9.png"), LoadImage("spritesMonkey/hitAnim/hit1/right/lightComboRight10.png") },

	hit1PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft8.png"),
								LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft9.png"), LoadImage("spritesMonkey/hitAnim/hit1/left/lightComboLeft10.png") },

	currPlayerTexture(LoadTextureFromImage(idleAnimRightArr[0])), currPlayerImage(idleAnimRightArr[0]),
	currentMoveSpeed(0), walkSpeed(5.0f), sprintSpeed(10.0f), curAnimSpeed(0.2f), sprintAnimSpeed(0.1f), walkAnimSpeed(0.2f), notWalking(true),
	facingRight(true), hitting(false), animTimeRight(0.0f), animTimeLeft(0.0f), idleAnimTime(0.0f), animTimeHit1RightTime(0.0f), animTimeHit1LeftTime(0.0f),
	animHit1Left(0), animHit1Right(0), animRight(0), animLeft(0), animIdle(0),
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
		hitting = false;
		animHit1Left = 0;
		animTimeHit1LeftTime = 0.0f;
		animHit1Right = 0;
		animTimeHit1RightTime = 0.0f;

		animLeft = 0;
		animTimeLeft = 0.0f;

		currPlayerImage = walkPlayerImageRightArr[animRight];
		animTimeRight += GetFrameTime();
		if (animTimeRight > curAnimSpeed) {
			animRight++;
			if (animRight >= 6) animRight = 0;
			animTimeRight = 0.0f;
		}
		
		
		UpdateTexture(currPlayerTexture, currPlayerImage.data);

		
		this->PlayerBox.x += currentMoveSpeed;
		facingRight = true;

	}
	if (IsKeyDown(KEY_A)) {
		hitting = false;
		animHit1Left = 0;
		animTimeHit1LeftTime = 0.0f;
		animHit1Right = 0;
		animTimeHit1RightTime = 0.0f;

		animRight = 0;
		animTimeRight = 0.0f;

		currPlayerImage = walkPlayerImageLeftArr[animLeft];
		animTimeLeft += GetFrameTime();
		if (animTimeLeft > curAnimSpeed) {
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

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		animRight = 0;
		animTimeRight = 0.0f;
		animLeft = 0;
		animTimeLeft = 0.0f;

		if (hitting == false) {

		}

		hitting = true;
		if (facingRight) {
			currPlayerImage = hit1PlayerImageRightArr[animHit1Right];
			animTimeHit1RightTime += GetFrameTime();
			if (animTimeHit1RightTime > 0.1f) {
				animHit1Right++;
				if (animHit1Right >= 10) animHit1Right = 0;
				animTimeHit1RightTime = 0.0f;
			}
		}
		else {
			currPlayerImage = hit1PlayerImageLeftArr[animHit1Left];
			animTimeHit1LeftTime += GetFrameTime();
			if (animTimeHit1LeftTime > 0.1f) {
				animHit1Left++;
				if (animHit1Left >= 10) animHit1Left = 0;
				animTimeHit1LeftTime = 0.0f;
			}
		}
		

		UpdateTexture(currPlayerTexture, currPlayerImage.data);
	}
	else {
		hitting = true;
		animHit1Left = 0;
		animTimeHit1LeftTime = 0.0f;
		animHit1Right = 0;
		animTimeHit1RightTime = 0.0f;
	}



	if (IsKeyDown(KEY_LEFT_SHIFT)) {
		curAnimSpeed = sprintAnimSpeed;
		regenStamina = false;
		currentMoveSpeed = sprintSpeed;
		currStamina -= 5.0f * GetFrameTime();// decrease stamina over time 
											 // cuss your running
	}
	else {
		curAnimSpeed = walkAnimSpeed;
		regenStamina = true;
		currentMoveSpeed = walkSpeed;
	}

	if ((IsKeyUp(KEY_A) && IsKeyUp(KEY_D)) && !hitting) {
		animRight = 0;
		animTimeRight = 0.0f;
		animLeft = 0;
		animTimeLeft = 0.0f;

		currPlayerImage = idleAnimRightArr[animIdle];
		idleAnimTime += GetFrameTime();
 		if (idleAnimTime > 0.5f) {
			animIdle++;
			if (animIdle >= 2) animIdle = 0;
			idleAnimTime = 0.0f;
		}
		UpdateTexture(currPlayerTexture, currPlayerImage.data);

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
//- You can walk into a platform from the side
//-You can walk into an enemy from the side unless you add special logic
//- You can jump up through a platform unless you block upward collisions

void PlayerMonkey::CollisionWithRectangle(GroundObject object) {
	if (CheckCollisionRecs(this->PlayerBox, object.getRectangle())) {
		currentCollisionTags[object.getTag()] = object.getRectangle();
		for (std::pair<std::string, Rectangle> tag: currentCollisionTags) {
			if (tag.first == "MAIN_GROUND") {
				this->inAir = false;
				this->doubleJumpUsed = false;
				this->jumpProgress = 0.0f;
			}

			if (inAir && object.getRectangle().y < PlayerBox.y) {
				currentCollisionTags.erase(tag.first);
			}
		}
		
	}
}