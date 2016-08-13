#ifndef FACTORY_ABSTRACT
#define FACTORY_ABSTRACT
#include <iostream>
#include <vector>

using namespace std;

class stooze {
	public:
		static stooze* make_stooge(int kk);
		virtual void action() = 0;
};

class moe : public stooze {
	public:
		inline void action() {
			cout << "roll eyes \n";
		}
	moe() { cout << "thanks \n";}
	 ~moe() { cout << "moe: I am killed now moe\n"; }
};

class joe : public stooze {
	public:
		inline void action() {
			cout << "raise hand \n";
		}
	joe(){}
	~joe() { cout << "joe:i am on being killed \n";}
};

class ram : public stooze {
	public:
		inline void action() {
			cout << "raise leg \n";
		}
	ram(){}
	~ram() { cout << "ram: i am on being killed \n";}
};
#endif
