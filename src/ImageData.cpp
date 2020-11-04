#include "../include/ImageData.h"

ImageData::ImageData()
{
	redValues = new int *[numRows];
	for (int i = 0; i < numRows; i++)
	{
		redValues[i] = new int[numCols];
	}

	greenValues = new int *[numRows];
	for (int i = 0; i < numRows; i++)
	{
		greenValues[i] = new int[numCols];
	}

	blueValues = new int *[numRows];
	for (int i = 0; i < numRows; i++)
	{
		blueValues[i] = new int[numCols];
	}
}

ImageData::~ImageData()
{
}

int ImageData::getNumRows()
{
	return this->numRows;
}

int ImageData::getNumCols()
{
	return this->numCols;
}

int **ImageData::getRedValues()
{
	return this->redValues;
}

int **ImageData::getGreenValues()
{
	return this->greenValues;
}

int **ImageData::getBlueValues()
{
	return this->blueValues;
}