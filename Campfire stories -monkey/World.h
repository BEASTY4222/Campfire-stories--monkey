#pragma once
#include "GroundObject.h"
#include "Player.h"

class World {
	float worldGroundLevel = 1000.0f;
	float timeInAir = 0.0f;
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
	World() : mainGround(-10000.f, 1000.f, 200000.f, 20000.f, DARKGREEN, "GROUND")
	{}
	
	void gravityEffect(Rectangle& entityBox) {
		// Simple gravity effect
		if (entityBox.y + entityBox.height < 1000.0f) { // If player is above ground
			timeInAir += GetFrameTime();
			if (timeInAir < 0.5f)
				entityBox.y += 1.0f;
			else
				entityBox.y += 10.0f; // Apply gravity
		}
		else {
			entityBox.y = 1000.0f - entityBox.height; // Reset to ground level
			timeInAir = 0.0f;// its 800 cuss of the height of the ground + height of the player
							// 680 + 120 = 800
		}
	}
	void handleWorld(Rectangle& monkey) {
		gravityEffect(monkey);
		drawWorld();
	}

	float getGroundLevel() const {
		return 800.0f;
	}

	GroundObject getMainGround()const { return mainGround; }
};

