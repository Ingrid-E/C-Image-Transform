#include"Channel.h"

Channel::Channel(){

}

Channel::~Channel(){

}

bool Channel:: hasRed(){
	//TODO: falta implementarlo
}

bool Channel:: hasGreen(){
	//TODO: falta implementarlo
}

bool Channel:: hasBlue(){
	//TODO: falta implementarlo
}
bool Channel:: isRGB(){
	//TODO: falta implementarlo	
}


int Channel:: getRed(){
	return this->red;
}

int Channel:: getGreen(){
	return this->green;
}

int Channel:: getBlue(){
	return this->blue;
}


void Channel:: setRed(int red){
	this->red=red;
}

void Channel:: setGreen(int green){
	this->green=green;
}

void Channel:: setBlue(int blue){
	this->blue=blue;
}
