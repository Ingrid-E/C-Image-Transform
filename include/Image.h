/** 
 * @file Image.h
 * @brief Creates an array of the image and gets values.
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @date 1/12/20
 * @version 1.0
*/

#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <iostream>
#include <string>
#include "File.h"
#include "ImageVector.h"
using namespace std;

class File;
class Image
{
private:
	int **aImage;
	int max;
	int height;
	int width;
	int type;
	int heightFile;
	int widthFile;
	string header;

	void setHeight(int height);
	void setWidth(int width);
	void initImage();

public:
	/**
	* @brief Construct a new Image object
	*/
	Image();

	/**
	* @brief Constructor
	* @param rows 
	* @param cols 
	*/
	Image(int rows, int cols);
	/**
	* @brief Constructor
	* @param rows 
	* @param cols 
	* @param maxValue 
	*/

	Image(int rows, int cols, int maxValue);

	/**
	* @brief 
	* @param rows 
	* @param cols
	* @param maxValue
	* @param newHeightFile
	* @param newWidthFile
	* @param header
	*/
	Image(int rows, int cols, int maxValue, int newHeightFile, int newWidthFile, string header);

	/**
	* @brief Destroy the Image object
	*/
	~Image();

	/**
	* Gets the height of an image
	* @return  height
	*/
	int getHeight();

	/**
	* Gets the width of an image
	* @return  width
	*/
	int getWidth();

	/**
	* Gets the value of an x and y position of a matrix
	* @param x position x
	* @param y position y 
	* @return  a value into x and y position
	*/
	int getPixel(int x, int y);

	int getMax();

	/**
	* Sets a value into an x and y position for a matrix
	* @param x position x
	* @param y position y 
	* @param  value
	*/
	void setPixel(int x, int y, int value);

	/**
	* Sets a value into an x and y position for a matrix
	* @param x position x
	* @param y position y 
	* @param  channel
	*/
	void setPixel(int x, int y, int value, int channel);

	/**
	* Allows to save an image
	* 
	* @param path
	*/
	int saveImage(Image *imagen, string nombre, ImageVector original);

	/**
    * @brief Sets type;
    * @param type
	*/
	void setType(int type);
};
#endif
