/** 
 * @file ImageVector.h
 * @brief Creates a matrix vector of the image file.txt
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @date 1/12/20
 * @version 1.0
*/

#ifndef IMAGEVECTOR_H_
#define IMAGEVECTOR_H_
#include <string>
#include <vector>
using namespace std;

class ImageVector
{

private:
  /*Name of the file that is going to create a vector of */
  string fileName;
  /*Vector that contains a vector so it's like a matrix of numbers*/
  vector<vector<int>> image;
  /*Number of rows in the file*/
  int rows;
  /*Number of columns in the file */
  int columns;
  /*Width of the image, can be found in the third line of the file*/
  int width;
  /*Height of the image, can be found in the third line of the file*/
  int height;
  /*Max RGB value, can be found in the forth line of the file*/
  int maxRGB;
  /*Bit type of the image found in the first line of the file*/
  string header;
  /*Line where the matrix starts*/
  int matrixStart;

public:
  /*
   * @brief Construct a new Image Vector object
  */
  ImageVector();
  /**
   * @brief Construct a new Image Vector object
   * @param fileName //Name of the image file
   */
  ImageVector(string fileName);
  /**
   * @brief Destroy the Image Vector object
  */
  ~ImageVector();
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
   * @brief Get the Width object
   * @return int 
  */
  int getWidth();
  /**
   * @brief Get the Height object
   * @return int 
  */
  int getHeight();
  /**
   * @brief Get the Max RGB object
   * @return int 
  */
  int getMaxRGB();
  /**
   * @brief Get the header of the file.
   * @return string
  */
  string getHeader();
  /**
   * @brief counts the rows and columns, 
   * sets the maxRGB, width and height, values.
  */
  void start();
  /**
   * @brief Converts the numbers in the file to a vector matrix.
  */
  void convertToVector();
  /**
   * @brief Get the Vector object
   * @return vector<vector<int>> // Image Vector
  */
  vector<vector<int>> getVector();
};

#endif