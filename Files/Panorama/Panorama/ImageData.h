#ifndef IMAGEDATA_H
#define IMAGEDATA_H

class ImageData{
	private:
		int numRows;
		int numCols;
		int** redValues;
		int** greenValues;
		int** blueValues;

	public:
		/**
		 * Constructor
		*/
		ImageData();
		/**
		 * Destructor
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
		int** getRedValues();
		/**
		 * Obtiene una matriz de verdes
		 * @return  greenValues[][]
		*/
		int** getGreenValues();
		/**
		 * Obtiene una matriz de azules
		 * @return  blueValues[][]
		*/
		int** getBlueValues();


};
#endif
