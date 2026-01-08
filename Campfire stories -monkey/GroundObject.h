#pragma once
#include "raylib.h"

struct GroundObject {
	Rectangle groundBox;
	const std::string TAG;
	Texture2D groundTexture;

	GroundObject() = default;

	GroundObject(const float& x, const float& y, const float& width, const float& height, const std::string& tag)
		: groundBox{ x, y, width, height }, TAG{ tag }, groundTexture(groundTexture)
	{}
	void drawObject(int times) {
		DrawRectangleLinesEx(groundBox, 3, BLUE);// to see the box
		float spacebetween = groundBox.x;
		while (times--) {
			DrawTexture(groundTexture, spacebetween, groundBox.y-250, WHITE);
			spacebetween += groundBox.width;
		}

	}
	void setTexture(const Texture2D groundTexture) { this->groundTexture = groundTexture; }
	Rectangle& getRectangle() { return this->groundBox; }
	std::string getTag() const { return this->TAG; }

};
