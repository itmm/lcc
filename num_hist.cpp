#include <iostream>
#include <map>
#include <ranges>
#include <vector>

#include "parser.h"

using reverse_map = std::map<size_t, std::vector<size_t>>;

static inline reverse_map reverse_counts(const Parser::count_map& counts) {
	reverse_map reverse;

	for (const auto& entry : counts) {
		reverse[entry.second].push_back(entry.first);
	}

	return reverse;
}

int main() {
	Parser parser;
	Parser::count_map counts { parser.parse() };
	reverse_map reverse { reverse_counts(counts) };

	for (const auto& entry : reverse | std::ranges::views::reverse) {
		for (size_t item : entry.second) {
			std::cout << item << '\t' << entry.first << '\n';
		}
	}

	return 0;
}
