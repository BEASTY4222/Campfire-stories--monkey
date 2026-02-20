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
    EnemyGoblinBrute goblinFront(7400.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f);
	EnemyGoblinBrute goblinMiddle(8000.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f);
	EnemyGoblinBrute goblinBack(8600.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f);
    World gameWorld;
	Village village;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here

		Monkey.handleUpdates(gameWorld, goblinFront);
        goblinFront.handleUpdates(Monkey, gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(Monkey.getCamera());


		gameWorld.handleWorld(goblinFront.getRectangle(), goblinFront.getCurrentCollisionTags(), goblinFront.getAirTime());
        gameWorld.handleWorld(Monkey.getRectangle(), Monkey.getCurrentCollisionTags(), Monkey.getTimeInAir());
        village.DrawVillageBackHouses();
        Monkey.handlePlayerVisuals();
        goblin.handleEnemy();
        village.DrawVillageFrontHouses();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}