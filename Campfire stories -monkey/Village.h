#include "raylib.h"

class Village {
private:
	// Houses
	Texture2D greenRoofHouseTexture;
	Texture2D woodenStandTexture;
	Texture2D woodenstallTexture;
	Texture2D tatchRoofHouseTexture;
	Texture2D woodenHouseTexture;
	Texture2D greenRoofHouseTexture2;
	Texture2D chimneyHouseTexture;
	Texture2D blackSmithHouseTexture;
	Texture2D stoneTowerTexture;
	Texture2D grassRoofHouse;

	// Villagers
	Texture2D deadOldManTexture;
	Texture2D deadOldWomanTexture;
	Texture2D deadManTexture;
	Texture2D deadWomanTexture;
	Texture2D deadBoyTexture;
	Texture2D deadGirlTexture;

	Texture2D boyTexture;

public:
	Village();
	void DrawVillageBackHouses();
	void DrawVillageFrontHouses();
};