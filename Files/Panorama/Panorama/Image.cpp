#include "Image.h"

Image::Image(){
}

Image::Image(int rows, int cols){ 
	this->max		=255; //comunmente es 255
	this->height	=rows;
	this->width	    =cols;
	this-> aImage   = new int*[rows];
	this->initImage();
}
Image::Image(int rows, int cols, int maxValue){ 
	this->max		=maxValue;
	this->height	=rows;
	this->width	    =cols;
	this-> aImage   = new int*[rows];
	this->initImage();
}
Image::~Image(){}

void Image::initImage(){
	for(int i=0;i<this->height;i++){
		this-> aImage[i] = new int[this->width];
	}
}

int Image::getHeight(){
	return this ->height;
}
void Image::setHeight(int height){
	this ->height = height;
}
int Image::getWidth(){
	return this ->width;
}
int Image:: getMax(){
	return this->max;
}

void Image::setWidth(int width){
	this ->width = width;
}
int Image::getPixel(int x, int y){
	int pixelValue;
	pixelValue = this->aImage[x][y];
	return pixelValue;
}
void Image::setPixel(int x, int y, int value){
	this-> aImage[x][y] = value;
}
void Image::setType(int type){
	this->type=type;
}

void Image::setPixel(int x, int y, int value, int channel){
	//TODO: falta implementarlo
}
int Image::saveImage(Image* imagen, string nombre){
	File* archivo = new File ();
	archivo->writeFile(imagen, nombre);
	return 0;
}
