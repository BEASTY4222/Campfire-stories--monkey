#pragma once
#include "raylib.h"

struct GroundObject {
	Rectangle groundBox;
	Color groundColor;// later change to image or texture
	const std::string TAG;;

	GroundObject() 
		: groundBox{0, 0, 0, 0}, groundColor{0, 0, 0, 255}, // Default values
		TAG{ "---" }
	{}

	GroundObject(float x, float y, float width, float height, Color color, std::string tag) : groundBox{ x, y, width, height },
		groundColor(color), TAG{ tag }
	{}
	void drawObject() const {
		DrawRectangleRec(this->groundBox, this->groundColor);
	}
	Rectangle& getRectangle() { return this->groundBox; }
	std::string getTag() const { return this->TAG; }

};