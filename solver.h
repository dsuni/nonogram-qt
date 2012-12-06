#ifndef SOLVER_H
#define SOLVER_H
#include "linesolver.h"

#define STAT_SIZE 3

class solver {
 private:
	vector<size_t> **x_axis_clue;
	vector<size_t> **y_axis_clue;
	size_t width, height;
	/* The stats-variables contain the current status of the solution.
		 [0] is a true/false indicator of whether the line is solved or not. (true == solved)
		 [1] is the current bitblock status of the solids (5 == b101 -> solid, unknown, solid)
		 [2] same as above, but for dots. (3 == b011 -> unknown, dot, dot)

		 The x_stats variable contains data along the x-axis, i.e. the *columns*, the
		 y_stats for the *rows*. The data is redundant so that it can be more readily
		 processed by the linesolver.

		                              (2)--vv--(1,1)
		 E.g. a 2 x 3 puzzle like this:(2) ##
                                   (1) #-
                                   (1) -#

		When solved the stats-variables would have the following values. (When starting they're 0)
		x[0][0]: 1 (= true) x[1][0]: 1 (= true) 
		x[0][1]: 6 (= b110) x[1][1]: 5 (= b101)
		x[0][2]: 1 (= b001) x[1][2]: 2 (= b010)

		y[0][0]: 1 (= true) y[1][0]: 1 (= true) y[2][0]: 1 (= true)
		y[0][1]: 3 (= b11)  y[1][1]: 2 (= b10)  y[2][1]: 1 (= b01)
		y[0][2]: 0 (= b00)  y[1][2]: 1 (= b01)  y[2][2]: 2 (= b10)
	*/
	vector<size_t*> x_stats;
	vector<size_t*> y_stats;
	void update_y_stats(size_t column);
	void update_x_stats(size_t row);

 public:
	solver(size_t w, size_t h, vector<size_t> **x, vector<size_t> **y);
	~solver();
	void print_result();
	bool solve();
};
#endif
