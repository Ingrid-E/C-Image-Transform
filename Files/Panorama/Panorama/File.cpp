#include "File.h"



File::File(){
	
}

File::~File(){

}

void File:: readFile(string nombre){
	ifstream archivo;
	string linea;
	archivo.open(nombre,ios::in);
	if(archivo.fail()){
		cout<<"El archivo no abrio."<<endl;
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,linea);
		cout<<linea<<endl;
	}
	archivo.close();
}

void File:: writeFile(Image* imagen, string nombre){
	int alto;
	int ancho;
	int valorMaximo;
	alto=imagen->getHeight();
	ancho=imagen->getWidth();
	valorMaximo=imagen->getMax();
	ofstream archivo;
	archivo.open(nombre,ios::out);
	if(archivo.fail()){
		cout<<"Error no abrio el archivo"<<endl;
		exit(1);
	}
	archivo<<alto<<" "<<ancho<<endl;
	archivo<<valorMaximo<<endl;
	for(int i=0;i<alto;i++){
		for(int j=0;j<ancho;j++){
			if(imagen->getPixel(i,j)<=7){
				imagen->setPixel(i,j,7);
			}
			else{
				imagen->setPixel(i,j,15);
			}
			archivo<<imagen->getPixel(i,j); 
		}
		archivo<<endl;
	}
	archivo.close();
}

	string File:: getName(){
		return this->name;
	}

	void File:: setName(string name){
		this->name=name;
	}