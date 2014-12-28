#include "the_tree.h"
#include <cctype>
#include <iostream>
#include <string>
#include <fstream>

// Programming Assignment 3 - Data Structures
// Abdul Wahab

using namespace std;

string select() {
	string choice;
	cout << "Enter 'd' for decode, or 'e' for encode: \n " << endl;
	getline(cin, choice);
	for (string::size_type i = -0; i < choice.length(); i++) {
		tolower(choice[i]);
	}
	return choice;
}



string inputted_text() {
	string the_text;
	cout << "Type in the Morse Code to decode:  \n" << endl;
	getline(cin, the_text);
	return the_text;
}


string caseLow(string lower) {
for (string::size_type i = 0; i < lower.length(); i++) {
tolower(lower[i]);
}
return lower;
}


string inside_encode() {
	string text;
	string the_output = "";
	cout << "Type in a text in English to encode: \n " << endl;
	getline(cin, text);
	text = caseLow(text);
	for (string::size_type i = 0; i < text.length(); i++) {
		if (isalpha(text[i]) || text[i] == '.' || text[i] == '-') {
			the_output.append(1, text[i]);
		}
	}
	return the_output;
}



bool stringChecker(string input) {
	if (!input.size()) {
		return false;
	}
	for (string::size_type i = 0; i < input.length(); ++i) {
		if (input[i] != '.' && input[i] != '-' && input[i] != ' ') {
			return false;
		}
	}
	return true;
}

int main() {
	string code_main = "";
	ifstream file_open;
	string to_lowered = "";
	string the_choice = "";
	string text_encode = "";
	string text_decode = "";

	BT tree;
	bool added_node = false;








	file_open.open("morse-code.txt");
	if (!file_open) {
		cout << "Could not find the file. " << std::endl;
	}
	else{
		tree.insert('0', "*");
		while (getline(file_open, code_main)) {
			tree.insert(code_main[0], code_main.substr(2, code_main.length() - 2));
		}
		do{
			the_choice = select();
			if (the_choice == "d") {
				text_decode = inputted_text();
				to_lowered = caseLow(text_decode);
				while (!stringChecker(to_lowered)) {
					text_decode = inputted_text();
					to_lowered = caseLow(text_decode);
				}
				cout << "The decoded text is: \n" << tree.decode(text_decode, added_node) << endl;
			}

			else if (the_choice == "e") {
				text_decode = inside_encode();
				cout << "The encoded text is:  \n " << tree.encode(text_decode) << endl;
			}
		} while (the_choice == "d" || the_choice == "e");
		file_open.close();
	}
	system("pause");
	return 0;
}
