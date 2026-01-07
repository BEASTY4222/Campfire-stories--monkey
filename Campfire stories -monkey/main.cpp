#include <iostream>

#include "raylib.h"
#include "Player.h"
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
    World gameWorld;

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here

		Monkey.handleUpdates(gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(Monkey.getCamera());

        gameWorld.handleWorld(Monkey.getRectangle(), Monkey.getCurrentCollisionTags());
        Monkey.handlePlayer();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}