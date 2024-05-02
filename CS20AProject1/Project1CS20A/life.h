#ifndef LIFE_H
#define LIFE_H
class Matrix;
class Simulation;

class Life {
public:
	int getCol() const {
		return col;
	}
	int getRow() const {
		return row;
	}
	int getHeight() const {
		return height;
	}
	int getWidth() const {
		return width;
	}
	char getFigure(int r, int c) const {
		return sprite[r][c];
	}
	void inMatrix(Matrix *m) {
		matrix = m;
	}
	void inSimulation(Simulation *s) {
		simulation = s;
	}
	bool areWeInASimulation() {
		return simulation != nullptr;
	}
protected:
	int col;
	int row;
	int height;
	int width;
	char **sprite;
	Matrix *matrix;
	Simulation *simulation;
};

#endif // !LIFE_H