/**
 * @file Filters.h
 * @author: Andres David Camargo Arcos (andres.camargo@correounivalle.edu.co)
 * @author: Ingrid Echeverri Montoya (ingrid.echeverri@correounivalle.edu.co)
 * @author: Jhan Alejandro Perez Umbarila (jhan.perez@correounivalle.edu.co)
 * @author: Jean Pierre Cardenas Perea (jean.cardenas@correunivalle.edu.co)
 * @brief Modifies the image and applies filters to it, to show in the interface.
 * @version 0.1
 * @date 2020-12-1
 */
#ifndef FILTERS_H_
#define FILTERS_H_
#include "File.h"

class Filters:public File
{
private:
    /** Image file name */
    string newFileName;
    /** Image rgb counter to get r,g,or b place*/
    int rgbCounter;
    /** Filter num to apply */
    int filter;
    /** original image vector containing the values */
    vector<vector<int>> image;
    /** second image to use in overlay */
    vector<vector<int>> secondImage;
    /** Image copy of the original image */
    vector<vector<int>> copyImg;
    /** Max RGB value */
    int maxRGB;
    /** True if image is Grey, Flase if not  */
    bool isGrey;
public:
    /** @brief Construct a new Filters object */
    Filters();
    /**
     * @brief Construct a new Filters object
     * @param obj 
     * @param filter 
     * @param value 
     */
    Filters(File &obj, int filter, int value=0);
    /**
     * @brief Construct a new Filters object
     * @param obj 
     * @param obj2 
     */
    Filters(File &obj, File &obj2);
    /** @brief Destroy the Filters object */
    ~Filters();
    /**
     * @brief Get the Filtered object
     * @return vector<vector<int>> 
     */
    vector<vector<int>> getFiltered();
    /**  @brief Returns original image */
    void normal();
    /**  @brief Checks image values and returns true if grey, false if not */
    bool isBlacknWhite();
    /**  @brief Checks rgb values and gets the largest, 
     * then rounds up to 255 (white) or 0 (black).
     */
    void threshold();
    /**
     * @brief Flips image by putting the top 
     * values in the bottom.
     */
    void flip();
    /**  @brief Turns image to grey values 
     * by applying grey formula.
     * gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
    */
    void toGrey();
    /**
     * @brief Turns image to negative by resting the maxRGB
     * to the current pixel value.
     * 
     */
    void toNegative();
    /**
     * @brief Turns image to sephia by getting each rgb value
     * and applying the sephia formula.
     * tr = 0.393 *red+ 0.769 *green+ 0.189 *blue;
     * tg = 0.349 *red+ 0.686 *green+ 0.168 *blue;
     * tb = 0.272 *red+ 0.534 *green+ 0.131 *blue;
     */
    void toSephia();
    /**
     * @brief Applies a tone color to the image, pink, blue or green.
     * Gets each rgb value and applies the designed formula.
     * @param color  // Tone to apply
     */
    void toTone(int color);
    /**
     * @brief Makes a grey image to color,
     * getting each rgb value and applying the formula. 
     *  r = r/50
     *  g = g /40
     *  b = b/30
     */
    void toColor();
    /**
     * @brief Overlays an image in top of another image
     * by changing the green values to the first image.
     * 
     */
    void overLay();
};

#endif
