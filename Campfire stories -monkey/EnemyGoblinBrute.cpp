#include "EnemyGoblinBrute.h"

EnemyGoblinBrute::EnemyGoblinBrute(const float& x, const float& y, const float& width, const float& hegiht, const float& hp, const float& speed, const float& damage)
	: Enemy(x, y, width, hegiht, hp, speed, damage)
	
{
	// Assign images to the inherited array in the constructor body
	// Walking
	// left
	imageWalkLeftArr[0] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft1.png");
	imageWalkLeftArr[1] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft2.png");
	imageWalkLeftArr[2] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft3.png");
	imageWalkLeftArr[3] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft4.png");
	imageWalkLeftArr[4] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft5.png");
	imageWalkLeftArr[5] = LoadImage("enemies/golblin brute/walkAnim/left/walkLeft6.png");

	textureWalkLeftArr[0] = LoadTextureFromImage(imageWalkLeftArr[0]);
	textureWalkLeftArr[1] = LoadTextureFromImage(imageWalkLeftArr[1]);
	textureWalkLeftArr[2] = LoadTextureFromImage(imageWalkLeftArr[2]);
	textureWalkLeftArr[3] = LoadTextureFromImage(imageWalkLeftArr[3]);
	textureWalkLeftArr[4] = LoadTextureFromImage(imageWalkLeftArr[4]);
	textureWalkLeftArr[5] = LoadTextureFromImage(imageWalkLeftArr[5]);
	// right
	imageWalkRightArr[0] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight1.png");
	imageWalkRightArr[1] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight2.png");
	imageWalkRightArr[2] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight3.png");
	imageWalkRightArr[3] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight4.png");
	imageWalkRightArr[4] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight5.png");
	imageWalkRightArr[5] = LoadImage("enemies/golblin brute/walkAnim/right/walkRight6.png");

	textureWalkRightArr[0] = LoadTextureFromImage(imageWalkRightArr[0]);
	textureWalkRightArr[1] = LoadTextureFromImage(imageWalkRightArr[1]);
	textureWalkRightArr[2] = LoadTextureFromImage(imageWalkRightArr[2]);
	textureWalkRightArr[3] = LoadTextureFromImage(imageWalkRightArr[3]);
	textureWalkRightArr[4] = LoadTextureFromImage(imageWalkRightArr[4]);
	textureWalkRightArr[5] = LoadTextureFromImage(imageWalkRightArr[5]);

	//Hitting
	// left
	imageHitLeftArr[0] = LoadImage("enemies/golblin brute/hitAnim/left/hitLeft1.png");
	imageHitLeftArr[1] = LoadImage("enemies/golblin brute/hitAnim/left/hitLeft2.png");
	imageHitLeftArr[2] = LoadImage("enemies/golblin brute/hitAnim/left/hitLeft3.png");
	imageHitLeftArr[3] = LoadImage("enemies/golblin brute/hitAnim/left/hitLeft4.png");

	textureHitLeftArr[0] = LoadTextureFromImage(imageHitLeftArr[0]);
	textureHitLeftArr[1] = LoadTextureFromImage(imageHitLeftArr[1]);
	textureHitLeftArr[2] = LoadTextureFromImage(imageHitLeftArr[2]);
	textureHitLeftArr[3] = LoadTextureFromImage(imageHitLeftArr[3]);
	// right
	imageHitRightArr[0] = LoadImage("enemies/golblin brute/hitAnim/right/hitRight1.png");
	imageHitRightArr[1] = LoadImage("enemies/golblin brute/hitAnim/right/hitRight2.png");
	imageHitRightArr[2] = LoadImage("enemies/golblin brute/hitAnim/right/hitRight3.png");
	imageHitRightArr[3] = LoadImage("enemies/golblin brute/hitAnim/right/hitRight4.png");

	textureHitRightArr[0] = LoadTextureFromImage(imageHitRightArr[0]);
	textureHitRightArr[1] = LoadTextureFromImage(imageHitRightArr[1]);
	textureHitRightArr[2] = LoadTextureFromImage(imageHitRightArr[2]);
	textureHitRightArr[3] = LoadTextureFromImage(imageHitRightArr[3]);

	// Idle
	// left
	imageIdleLeftArr[0] = LoadImage("enemies/golblin brute/idleAnim/left/idleLeft1.png");
	imageIdleLeftArr[1] = LoadImage("enemies/golblin brute/idleAnim/left/idleLeft2.png");
	imageIdleLeftArr[2] = LoadImage("enemies/golblin brute/idleAnim/left/idleLeft3.png");
	imageIdleLeftArr[3] = LoadImage("enemies/golblin brute/idleAnim/left/idleLeft4.png");
	imageIdleLeftArr[4] = LoadImage("enemies/golblin brute/idleAnim/left/idleLeft5.png");

	textureIdleLeftArr[0] = LoadTextureFromImage(imageIdleLeftArr[0]);
	textureIdleLeftArr[1] = LoadTextureFromImage(imageIdleLeftArr[1]);
	textureIdleLeftArr[2] = LoadTextureFromImage(imageIdleLeftArr[2]);
	textureIdleLeftArr[3] = LoadTextureFromImage(imageIdleLeftArr[3]);
	textureIdleLeftArr[4] = LoadTextureFromImage(imageIdleLeftArr[4]);
	// right
	imageIdleRightArr[0] = LoadImage("enemies/golblin brute/idleAnim/right/idleRight1.png");
	imageIdleRightArr[1] = LoadImage("enemies/golblin brute/idleAnim/right/idleRight2.png");
	imageIdleRightArr[2] = LoadImage("enemies/golblin brute/idleAnim/right/idleRight3.png");
	imageIdleRightArr[3] = LoadImage("enemies/golblin brute/idleAnim/right/idleRight4.png");
	imageIdleRightArr[4] = LoadImage("enemies/golblin brute/idleAnim/right/idleRight5.png");

	textureIdleRightArr[0] = LoadTextureFromImage(imageIdleRightArr[0]);
	textureIdleRightArr[1] = LoadTextureFromImage(imageIdleRightArr[1]);
	textureIdleRightArr[2] = LoadTextureFromImage(imageIdleRightArr[2]);
	textureIdleRightArr[3] = LoadTextureFromImage(imageIdleRightArr[3]);
	textureIdleRightArr[4] = LoadTextureFromImage(imageIdleRightArr[4]);

	currentTexture = textureIdleRightArr[0];
}

void EnemyGoblinBrute::DrawEnemy() {
	DrawTexture(currentTexture, enemyBox.x, enemyBox.y + 10, WHITE);
	DrawRectangleRec(this->getHealhBar(), LIME);// health
}

void EnemyGoblinBrute::movement() {
	if (standing) {
		animLeft = 0;
		animRight = 0;
		animTimeLeft = 0.0f;
		animTimeRight = 0.0f;

		currentTexture = facingRight ? textureIdleRightArr[animIdle] : textureIdleLeftArr[animIdle];
		standTime += GetFrameTime();
		animIdleTime += GetFrameTime();
		if (animIdleTime > 0.15f) {
			animIdle++;
			if (animIdle >= 5) animIdle = 0;
			animIdleTime = 0.0f;
		}

		if (standTime > 2.0f) {
			facingRight = !facingRight;
			standing = false;
			standTime = 0.0f;
			animIdle = 0;
		}
	}
	
	if (facingRight && !standing) {
		animLeft = 0;
		animTimeLeft = 0.0f;

		currentTexture = textureWalkRightArr[animRight];
		animTimeRight += GetFrameTime();
		if (animTimeRight > 0.2f) {
			animRight++;
			if (animRight >= 6) animRight = 0;
			animTimeRight = 0.0f;
		}
		if (enemyBox.x > 2600.0f) {
			standing = true;
		}else{
			standing = false;
			this->enemyBox.x += speed;
		}
	}
	else if(!facingRight && !standing) {
		animRight = 0;
		animTimeRight = 0.0f;

		currentTexture = textureWalkLeftArr[animLeft];
		animTimeLeft += GetFrameTime();
		if (animTimeLeft > 0.2f) {
			animLeft++;
			if (animLeft >= 6) animLeft = 0;
			animTimeLeft = 0.0f;
		}


		if (enemyBox.x < 1600.0f) {
			standing = true;
		}
		else {
			standing = false;
			this->enemyBox.x -= speed;
		}
	}

	
}