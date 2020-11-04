/** 
 * @file File.h
 * @brief Reads and writes the image.
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @date 1/12/20
 * @version 1.0
*/

#ifndef FILA_H
#define FILA_H
using namespace std;
#include <iostream>
#include <fstream>
#include "Image.h"
#include "ImageVector.h"

class Image;
class File
{
private:
	string path;
	string name;
	string extension;
	int width;
	int height;
	string header;

public:
	/**
	* @brief Construct a new File object
	*/
	File(int width, int height, string header);
	File();
	/**
	* @brief Destroy the File object
	*/
	~File();

	/**
	* @brief Read a file like an txt
	* @param nombre
	*/
	void readFile(string nombre);

	/**
	* @brief writes a txt file composed by pixels
	* @param imagen
    * @param nombre
	*/
	void writeFile(Image *imagen, string nombre, ImageVector original);
	/**
	 * @brief Get the Name object
	 * 
	 * @return string 
	 */
	string getName();
	/**
	 * @brief Set the Name object
	 * 
	 * @param name 
	 */
	void setName(string name);
};
#endif
