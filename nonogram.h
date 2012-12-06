#ifndef NONOGRAM_H
#define NONOGRAM_H
#include <ctime> 
#include <cstdlib>
#include "solver.h"

class nonogram {
 private:
	size_t width, height;
	int solids, dots;
	size_t *field;
	vector<size_t> **x_axis;
	vector<size_t> **y_axis;
	void generate_field();
	void generate_puzzle();
	double probability(int above, int left);

 public:
	nonogram(int w, int h);
	~nonogram();
	void print();
	vector<size_t>** get_x_axis();
	vector<size_t>** get_y_axis();
	size_t* get_field();
};
#endif
