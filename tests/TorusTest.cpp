#include "pch.h"
#include "../src/Torus.h"

// When templetized class has its implementation outside header file we have to give info to linker where to find instructions for
// calling templetized methods
#include "../src/Torus.cpp"

TEST(TorusNumberOfPointsTest, TorusTest) {
	std::vector<int> testedDensities = { 1, 2, 10, 50, 71, 100 };
	for (const int density : testedDensities) {
		Torus torus = Torus(3, 2, density);
		EXPECT_EQ(density * density, torus.getPoints().size());
	}
}