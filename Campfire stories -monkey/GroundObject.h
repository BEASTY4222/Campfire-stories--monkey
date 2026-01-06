#pragma once
#include "raylib.h"

struct GroundObject {
	Rectangle groundBox;
	const std::string TAG;
	Texture2D groundTexture;

	GroundObject() 
		: groundBox{0, 0, 0, 0}, // Default values
		TAG{ "---" }, groundTexture()
	{}

	GroundObject(const float& x, const float& y, const float& width, const float& height, const std::string& tag, const Texture2D groundTexture)
		: groundBox{ x, y, width, height }, TAG{ tag }, groundTexture(groundTexture)
	{}
	void drawObject(const float &x)const {
		//DrawTexture(startingForestGroundTexture, spaceBetween, 680.0f, WHITE);
		DrawTexture(groundTexture, x, groundBox.y, WHITE);
	}
	Rectangle& getRectangle() { return this->groundBox; }
	std::string getTag() const { return this->TAG; }

};
