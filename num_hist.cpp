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

static int ch;

static inline size_t read_number() {
	size_t number { 0 };
	if (ch < '0' || ch > '9') {
		std::cerr << "line does not start with number\n";
		std::exit(10);
	}
	for (; ch >= '0' && ch <= '9'; ch = std::cin.get()) {
		number = add_digit(number, ch - '0');
	}
	return number;
}

static inline count_map read_counts() {
	count_map counts;
	ch = std::cin.get();

	for (;;) {
		if (ch == EOF) { break; }
		size_t number { read_number() };
		counts[number] = inc(counts[number]);
		for (; ch != EOF; ch = std::cin.get()) {
			if (ch == '\n') { ch = std::cin.get(); break; }
		}
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
