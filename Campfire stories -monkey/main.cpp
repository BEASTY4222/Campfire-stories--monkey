#include <iostream>

#include "raylib.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyGoblinBrute.h"
#include "World.h"


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
    EnemyGoblinBrute goblin(1500.0f, 600.0f, 80.0f, 200.0f, 200.0f, 3.0f, 50.0f);
    World gameWorld;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here

		Monkey.handleUpdates(gameWorld, goblin);
        goblin.handleUpdates(Monkey, gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(Monkey.getCamera());


		gameWorld.handleWorld(goblin.getRectangle(), goblin.getCurrentCollisionTags(), goblin.getAirTime());
        gameWorld.handleWorld(Monkey.getRectangle(), Monkey.getCurrentCollisionTags(), Monkey.getTimeInAir());
        Monkey.handlePlayerVisuals();
        goblin.handleEnemy();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}