#include "simulation.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "global.h"
#include "matrix.h"

Simulation::Simulation(Life** life, int numLife) {
	watchme = 1;
	steps = 0;
	automate = false;
	matrix = new Matrix();

	if (life != nullptr) {
		for (int i = 0; i < numLife; i++) {
			if (life[i] != nullptr) {
				bool success = matrix->initState(life[i]);
				if (!success) {
					std::cout << "Failed to add life to the matrix" << std::endl;
				}
			}
		}
	}
}

Simulation::~Simulation() {
	delete matrix;
}

void Simulation::simulate() {
	while (true) {
		matrix->render();

		if (!automate) {
			std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";

			std::string action;
			std::getline(std::cin, action);

			switch (action[0])
			{

			default:
				std::cout << '\a' << std::endl;  // beep
				continue;
			case 'q':
				std::cout << "Quitting Game." << std::endl;
				return;
			case 's':

				continue;
			case ' ':

				break;
			case 'a':
				automate = true;
				break;
			}
		}
		else {
			if (steps >= MAX_STEPS) {
				std::cout << "Reached max steps, quitting." << std::endl;
				return;
			}
			delay(300);
		}
		steps++;
		matrix->computeNextState();
	}
}

void Simulation::report() {
	std::string msg = "For the first part of the discussion, the numbers are 17825 that watchme changes to. The number that was used to dcode the word was 52871 which was the number backwards. The decoded word is 'never goin give you up'. For the second part, the main may not end up compiling because the headers correctly where the headers do have have guards which prevent simulation or matrix or the other header classes from being created multiple times. For the third discussion, the code is not supposed to compile properly. If it does compile, it would be due to the fact that rather than declaring a class, they included the header file in the simulation header, causing it to also grab the declares the Matrix class and causes the code to work. "; // Replace Hello World with your answer.
	std::cout << msg << std::endl;
}

int Simulation::two(int u) {
	return (u << 2) % 10;
}
int Simulation::three(int x) {
	if (x % 2 == 0)
		return 5;
	else
		return 3;
}
void Simulation::one(int t) {
	int i = 0;
	int k = watchme;
	while (++i < t) {
		if (i == 0)
			k = 2;
		else if (i == 1)
			k = 7;
		else if (i == 4)
			k = 8;
		else if (i == 5)
			k = 5;
		else
			k = two(watchme);
		watchme = k;
	}
	k = three(watchme);
	watchme = k;
}

void Simulation::delay(int ms) const {
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}