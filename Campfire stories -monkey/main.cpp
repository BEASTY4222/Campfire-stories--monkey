#include <iostream>

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "World.h"

int main() {
    // Initialization
    SetTraceLogLevel(LOG_ALL);
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Campfire stories: Monkey");

    SetTargetFPS(60);  // Set the game to run at 60 frames per second

    //INIT ONLY AFTER THE INITS FOR THE WINDOW FOR TEXTURES TO WORK GOOD
    // SO VRAM RESCOURSEC COULD BE LOADED

    PlayerMonkey Monkey;
    //          hp(hp), speed(speed), damage(damage), enemyBox{ x, y, width, hegiht }
	Enemy enemy1(1500.0f, 600.0f, 80.0f, 150.0f, 100.0f, 2.0f, 10.0f);
    World gameWorld;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here

		Monkey.handleUpdates(gameWorld, enemy1);
		enemy1.handleUpdates(Monkey, gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(Monkey.getCamera());


		gameWorld.handleWorld(enemy1.getRectangle(), enemy1.getCurrentCollisionTags(), enemy1.getAirTime());
        gameWorld.handleWorld(Monkey.getRectangle(), Monkey.getCurrentCollisionTags(), Monkey.getTimeInAir());
        Monkey.handlePlayerVisuals();
		enemy1.handleEnemy();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}