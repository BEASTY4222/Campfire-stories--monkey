#pragma once
#include <string>
#include <map>

#include "raylib.h"
#include "GroundObject.h"
#include "Enemy.h"
#include "World.h"
#include "Village.h"

class Enemy;

class PlayerMonkey{
	// Player properties
	Rectangle PlayerBox;
	Camera2D mainCamera;
	// Player sprites & animations
	Image currPlayerImage;
	float animTimeRight;
	float animTimeLeft;
	float idleAnimTime;
	const float sprintAnimSpeed;
	const float walkAnimSpeed;
	float curAnimSpeed;
	float animJumpTime;
	float animDashTime;
	float animDeathTime;
	float animTimeHit;
	int animDashRight;
	int animDashLeft;
	int animRightJump;
	int animLeftJump;
	int animRight;
	int animLeft;
	int animIdle;
	int animHit;
	int animDeath;

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

	Image hit2PlayerImageRightArr[10];
	Texture2D hit2PlayerTextureRightArr[10];
	Image hit2PlayerImageLeftArr[10];
	Texture2D hit2PlayerTextureLeftArr[10];

	Image hit3PlayerImageRightArr[4];
	Texture2D hit3PlayerTextureRightArr[4];
	Image hit3PlayerImageLeftArr[4];
	Texture2D hit3PlayerTextureLeftArr[4];

	Image hit4PlayerImageRightArr[8];
	Texture2D hit4PlayerTextureRightArr[8];
	Image hit4PlayerImageLeftArr[8];
	Texture2D hit4PlayerTextureLeftArr[8];

	Image hit5PlayerImageRightArr[4];
	Texture2D hit5PlayerTextureRightArr[4];
	Image hit5PlayerImageLeftArr[4];
	Texture2D hit5PlayerTextureLeftArr[4];

	Image hit6PlayerImageRightArr[10];
	Texture2D hit6PlayerTextureRightArr[10];
	Image hit6PlayerImageLeftArr[10];
	Texture2D hit6PlayerTextureLeftArr[10];

	Image hit7PlayerImageRightArr[11];
	Texture2D hit7PlayerTextureRightArr[11];
	Image hit7PlayerImageLeftArr[11];
	Texture2D hit7PlayerTextureLeftArr[11];

	Image hit8PlayerImageRightArr[9];
	Texture2D hit8PlayerTextureRightArr[9];
	Image hit8PlayerImageLeftArr[9];
	Texture2D hit8PlayerTextureLeftArr[9];

	Image jumpPlayerImageRightArr[1];
	Texture2D jumpPlayerTextureRightArr[1];
	Image jumpPlayerImageLeftArr[1];
	Texture2D jumpPlayerTextureLeftArr[1];

	Image dashPlayerImageRightArr[3];
	Texture2D dashPlayerTextureRightArr[3];
	Image dashPlayerImageLeftArr[3];
	Texture2D dashPlayerTextureLeftArr[3];

	Image deathPlayerImageRightArr[6];
	Texture2D deathPlayerTextureRightArr[6];
	Image deathPlayerImageLeftArr[6];
	Texture2D deathPlayerTextureLeftArr[6];

	// Player Textures
	Texture2D currPlayerTexture;
	// Player stats
	float lastPlayerX;
	float lastPlayerY;
	float howBlack;
	bool firstStageDeath;
	bool alive;
	float maxInvincibilityTime;
	float currInvincibilityTime;
	float lastInvincibilityTime;
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
	bool restarted;
	float restartTime;
	Sound deathSound;
	bool hasKey;
	bool showLockedDoorMessage;
	bool talkingToBoy;
	int golbinsKilled;
	bool goblin1Dead;
	bool goblin2Dead;
	bool goblin3Dead;
	// Direction vars
	bool facingRight;
	bool hitting;
	// Moving vars
	//*these(*) are used to move the player in a direction for a short time*
	//*like when getting to close to the end of the map*
	bool canJump;
	bool moveRight;//*
	bool moveLeft;//*
	bool stopControl;//*
	bool displayMoveRightMessage;//*
	bool displayMoveLeftMessage;//*
	bool running;
	float timeInAir;
	float currentMoveSpeed;
	const float walkSpeed;
	const float sprintSpeed;
	const float hitWalkSpeed;
	bool notWalking;
	Vector2 mousePos;
	Color restartButtonColor;
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
	bool isDashing;
	float timeDashing;
	// Collison
	std::map <std::string, Rectangle> currentCollisionTags;
	// Combat vars
	Sound lightAttackSound;
	bool soundPlayed;
	Rectangle lightAttackHitBox;
	float lightAttackDamage;
	bool lightAttack1Used, lightAttack2Used, lightAttack3Used, lightAttack4Used, lightAttack5Used, lightAttack6Used, lightAttack7Used, lightAttack8Used;

	


	inline void drawPlayer() {
		//DrawRectangleLinesEx(PlayerBox, 3, RED);// to see the playerBox
		//DrawRectangleLinesEx(lightAttackHitBox, 3, GREEN);// to see the hitbox


		// Draw main character
		DrawTexture(currPlayerTexture, PlayerBox.x, PlayerBox.y + 10, WHITE);
	}

	void handleCamera(); 
	void handleHitting();
	void hittingLogic();
	void hittingHitbox();
	void handleMovement();
	void handleIdle();
	void handleCollisionsGroundObjects(GroundObject object);// Collision with ground objects
	void handleCollisionsEnemies(Enemy enemy);// Collision with enemies
	void staminaHandler(float amount, bool regen);
	void deathScreen(Enemy& enemy1, Enemy& enemy2, Enemy& enemy3);
	void messageBoxOutOfBoundsLeft();
	void messageBoxOutOfBoundsRight();
	void messageBoxTowerEntrance();
	void messageBoxBoy(Village village);
	void handleDialogue(Village village);
public:
	PlayerMonkey();


	// Handlers
	inline void drawPlayerBars()const {
		if (alive) {
			DrawRectangleRec(healthBar, LIME);// health
			DrawRectangleLinesEx(healthBarOutline, 4, BLACK);// health outline

			DrawRectangleRec(staminaBar, ORANGE);// stamina
			DrawRectangleLinesEx(staminaBarOutline, 4, BLACK);// stamina outline
		}
	}
	void handlePlayerActions();// for handling player actions like movement, hitting, etc
	void handleUpdates(World world, Enemy& enemy);// for vars that need to be updated every frame
	void handlePlayerVisuals(Enemy& enemy1, Enemy& enemy2, Enemy& enemy3, Village vilage);// visuals
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
	inline bool isSecondStage() const { return firstStageDeath; }
};
 
