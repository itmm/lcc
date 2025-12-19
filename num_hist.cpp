#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using count_map = std::map<int, int>;

static inline count_map read_counts() {
	std::string line;
	count_map counts;

	while (std::getline(std::cin, line)) {
		std::istringstream in { line };
		int count;
		in >> count;
		++counts[count];
	}

	return counts;
}

using reverse_map = std::map<int, std::vector<int>>;

static inline reverse_map reverse_counts(const count_map& counts) {
	reverse_map reverse;

	for (auto entry : counts) {
		reverse[entry.second].push_back(entry.first);
	}

	return reverse;
}

int main() {
	count_map counts { read_counts() };
	reverse_map reverse { reverse_counts(counts) };

	for (auto entry : reverse) {
		for (auto item : entry.second) {
			std::cout << item << '\t' << entry.first << '\n';
		}
	}

	return 0;
}
