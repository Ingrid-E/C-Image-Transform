#include "../include/File.h"
#include <string>

File::File(int width, int height, string header)
{
	this->width = width;
	this->height = height;
	this->header = header;
}

File::File()
{
}

File::~File()
{
}

void File::readFile(string nombre)
{

	ifstream archivo;
	string linea;
	archivo.open("images/" + nombre, ios::in);
	if (archivo.fail())
	{
		cout << "File couldn't be open." << endl;
		exit(1);
	}
	while (!archivo.eof())
	{
		getline(archivo, linea);
		cout << linea << endl;
	}
	archivo.close();
}

void File::writeFile(Image *imagen, string nombre, ImageVector original)
{

	int rows = imagen->getHeight();
	int columns = imagen->getWidth();
	vector<vector<int>> imageVector = original.getVector();
	int maxRGB = imagen->getMax();
	cout << "working" << endl;
	ofstream archive;
	archive.open("images/" + nombre, ios::out);

	if (archive.fail())
	{
		cout << "Error could not open archive" << endl;
		exit(1);
	}
	archive << this->header << endl;
	archive << endl;

	archive << this->width << " " << this->height << endl;

	archive << maxRGB << endl;
	for (int i = 0; i < imageVector.size(); i++)
	{
		for (int j = 0; j < imageVector[i].size(); j++)
		{
			archive << imagen->getPixel(i, j);
			archive << " ";
		}
		archive << endl;
	}
	archive.close();
}

string File::getName()
{
	return this->name;
}

void File::setName(string name)
{
	this->name = name;
}