#include <cstdio>
#include <iostream>
#include <map>
#include <ranges>
#include <vector>

using count_map = std::map<int, int>;

static inline count_map read_counts() {
	count_map counts;
	int ch;
	int number { 0 };
	bool number_parsed { false };

	while ((ch = std::cin.get()) != EOF) {
		if (! number_parsed) {
			if (ch >= '0' && ch <= '9') {
				number = number * 10 + (ch - '0');
			} else {
				++counts[number];
				number = 0;
				number_parsed = true;
			}
		}
		if (ch == '\n') { number_parsed = false; }
	}

	return counts;
}

using reverse_map = std::map<int, std::vector<int>>;

static inline reverse_map reverse_counts(const count_map& counts) {
	reverse_map reverse;

	for (const auto& entry : counts) {
		reverse[entry.second].push_back(entry.first);
	}

	return reverse;
}

int main() {
	count_map counts { read_counts() };
	reverse_map reverse { reverse_counts(counts) };

	for (const auto& entry : reverse | std::ranges::views::reverse) {
		for (int item : entry.second) {
			std::cout << item << '\t' << entry.first << '\n';
		}
	}

	return 0;
}
