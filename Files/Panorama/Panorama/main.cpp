#include "Image.h"
#include <iostream>
using namespace std;

int main(){
	int matImg[7][24] = {
		{15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{8,3,3,3,3,0,0,7,7,7,7,0,0,11,11,11,11,0,0,15,15,15,15,0},
		{0,3,0,0,0,0,0,7,0,0,0,0,0,11,0,0,0,0,0,15,0,0,15,0},
		{0,3,3,3,0,0,0,7,7,7,0,0,0,11,11,11,0,0,0,15,15,15,15,0},
		{0,3,0,0,0,0,0,7,0,0,0,0,0,11,0,0,0,0,0,15,0,0,0,0},
		{0,3,0,0,0,0,0,7,7,7,7,0,0,11,11,11,11,0,0,15,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}  
	};

	Image * img = new Image(4, 4, 15);

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			img->setPixel(i, j, matImg[i][j]);
		}
	}

	string nombreArchivo;
	cout<<"Digite el nombre con el que desea guardar su archivo añadiendo .pgm al final:";
	cin>>nombreArchivo;

	img->saveImage(img, nombreArchivo);

	cout <<"Height: "<<img->getHeight()<<endl
		 <<" width: "<<img->getWidth()<<endl;

	File* archi=new File();
	archi->readFile(nombreArchivo);

	return 0;
}
