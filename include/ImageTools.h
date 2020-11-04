/** 
 * @file ImageTools.h
 * @brief
 * @author: Andres David Camargo Arcos
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Sombrilla Perez
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @version 1.0 1/12/20
*/

#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H
#include "Image.h"
#include "ImageVector.h"

class ImageTools
{

public:
	/**
		 * @brief Construct a new ImageTools object
		*/
	ImageTools();
	/**
		 * @brief Destroy the ImageTools object
		*/
	~ImageTools();

	/**
		 * @brief scales a picture to convert into a black and white *colors
		 * @params Image ImageVector bidimensional arrays 
		*/
	int toGray(Image *picture, ImageVector original);
	/**
		 * @brief scales a picture to convert into a negative colors
		 * @params Image ImageVector bidimensional arrays
		*/
	int toNegative(Image *picture);
	/**
		 * @brief scales a picture to convert into sephia tones
		 * @params Image ImageVector bidimensional arrays
		*/
	int toSephia(Image *picture, ImageVector original);
	/**
		 * @brief scales a picture to reverse these colors
		 * @params Image ImageVector bidimensional arrays
		*/
	void reverse(Image *picture, ImageVector original);
	/**
		 * @brief scales a picture to cause an mirror effect into it
		 * @params Image ImageVector bidimensional arrays
		*/
	void mirror(Image *picture, ImageVector original);
	/**
		 * @brief scales a picture to apply a one tone to these pixels
		 * @params Image ImageVector bidimensional arrays
		*/
	int toColor(Image *picture, ImageVector original);
	/**
     * @brief allow to put a picture over other picture
		 * @params Image Image bidimensional arrays
		*/
	void sobrePoner(Image *front, Image *back);
};
#endif
