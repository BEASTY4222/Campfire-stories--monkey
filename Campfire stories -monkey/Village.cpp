#include "Village.h"

Village::Village() {
	greenRoofHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_1/building_1.png");
	woodenStandTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_2/building_1.png");
	woodenstallTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_3/building_1.png");
	tatchRoofHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_5/building_1.png");
	woodenHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_6/building_1.png");
	greenRoofHouseTexture2 = LoadTexture("spritesWorld/village/PNG/buildings/building_7/building_1.png");
	// foreground houses
	chimneyHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_9/building_1.png");
	blackSmithHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_10/building_1.png");
	stoneTowerTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_12/building_1.png");

}

void Village::DrawVillageBackHouses() {
	DrawTexture(greenRoofHouseTexture, 7000.0f, 550.0f, WHITE);
	DrawTexture(woodenStandTexture, 7330.0f, 550.0f, WHITE);
	DrawTexture(woodenstallTexture, 7710.0f, 550.0f, WHITE);
	DrawTexture(tatchRoofHouseTexture, 8120.0f, 550.0f, WHITE);
	DrawTexture(woodenHouseTexture, 8650.0f, 420.0f, WHITE);
	DrawTexture(greenRoofHouseTexture2, 9200.0f, 430.0f, WHITE);
	DrawTexture(blackSmithHouseTexture, 9650.0f, 520.0f, WHITE);
	DrawTexture(stoneTowerTexture, 11000.0f, 130.0f, WHITE);


}
void Village::DrawVillageFrontHouses() {
	DrawTexture(chimneyHouseTexture, 8150.0f, 800.0f, Fade(WHITE, 0.5f));

}