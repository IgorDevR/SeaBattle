#include <array>
#include "DeclarationFunc.h"

void SortCoordinates (array<int, 6>& coordInt)
{
	int X1 = min(coordInt[0], coordInt[3]);//0 1_3 4
	int Y1 = min(coordInt[1], coordInt[4]);
	int X2 = max(coordInt[0], coordInt[3]);
	int Y2 = max(coordInt[1], coordInt[4]);

	coordInt[0] = X1;
	coordInt[1] = Y1;
	coordInt[3] = X2;
	coordInt[4] = Y2;
	
}

void ConverterCoord(array<int, 6>& coord)
{

	coord[0] = coord[0] - 48;
	coord[1] = coord[1] - 65;
	coord[3] = coord[3] - 48;
	coord[4] = coord[4] - 65;
}