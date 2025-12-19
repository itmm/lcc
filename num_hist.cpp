#include <cstdio>
#include <iostream>
#include <limits>
#include <map>
#include <ranges>
#include <vector>

using count_map = std::map<size_t, size_t>;

static inline size_t add_digit(size_t cur, int digit) {
	if (cur <= (std::numeric_limits<size_t>::max() - digit)/10) {
		return cur * 10 + digit;
	}
	std::cerr << "parse overflow: " << cur << digit << '\n';
	std::exit(10);
}

static inline size_t inc(size_t cur) {
	if (cur < std::numeric_limits<size_t>::max()) {
		return cur + 1;
	}
	std::cerr << "inc overflow: " << cur << '\n';
	std::exit(10);
}

static inline count_map read_counts() {
	count_map counts;
	int ch;
	size_t number { 0 };
	bool number_parsed { false };

	while ((ch = std::cin.get()) != EOF) {
		if (! number_parsed) {
			if (ch >= '0' && ch <= '9') {
				number = add_digit(number, ch - '0');
			} else {
				counts[number] = inc(counts[number]);
				number = 0;
				number_parsed = true;
			}
		}
		if (ch == '\n') { number_parsed = false; }
	}

	return counts;
}

using reverse_map = std::map<size_t, std::vector<size_t>>;

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
		for (size_t item : entry.second) {
			std::cout << item << '\t' << entry.first << '\n';
		}
	}

	return 0;
}
