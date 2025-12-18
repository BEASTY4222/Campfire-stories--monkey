#pragma once
#include "raylib.h"

class World {
	void drawWorld() const {
		// Draw ground
		DrawRectangle(0, 920, 1920, 160, DARKGREEN);
		// Draw sky
		DrawRectangle(0, 0, 1920, 920, SKYBLUE);
	}
	
public:
	World() {
		// Constructor implementation (if needed)
	}
	
	void gravityEffect(Rectangle& playerBox) {
		// Simple gravity effect
		if (playerBox.y + playerBox.height < 920) { // If player is above ground
			playerBox.y += 10.0f; // Apply gravity
		}
		else {
			playerBox.y = 920 - playerBox.height; // Reset to ground level
		}
	}
	void handleWorld(PlayerMonkey& player) {
		drawWorld();
		gravityEffect(player.getRectangle());
	}

	float getGroundLevel() const {
		return 920.0f;
	}
};

