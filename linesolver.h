#ifndef LINESOLVER_H
#define LINESOLVER_H
#include <vector>
#include <iostream>

using namespace std;

class linesolver {
private:
	size_t length;
	vector<size_t> *clue;
	size_t partial_solid;
	size_t partial_dot;
	size_t improved_solid;
	size_t improved_dot;
	size_t improved_dot_mask;
	bool is_dot_covered(size_t test);
	bool is_solid_abutted (size_t test);
	bool is_solid_revealed (size_t test);
	bool is_solid_match (size_t test);
	size_t bit_representation_of_block (size_t block_size, size_t position);
	bool solve (size_t block, size_t position, size_t parents);
	
public:
	linesolver();
	void print_bitblock (size_t bitblock);
	void print_result();
	void solve(size_t l, size_t ps, size_t pd, vector<size_t> *c);
	size_t get_solid();
	size_t get_dot();
};
#endif
