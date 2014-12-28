#include "the_tree.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

// Programming Assignment 3 - Data Structures
// Abdul Wahab


using namespace std;
BT::BT() {
	root_node = NULL;
}

BT::~BT() {
}

void BT::insert(char alpha, string code) {
	if (!root_node) {
		insert(root_node, alpha, code, true);
	}
	else {
		BTNode *node = root_node;
		for (string::size_type i = 0; i < code.length(); i++) {
			if (code[i] == '.') {
				if (!node->left_node) {
					if (i == code.length() - 1) {
						insert(node->left_node, alpha, code.substr(0, i + 1), true);
					}
					else {
						insert(node->left_node, alpha, code.substr(0, i + 1), false);
					}
				}
				node = node->left_node;
				if (node->left_node) {
					if (i == code.length() - 1) {
						node->alpha = alpha;
					}
				}
				if (!node->left_node) {
					if (i == code.length() - 1) {
						node->alpha = alpha;
					}
				}
			}
			else if (code[i] == '-') {
				if (!node->right_node) {
					if (i == code.length() - 1) {
						insert(node->right_node, alpha, code.substr(0, i + 1), true);
					}
					else {
						insert(node->right_node, alpha, code.substr(0, i + 1), false);
					}
				}
				node = node->right_node;
				if (node->right_node) {
					if (i == code.length() - 1) {
						node->alpha = alpha;
					}
				}
				if (!node->right_node) {
					if (i == code.length() - 1) {
						node->alpha = alpha;
					}
				}
			}
		}
	}
}

void BT::insert(BTNode *&node, char alpha, string code, bool last) { // wrapper function for insert() fcn.
	if (last) {
		node = new BTNode();
		node->alpha = alpha;
		node->right_node = NULL;
		node->left_node = NULL;
		node->morse_code = code;
	}

	if (!last) {
		node = new BTNode();
		node->alpha = '\0';
		node->right_node = NULL;
		node->left_node = NULL;
		node->morse_code = code;
	}
}


string BT::decode(string input, bool added_node) {
	string the_output = "";
	BTNode *node = root_node;
	for (string::size_type i = 0; i < input.length(); ++i) {
		if (input[i] == '.') {
			if (node->left_node) {
				node = node->left_node;
				added_node = true;
			}
			if ((i == input.length() - 1 || input[i + 1] == ' ') && added_node) {
				the_output += node->alpha;
			}
		}
		if (input[i] == ' ') {
			node = root_node;
			added_node = false;
		}
		if (input[i] == '-') {
			if (node->right_node) {
				node = node->right_node;
				added_node = true;
			}
			if ((i == input.length() - 1 || input[i + 1] == ' ') && added_node) {
				the_output += node->alpha;
			}
		}
		added_node = false;
	}
	return the_output;
}

string BT::encode(string text) {  // wrapper function for encode() fcn.
	string the_output = "";
	BTNode *node = root_node;
	string input = text;
	string::size_type node_ptr = 0;
	string out;
	the_output = encode(input, node, node_ptr, out);
	return the_output;
}

string BT::encode(string input, BTNode *node, string::size_type &node_ptr, string out) {
	string the_output = out;
	if (node) {
		if (input[node_ptr] == node->alpha) {
			the_output += node->morse_code;
			the_output += ' '; ++node_ptr;
			node = root_node;
		}
		if (node_ptr < input.length()) {
			if (input[node_ptr] != node->alpha && node->left_node) {
				the_output = encode(input, node->left_node, node_ptr, the_output);
			}
			if (input[node_ptr] != node->alpha && node->right_node) {
				the_output = encode(input, node->right_node, node_ptr, the_output);
			}
		}
		return the_output;
	}
	else {
		return "";
	}
}
