#pragma once

#include <cstdio>
#include <iostream>
#include <limits>
#include <map>

class Parser {
		int ch;

		static inline size_t add_digit(size_t cur, int digit);
		inline size_t read_number();
		static inline size_t inc(size_t cur);

	public:
		using count_map = std::map<size_t, size_t>;

		Parser(): ch { std::cin.get() } { }

		inline count_map parse();
};

inline size_t Parser::add_digit(size_t cur, int digit) {
	if (cur <= (std::numeric_limits<size_t>::max() - digit)/10) {
		return cur * 10 + digit;
	}
	std::cerr << "parse overflow: " << cur << digit << '\n';
	std::exit(10);
}

inline size_t Parser::read_number() {
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

inline size_t Parser::inc(size_t cur) {
	if (cur < std::numeric_limits<size_t>::max()) {
		return cur + 1;
	}
	std::cerr << "inc overflow: " << cur << '\n';
	std::exit(10);
}

inline Parser::count_map Parser::parse() {
	count_map counts;

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

