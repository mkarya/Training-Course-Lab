#ifndef PROXY_H
#define PROXY_H 
#include <iostream>
#include <string>
using namespace std;

class real_Image {
	private:
		string imageFileName;
	
	public:
		real_Image(const string &ff) : imageFileName(ff) {}
		inline void loadImage() { 
			cout << "loading image : " << imageFileName << "\n";
			this->draw_Image();
		}
		inline void draw_Image(){ cout << "drawing image : " << imageFileName << "\n"; }
	
};
	
class Image {
	private:
		string filename; 
		class real_Image * _ptr;

	public:
		Image(const string &);
		void draw_image();
};

#endif
