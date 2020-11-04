/**
 * @file main.cpp
 * @brief : Receive an image and applies a filter to it. 
 * @author: Andres David Camargo Arcos
 * @author: Ingrid Echeverri Montoya
 * @author: Jhan Alejandro Sombrilla Perez
 * @author: Jean Pierre Cardenas Perea
 * @date 1/12/20
 * @version 1.0
*/

#include "../include/Image.h"
#include "../include/ImageVector.h"
#include "../include/ImageTools.h"
#include "../include/Channel.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

  cout << "Write the image file name to open with its extension (.ppm, .pgm, .txt), must be in images folder" << endl;
  string fileToOpen;
  cin >> fileToOpen;
  ImageVector imageVector("images/" + fileToOpen); 
  int rows = imageVector.getRows();
  int columns = imageVector.getColumns();
  int height = imageVector.getHeight();
  int width = imageVector.getWidth();
  int maxRGB = imageVector.getMaxRGB();
  string header = imageVector.getHeader();

  //Este es la variable que contiene el vector de la imagen.
  vector<vector<int>> vectorImagen = imageVector.getVector();

  //Aqui see crea la imagen con la clase del profe
  Image *img = new Image(rows, columns, maxRGB, width, height, header);

  //Los valores del vector imagen se ingresan al de image.

  for (int i = 0; i < vectorImagen.size(); i++)
  {
    for (int j = 0; j < vectorImagen[i].size(); j++)
    {
      img->setPixel(i, j, vectorImagen[i][j]);
    }
  }

  ImageTools picture;
  string extension = fileToOpen.substr(fileToOpen.find(".") + 1, fileToOpen.length());
  if (extension == "pgm")
  {
    cout << "No filters yet for .pgm" << endl;
  }
  else
  {
    cout << "Select a filter to apply: " << endl;
    cout << "1-Normal" << endl;
    cout << "2-Black and White" << endl;
    cout << "3-Negative" << endl;
    cout << "4-Sephia" << endl;
    cout << "5-Colorize" << endl;
    cout << "-> ";

    int filtro;
    cin >> filtro;
    switch (filtro)
    {
    case 1:
      picture;
      break;
    case 2:
      picture.toGray(img, imageVector);
      break;
    case 3:
      picture.toNegative(img);
      break;
    case 4:
      picture.toSephia(img, imageVector);
      break;
    case 5:
      picture.toColor(img, imageVector);
      break;
    default:
      picture;
    }
  }

  string fileName;
  cout << "Type the new file name with its extension (.pgm, .txt, .ppm) to save it: ";
  cin >> fileName;

  img->saveImage(img, fileName, imageVector);

  File *archi = new File();
  archi->readFile(fileName);

  return 0;
}
