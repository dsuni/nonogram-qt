#include "nonogram.h"

Nonogram::Nonogram(int w, int h) : width(w), height(h), solids(0), dots(0), field(new size_t[h]) {
if ((xAxis = (vector<size_t>**)malloc(width * sizeof(vector<size_t>*))) == NULL ||
		(yAxis = (vector<size_t>**)malloc(height * sizeof(vector<size_t>*))) == NULL) {
	cerr << "ERROR: Malloc failed." << endl;
	exit(1);
 }
	generateField();
	generatePuzzle();
}

Nonogram::~Nonogram() {
	delete[] field;
	for (size_t i = 0; i < width; ++i) {
		delete xAxis[i];
	}
	for (size_t i = 0; i < height; ++i) {
		delete yAxis[i];
	}
	free(xAxis);
	free(yAxis);
}

vector<size_t>** Nonogram::getXAxis() {
	return xAxis;
}

vector<size_t>** Nonogram::getYAxis() {
	return yAxis;
}

size_t* Nonogram::getField() {
	return field;
}

// Prints the puzzle. Mostly usable for debugging.
void Nonogram::print() {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = (1 << (width - 1)); j > 0; j >>= 1) {
			if (field[i] & j) {
				cout << "X";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}

// Generates the puzzle (i.e. the numbers shown to the user) from the existing field.
void Nonogram::generatePuzzle() {
	size_t temp;
	for (size_t i = 0; i < height; ++i) {
		temp = 0;
		yAxis[i] = new vector<size_t>;
		for (size_t j = (1 << (width - 1)); j > 0; j >>= 1) {
			if (!(field[i] & j)) {
				if (temp > 0) {
					yAxis[i]->push_back(temp);
				}
				temp = 0;
			}
			else {
				++temp;
			}
		}
		if (temp > 0 || yAxis[i]->size() == 0) {
			yAxis[i]->push_back(temp);
		}
	}
	size_t mask = 1 << width;
	for(size_t i = 0; i < width; ++i) {
		mask >>= 1;
		xAxis[i] = new vector<size_t>;
		temp = 0;
		for (size_t j = 0; j < height; ++j) {
			if (!(field[j] & mask)) {
				if (temp > 0) {
					xAxis[i]->push_back(temp);
				}
				temp = 0;
			}
			else {
				++temp;
			}
		}
		if (temp > 0 || xAxis[i]->size() == 0) {
			xAxis[i]->push_back(temp);
		}
	}
}

// Generate a semi-random playing field.
void Nonogram::generateField() {
	int random, above, left;
	size_t mask = 1 << (width - 1);
	double prob;
	srand(time(NULL));
	for (size_t i = 0; i < height; ++i) {
		field[i] = 0;
		for (size_t j = mask; j > 0; j >>=1) {
			if (i == 0) {
				above = -1;
			}
			else {
				above = ((field[i - 1] & j) > 0);
			}
			if (j == mask) {
				left = -1;
			}
			else {
				left = ((field[i] & (j << 1)) > 0);
			}
			prob = probability(above, left);
			random = rand();
			if (random > prob * RAND_MAX) {
				++dots;
			}
			else {
				field[i] |= j;
				++solids;
			}
		}
	}
}

/* Calculates the probability for the next block being black.
	 The purpose of this function is to have the generated field be random, but
	 not too random. We want a (roughly) 50-50 split between white and black fields,
	 and we'd rather see that the black & white fields are (again roughly) collected
	 in "islands" rather than a chessboard-type distribution.
*/
double Nonogram::probability(int above, int left) {
	double p = 0.5;
	switch (above + left) {
	case -2:
	case 1:
		break;
	case -1:
		p = 0.25;
		break;
	case 0:
		if (above == 0) {
			p = 0.1;
		}
		else {
			p = 0.75;
		}
		break;
	case 2:
		p = 0.9;
		break;
	}
	p += (1.0 / (width * height)) * (dots - solids);
	return p;
}
