#pragma once
#include "raylib.h"

struct GroundObject {
	Rectangle groundBox;
	Color groundColor;// later change to image or texture
	const std::string TAG;
	Texture2D groundTexture;

	GroundObject() 
		: groundBox{0, 0, 0, 0}, groundColor{0, 0, 0, 255}, // Default values
		TAG{ "---" }, groundTexture()
	{}

	GroundObject(float x, float y, float width, float height, std::string tag, Texture2D groundTexture) : groundBox{ x, y, width, height },
		 TAG{ tag }, groundTexture(groundTexture)
	{}
	void drawObject() const {
		DrawTexture(groundTexture, groundBox.x, groundBox.y, WHITE);
	}
	Rectangle& getRectangle() { return this->groundBox; }
	std::string getTag() const { return this->TAG; }

};