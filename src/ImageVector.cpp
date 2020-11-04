#include "../include/ImageVector.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

ImageVector::ImageVector()
{
  this->fileName = "";
  this->image;
  this->rows = 0;
  this->columns = 0;
  this->width = 0;
  this->height = 0;
  this->maxRGB = 0;
  this->header = "";
  this->matrixStart = 0;
}

ImageVector::ImageVector(string fileName)
{
  this->fileName = fileName;
  this->image;
  this->rows = 0;
  this->columns = 0;
  this->width = 0;
  this->height = 0;
  this->maxRGB = 0;
  this->header = "";
  this->matrixStart = 0;
  this->start();
  this->convertToVector();
}

ImageVector::~ImageVector() {}

int ImageVector::getRows()
{
  return this->rows;
}

int ImageVector::getColumns()
{
  return this->columns;
}

int ImageVector::getHeight()
{
  return this->height;
}

int ImageVector::getWidth()
{
  return this->width;
}

int ImageVector::getMaxRGB()
{
  return this->maxRGB;
}

void ImageVector::start()
{
  ifstream file;
  file.open(this->fileName);
  string line;

  while (getline(file, line))
  {
    this->rows++; //Counts the rows.

    if (this->rows == 1 && line[0] == 'P')
    {
      this->header = line;
    }
    if (this->rows == 2 && line[0] != '#' && !line.empty())
    {
      string widthString = line.substr(0, line.find(" ") + 1);              //Gets the first number
      string heightString = line.substr(line.find(" ") + 1, line.length()); //Gets the second number

      this->width = stod(widthString);   //Converts the string to a number
      this->height = stod(heightString); //Converts the string to a number
    }
    if (this->rows == 3) //Line that contains the width and height
    {
      if (line.length() <= 3)
      {
        this->maxRGB = stod(line);
        matrixStart = 3;
      }
      else
      {

        string widthString = line.substr(0, line.find(" ") + 1);              //Gets the first number
        string heightString = line.substr(line.find(" ") + 1, line.length()); //Gets the second number

        this->width = stod(widthString);   //Converts the string to a number
        this->height = stod(heightString); //Converts the string to a number
      }
    }

    if (this->rows == 4) //Line that contains the max RGB value
    {
      if (line.length() <= 3)
      {
        this->maxRGB = stod(line); //turns line strinf to
        matrixStart = 4;
      }
    }

    int fileColumns = 0;

    for (int i = 0; i < line.length(); i++)
    {
      if (line[i] == ' ')
      {
        fileColumns++; //Counts the columns
      }
      if (fileColumns >= columns)
      {
        this->columns = fileColumns;
      }
    }
  }

  this->columns;
  //Rows - 4 because the first 4 lines don't count for the matrix.
  this->rows = this->rows - matrixStart;
}

void ImageVector::convertToVector()
{
  ifstream file(this->fileName.c_str());
  string line;
  for (int i = 0; i < this->rows + matrixStart; i++)
  {
    vector<int> row;
    string line;
    getline(file, line);
    stringstream spliter(line);
    string columnValue;
    if (i >= 4)
    {
      while (getline(spliter, columnValue, ' '))
      {
        row.push_back(stoi(columnValue));
      }
      this->image.push_back(row);
    }
    if (i == rows - 1)
    {

    }
  }
}

vector<vector<int>> ImageVector::getVector()
{
  return this->image;
}

string ImageVector::getHeader()
{
  return this->header;
}