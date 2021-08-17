/**
 * @file Image.h
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @brief Gets file basic info and create a File of it using the File.h class. 
 * @version 0.1
 * @date 2020-12-1
 */

#ifndef IMAGE_H_
#define IMAGE_H_
#include <string>
#include <vector>
using namespace std;

class Image
{
protected:
    /** Image rows */
    int rows;
    /** Image columns */
    int columns;
    /** Image maxRGB value */
    int maxRGB;
    /** Image filename */
    string name;
public:
    /** @brief Construct a new Image object */
    Image();
    /**
     * @brief Construct a new Image object
     * @param fileName 
     */
    Image(string fileName);
    /** @brief Destroy the Image object */
    ~Image();
    /**
     * @brief Get the Rows object
     * @return int 
     */
    int getRows();
    /**
     * @brief Get the Columns object
     * @return int 
     */
    int getColumns();
    /**
     * @brief Get the Max R G B object
     * 
     * @return int 
     */
    int getMaxRGB();
    /**
     * @brief Get the Name object
     * 
     * @return string 
     */
    string getName();
};
#endif
