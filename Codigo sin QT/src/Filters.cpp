#include "Filters.h"
#include "File.h"
#include "mainwindow.h"
#include <iostream>
using namespace std;

Filters::Filters()
{
    this->rgbCounter=0;
}

Filters::Filters(File &obj, int filter, int value)
{
    this->image = obj.getPicture();
    this->copyImg = this->image;
    this->maxRGB = obj.getMaxRGB();
    this->rgbCounter=0;
    this->isGrey = false;
    this->isBlacknWhite();
    switch (filter)
    {
    case 1:
        this->normal();
        break;
    case 2:
        this->toGrey();
        break;
    case 3:
        this->toNegative();
        break;
    case 4:
        this->toSephia();
        break;
    case 5:
        this->toTone(value);
        break;
    case 6:
        this->flip();
        break;
    case 7:
        this->toColor();
        break;
    case 8:
        this->threshold();
        break;
    default:
        break;
    }
}


Filters::Filters(File &obj, File &obj2)
{
    this->image = obj.getPicture();
    this->secondImage = obj2.getPicture();
    this->maxRGB = obj.getMaxRGB();
    this->rgbCounter=0;
    this->overLay();

}

void Filters::normal()
{
    int imageRows = this->image.size();
    for(int rows = 0; rows<imageRows; rows++)
    {
        int imageColumns = this->image[rows].size();
        for(int columns = 0; columns < imageColumns; columns++)
        {
            this->image[rows][columns] = this->copyImg[rows][columns];
        }
    }
}

void Filters::overLay(){

    int imageRows = this->image.size();
    for(int rows = 0; rows < imageRows; rows++)
    {
        int secondImgRows = this->secondImage.size();
        if(rows > secondImgRows)
        {
            this->secondImage.push_back(this->image[rows]);
        }
        else
        {

            int imageColumns = this->image[rows].size();
            int secondImgColumns = this->secondImage[rows].size();
            for(int columns = 0; columns < imageColumns; columns++)
            {
                if(columns > secondImgColumns)
                {
                    int greenValue = 0;
                    if(rgbCounter == 0) greenValue = 0;
                    if(rgbCounter == 1) greenValue = 255;
                    if(rgbCounter == 2)
                    {
                        greenValue = 0;
                        rgbCounter = 0;
                    }
                    this->secondImage[rows].push_back(greenValue);
                }
                rgbCounter++;
            }
        }
    }
    for(int rows = 0; rows < imageRows; rows++)
    {
        int imageColumns = this->secondImage[rows].size();
        for(int columns = 0; columns<imageColumns; columns++)
        {
            int red = this->secondImage[rows][columns] ;
            int green = this->secondImage[rows][columns+1];
            int blue = this->secondImage[rows][columns+2];
            if((red != 0 && green != 255 && blue!= 0) || (red == 255 && green == 255 && blue == 255))
            {
                this->image[rows][columns] = this->secondImage[rows][columns];
                this->image[rows][columns+1] = this->secondImage[rows][columns+1];
                this->image[rows][columns+2] = this->secondImage[rows][columns+2];
            }else{

            }
            columns = columns+2;
        }
    }
}

void Filters::flip()
{
    int imageRows = this->image.size();
    for(int rows = 0; rows < imageRows; rows++)
    {
        int imageColumns =  this->image[rows].size();
        for(int columns = 0; columns < imageColumns; columns++ )
        {
            int red = copyImg[rows][imageColumns - 3 - columns];
            int green = copyImg[rows][imageColumns - 2 - columns];
            int blue = copyImg[rows][imageColumns - 1 - columns];
            this->image[imageRows-1-rows][columns] = red;
            this->image[imageRows-1-rows][columns+1] = green;
            this->image[imageRows-1-rows][columns+2] = blue;
            columns = columns + 2;
        }
    }
}


Filters::~Filters(){}

void Filters::threshold()
{
    int largest = 0;
    int imageRows = this->image.size();
    for(int rows = 0; rows < imageRows; rows++)
    {
        int imageColumns = this->image[rows].size();
        for(int columns = 0; columns < imageColumns; columns++)
        {
            int red = this->image[rows][columns];
            int green = this->image[rows][columns+1];
            int blue = this->image[rows][columns+2];

            if(red > green && red > blue){
                largest = red;
            }else if(green > red && green > blue){
                largest = green;

            }else if(blue > red && blue > green){
                largest = blue;

            }else if(red == green || red == blue || green == blue){
                largest = red;
            }

            if(largest>127)
            {
                this->image[rows][columns] = 255;
                this->image[rows][columns+1] = 255;
                this->image[rows][columns+2] = 255;
            }
            else
            {
                this->image[rows][columns] = 0;
                this->image[rows][columns+1] = 0;
                this->image[rows][columns+2] = 0;
            }

            columns = columns + 2;
        }


    }



}

void Filters::toGrey()
{
    int imageSize = this->image.size();
    for(int i=0; i<imageSize; i++)
    {
        int columnsSize =this->image[i].size();
        for(int j=0; j<columnsSize; j++)
        {
            int red = this->image[i][j];
            int green = this->image[i][j+1];
            int blue = this->image[i][j+2];
            int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
            this->image[i][j] = gray;
            this->image[i][j+1] = gray;
            this->image[i][j+2] = gray;
            j = j + 2;
        }
    }
}

void Filters::toNegative(){
    int imageSize = this->image.size();
    for(int i=0; i<imageSize; i++)
    {
        int columnsSize =this->image[i].size();
        for(int j=0; j<columnsSize; j++)
        {
            if(this->image[i][j] == 0)
            {
                this->image[i][j] = maxRGB;
            }
            else if(this->image[i][j] == maxRGB)
            {
                this->image[i][j] = 0;
            }
            else
            {
                int negative = maxRGB - this->image[i][j];
                this->image[i][j] = negative;
            }
        }
    }
}

void Filters::toSephia()
{
    int imageSize = this->image.size();
    for(int i=0; i<imageSize; i++)
    {
        int columnsSize =this->image[i].size();
        for(int j=0; j<columnsSize; j++)
        {
            int red = this->image[i][j];
            int green = this->image[i][j+1];
            int blue = this->image[i][j+2];
            int tr = 0.393 *red+ 0.769 *green+ 0.189 *blue;
            if (tr >= maxRGB)
            {
                tr = maxRGB;
            }
            int tg = 0.349 *red+ 0.686 *green+ 0.168 *blue;
            if (tg >= maxRGB)
            {
                tg = maxRGB;
            }
            int tb = 0.272 *red+ 0.534 *green+ 0.131 *blue;
            if (tb >= maxRGB)
            {
                tb = maxRGB;
            }
            this->image[i][j] = tr;
            this->image[i][j+1] = tg;
            this->image[i][j+2] = tb;
            j = j + 2;
        }
    }
}

void Filters::toTone(int color)
{

  vector<vector<int>> colorTone = {{0,0,0},{91, -99, -14}, {-115, -86, -23},{-72,75,-77}};
  int imageSize = this->image.size();
  for (int i = 0; i < imageSize; i++)
  {
    int columnsSize =this->image[i].size();
    for (int j = 0; j < columnsSize; j++)
    {
      int red = this->image[i][j];
      int green = this->image[i][j + 1];
      int blue = this->image[i][j + 2];

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
      this->image[i][j] = toneR;
      this->image[i][j+1] = toneG;
      this->image[i][j+2] = toneB;
      j = j + 2;
    }
  }
}


bool Filters::isBlacknWhite()
{
    int imageSize = this->image.size();
    for (int i = 0; i < imageSize; i++)
    {
      int columnsSize =this->image[i].size();
      for (int columns = 0; columns < columnsSize; columns++)
      {
        bool redGrey = this->copyImg[rows][columns] >= 0 && this->copyImg[rows][columns] <= 150;
        bool greenGrey = this->copyImg[rows][columns+1] >= 0 && this->copyImg[rows][columns+1] <= 150;
        bool blueGrey = this->copyImg[rows][columns+2] >= 0 && this->copyImg[rows][columns+2] <= 150;
        if(redGrey & greenGrey & blueGrey)
        {
            isGrey = true;
        }
        else
        {
            isGrey = false;
            break;
        }

      }
    }
    return isGrey;
}


void Filters::toColor(){
    if(this->isGrey){
        int imageSize = this->image.size();
        for (int rows = 0; rows < imageSize; rows++)
        {
            int columnsSize =this->image[rows].size();
            for (int columns = 0; columns < columnsSize; columns++)
            {
                int r = copyImg[rows][columns]/50;
                int g = copyImg[rows][columns + 1]/40;
                int b = copyImg[rows][columns + 2]/30;
                this->image[rows][columns] = copyImg[rows][columns]*r;
                this->image[rows][columns+1] = copyImg[rows][columns+1]*g;
                this->image[rows][columns+2] = copyImg[rows][columns+2]*b;
                columns = columns+2;
            }
        }
    }
    else
    {

    }
}



vector<vector<int>> Filters::getFiltered()
{
    return this->image;
}
