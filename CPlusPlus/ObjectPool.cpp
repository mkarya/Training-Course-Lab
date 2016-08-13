#include <iostream> 
#include "factoryAbstract.h"
#include "ObjectPool.h"
#include <single.h>
#include <map>

using namespace std;

ObjectPool::ObjectPool() {
	for (int i=0; i < 5; i++) {
		joe[i] = stooze::make_stooge(1);
		moe[i] = stooze::make_stooge(2);
		ram[i] = stooze::make_stooge(3);
	}
	for(int i=0;i<15;i++) {
		status[i] = false;
	}
}

stooze * ObjectPool::getObject(int xx) {
	switch(xx) {
		case 1:
			for (int i = 0 ; i < 5; i++ ) {
				if (status[i] == false) {
					status[i] == true;
					return joe[i];
				}
				else { cout << "give object is not available, returning null \n" };
			break;
		case 2:
			for (int i = 5 ; i < 10; i++ ) {
				if (status[i] == false) {
					status[i] == true;
					return moe[i-5];
				}
				else { cout << "give object is not available, returning null \n" };
			break;
		case 3:
			for (int i = 10 ; i < 15; i++ ) {
				if (status[i] == false) {
					status[i - 10] == true;
					return ram[i -10];
				}
				else { cout << "give object is not available, returning null \n" };
			break;

		default:
			cout << "wrong entry \n";
	}

	return NULL;
}
		

int ObjectPool::releaseObject(stooze * _ptr) {
	for (int i = 0 ; i < 5 ; i++ ) {
		if (joe[i] == _ptr) {
			status[i] = false;
		else if(moe[i] == _ptr) {
			status[i+5] = false;
		else if(ram[i] == _ptr) {
			status[i+10] = false;	
	}
return;
}
