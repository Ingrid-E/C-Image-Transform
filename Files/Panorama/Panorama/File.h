#ifndef FILA_H
#define FILA_H
using namespace std;
#include<iostream>
#include <fstream>
#include "Image.h"

class Image;
class File{
	private:

		string path;
		string name;
		string extension;

	public:
		/**
		 * Constructor
		*/
		File();
		/**
		 * Destructor
		*/
		~File();
		/**
		 * lee la imagen como un archivo .txt
		 * @param path
		*/
		void readFile(string nombre);
		/**
		 * escribe un archivo .txt que es una imagen
		 * @param path
		*/
		void writeFile(Image* imagen, string nombre);

		string getName();
		void setName(string name);

};
#endif
