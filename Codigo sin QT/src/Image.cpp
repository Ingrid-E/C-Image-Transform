#include "Image.h"
#include <iostream>
using namespace std;

Image::Image(){
    this->rows = 0;
    this->columns = 0;
    this->maxRGB = 0;
    this->name = " ";
}

Image::Image(string fileName){
    this->rows = 0;
    this->columns = 0;
    this->maxRGB = 0;
    this->name = fileName;
}

Image::~Image(){}

int Image::getRows(){
    return rows;
}

int Image::getColumns()
{
    return columns;
}

int Image::getMaxRGB()
{
    return maxRGB;
}

string Image::getName()
{
    return this->name;
}



