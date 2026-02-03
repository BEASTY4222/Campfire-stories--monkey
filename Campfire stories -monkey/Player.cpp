#include "Player.h"

PlayerMonkey::PlayerMonkey() : PlayerBox{ 1000.0f, 800.0f,80.0f, 150.0f },// Player rectangle
mainCamera{ { 1920.0 / 2, 720.0f}, { 1920 / 2, 1080 * 0.75f }, 0.0f, 1.0f },// Camera
jumpProgress{ 0.0f }, jumpProgressDoubleJump{ 0.0f }, jumpPower{ 1200.0f }, doubleJumpPower{ 800.0f }, timeInAir(0.0f),// Jumping vars
dashCooldown{ 2.0f }, dashPower{ 1000.0f }, dashProgress(0.0f), isDashing(false), timeDashing(0.0f),// Dash vars
// PLAYER IMAGE SPRITES
idleAnimRightArr{ LoadImage("spritesMonkey/IdleAnim/right/idleRight1.png"), LoadImage("spritesMonkey/IdleAnim/right/idleRight2.png") },
idleAnimLeftArr{ LoadImage("spritesMonkey/IdleAnim/left/idleLeft1.png"), LoadImage("spritesMonkey/IdleAnim/left/idleLeft2.png") },

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

	hit2PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight8.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight9.png"), LoadImage("spritesMonkey/hitAnim/hit2/right/lightComboRight10.png") },
	hit2PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft8.png"),
								LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft9.png"), LoadImage("spritesMonkey/hitAnim/hit2/left/lightComboLeft10.png") },

	hit3PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit3/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit3/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit3/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit3/right/lightComboRight4.png"), },
	hit3PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit3/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit3/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit3/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit3/left/lightComboLeft4.png"), },

	hit4PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit4/right/lightComboRight8.png"), },
	hit4PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit4/left/lightComboLeft8.png"), },
	
	hit5PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit5/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit5/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit5/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit5/right/lightComboRight4.png"), },
	hit5PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit5/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit5/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit5/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit5/left/lightComboLeft4.png"), },

	hit6PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight8.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight9.png"), LoadImage("spritesMonkey/hitAnim/hit6/right/lightComboRight10.png") },
	hit6PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft8.png"),
								LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft9.png"), LoadImage("spritesMonkey/hitAnim/hit6/left/lightComboLeft10.png") },

	hit7PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight8.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight9.png"), LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight10.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/right/lightComboRight11.png") },
	hit7PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft8.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft9.png"), LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft10.png"),
								LoadImage("spritesMonkey/hitAnim/hit7/left/lightComboLeft11.png") },

	hit8PlayerImageRightArr{ LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight1.png"), LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight2.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight3.png"), LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight4.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight5.png"), LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight6.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight7.png"), LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight8.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/right/lightComboRight9.png") },

	hit8PlayerImageLeftArr{ LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft1.png"), LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft2.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft3.png"), LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft4.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft5.png"), LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft6.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft7.png"), LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft8.png"),
								LoadImage("spritesMonkey/hitAnim/hit8/left/lightComboLeft9.png") },
	
	
	
	
	jumpPlayerImageRightArr{ LoadImage("spritesMonkey/jumpAnim/jumpRight/jumpRight1.png") },
	jumpPlayerImageLeftArr{ LoadImage("spritesMonkey/jumpAnim/jumpLeft/jumpLeft1.png") },

	dashPlayerImageRightArr{ LoadImage("spritesMonkey/dashAnim/dashRight/dashRight1.png"), LoadImage("spritesMonkey/dashAnim/dashRight/dashRight2.png"),
								LoadImage("spritesMonkey/dashAnim/dashRight/dashRight3.png") },
	dashPlayerImageLeftArr{ LoadImage("spritesMonkey/dashAnim/dashLeft/dashLeft1.png"), LoadImage("spritesMonkey/dashAnim/dashLeft/dashLeft2.png"),
								LoadImage("spritesMonkey/dashAnim/dashLeft/dashLeft3.png") },
	currPlayerTexture(LoadTextureFromImage(idleAnimRightArr[0])), currPlayerImage(idleAnimRightArr[0]),// CURR PLAYER TEXTURE & IMAGE

	//PLAYER TEXTURE ARRAYS
	// Idle left & right
	idleAnimRightTexArr{ LoadTextureFromImage(idleAnimRightArr[0]), LoadTextureFromImage(idleAnimRightArr[1]) },
	idleAnimLeftTexArr{ LoadTextureFromImage(idleAnimLeftArr[0]), LoadTextureFromImage(idleAnimLeftArr[1]) },
	// Walking left & right
	walkPlayerTextureRightArr{ LoadTextureFromImage(walkPlayerImageRightArr[0]), LoadTextureFromImage(walkPlayerImageRightArr[1]),
								LoadTextureFromImage(walkPlayerImageRightArr[2]), LoadTextureFromImage(walkPlayerImageRightArr[3]),
								LoadTextureFromImage(walkPlayerImageRightArr[4]), LoadTextureFromImage(walkPlayerImageRightArr[5]) },
	walkPlayerTextureLeftArr{ LoadTextureFromImage(walkPlayerImageLeftArr[0]), LoadTextureFromImage(walkPlayerImageLeftArr[1]),
								LoadTextureFromImage(walkPlayerImageLeftArr[2]), LoadTextureFromImage(walkPlayerImageLeftArr[3]),
								LoadTextureFromImage(walkPlayerImageLeftArr[4]), LoadTextureFromImage(walkPlayerImageLeftArr[5]) },
	// Hitting left & right
	hit1PlayerTextureRightArr{ LoadTextureFromImage(hit1PlayerImageRightArr[0]), LoadTextureFromImage(hit1PlayerImageRightArr[1]),
								LoadTextureFromImage(hit1PlayerImageRightArr[2]), LoadTextureFromImage(hit1PlayerImageRightArr[3]),
								LoadTextureFromImage(hit1PlayerImageRightArr[4]), LoadTextureFromImage(hit1PlayerImageRightArr[5]),
								LoadTextureFromImage(hit1PlayerImageRightArr[6]), LoadTextureFromImage(hit1PlayerImageRightArr[7]),
								LoadTextureFromImage(hit1PlayerImageRightArr[8]), LoadTextureFromImage(hit1PlayerImageRightArr[9]) },
	hit1PlayerTextureLeftArr{ LoadTextureFromImage(hit1PlayerImageLeftArr[0]), LoadTextureFromImage(hit1PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit1PlayerImageLeftArr[2]), LoadTextureFromImage(hit1PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit1PlayerImageLeftArr[4]), LoadTextureFromImage(hit1PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit1PlayerImageLeftArr[6]), LoadTextureFromImage(hit1PlayerImageLeftArr[7]),
								LoadTextureFromImage(hit1PlayerImageLeftArr[8]), LoadTextureFromImage(hit1PlayerImageLeftArr[9]) },

	hit2PlayerTextureRightArr{ LoadTextureFromImage(hit2PlayerImageRightArr[0]), LoadTextureFromImage(hit2PlayerImageRightArr[1]),
								LoadTextureFromImage(hit2PlayerImageRightArr[2]), LoadTextureFromImage(hit2PlayerImageRightArr[3]),
								LoadTextureFromImage(hit2PlayerImageRightArr[4]), LoadTextureFromImage(hit2PlayerImageRightArr[5]),
								LoadTextureFromImage(hit2PlayerImageRightArr[6]), LoadTextureFromImage(hit2PlayerImageRightArr[7]),
								LoadTextureFromImage(hit2PlayerImageRightArr[8]), LoadTextureFromImage(hit2PlayerImageRightArr[9]) },
	hit2PlayerTextureLeftArr{ LoadTextureFromImage(hit2PlayerImageLeftArr[0]), LoadTextureFromImage(hit2PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit2PlayerImageLeftArr[2]), LoadTextureFromImage(hit2PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit2PlayerImageLeftArr[4]), LoadTextureFromImage(hit2PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit2PlayerImageLeftArr[6]), LoadTextureFromImage(hit2PlayerImageLeftArr[7]),
								LoadTextureFromImage(hit2PlayerImageLeftArr[8]), LoadTextureFromImage(hit2PlayerImageLeftArr[9]) },

	hit3PlayerTextureRightArr{ LoadTextureFromImage(hit3PlayerImageRightArr[0]), LoadTextureFromImage(hit3PlayerImageRightArr[1]),
								LoadTextureFromImage(hit3PlayerImageRightArr[2]), LoadTextureFromImage(hit3PlayerImageRightArr[3]) },
	hit3PlayerTextureLeftArr{ LoadTextureFromImage(hit3PlayerImageLeftArr[0]), LoadTextureFromImage(hit3PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit3PlayerImageLeftArr[2]), LoadTextureFromImage(hit3PlayerImageLeftArr[3]) },

	hit4PlayerTextureRightArr{ LoadTextureFromImage(hit4PlayerImageRightArr[0]), LoadTextureFromImage(hit4PlayerImageRightArr[1]),
								LoadTextureFromImage(hit4PlayerImageRightArr[2]), LoadTextureFromImage(hit4PlayerImageRightArr[3]),
								LoadTextureFromImage(hit4PlayerImageRightArr[4]), LoadTextureFromImage(hit4PlayerImageRightArr[5]),
								LoadTextureFromImage(hit4PlayerImageRightArr[6]), LoadTextureFromImage(hit4PlayerImageRightArr[7]), },
	hit4PlayerTextureLeftArr{ LoadTextureFromImage(hit4PlayerImageLeftArr[0]), LoadTextureFromImage(hit4PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit4PlayerImageLeftArr[2]), LoadTextureFromImage(hit4PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit4PlayerImageLeftArr[4]), LoadTextureFromImage(hit4PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit4PlayerImageLeftArr[6]), LoadTextureFromImage(hit4PlayerImageLeftArr[7]), },

	hit5PlayerTextureRightArr{ LoadTextureFromImage(hit5PlayerImageRightArr[0]), LoadTextureFromImage(hit5PlayerImageRightArr[1]),
								LoadTextureFromImage(hit5PlayerImageRightArr[2]), LoadTextureFromImage(hit5PlayerImageRightArr[3]) },
	hit5PlayerTextureLeftArr{ LoadTextureFromImage(hit5PlayerImageLeftArr[0]), LoadTextureFromImage(hit5PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit5PlayerImageLeftArr[2]), LoadTextureFromImage(hit5PlayerImageLeftArr[3]) },

	hit6PlayerTextureRightArr{ LoadTextureFromImage(hit6PlayerImageRightArr[0]), LoadTextureFromImage(hit6PlayerImageRightArr[1]),
								LoadTextureFromImage(hit6PlayerImageRightArr[2]), LoadTextureFromImage(hit6PlayerImageRightArr[3]),
								LoadTextureFromImage(hit6PlayerImageRightArr[4]), LoadTextureFromImage(hit6PlayerImageRightArr[5]),
								LoadTextureFromImage(hit6PlayerImageRightArr[6]), LoadTextureFromImage(hit6PlayerImageRightArr[7]),
								LoadTextureFromImage(hit6PlayerImageRightArr[8]), LoadTextureFromImage(hit6PlayerImageRightArr[9]) },
	hit6PlayerTextureLeftArr{ LoadTextureFromImage(hit6PlayerImageLeftArr[0]), LoadTextureFromImage(hit6PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit6PlayerImageLeftArr[2]), LoadTextureFromImage(hit6PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit6PlayerImageLeftArr[4]), LoadTextureFromImage(hit6PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit6PlayerImageLeftArr[6]), LoadTextureFromImage(hit6PlayerImageLeftArr[7]),
								LoadTextureFromImage(hit6PlayerImageLeftArr[8]), LoadTextureFromImage(hit6PlayerImageLeftArr[9]) },

	hit7PlayerTextureRightArr{ LoadTextureFromImage(hit7PlayerImageRightArr[0]), LoadTextureFromImage(hit7PlayerImageRightArr[1]),
								LoadTextureFromImage(hit7PlayerImageRightArr[2]), LoadTextureFromImage(hit7PlayerImageRightArr[3]),
								LoadTextureFromImage(hit7PlayerImageRightArr[4]), LoadTextureFromImage(hit7PlayerImageRightArr[5]),
								LoadTextureFromImage(hit7PlayerImageRightArr[6]), LoadTextureFromImage(hit7PlayerImageRightArr[7]),
								LoadTextureFromImage(hit7PlayerImageRightArr[8]), LoadTextureFromImage(hit7PlayerImageRightArr[9]),
								LoadTextureFromImage(hit7PlayerImageRightArr[10]) },
	hit7PlayerTextureLeftArr{ LoadTextureFromImage(hit7PlayerImageLeftArr[0]), LoadTextureFromImage(hit7PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit7PlayerImageLeftArr[2]), LoadTextureFromImage(hit7PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit7PlayerImageLeftArr[4]), LoadTextureFromImage(hit7PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit7PlayerImageLeftArr[6]), LoadTextureFromImage(hit7PlayerImageLeftArr[7]),
								LoadTextureFromImage(hit7PlayerImageLeftArr[8]), LoadTextureFromImage(hit7PlayerImageLeftArr[9]),
								LoadTextureFromImage(hit7PlayerImageLeftArr[10]) },

	hit8PlayerTextureRightArr{ LoadTextureFromImage(hit8PlayerImageRightArr[0]), LoadTextureFromImage(hit8PlayerImageRightArr[1]),
								LoadTextureFromImage(hit8PlayerImageRightArr[2]), LoadTextureFromImage(hit8PlayerImageRightArr[3]),
								LoadTextureFromImage(hit8PlayerImageRightArr[4]), LoadTextureFromImage(hit8PlayerImageRightArr[5]),
								LoadTextureFromImage(hit8PlayerImageRightArr[6]), LoadTextureFromImage(hit8PlayerImageRightArr[7]),
								LoadTextureFromImage(hit8PlayerImageRightArr[8]) },
	hit8PlayerTextureLeftArr{ LoadTextureFromImage(hit8PlayerImageLeftArr[0]), LoadTextureFromImage(hit8PlayerImageLeftArr[1]),
								LoadTextureFromImage(hit8PlayerImageLeftArr[2]), LoadTextureFromImage(hit8PlayerImageLeftArr[3]),
								LoadTextureFromImage(hit8PlayerImageLeftArr[4]), LoadTextureFromImage(hit8PlayerImageLeftArr[5]),
								LoadTextureFromImage(hit8PlayerImageLeftArr[6]), LoadTextureFromImage(hit8PlayerImageLeftArr[7]),
								LoadTextureFromImage(hit8PlayerImageLeftArr[8]) },


	// Jumping left & right
	jumpPlayerTextureRightArr{ LoadTextureFromImage(jumpPlayerImageRightArr[0]) },
	jumpPlayerTextureLeftArr{ LoadTextureFromImage(jumpPlayerImageLeftArr[0]) },

	// Dashing left & right
	dashPlayerTextureRightArr{ LoadTextureFromImage(dashPlayerImageRightArr[0]), LoadTextureFromImage(dashPlayerImageRightArr[1]),
								LoadTextureFromImage(dashPlayerImageRightArr[2]) },
	dashPlayerTextureLeftArr{ LoadTextureFromImage(dashPlayerImageLeftArr[0]), LoadTextureFromImage(dashPlayerImageLeftArr[1]),
								LoadTextureFromImage(dashPlayerImageLeftArr[2]) },

	// Movement vars															// Sprinting vars
	currentMoveSpeed(0), hitWalkSpeed(2.5f), walkSpeed(5.0f), walkAnimSpeed(0.2f), sprintSpeed(10.0f), curAnimSpeed(0.2f), sprintAnimSpeed(0.1f),
	notWalking(true), running(false),
	facingRight(true),  // Facing direction vars
	// Animation time vars
	animTimeRight(0.0f), animTimeLeft(0.0f), idleAnimTime(0.0f),
	animRight(0), animLeft(0), animIdle(0), animDashRight(0), animRightJump(0), animJumpTime(0.0f),
	animDashTime(0.0f), animDashLeft(0), animLeftJump(0), animHit(0), animTimeHit(0.0f),
	// Player stats
	maxHealth(300.0f), currHealth(maxHealth), maxInvincibilityTime(2.0f), currInvincibilityTime(0.0f), lastInvincibilityTime(0.0f), alive(true),
	maxStamina(260.0f), currStamina(maxStamina), staminaRegenRate(7.0f), regenStamina(true),
	// Bars Initalization
	healthBarOutline{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, 304.0f, 30.0f },
	healthBar{ mainCamera.target.x + 640.0f, mainCamera.target.y + 220.0f, currHealth, 30.0f },
	staminaBarOutline{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, 264.0f, 30.0f },
	staminaBar{ mainCamera.target.x + 680.0f, mainCamera.target.y + 260.0f, currStamina, 30.0f }
	, TAG{ "PLAYER" },// Tag
	// Combat vars
	lightAttackHitBox{ 0, 0, 0, 0 }, lightAttackDamage(30.0f), hitting(false), 
	lightAttack1Used(false), lightAttack2Used(false), lightAttack3Used(false), lightAttack4Used(false),
	lightAttack5Used(false), lightAttack6Used(false), lightAttack7Used(false), lightAttack8Used(false)
		{}
// Handlers
// Movement handler
void PlayerMonkey::handlePlayerActions() {
	if (currHealth <= 0) {
		alive = false;
	}
	// Hitting handler
	this->handleHitting();
	// Movement handler
	this->handleMovement();

	
	// Idle animation handler
	this->handleIdle();


	if (currInvincibilityTime < maxInvincibilityTime) {
		currInvincibilityTime += GetFrameTime();
	}
}

void PlayerMonkey::handleHitting() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && currStamina > 0) {
		animRight = 0;
		animTimeRight = 0.0f;
		animLeft = 0;
		animTimeLeft = 0.0f;

		hitting = true;
		// Right attack
		hittingLogic();
		

		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D)) {
			currentMoveSpeed = hitWalkSpeed;
		}
		
	}
	else {
		hitting = false;
		lightAttackHitBox.x = 0.0f;
		lightAttackHitBox.y = 0.0f;
		lightAttackHitBox.width = 0.0f;
		lightAttackHitBox.height = 0.0f;
	}
}

void::PlayerMonkey::hittingLogic() {
	if (!lightAttack1Used) {
		if (facingRight) {
			currPlayerImage = hit1PlayerImageRightArr[animHit];
			currPlayerTexture = hit1PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit1PlayerImageLeftArr[animHit];
			currPlayerTexture = hit1PlayerTextureLeftArr[animHit];
		}
		

		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 9) {
				if (animTimeHit > 0.3f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack1Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}		
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack2Used) {
		if (facingRight) {
			currPlayerImage = hit2PlayerImageRightArr[animHit];
			currPlayerTexture = hit2PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit2PlayerImageLeftArr[animHit];
			currPlayerTexture = hit2PlayerTextureLeftArr[animHit];
		}
		

		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 9) {
				if (animTimeHit > 0.3f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack2Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack3Used) {
		if (facingRight) {
			currPlayerImage = hit3PlayerImageRightArr[animHit];
			currPlayerTexture = hit3PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit3PlayerImageLeftArr[animHit];
			currPlayerTexture = hit3PlayerTextureLeftArr[animHit];
		}
		

		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.15f) {
			if (animHit >= 3) {
				if (animTimeHit > 0.2f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack3Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack4Used) {
		if (facingRight) {
			currPlayerImage = hit4PlayerImageRightArr[animHit];
			currPlayerTexture = hit4PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit4PlayerImageLeftArr[animHit];
			currPlayerTexture = hit4PlayerTextureLeftArr[animHit];
		}


		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 7) {
				if (animTimeHit > 0.2f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack4Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack5Used) {
		if (facingRight) {
			currPlayerImage = hit5PlayerImageRightArr[animHit];
			currPlayerTexture = hit5PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit5PlayerImageLeftArr[animHit];
			currPlayerTexture = hit5PlayerTextureLeftArr[animHit];
		}


		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 3) {
				if (animTimeHit > 0.2f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack5Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack6Used) {
		if (facingRight) {
			currPlayerImage = hit6PlayerImageRightArr[animHit];
			currPlayerTexture = hit6PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit6PlayerImageLeftArr[animHit];
			currPlayerTexture = hit6PlayerTextureLeftArr[animHit];
		}


		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 9) {
				if (animTimeHit > 0.1f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack6Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack7Used) {
		if (facingRight) {
			currPlayerImage = hit7PlayerImageRightArr[animHit];
			currPlayerTexture = hit7PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit7PlayerImageLeftArr[animHit];
			currPlayerTexture = hit7PlayerTextureLeftArr[animHit];
		}


		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 10) {
				if (animTimeHit > 0.3f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack7Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
	else if (!lightAttack8Used) {
		if (facingRight) {
			currPlayerImage = hit8PlayerImageRightArr[animHit];
			currPlayerTexture = hit8PlayerTextureRightArr[animHit];
		}
		else {
			currPlayerImage = hit8PlayerImageLeftArr[animHit];
			currPlayerTexture = hit8PlayerTextureLeftArr[animHit];
		}


		animTimeHit += GetFrameTime();
		if (animTimeHit > 0.1f) {
			if (animHit >= 8) {
				if (animTimeHit > 0.3f) {
					animHit = 0;
					animTimeHit = 0.0f;
					lightAttack8Used = true;
				}
			}
			else {
				animHit++;
				animTimeHit = 0.0f;
			}
		}
		// Hitbox handling
		hittingHitbox();
	}
}
void PlayerMonkey::hittingHitbox() {
	if (!lightAttack1Used) {
		if (animHit >= 5 && animHit <= 6) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}

		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack2Used) {
		if (animHit >= 3 && animHit <= 4) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack3Used){
		if (animHit >= 0 && animHit <= 1) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack4Used) {
		if (animHit >= 1 && animHit <= 3) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
		}
		else if (animHit == 7) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack5Used) {
		if (animHit >= 0 && animHit <= 1) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack6Used) {
		if (animHit >= 7 && animHit <= 9) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}

		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack7Used) {
		if (animHit >= 7 && animHit <= 9) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}

		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else if (!lightAttack8Used) {
		if (animHit >= 7 && animHit <= 8) {
			if (facingRight) {
				lightAttackHitBox.x = this->PlayerBox.x + this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}
			else {
				lightAttackHitBox.x = this->PlayerBox.x - this->PlayerBox.width;
				lightAttackHitBox.y = this->PlayerBox.y + 50.0f;
				lightAttackHitBox.width = 60.0f;
				lightAttackHitBox.height = 80.0f;
			}

		}
		else {
			lightAttackHitBox.x = 0.0f;
			lightAttackHitBox.y = 0.0f;
			lightAttackHitBox.width = 0.0f;
			lightAttackHitBox.height = 0.0f;
		}
	}
	else {
		lightAttackHitBox.x = 0.0f;
		lightAttackHitBox.y = 0.0f;
		lightAttackHitBox.width = 0.0f;
		lightAttackHitBox.height = 0.0f;
	}
}

void PlayerMonkey::handleMovement() {
	if (IsKeyDown(KEY_D)) {
		animLeft = 0;
		animTimeLeft = 0.0f;

		if (!hitting) {
			currPlayerImage = walkPlayerImageRightArr[animRight];
			currPlayerTexture = walkPlayerTextureRightArr[animRight];
			animTimeRight += GetFrameTime();
			if (animTimeRight > curAnimSpeed) {
				animRight++;
				if (animRight >= 6) animRight = 0;
				animTimeRight = 0.0f;
			}
		}

		this->PlayerBox.x += currentMoveSpeed;
		facingRight = true;

	}
	if (IsKeyDown(KEY_A)) {
		animRight = 0;
		animTimeRight = 0.0f;

		if (!hitting) {
			currPlayerImage = walkPlayerImageLeftArr[animLeft];
			currPlayerTexture = walkPlayerTextureLeftArr[animLeft];
			animTimeLeft += GetFrameTime();
			if (animTimeLeft > curAnimSpeed) {
				animLeft++;
				if (animLeft >= 6) animLeft = 0;
				animTimeLeft = 0.0f;
			}
		}



		this->PlayerBox.x -= currentMoveSpeed;
		facingRight = false;

	}
	if ((IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE)) && currStamina > 20.0f) {
		if (inAir) {
			if (!doubleJumpUsed) {
				jumpProgress = doubleJumpPower;
				this->staminaHandler(15.0f, !running);
				doubleJumpUsed = true;
			}
		}
		else {
			jumpProgress = jumpPower;
			this->staminaHandler(20.0f, !running);
			inAir = true;

			
		}
	}
	if (inAir) {
		if (facingRight) {
			currPlayerImage = jumpPlayerImageRightArr[0];
			currPlayerTexture = jumpPlayerTextureRightArr[0];
		}
		else {
			currPlayerImage = jumpPlayerImageLeftArr[0];
			currPlayerTexture = jumpPlayerTextureLeftArr[0];
		}
		jumpProgress -= 1000.0f * GetFrameTime();

		this->PlayerBox.y -= jumpProgress * GetFrameTime();
	}
	


	if (IsKeyPressed(KEY_Q) && currStamina > 50.0f) {
		if (dashCooldown >= 2.0f) {
			if (IsKeyDown(KEY_A)) { dashProgress -= dashPower; }
			if (IsKeyDown(KEY_D)) { dashProgress += dashPower; }

			isDashing = true;
			dashCooldown = 0.0f;
			this->staminaHandler(50.0f, !running);
		}
	}
	else if (isDashing) {
		timeDashing += GetFrameTime();
		animDashTime += GetFrameTime();

		lastInvincibilityTime = currInvincibilityTime;
		currInvincibilityTime = 0.0f;// invincibility while dashing

		if (dashProgress > 0) {
			currPlayerImage = dashPlayerImageRightArr[animDashRight];
			currPlayerTexture = dashPlayerTextureRightArr[animDashRight];
			if (animDashTime > 0.1f) {
				animDashRight++;
				if (animDashTime >= 3) animDashRight = 0;
				animDashTime = 0.0f;
			}

			dashProgress -= 800.0f * GetFrameTime();
			this->PlayerBox.x += dashProgress * GetFrameTime();
		}
		else {
			currPlayerImage = dashPlayerImageLeftArr[animDashLeft];
			currPlayerTexture = dashPlayerTextureLeftArr[animDashLeft];
			if (animDashTime > 0.1f) {
				animDashLeft++;
				if (animDashTime >= 3) animDashLeft = 0;
				animDashTime = 0.0f;
			}

			dashProgress += 800.0f * GetFrameTime();
			this->PlayerBox.x += dashProgress * GetFrameTime();
		}

		if (timeDashing > 0.3f) {
			dashProgress = 0.0f;
			isDashing = false;
			timeDashing = 0.0f;
			animDashRight = 0;
			animDashLeft = 0;
			animDashTime = 0.0f;

			currInvincibilityTime = lastInvincibilityTime;
		}
	}
	dashCooldown += GetFrameTime();
	
	if (IsKeyDown(KEY_LEFT_SHIFT) && currStamina >= 5.0f) {
		curAnimSpeed = sprintAnimSpeed;
		currentMoveSpeed = sprintSpeed;
		running = true;
		staminaHandler(5.0f * GetFrameTime(), running);// decrease stamina over time 
		// cuss your running
	}
	else {
		running = false;
		curAnimSpeed = walkAnimSpeed;
		staminaHandler(0.0f, running);
		currentMoveSpeed = walkSpeed;
	}
}
void PlayerMonkey::handleIdle() {
	if ((IsKeyUp(KEY_A) && IsKeyUp(KEY_D) && !inAir )&& !hitting) {
		// Anim times
		animRight = 0;
		animTimeRight = 0.0f;

		animLeft = 0;
		animTimeLeft = 0.0f;

		animHit = 0;
		animTimeHit = 0.0f;

		lightAttack1Used = false;
		lightAttack2Used = false;
		lightAttack3Used = false;
		lightAttack4Used = false;
		lightAttack5Used = false;
		lightAttack6Used = false;
		lightAttack7Used = false;
		lightAttack8Used = false;


		if (facingRight) {
			currPlayerImage = idleAnimRightArr[animIdle];
			currPlayerTexture = idleAnimRightTexArr[animIdle];

			idleAnimTime += GetFrameTime();
			if (idleAnimTime > 0.5f) {
				animIdle++;
				if (animIdle >= 2) animIdle = 0;
				idleAnimTime = 0.0f;
			}
		}
		else {
			currPlayerImage = idleAnimLeftArr[animIdle];
			currPlayerTexture = idleAnimLeftTexArr[animIdle];

			idleAnimTime += GetFrameTime();
			if (idleAnimTime > 0.5f) {
				animIdle++;
				if (animIdle >= 2) animIdle = 0;
				idleAnimTime = 0.0f;
			}
		}




	}
}
void PlayerMonkey::staminaHandler(float amount, bool regen) {
	currStamina -= amount;
	if (regen && currStamina < maxStamina) {
		currStamina += staminaRegenRate * GetFrameTime();// regenerate stamina over time
	}
}



// Bars handler
void PlayerMonkey::handleBars() {
	healthBarOutline.x = mainCamera.target.x + 640.0f;
	healthBarOutline.y = mainCamera.target.y + 220.0f;
	healthBar.x = mainCamera.target.x + 640.0f;
	healthBar.y = mainCamera.target.y + 220.0f;
	healthBar.width = currHealth;

	staminaBarOutline.x = mainCamera.target.x + 680.0f;
	staminaBarOutline.y = mainCamera.target.y + 260.0f;
	staminaBar.x = mainCamera.target.x + 680.0f;
	staminaBar.y = mainCamera.target.y + 260.0f;
	staminaBar.width = currStamina;
	if ((currStamina < maxStamina) && regenStamina) 
		currStamina += staminaRegenRate * GetFrameTime();// regenerate stamina over time
	
}
// Update handler
void PlayerMonkey::handleUpdates(World world, Enemy& enemy) {// For vars that need to be updated every frame
	this->handlePlayerActions();// heavy on calculations so separated
	this->handleCamera();
	this->handleBars();// dependent on the camera x & y
	this->handleCollisionsGroundObjects(world.getMainGround());
	this->handleCollisionsEnemies(enemy);// temporary enemy for testing
}
// Draw handler
void PlayerMonkey::handlePlayerVisuals() {
	this->drawPlayer();

}
// Collision with rectangle objects
void PlayerMonkey::handleCollisionsEnemies(Enemy enemy) {
	CollisionWithRectangle(enemy);
}
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
void PlayerMonkey::CollisionWithRectangle(Enemy enemy) {
	if (CheckCollisionRecs(this->PlayerBox, enemy.getRectangle())) {
		currentCollisionTags[enemy.getTag()] = enemy.getRectangle();
		for (std::pair<std::string, Rectangle> tag : currentCollisionTags) {
			if (tag.first == "ENEMY") {
				if (currInvincibilityTime >= 2.0f) {
					currHealth -= enemy.getDamage();
					currInvincibilityTime = 0.0f;
				}
					
			}
			
		}

	}
}