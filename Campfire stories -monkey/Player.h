#pragma once

#include "raylib.h"


class PlayerMonkey{
	Rectangle PlayerBox;
	bool inAir = false;
	bool doubleJumpUsed = false;
	Camera2D mainCamera;
	float jumpProgress;
	const std::string TAG;

	void drawPlayer() const {
		DrawRectangleRec(this->PlayerBox, BROWN);
	}

	void handleMovement() {
		if (IsKeyDown(KEY_D)) {
			this->PlayerBox.x += 15.0f;
		}
		if (IsKeyDown(KEY_A)) {
			this->PlayerBox.x -= 15.0f;
		}
		if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_SPACE)) {
			if (inAir) {
				if (!doubleJumpUsed) {
					if (jumpProgress != 150.0f) {
						jumpProgress += 150.0f * GetFrameTime();
					}
					this->PlayerBox.y -= jumpProgress;
					doubleJumpUsed = true;
					return;
				}
			}
			else {
				if (jumpProgress != 350.0f) {
					jumpProgress += 350.0f * (GetFrameTime() * 50);
				}
				this->PlayerBox.y -= jumpProgress;
				inAir = true;
			}			
		}
		if (PlayerBox.y == 800.0f) {
			inAir = false;
			doubleJumpUsed = false;
			jumpProgress = 0.0f;
		}
	}
public:
	PlayerMonkey() : PlayerBox{ 1000.0f, 800.0f,80.0f, 120.0f }, 
		mainCamera{ { 1920.0 / 2, 720.0f}, { 1920 / 2, 1080 * 0.75f }, 0.0f, 0.6f},
		jumpProgress{ 0.0f }, TAG{ "PLAYER" }
		 {}

	void handleCamera() {
		this->mainCamera.target.x = { this->PlayerBox.x };
	}
	
	void handleUpdates() {
		handleMovement();
		handleCamera();
	}

	void handlePlayer() {
		
		
		drawPlayer();

	}

	bool colliedsWithRectangle(const Rectangle& other) const {
		return CheckCollisionRecs(this->PlayerBox, other);
	}
	Rectangle& getRectangle() { return PlayerBox; } // Non-const getter

	Camera2D& getCamera() { return mainCamera; } // Non-const getter
};

