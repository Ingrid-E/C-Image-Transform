/** 
 * @file ImageData.h
 * @brief Creates a matrix of red, green and blue;
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @date 1/12/20
 * @version 1.0
*/

#ifndef IMAGEDATA_H
#define IMAGEDATA_H

class ImageData
{
private:
	int numRows;
	int numCols;
	int **redValues;
	int **greenValues;
	int **blueValues;

public:
	/**
		 * @brief Construct a new ImageData object
		*/
	ImageData();
	/**
		 * @brief Destroy a ImageData object
		*/
	~ImageData();
	/**
		 * Obtiene el numero de filas
		 * @return  numRows
		*/
	int getNumRows();
	/**
		 * Obtiene el numero de columnas
		 * @return  numCols
		*/
	int getNumCols();
	/**
		 * Obtiene una matriz de rojos
		 * @return  redValues[][]
		*/
	int **getRedValues();
	/**
		 * Obtiene una matriz de verdes
		 * @return  greenValues[][]
		*/
	int **getGreenValues();
	/**
		 * Obtiene una matriz de azules
		 * @return  blueValues[][]
		*/
	int **getBlueValues();
};
#endif
