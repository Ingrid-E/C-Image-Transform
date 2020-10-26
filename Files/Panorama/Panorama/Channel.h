#ifndef CHANNEL_H
#define CHANNEL_H

class Channel{
	private:
		int red;
		int green;
		int blue;

	public:
		/**
		 * Constructor
		*/
		Channel();
		/**
		 * Destructor
		*/
		~Channel();

		/***/
		static bool hasRed();
		/***/
		static bool hasGreen();
		/***/
		static bool hasBlue();
		/***/
		bool isRGB();

		/**
		 * Obtiene la parte roja del canal
		 * @return  red
		*/
		int getRed();
		/**
		 * Obtiene la parte verde del canal
		 * @return  green
		*/
		int getGreen();
		/**
		 * Obtiene la parte azul del canal
		 * @return  blue
		*/
		int getBlue();

		/**
		 * cambia la parte roja del canal
		 * @param  red
		*/
		void setRed(int red);
		/**
		 * cambia la parte verde del canal
		 * @param  green
		*/
		void setGreen(int green);
		/**
		 * cambia la parte azul del canal
		 * @param  blue
		*/
		void setBlue(int blue);
	
};
#endif
