#include "Village.h"

Village::Village() {
	// Houses	
	greenRoofHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_1/building_1.png");
	woodenStandTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_2/building_1.png");
	woodenstallTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_3/building_1.png");
	tatchRoofHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_5/building_1.png");
	woodenHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_6/building_1.png");
	greenRoofHouseTexture2 = LoadTexture("spritesWorld/village/PNG/buildings/building_7/building_1.png");
	chimneyHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_9/building_1.png");
	blackSmithHouseTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_10/building_1.png");
	stoneTowerTexture = LoadTexture("spritesWorld/village/PNG/buildings/building_12/building_1.png");
	grassRoofHouse = LoadTexture("spritesWorld/village/PNG/buildings/building_13/building_1.png");

	// Villagers
	deadOldManTexture= LoadTexture("spritesWorld/villagers/1Old_man/Old_man_death_last.png");
	deadOldWomanTexture = LoadTexture("spritesWorld/villagers/2Old_woman/Old_woman_death_last.png");
	deadManTexture = LoadTexture("spritesWorld/villagers/3Man/Man_death_last.png");
	deadWomanTexture = LoadTexture("spritesWorld/villagers/4Woman/Woman_death_last.png");
	deadBoyTexture = LoadTexture("spritesWorld/villagers/5Boy/Boy_death_last.png");
	deadGirlTexture = LoadTexture("spritesWorld/villagers/6Girl/Girl_death_last.png");

	boyTexture = LoadTexture("spritesWorld/villagers/5Boy/Boy.png");

}

void Village::DrawVillageBackHouses() {
	DrawTexture(greenRoofHouseTexture, 7000, 550, WHITE);
	DrawTexture(woodenStandTexture, 7330, 550, WHITE);
	DrawTexture(deadOldManTexture, 7440, 650, WHITE);

	DrawTexture(deadBoyTexture, 7330, 900, WHITE);

	DrawTexture(woodenstallTexture, 7710, 550, WHITE);
	DrawTexture(deadOldWomanTexture, 7840, 830, WHITE);

	DrawTexture(tatchRoofHouseTexture, 8120, 550, WHITE);
	DrawTexture(deadGirlTexture, 8600, 900, WHITE);
	DrawTexture(woodenHouseTexture, 8650, 420, WHITE);
	DrawTexture(deadWomanTexture, 8800, 650, WHITE);
	DrawTexture(deadOldManTexture, 9050, 950, WHITE);

	DrawTexture(greenRoofHouseTexture2, 9200, 430, WHITE);
	DrawTexture(blackSmithHouseTexture, 9650, 520, WHITE);
	DrawTexture(deadGirlTexture, 11000, 900, WHITE);
	DrawTexture(woodenStandTexture, 11000, 550, WHITE);
	DrawTexture(deadManTexture, 11100, 650, WHITE);

	DrawTexture(greenRoofHouseTexture2, 10600, 430, WHITE);
	DrawTexture(greenRoofHouseTexture, 10200, 550, WHITE);

	DrawTexture(deadManTexture, 10000,1000,WHITE);
	DrawTexture(deadWomanTexture, 10500, 1050,WHITE);


	DrawTexture(stoneTowerTexture, 12500.0f, 130.0f, WHITE);
	DrawTexture(boyTexture, 12900.0f, 900.0f, WHITE);
}
void Village::DrawVillageFrontHouses() {
	DrawTexture(chimneyHouseTexture, 8450.0f, 800.0f, Fade(WHITE, 0.5f));
	DrawTexture(woodenHouseTexture, 9000.0f, 700.0f, Fade(WHITE, 0.5f));
	DrawTexture(woodenstallTexture, 9510.0f, 750.0f, Fade(WHITE, 0.5f));
	DrawTexture(tatchRoofHouseTexture, 10000, 750.0f, Fade(WHITE, 0.5f));


}