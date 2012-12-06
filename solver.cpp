#include "solver.h"

solver::solver(size_t w, size_t h, vector<size_t> **x, vector<size_t> **y) : width(w), height(h), x_axis_clue(x), y_axis_clue(y) {
	for (size_t i = 0; i < width; ++i) {
		size_t *temp = new size_t[STAT_SIZE];
		for (size_t j = 0; j < STAT_SIZE; ++j) {
			temp[j] = 0;
		}
		x_stats.push_back(temp);
	}
	for (size_t i = 0; i < height; ++i) {
		size_t *temp = new size_t[STAT_SIZE];
		for (size_t j = 0; j < STAT_SIZE; ++j) {
			temp[j] = 0;
		}
		y_stats.push_back(temp);
	}
}

solver::~solver() {
	for (size_t i = 0; i < width; ++i) {
		delete[] x_stats.at(i);
	}
	for (size_t i = 0; i < height; ++i) {
		delete[] y_stats.at(i);
	}
}

/* When additional information has been received on the x_stats, the corresponding
   y_stats need to be updated with this information so the it can be used to solve
	 the puzzle.

	 The mask variable is the bit that should be updated, (if anything is to be). E.g:
	 width = 4 -> The last 4 bits are relevant bits for lines along the y-axis.
	 column = 1 -> It's the second most relevant bit that is affected. (0 = most, 3 = least)
	 mask = 1 << (4 - 1 - 1) -> 00000100

	 The column variable is used against the x_stats variable to check whether the
	 corresponding bit is a 1 or not (by using an and operation). If it's a 1, this is
	 updated to the corresponding y_stats position (defined by the mask variable). It
	 starts at the most relevant bit and is right shifted one step for every iteration.
 */
void solver::update_y_stats(size_t column) {
	size_t mask = 1 << (width - column - 1);
	size_t row = 1 << (height - 1);
	for (size_t i = 0; i < height; ++i) {
		if (row & x_stats[column][1]) {
			y_stats[i][1] |= mask;
		}
		else if (row & x_stats[column][2]) {
			y_stats[i][2] |= mask;
		}
		row >>= 1;
	}
}

// Same as above function, but other way around.
void solver::update_x_stats(size_t row) {
	size_t mask = 1 << (height - row - 1);
	size_t column = 1 << (width - 1);
	for (size_t i = 0; i < width; ++i) {
		if (column & y_stats[row][1]) {
			x_stats[i][1] |= mask;
		}
		else if (column & y_stats[row][2]) {
			x_stats[i][2] |= mask;
		}
		column >>= 1;
	}
}

void solver::print_result() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 1 << (width - 1); j > 0; j >>= 1) {
			if ((y_stats[i][1] & j) > 0) {
				cout << "#";
			}
			else if ((y_stats[i][2] & j) > 0) {
				cout << "-";
			}
			else {
				cout << "+";
			}
		}
		cout << endl;
	}
}

bool solver::solve() {
	linesolver lsolver;
	bool info_increased;
	bool is_solved;
	/* The mask is a variable of n 0's followed by m 1's. By 'or'ing the solids and the dots, and
		 comparing the result to the mask we know if a line is completely solved or not. E.g.
		 
		 height = 4 -> x_mask = 00001111 (meaning the last 4 x_stats bits are relevant)

		 x_stats[0][1] (solids): 00001101
		 x_stats[0][2] (dots)  : 00000010
		 --------------------------------
		                     or: 00001111 (== x_mask -> solved)
	*/
	size_t x_mask = (1 << height) - 1;
	size_t y_mask = (1 << width) - 1;
	size_t result_solid, result_dot;
	while (true) {
		info_increased = false;
		is_solved = true;
		for (size_t i = 0; i < width; ++i) {
			// If the line is not already solved, try to solve it.
			if (!x_stats[i][0]) {
				lsolver.solve(height, x_stats[i][1], x_stats[i][2], x_axis_clue[i]);
				result_solid = lsolver.get_solid();
				result_dot = lsolver.get_dot();
				// if the result differs from the original, it means we've gotten more information to merge.
				if (result_solid != x_stats[i][1] || result_dot != x_stats[i][2]) {
					info_increased = true;
					x_stats[i][1] = result_solid;
					x_stats[i][2] = result_dot;
					update_y_stats(i);
				}
				x_stats[i][0] = ((x_stats[i][1] | x_stats[i][2]) == x_mask);
				if (!x_stats[i][0]) {
					is_solved = false;
				}
			}
		}
		if (is_solved) {
			return true;
		}
		is_solved = true;
		for (size_t i = 0; i < height; ++i) {
			if (!y_stats[i][0]) {
				lsolver.solve(width, y_stats[i][1], y_stats[i][2], y_axis_clue[i]);
				result_solid = lsolver.get_solid();
				result_dot = lsolver.get_dot();
				if (result_solid != y_stats[i][1] || result_dot != y_stats[i][2]) {
					info_increased = true;
					y_stats[i][1] = result_solid;
					y_stats[i][2] = result_dot;
					update_x_stats(i);
				}
				y_stats[i][0] = ((y_stats[i][1] | y_stats[i][2]) == y_mask);
				if (!y_stats[i][0]) {
					is_solved = false;
				}
			}
		}
		if (is_solved) {
			return true;
		}
		// If we're stuck with a puzzle we can't solve, it's time to give up.
		if (!info_increased) {
			return false;
		}
	}
}
