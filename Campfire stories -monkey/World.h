#pragma once
#include "raylib.h"
#include "GroundObject.h"

class World {
	float worldGroundLevel = 920.0f;
	float timeInAir = 0.f;
	GroundObject mainGround;

	void drawWorld() const {
		// Draw random Mountain 
		DrawRectangle(-10000, -1000, 1920000, 10000, GRAY);
		// Draw sky
		DrawRectangle(0, -10000, 19200, 920000, SKYBLUE);
		// Draw ground
		mainGround.drawObject();
	}
	
public:
	World() :mainGround(-10000.f, worldGroundLevel, 200000.f, 20000.f, DARKGREEN)
	{}
	
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

