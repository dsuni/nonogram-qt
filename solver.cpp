#include "solver.h"

Solver::Solver(size_t w, size_t h, vector<size_t> **x, vector<size_t> **y) : width(w), height(h), xAxisClue(x), yAxisClue(y) {
	for (size_t i = 0; i < width; ++i) {
		size_t *temp = new size_t[STAT_SIZE];
		for (size_t j = 0; j < STAT_SIZE; ++j) {
			temp[j] = 0;
		}
		xStats.push_back(temp);
	}
	for (size_t i = 0; i < height; ++i) {
		size_t *temp = new size_t[STAT_SIZE];
		for (size_t j = 0; j < STAT_SIZE; ++j) {
			temp[j] = 0;
		}
		yStats.push_back(temp);
	}
}

Solver::~Solver() {
	for (size_t i = 0; i < width; ++i) {
		delete[] xStats.at(i);
	}
	for (size_t i = 0; i < height; ++i) {
		delete[] yStats.at(i);
	}
}

/* When additional information has been received on the xStats, the corresponding
   yStats need to be updated with this information so the it can be used to solve
	 the puzzle.

	 The mask variable is the bit that should be updated, (if anything is to be). E.g:
	 width = 4 -> The last 4 bits are relevant bits for lines along the y-axis.
	 column = 1 -> It's the second most relevant bit that is affected. (0 = most, 3 = least)
	 mask = 1 << (4 - 1 - 1) -> 00000100

	 The column variable is used against the xStats variable to check whether the
	 corresponding bit is a 1 or not (by using an and operation). If it's a 1, this is
	 updated to the corresponding yStats position (defined by the mask variable). It
	 starts at the most relevant bit and is right shifted one step for every iteration.
 */
void Solver::updateYStats(size_t column) {
	size_t mask = 1 << (width - column - 1);
	size_t row = 1 << (height - 1);
	for (size_t i = 0; i < height; ++i) {
		if (row & xStats[column][1]) {
			yStats[i][1] |= mask;
		}
		else if (row & xStats[column][2]) {
			yStats[i][2] |= mask;
		}
		row >>= 1;
	}
}

// Same as above function, but other way around.
void Solver::updateXStats(size_t row) {
	size_t mask = 1 << (height - row - 1);
	size_t column = 1 << (width - 1);
	for (size_t i = 0; i < width; ++i) {
		if (column & yStats[row][1]) {
			xStats[i][1] |= mask;
		}
		else if (column & yStats[row][2]) {
			xStats[i][2] |= mask;
		}
		column >>= 1;
	}
}

void Solver::printResult() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 1 << (width - 1); j > 0; j >>= 1) {
			if ((yStats[i][1] & j) > 0) {
				cout << "#";
			}
			else if ((yStats[i][2] & j) > 0) {
				cout << "-";
			}
			else {
				cout << "+";
			}
		}
		cout << endl;
	}
}

bool Solver::solve() {
	LineSolver lSolver;
	bool info_increased;
	bool is_solved;
	/* The mask is a variable of n 0's followed by m 1's. By 'or'ing the solids and the dots, and
		 comparing the result to the mask we know if a line is completely solved or not. E.g.
		 
		 height = 4 -> x_mask = 00001111 (meaning the last 4 xStats bits are relevant)

		 xStats[0][1] (solids): 00001101
		 xStats[0][2] (dots)  : 00000010
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
			if (!xStats[i][0]) {
				lSolver.solve(height, xStats[i][1], xStats[i][2], xAxisClue[i]);
				result_solid = lSolver.getSolid();
				result_dot = lSolver.getDot();
				// if the result differs from the original, it means we've gotten more information to merge.
				if (result_solid != xStats[i][1] || result_dot != xStats[i][2]) {
					info_increased = true;
					xStats[i][1] = result_solid;
					xStats[i][2] = result_dot;
					updateYStats(i);
				}
				xStats[i][0] = ((xStats[i][1] | xStats[i][2]) == x_mask);
				if (!xStats[i][0]) {
					is_solved = false;
				}
			}
		}
		if (is_solved) {
			return true;
		}
		is_solved = true;
		for (size_t i = 0; i < height; ++i) {
			if (!yStats[i][0]) {
				lSolver.solve(width, yStats[i][1], yStats[i][2], yAxisClue[i]);
				result_solid = lSolver.getSolid();
				result_dot = lSolver.getDot();
				if (result_solid != yStats[i][1] || result_dot != yStats[i][2]) {
					info_increased = true;
					yStats[i][1] = result_solid;
					yStats[i][2] = result_dot;
					updateXStats(i);
				}
				yStats[i][0] = ((yStats[i][1] | yStats[i][2]) == y_mask);
				if (!yStats[i][0]) {
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
