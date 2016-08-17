#include <iostream>
#include <string>
#include "ProxyPattern.h"
using namespace std;

Image::Image(const string &imageName):filename(imageName) {}
void Image::draw_image() {
	_ptr = new real_Image(filename);
	_ptr->loadImage();
	delete _ptr;

}

int main(void) {
	string xx;
	cout << "name the file to draw -> "; 
	cin >> xx;
	Image * im = new Image(xx);
	im->draw_image();
}

