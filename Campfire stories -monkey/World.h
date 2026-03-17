#pragma once
#include <map>
#include <string>

#include "GroundObject.h"
#include "Player.h"
#include "Enemy.h"

class World {
	float worldGroundLevel;
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
	float timeMessage1;
	float timeMessage2;
	float timeMessage3;



	void drawWorld() {
		int spaceBetween = 0;
		for (int i = 0; i < 15;i++) {
			DrawTexture(startingSkyTexture, spaceBetween, 0, WHITE);
			DrawTexture(startingForestBackgroundTreesTexture, spaceBetween, 0, WHITE);
			DrawTexture(startingForestTreesTexture, spaceBetween, 0, WHITE);
			DrawTexture(startingForestGroundTexture, spaceBetween, 750, WHITE);
			spaceBetween += 1000;
		}
	}
	
public:
	World() : worldGroundLevel(850.0f),
		startingSkyImage(LoadImage("spritesWorld/magicalForest/forest/1.png")),
		startingForestBackgroundTreesImage(LoadImage("spritesWorld/magicalForest/forest/2.png")),
		startingForestTreesImage(LoadImage("spritesWorld/magicalForest/forest/3.png")),
		startingForestGroundImage(LoadImage("spritesWorld/magicalForest/forest/4.png")),

		startingSkyTexture(LoadTextureFromImage(startingSkyImage)),
		startingForestBackgroundTreesTexture(LoadTextureFromImage(startingForestBackgroundTreesImage)),
		startingForestTreesTexture(LoadTextureFromImage(startingForestTreesImage)),
		startingForestGroundTexture(LoadTextureFromImage(startingForestGroundImage)),
		mainGround(0.0f, 1000.0f, 100000.0f, 400.0f, "MAIN_GROUND"),
		groundObjects{ { "MAIN_GROUND", mainGround } },

		timeMessage1(0.0f), timeMessage2(0.0f), timeMessage3(0.0f)

	{
		mainGround.setTexture(startingForestGroundTexture);
	}
	
	void gravityEffect(Rectangle& entityBox, std::map <std::string, Rectangle> entityCollisins, float timeInAir) {
		// not Simple gravity effect
		if (entityBox.y + entityBox.height < groundObjects["MAIN_GROUND"].getRectangle().y) { // If player is above ground
			timeInAir += GetFrameTime();
			if (timeInAir <= 0.2f)
				entityBox.y += 8.0f;
			else
				entityBox.y += 1.0f; // Apply gravity
		}
		else {
			entityBox.y = groundObjects["MAIN_GROUND"].getRectangle().y - entityBox.height; // Reset to ground level
			timeInAir = 0.0f;
		}
	}
	void handleWorld(Rectangle& entity,std::map <std::string,Rectangle> entityCollisins, float entinysTimeInAir) {
		gravityEffect(entity, entityCollisins, entinysTimeInAir);          
		drawWorld();
	}

	void gameStart(bool & prologuePassed) {
		DrawRectangle(0, 0, 19200, 10800, BLACK);

		DrawText("You hear distant cries", 4100.0f, 320, 50, DARKGRAY);
		timeMessage2 += GetFrameTime();

		if (timeMessage2 >= 4.0f) {
			DrawText("from a village you bearly see", 4100.0f, 420, 50, DARKGRAY);
			timeMessage3 += GetFrameTime();
		}

		if (timeMessage3 >= 4.0f) {
			DrawText("you rush towards it", 4100.0f, 520, 50, DARKGRAY);
			timeMessage1 += GetFrameTime();
		}

		if (timeMessage1 >= 5.5f) {
			prologuePassed = true;
		}
	}

	float getGroundLevel() const {
		return worldGroundLevel;
	}

	GroundObject getMainGround()const { return mainGround; }
};

