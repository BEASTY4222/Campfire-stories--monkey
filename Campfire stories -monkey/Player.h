#pragma once

#include "raylib.h"


class PlayerMonkey{
	Rectangle PlayerBox;
	bool inAir = false;
	bool doubleJumpUsed = false;

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
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_SPACE)) {
			if (inAir) {
				if (!doubleJumpUsed) {
					this->PlayerBox.y -= 50.0f;
					doubleJumpUsed = true;
					return;
				}
				else {
					doubleJumpUsed = false;
				}
			}
			this->PlayerBox.y -= 50.0f;
			inAir = true;
			
		}
		if (PlayerBox.y == 920.0f) {

		}
	}
public:
	PlayerMonkey() {
		this->PlayerBox.x = 100.0f;
		this->PlayerBox.y = 800.0f;
		this->PlayerBox.width = 80.0f;
		this->PlayerBox.height = 120.0f;
	}

	

	void handlePlayer() {
		drawPlayer();
		handleMovement();
	}
	Rectangle& getRectangle() { return PlayerBox; } // Non-const getter

};

