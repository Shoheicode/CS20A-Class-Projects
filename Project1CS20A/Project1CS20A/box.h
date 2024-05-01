#ifndef BOX_H
#define BOX_H
#include "life.h"

class Box : public Life {
public:
	Box(int r, int c);
	~Box();
};

#endif // !BOX_H
