#ifndef SIMULATION_H
#define SIMULATION_H

class Matrix;
class Life;


class Simulation {
public:
	Simulation(Life** life, int numLife);
	~Simulation();
	void simulate();
	void report();
	int two(int u);
	int three(int x);
	void one(int t);

private:
	void delay(int ms) const;

	int		watchme;
	Matrix* matrix;
	int		steps;
	bool	automate;
};

#endif // !SIMULATION_H
