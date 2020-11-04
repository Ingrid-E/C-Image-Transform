#include "../include/ImageVector.h"
#include "../include/ImageTools.h"
#include <iostream>
#include <vector>
using namespace std;

ImageTools::ImageTools()
{
}

ImageTools::~ImageTools()
{
}

int ImageTools::toGray(Image *picture, ImageVector original)
{
  int counterRGB = 0;
  vector<vector<int>> originalImg = original.getVector();

  for (int i = 0; i < originalImg.size(); i++)
  {
    for (int j = 0; j < originalImg[i].size(); j++)
    {
      int red = originalImg[i][j];
      int green = originalImg[i][j + 1];
      int blue = originalImg[i][j + 2];

      int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;

      picture->setPixel(i, j, gray);
      picture->setPixel(i, j + 1, gray);
      picture->setPixel(i, j + 2, gray);
      j = j + 2;
    }
  }
  return 0;
}

int ImageTools::toNegative(Image *picture)
{

  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j++)
    {
      if (picture->getPixel(i, j) == 0)
      {
        picture->setPixel(i, j, picture->getMax());
      }
      else if (picture->getPixel(i, j) == picture->getMax())
      {
        picture->setPixel(i, j, 0);
      }
      else
      {
        int negativeValue = picture->getMax() - picture->getPixel(i, j);
        picture->setPixel(i, j, negativeValue);
      }
    }
  }
  return 0;
}

int ImageTools::toSephia(Image *picture, ImageVector original)
{

  int counterRGB = 0;
  vector<vector<int>> originalImg = original.getVector();
  int maxRGB = picture->getMax();
  for (int i = 0; i < originalImg.size(); i++)
  {
    for (int j = 0; j < originalImg[i].size(); j++)
    {

      int r = originalImg[i][j];
      int g = originalImg[i][j + 1];
      int b = originalImg[i][j + 2];

      int tr = 0.393 * r + 0.769 * g + 0.189 * b;
      if (tr >= maxRGB)
        tr = maxRGB;
      int tg = 0.349 * r + 0.686 * g + 0.168 * b;
      if (tg >= maxRGB)
        tg = maxRGB;
      int tb = 0.272 * r + 0.534 * g + 0.131 * b;
      if (tb >= maxRGB)
        tb = maxRGB;

      picture->setPixel(i, j, tr);
      picture->setPixel(i, j + 1, tg);
      picture->setPixel(i, j + 2, tb);

      j = j + 2;
    }
  }
  return 0;
}

void ImageTools::reverse(Image *picture, ImageVector original)
{
  int valueToReplace = 0;
  vector<vector<int>> originalImg = original.getVector();

  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j++)
    {
      valueToReplace = originalImg[j][i];
      picture->setPixel(i, j, valueToReplace);
    }
  }
}

//Colorize
int ImageTools::toColor(Image *picture, ImageVector original)
{
  int counterRGB = 0;
  vector<vector<int>> originalImg = original.getVector();
  //Pink = tonoColor[0], Blue = tonoColor[1],... more can be added.
  vector<vector<int>> colorTone = {{91, -99, -14}, {-115, -86, -23},{-72,75,-77}};

  cout << "Choose a Color: " << endl;
  cout << "0-Pink" << endl;
  cout << "1-Blue" << endl;
  cout << "2-Green" << endl;
  cout << "-> ";
  int color;
  cin >> color;

  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j++)
    {

      int red = originalImg[i][j];
      int green = originalImg[i][j + 1];
      int blue = originalImg[i][j + 2];

      int toneR = colorTone[color][0] + red;
      int toneG = colorTone[color][1] + green;
      int toneB = colorTone[color][2] + blue;
      if (toneR <= 0)
        toneR = 0;
      if (toneR >= 255)
        toneR = 255;
      if (toneG <= 0)
        toneG = 0;
      if (toneG >= 255)
        toneG = 255;
      if (toneB <= 0)
        toneB = 0;
      if (toneB >= 255)
        toneB = 255;

      picture->setPixel(i, j, toneR);
      picture->setPixel(i, j + 1, toneG);
      picture->setPixel(i, j + 2, toneB);
      j = j + 2;
    }
  }
  return 0;
}

/*

***********************************************************      IN PROCESS ****************************************************************

//mirror
void ImageTools::mirror(Image *picture, ImageVector original)
{
  int valueToReplace = 0;
  vector<vector<int>> originalImg = original.getVector();

  for (int i = 0; i < picture->getHeight(); i++)
  {
    for (int j = 0; j < picture->getWidth(); j++)
    {
      int newB = originalImg[i][original.getColumns() - 1 - j];
      int newG = originalImg[i][original.getColumns() - 2 - j];
      int newR = originalImg[i][original.getColumns() - 3 - j];
      picture->setPixel((picture->getHeight()) - 1 - i, j, newR);
      picture->setPixel((picture->getHeight()) - 1 - i, j + 1, newG);
      picture->setPixel((picture->getHeight()) - 1 - i, j + 2, newB);
      j = j + 2;
    }
  }
}

void ImageTools::sobrePoner(Image *front, Image *back)
{
  for (int i = 0; i < front->getHeight(); i++)
  {
    for (int j = 0; j < front->getWidth(); j++)
    {
      int r = front->getPixel(i, j);
      int g = front->getPixel(i, j + 1);
      int b = front->getPixel(i, j + 2);
      if (r != 15 && g != 255 && b != 2)
      {
        back->setPixel(i, j, r);
        back->setPixel(i, j + 1, g);
        back->setPixel(i, j + 2, b);
      }
      j = j + 2;
    }
  }
}

*/