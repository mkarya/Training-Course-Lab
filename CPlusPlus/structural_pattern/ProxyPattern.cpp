#ifndef PROXY_H
#define PROXY_H 
#include <iostream>
#include <string>

class real_Image {
	public:
		real_Image(const string & filename);
	
	
class Image {
	private:
		string filename; 
		class real_Image * _ptr;

	public:
		Image(const string &);
		void draw_image(const string &);
};

#endif
