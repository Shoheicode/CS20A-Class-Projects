#ifndef BOAT_H
#define BOAT_H
#include "life.h"

class Boat : public Life {
public:
	Boat(int r, int c);
	~Boat();
};

#endif // !BOAT_H
