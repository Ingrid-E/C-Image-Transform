#include "../include/Channel.h"
#include "../include/Image.h"
#include "../include/ImageVector.h"
#include "../include/ImageTools.h"
#include <vector>
#include <iostream>
using namespace std;

Channel::Channel()
{
}

Channel::~Channel()
{
}

bool Channel::hasRed(Image *picture, ImageVector original)
{

  vector<vector<int>> originalImg = original.getVector();

  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j = j + 3)
    {
      int red = originalImg[i][j];
      if (red != 0)
        return true;
      else
        return false;
    }
  }
};

bool Channel::hasGreen(Image *picture, ImageVector original)
{
  vector<vector<int>> originalImg = original.getVector();
  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 1; j < picture->getWidth(); j = j + 3)
    {
      int green = originalImg[i][j];
      if (green != 0)
        return true;
      else
        return false;
    }
  }
};

bool Channel::hasBlue(Image *picture, ImageVector original)
{
  vector<vector<int>> originalImg = original.getVector();
  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 2; j < picture->getWidth(); j = j + 3)
    {
      int blue = originalImg[i][j];
      if (blue != 0)
        return true;
      else
        return false;
    }
  }
};

bool Channel::isRGB(Image *picture, ImageVector original)
{
  vector<vector<int>> originalImg = original.getVector();
  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j += 3)
    {
      int red = originalImg[i][j];
      int green = originalImg[i][j + 1];
      int blue = originalImg[i][j + 2];
      if (red != 0 && green != 0 && blue != 0)
        return true;
      else
        return false;
    }
  }
};

int Channel::getRed()
{
  return this->red;
};

int Channel::getGreen()
{
  return this->green;
};

int Channel::getBlue()
{
  return this->blue;
};

void Channel::setRed(int red)
{
  this->red = red;
};

void Channel::setGreen(int green)
{
  this->green = green;
};

void Channel::setBlue(int blue)
{
  this->blue = blue;
};
