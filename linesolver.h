#ifndef LINESOLVER_H
#define LINESOLVER_H
#include <vector>
#include <iostream>

using namespace std;

class LineSolver {
private:
	size_t length;
	vector<size_t> *clue;
	size_t partialSolid;
	size_t partialDot;
	size_t improvedSolid;
	size_t improvedDot;
	size_t improvedDotMask;
	bool isDotCovered(size_t test);
	bool isSolidAbutted (size_t test);
	bool isSolidRevealed (size_t test);
	bool isSolidMatch (size_t test);
	size_t bitRepresentationOfBlock (size_t block_size, size_t position);
	bool solve (size_t block, size_t position, size_t parents);
	
public:
	LineSolver();
	void printBitblock (size_t bitblock);
	void printResult();
	void solve(size_t l, size_t ps, size_t pd, vector<size_t> *c);
	size_t getSolid();
	size_t getDot();
};
#endif
