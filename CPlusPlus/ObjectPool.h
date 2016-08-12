#ifndef OBJECT_POOL
#define OBJECT_POOL
#include <iostream>
#include <map>
#include "factoryAbstract.h"

class ObjectPool {
        private:
                stooze *joe[5];
                stooze *moe[5];
                stooze *ram[5];
		bool status[15];

        public:
                ObjectPool();
                stooze & getObject(int xx);
                int releaseObject(stooze * );
};

#endif
