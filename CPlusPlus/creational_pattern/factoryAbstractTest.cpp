#include <iostream>
#include <vector>
#include <iterator>
#include "factoryAbstract.h"

using namespace std;

int main (void) {
	int input = 0;
	vector<stooze *> ll;
	stooze *_ptr;
	cout << "enter choice, enter 0 to finish \n";
	while (true) {
		cin >> input; 

		switch (input) {
			case 1:
			case 2:
			case 3:
				ll.push_back(stooze::make_stooge(input));
				break;
			default:
				cout << "wrong entry \n";
		}
				
		if (input == 0) break ;
	}

	vector<stooze *>::iterator it = ll.begin();
	for (; it != ll.end(); ++it) { 
		 _ptr = *it;
		_ptr->action();
	}
	ll.clear();
	_ptr->action();
	delete(_ptr);

	return 0;
}
