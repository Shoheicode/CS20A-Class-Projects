#ifndef SNAKE_H
#define SNAKE_H

#include "life.h"

class Snake : public Life {
public:
	Snake(int r, int c);
	~Snake();
};
#endif // !SNAKE_H
