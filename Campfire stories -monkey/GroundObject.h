#pragma once
#include "raylib.h"

struct GroundObject {
	Rectangle groundBox;
	const std::string TAG;
	Texture2D groundTexture;

	GroundObject() = default;

	GroundObject(const float& x, const float& y, const float& width, const float& height, const std::string& tag, const Texture2D groundTexture)
		: groundBox{ x, y, width, height }, TAG{ tag }, groundTexture(groundTexture)
	{}
	void drawObject()const {
		DrawRectangleLinesEx(groundBox, 3, BLUE);// to see the box
		DrawTextureRec(groundTexture, groundBox, { groundBox.x,groundBox.y }, WHITE);

	}
	Rectangle& getRectangle() { return this->groundBox; }
	std::string getTag() const { return this->TAG; }

};
