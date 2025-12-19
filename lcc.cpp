#include <iostream>
#include <string>

int main() {
	std::string line;

	while (std::getline(std::cin, line)) {
		std::cout << line.size() << '\t' << line << '\n';
	}

	return 0;
}
