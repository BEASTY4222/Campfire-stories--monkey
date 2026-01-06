#pragma once
#include "GroundObject.h"
#include "Player.h"

class World {
	float worldGroundLevel = 1000.0f;
	float timeInAir = 0.0f;
	Image startingSkyImage;
	Texture2D startingSkyTexture;
	Image startingForestBackgroundTreesImage;
	Texture2D startingForestBackgroundTreesTexture;
	Image startingForestTreesImage;
	Texture2D startingForestTreesTexture;
	Image startingForestGroundImage;
	Texture2D startingForestGroundTexture;
	GroundObject mainGround;

	void drawWorld() const {
		// Draw random Mountain 
		// Draw sky
		float spaceBetween = 0.0f;
		for (int i = 0; i < 10;i++) {
			DrawTexture(startingSkyTexture, spaceBetween, 0.0f, WHITE);
			DrawTexture(startingForestBackgroundTreesTexture, spaceBetween, 0.0f, WHITE);
			DrawTexture(startingForestTreesTexture, spaceBetween, 0.0f, WHITE);
			mainGround.drawObject(spaceBetween);
			spaceBetween += 1000.0f;
		}
	}
	
public:
	World() :
		//startingSkyImage(LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\1.png")),
		//startingForestBackgroundTreesImage(LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\2.png")),
		//startingForestTreesImage(LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\3.png")),
		//startingForestGroundImage(LoadImage("C:\\Users\\IvanSuperPC\\source\\repos\\BEASTY4222\\Campfire-stories--monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\4.png")),
		startingForestGroundImage(LoadImage("C:\\Users\\USER69\\Desktop\\11B IG\\Informatik\\C++\\Campfire stories -monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\4.png")),
		startingForestTreesImage(LoadImage("C:\\Users\\USER69\\Desktop\\11B IG\\Informatik\\C++\\Campfire stories -monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\3.png")),
		startingForestBackgroundTreesImage(LoadImage("C:\\Users\\USER69\\Desktop\\11B IG\\Informatik\\C++\\Campfire stories -monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\2.png")),
		startingSkyImage(LoadImage("C:\\Users\\USER69\\Desktop\\11B IG\\Informatik\\C++\\Campfire stories -monkey\\Campfire stories -monkey\\spritesWorld\\magicalForest\\forest\\1.png")),
		startingSkyTexture(LoadTextureFromImage(startingSkyImage)),
		startingForestBackgroundTreesTexture(LoadTextureFromImage(startingForestBackgroundTreesImage)),
		startingForestTreesTexture(LoadTextureFromImage(startingForestTreesImage)),
		startingForestGroundTexture(LoadTextureFromImage(startingForestGroundImage)),
		mainGround(0.0f, 680.0f, 1000.0f, 0.0f, "GROUND", startingForestGroundTexture)

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

