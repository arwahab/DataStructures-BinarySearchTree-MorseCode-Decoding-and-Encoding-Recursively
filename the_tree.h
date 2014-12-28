ifndef THE_TREE_H
#define THE_TREE_H
#include "the_tree.h"
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>

// Programming Assignment 3 - Data Structures
// Abdul Wahab

using namespace std;

class BT {

private:

	struct BTNode {
		BTNode *left_node;
		BTNode *right_node;
		string morse_code;
		char alpha;
	}; BTNode *root_node;



public:
	
	 BT();
	~BT();
	void insert(char alpha, string code);
	void insert(BTNode *&add_node, char alpha, string code, bool last);
	string encode(string input, BTNode *node, string::size_type &i, string out);
	string encode(string input);
	string decode(string input, bool added_node);

};
#endif
