#pragma once
#include <map>
#include <string>

#include "GroundObject.h"
#include "Player.h"

class World {
	float worldGroundLevel = 700.0f;
	float timeInAir = 0.0f;
	GroundObject mainGround;
	std::map <std::string, GroundObject> groundObjects;
	Image startingSkyImage;
	Texture2D startingSkyTexture;
	Image startingForestBackgroundTreesImage;
	Texture2D startingForestBackgroundTreesTexture;
	Image startingForestTreesImage;
	Texture2D startingForestTreesTexture;
	Image startingForestGroundImage;
	Texture2D startingForestGroundTexture;

	void drawWorld() const {
		float spaceBetween = 0.0f;
		for (int i = 0; i < 10;i++) {
			DrawTexture(startingSkyTexture, spaceBetween, 0.0f, WHITE);
			DrawTexture(startingForestBackgroundTreesTexture, spaceBetween, 0.0f, WHITE);
			DrawTexture(startingForestTreesTexture, spaceBetween, 0.0f, WHITE);
			mainGround.drawObject();
			spaceBetween += 1000.0f;
		}
	}
	
public:
	World() :
		startingSkyImage(LoadImage("spritesWorld/magicalForest/forest/1.png")),
		startingForestBackgroundTreesImage(LoadImage("spritesWorld/magicalForest/forest/2.png")),
		startingForestTreesImage(LoadImage("spritesWorld/magicalForest/forest/3.png")),
		startingForestGroundImage(LoadImage("spritesWorld/magicalForest/forest/4.png")),

		startingSkyTexture(LoadTextureFromImage(startingSkyImage)),
		startingForestBackgroundTreesTexture(LoadTextureFromImage(startingForestBackgroundTreesImage)),
		startingForestTreesTexture(LoadTextureFromImage(startingForestTreesImage)),
		startingForestGroundTexture(LoadTextureFromImage(startingForestGroundImage)),
		mainGround(0.0f, 1000.0f, 100000.0f, 100.0f, "MAIN_GROUND", startingForestGroundTexture),
		groundObjects{ { "MAIN_GROUND", mainGround } }

	{}
	
	void gravityEffect(Rectangle& entityBox, std::map <std::string, Rectangle> entityCollisins) {
		// not Simple gravity effect
		if (entityBox.y + entityBox.height < groundObjects["MAIN_GROUND"].getRectangle().y) { // If player is above ground
			timeInAir += GetFrameTime();
			if (timeInAir < 0.5f)
				entityBox.y += 1.0f;
			else
				entityBox.y += 10.0f; // Apply gravity
		}
		else {
			entityBox.y = groundObjects["MAIN_GROUND"].getRectangle().y - entityBox.height; // Reset to ground level
			timeInAir = 0.0f;
		}
	}
	void handleWorld(Rectangle& entity,std::map <std::string,Rectangle> entityCollisins) {
		gravityEffect(entity, entityCollisins);          
		drawWorld();
	}

	float getGroundLevel() const {
		return worldGroundLevel;
	}

	GroundObject getMainGround()const { return mainGround; }
};

