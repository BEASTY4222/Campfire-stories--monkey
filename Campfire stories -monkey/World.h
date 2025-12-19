#pragma once
#include "raylib.h"

class World {
	float worldGroundLevel = 9200.0f;
	float timeInAir = 0.f;

	void drawWorld() const {
		// Draw ground
		DrawRectangle(0, 920, 1920000, 160, DARKGREEN);
		// Draw sky
		DrawRectangle(0, 0, 1920, 920, SKYBLUE);
	}
	
public:
	World() {
		// Constructor implementation (if needed)
	}
	
	void gravityEffect(Rectangle& playerBox) {
		// Simple gravity effect
		if (playerBox.y + playerBox.height < 920.f) { // If player is above ground
			timeInAir += GetFrameTime();
			if (timeInAir < 0.5f)
				playerBox.y += 3.0f;
			else
				playerBox.y += 10.0f; // Apply gravity
		}
		else {
			playerBox.y = 920.f - playerBox.height; // Reset to ground level
			timeInAir = 0.f;
		}
	}
	void handleWorld(PlayerMonkey& player) {
		drawWorld();
		gravityEffect(player.getRectangle());
	}

	float getGroundLevel() const {
		return 800.0f;
	}
};

