#pragma once

#include "raylib.h"


class PlayerMonkey{
	Rectangle PlayerBox;
	bool inAir = false;
	bool doubleJumpUsed = false;
	Camera2D mainCamera = { 0 };

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
					this->PlayerBox.y -= 150.0f;
					doubleJumpUsed = true;
					return;
				}
			}
			else {
				this->PlayerBox.y -= 350.0f;
				inAir = true;
			}			
		}
		if (PlayerBox.y == 800.0f) {
			inAir = false;
			doubleJumpUsed = false;
		}
	}
public:
	PlayerMonkey() {
		this->PlayerBox.x = 100.0f;
		this->PlayerBox.y = 920.0f;
		this->PlayerBox.width = 80.0f;
		this->PlayerBox.height = 120.0f;

		this->mainCamera.offset = { 1920.0f / 2, 720.0f };
		this->mainCamera.target = { 1920 / 2, 1080 * 0.75f };
		this->mainCamera.rotation = 0.0f;
		this->mainCamera.zoom = 0.6f;
	}

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
	Rectangle& getRectangle() { return PlayerBox; } // Non-const getter

	Camera2D& getCamera() { return mainCamera; } // Non-const getter
};

