#include <iostream>

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyGoblinBrute.h"
#include "World.h"
#include "Village.h"


int main() {
    // Initialization
    SetTraceLogLevel(LOG_ALL);
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Campfire stories: Monkey");
    InitAudioDevice();

    SetTargetFPS(60);  // Set the game to run at 60 frames per second

    //INIT ONLY AFTER THE INITS FOR THE WINDOW FOR TEXTURES TO WORK GOOD
    // SO VRAM RESCOURSEC COULD BE LOADED

    PlayerMonkey Monkey;
    //          hp(hp), speed(speed), damage(damage), enemyBox{ x, y, width, hegiht }
    EnemyGoblinBrute goblinFront(7400.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f,7000.0f, 8000.0f);
	EnemyGoblinBrute goblinMiddle(8500.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f, 7600.0f, 8800.0f);
	EnemyGoblinBrute goblinBack(9100.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f, 8200.0f, 9700.0f);
    World gameWorld;
	Village village;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here
		Monkey.handlePlayerActions();

		Monkey.handleUpdates(gameWorld, goblinFront);
        Monkey.handleUpdates(gameWorld, goblinMiddle);
		Monkey.handleUpdates(gameWorld, goblinBack);

        goblinFront.handleUpdates(Monkey, gameWorld);
		goblinMiddle.handleUpdates(Monkey, gameWorld);
		goblinBack.handleUpdates(Monkey, gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(Monkey.getCamera());


		gameWorld.handleWorld(goblinFront.getRectangle(), goblinFront.getCurrentCollisionTags(), goblinFront.getAirTime());
		gameWorld.handleWorld(goblinMiddle.getRectangle(), goblinMiddle.getCurrentCollisionTags(), goblinMiddle.getAirTime());
		gameWorld.handleWorld(goblinBack.getRectangle(), goblinBack.getCurrentCollisionTags(), goblinBack.getAirTime());

        gameWorld.handleWorld(Monkey.getRectangle(), Monkey.getCurrentCollisionTags(), Monkey.getTimeInAir());

        village.DrawVillageBackHouses();

        Monkey.handlePlayerVisuals();
        goblinFront.handleEnemy();
		goblinMiddle.handleEnemy();
		goblinBack.handleEnemy();

		Monkey.drawPlayerBars();

        village.DrawVillageFrontHouses();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}