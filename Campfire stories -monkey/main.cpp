#include <iostream>

#include "raylib.h"
#include "Player.h"
#include "World.h"

int main() {
    // Initialization
    const int screenWidth = 1920;
    const int screenHeight = 1080;

	PlayerMonkey Monkey;
	World gameWorld;

    InitWindow(screenWidth, screenHeight, "Campfire stories: Monkey");

    SetTargetFPS(60);  // Set the game to run at 60 frames per second

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Update
        // Update variables here

		Monkey.handleUpdates(gameWorld);

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode2D(Monkey.getCamera());

        gameWorld.handleWorld(Monkey.getRectangle());
        Monkey.handlePlayer();


        EndMode2D();
        EndDrawing();
    }


    // De-Initialization
    CloseWindow();

    return 0;
}