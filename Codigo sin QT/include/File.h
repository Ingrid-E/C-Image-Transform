/**
 * @file File.h
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @brief Gets the image file values and makes it into an Array
 * @version 0.1
 * @date 2020-12-1
 */
#include "Image.h"
#ifndef FILE_H_
#define FILE_H_
#include <string>
#include <vector>
#include <QVector>
using namespace std;

class File : public Image
{
private:
    /** filename */
    string name;
    /** Image width */
    int width; 
    /** Image height */
    int height;
    /** Image Header P3 or P2 or etc */
    string header;
    /** Position where the matrix starts in the file */
    int matrixStart;
    /** Max intensity of the rgb values */
    int maxIntensity;

protected:
    /** Picture vector */
    vector<vector<int>> picture;
    /** Image with filter vector */
    vector<vector<int>> filtered;
    /** File extension */
    string extension;

public:
    /** @brief Construct a new File object */
    File();
    /**
     * @brief Construct a new File object
     * @param fileName 
     */
    File(string fileName);
    /**  @brief Destroy the File object */
    ~File();
    /**
     * @brief Opens image file and returns the lines in console.
     */
    void readFile();
    /**
     * @brief Opens image file and extracts image values.
     */
    void getFileValues();
    /**
     * @brief Creates new file with filtered image values.
     * @param fileName 
     */
    void writeFile(string fileName);
    /**
     * @brief Converts image array values to vector.
     * 
     */
    void convertToVector();
    /**
     * @brief Get the Picture object
     * 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> getPicture();
    /**
     * @brief Set the Filtered object
     * 
     * @param fromFilters 
     */
    void setFiltered(vector<vector<int>> fromFilters);
    /**
     * @brief Get the Extension object
     * 
     * @return string 
     */
    string getExtension();
    /**
     * @brief Gets intensity of the rgb values, and saves it in a QVector.
     * to show it in the QGraph.
     * 
     * @return QVector<double> 
     */
    QVector<double> histogram();
    /**
     * @brief Returns maxIntensity value
     * 
     * @return int 
     */
    int getmaxIntensity();
};

#include "Filters.h"

#endif
