#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H

class ImageTools{

	public:
		/**
		 * Constructor
		*/
		ImageTools();
		/**
		 * Destructor
		*/
		~ImageTools();
		/**
		 * histogram
		*/
		int histogram;
		/***/
		int toGray();
		/***/
		int toNegative();
		/***/
		int toSephia();
};
#endif
