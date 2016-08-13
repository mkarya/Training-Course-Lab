#include <stdio.h>
#include <iostream>
#include <vector>
#include <iterator>
#include "factoryAbstract.h"
#include <thread>
#include <mutex>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
vector<stooze *> ll;
mutex mtx;
unsigned short memory_allocations = 0;
unsigned short memory_free = 0;

void signal_handler(int xx) {
	cout << "number of memory allocations : " << memory_allocations << "\n"; 
	cout << "number of memory free : " << memory_free << "\n"; 
	raise(SIGKILL);
}

void collectInput() {
	int input;
	while (true) {
		cin >> input; 

		switch (input) {
			case 1:
			case 2:
			case 3:
			//mtx.lock();
				ll.push_back(stooze::make_stooge(input));
				memory_allocations += 1;
			//mtx.unlock();
			break;
			default:
				cout << "wrong entry \n";
		}
				
	}
	return;
}

void performAction() {
	mtx.lock();
	while(true){
		vector<stooze *>::iterator it = ll.begin();
		for (; it != ll.end(); ++it) 
			(*it)->action();
		while(!ll.empty()) {
			ll.pop_back();
			memory_free += 1;
		}
	mtx.unlock();
}
	return;
}


int main (void) {
	signal(SIGINT, signal_handler);
	thread th01(collectInput);
	thread th02(performAction);

	th01.join();
	th02.join();

	return 0;
}
