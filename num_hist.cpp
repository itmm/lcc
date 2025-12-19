#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int main() {
	std::string line;
	std::map<int, int> counts;

	while (std::getline(std::cin, line)) {
		std::istringstream in { line };
		int count;
		in >> count;
		++counts[count];
	}

	std::map<int, std::vector<int>> reverse;

	for (auto entry : counts) {
		reverse[entry.second].push_back(entry.first);
	}

	for (auto entry : reverse) {
		for (auto item : entry.second) {
			std::cout << item << '\t' << entry.first << '\n';
		}
	}

	return 0;
}
