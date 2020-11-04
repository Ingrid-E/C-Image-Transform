/** 
 * @file Channel.h
 * @brief Check if it has colors.
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @date 1/12/20
 * @version 1.0
*/

#ifndef CHANNEL_H
#define CHANNEL_H

#include "Image.h"
#include "ImageVector.h"

class Channel
{
private:
	int red;
	int green;
	int blue;

public:
	/**
	* @brief Construct a new Channel object
	*/
	Channel();
	/**
	* @brief Destroy the Channel object
	*/
	~Channel();

	/**
	* @brief Checks if it has red
	* 
	* @param picture 
	* @param original 
	* @return true 
	* @return false 
	*/
	static bool hasRed(Image *picture, ImageVector original);

	/**
	* @brief Check if it has green
	* 
	* @param picture 
	* @param original 
	* @return true 
	* @return false 
	*/
	static bool hasGreen(Image *picture, ImageVector original);

	/**
	* @brief Check if it has blue
	* 
	* @param picture 
	* @param original 
	* @return true 
	* @return false 
	*/
	static bool hasBlue(Image *picture, ImageVector original);

	/**
	* @brief Check if it is RGB
	* 
	* @param picture 
	* @param original 
	* @return true 
	* @return false 
	*/
	bool isRGB(Image *picture, ImageVector original);

	/**
	* Gets the red part of the channel
	* @return  red
	*/
	int getRed();

	/**
	* Gets the green part of the channel
	* @return  green
	*/
	int getGreen();

	/**
	* Gets the blue part of the channel
	* @return  blue
	*/
	int getBlue();

	/**
	* Change a pixel of the red part of the channel
	* @param  red
	*/
	void setRed(int red);

	/**
	* change a pixel of the green part of the channel
	* @param  green
	*/
	void setGreen(int green);

	/**
	* Change a pixel of the blue part of the channel
	* @param  blue
	*/
	void setBlue(int blue);
};
#endif
