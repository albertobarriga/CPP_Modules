#include <iostream>
#include <string>
#include <fstream>

int main (int argc, char **argv) {
	if (argc != 4) {
		std::cout << "ERROR: The program need 3 arguments." << std::endl;
		return (1);
	}
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream file(file_name);
	std::string line;

	std::ofstream out_file(file_name + ".replace");

	if (!out_file)
		std::cout << "ERROR file cant be create" << std::endl;
	
	std::string text;
	if (file.is_open()) {
		while (getline(file, line)) {
			text += line;
		}
	}

	int pos;
	pos = 0;
	while ((pos = text.find(s1, pos)) != -1) {
		text = text.substr(0, pos) + s2 + text.substr(pos + s1.length());
		pos += s2.length();
	}
	out_file << text << std::endl;
	file.close();
	out_file.close();
}