#pragma once
#include "raylib.h"

class GroundObject {
	Rectangle groundBox;
	Color groundColor;// later change to image or texture
	const std::string TAG;;

public:
	GroundObject() 
		: groundBox{0, 0, 0, 0}, groundColor{0, 0, 0, 255}, // Default values
		TAG{ "GROUND_OBJECT" }
	{}

	GroundObject(float x, float y, float width, float height, Color color) :groundBox{ x, y, width, height },
			groundColor(color) 
	{}
	void drawObject() const {
		DrawRectangleRec(this->groundBox, this->groundColor);
	}
	Rectangle& getRectangle() {
		return this->groundBox;
	}

};