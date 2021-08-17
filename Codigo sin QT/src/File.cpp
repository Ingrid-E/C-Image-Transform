#include "File.h"
#include "Image.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <QDir>
using namespace std;

File::File()
{
    this->extension = ".";
    this->width = 0;
    this->height = 0;
    this->header = " ";
    this->matrixStart = 0;
    this->maxIntensity = 0;
}

File::File(string fileName)
{
    this->name = fileName;

    this->extension = fileName.substr(fileName.find("."), fileName.length());
    this->width = 0;
    this->height = 0;
    this->header = " ";
    this->matrixStart = 0;
    this->maxIntensity = 0;
    this->getFileValues();
    this->convertToVector();
}

File::~File(){}

void File::readFile()
{
    ifstream imageFile;
    string line;
    imageFile.open(this->name, ios::in);
    if(imageFile.fail())
    {
        cout << "File couldn't be openend" << endl;
        exit(1);
    }
    while(!imageFile.eof())
    {
        getline(imageFile, line);
        cout << line << endl;
    }
    imageFile.close();
}

void File::getFileValues()
{
    ifstream imageFile;
    string line;
    imageFile.open(this->name, ios::in);
    while(getline(imageFile,line))
    {
        rows++;
        if(rows == 1 && line[0] == 'P')
        {
            this->header = line;
        }
        if(rows == 2 && line[0] != '#' && !line.empty())
        {
            this->width = stod(line.substr(0, line.find(" ")+1));
            this->height = stod(line.substr(line.find(" ")+1,line.length()));
        }
        if(rows == 3)
        {
            if(line.length() <= 3)
            {
                maxRGB = stod(line);
                matrixStart = 3;
            }
            else
            {
                this->width = stod(line.substr(0, line.find(" ")+1));
                this->height = stod(line.substr(line.find(" ")+1,line.length()));
            }
        }
        if(rows == 4 && line.length() <=3)
        {
            maxRGB = stod(line);
            matrixStart = 4;
        }
        int lineLenght = line.length();
        for(int i=0; i<lineLenght; i++)
        {
            if(line[i] == ' ')
            {
                this->columns++;
            }
        }
    }
    this->rows = this->rows - matrixStart;
}

void File::writeFile(string fileName)
{
    QString tempPath = QDir::tempPath();
    QString extension = QString::fromStdString(this->extension);
    QString temporaryFile = tempPath +  "FilteredImage" + extension;
    ofstream newImageFile;
    if(fileName.length()>25){
        newImageFile.open(fileName, ios::out);
    }else
    {
        newImageFile.open(temporaryFile.toUtf8().constData(), ios::out);
    }
    if(newImageFile.fail())
    {
        cout << "Error could not open archive" <<  endl;
        exit(1);
    }

    newImageFile << this->header << endl;
    newImageFile << "#NervCode" << endl;
    newImageFile << this->width << " " << this->height << endl;
    newImageFile << maxRGB << endl;
    int filterSize = this->filtered.size();
    for(int i=0; i < filterSize; i++)
    {
        int columnSize = this->filtered[i].size();
        for(int j=0; j<columnSize; j++)
        {
            newImageFile << this->filtered[i][j] << " ";
        }
        newImageFile << endl;
    }
    newImageFile.close();
}

void File::convertToVector()
{
    ifstream imageFile;
    imageFile.open(this->name, ios::in);
    string line;
    for (int i = 0; i < this->rows + matrixStart; i++)
    {
        vector<int> row;
        string line;
        getline(imageFile, line);
        stringstream spliter(line);
        string columnValue;
        if (i >= 4)
        {
            while (getline(spliter, columnValue, ' '))
            {
                int values = stoi(columnValue);
                row.push_back(values);
            }
            picture.push_back(row);
        }
    }
}

QVector<double> File::histogram()
{
    int valueIntensity = 0;
    QVector<double> histogram(255);

    while(valueIntensity < 255)
    {
        int counter = 0;
        int imageSize = this->picture.size();
        for(int rows = 0; rows<imageSize; rows++)
        {
            int columnsSize = this->picture[rows].size();
            for(int columns = 0; columns < columnsSize; columns++)
            {
                if(this->picture[rows][columns] == valueIntensity)
                {
                    counter ++;
                }

            }
        }
        if(counter > this->maxIntensity)
        {
            this->maxIntensity = counter;
        }
        valueIntensity = valueIntensity + 1;
        histogram[valueIntensity] = counter;
    }
    return histogram;
}

int File::getmaxIntensity()
{
    return this->maxIntensity;
}

vector<vector<int>> File::getPicture()
{
    return this->picture;
}


void File::setFiltered(vector<vector<int>> fromFilters)
{
    this->filtered = fromFilters;
}

string File::getExtension()
{
    return this->extension;
}
