#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>
#include <algorithm>

typedef std::string str;
typedef std::vector<str> str_vec;
typedef std::unordered_map<str, str> str_str_m;

void rps(void);
bool includes(const str_vec& data, str query);
str trim(str original);
str lower(const str& original);

int main(void)
{
	while (true)
	{
		std::cout << "\x1b[1;32m[ROCK, PAPER, SCISSORS]:\x1b[0m" << '\n';
		rps();
		std::cout << "\x1b[1;31m[GAME OVER]\x1b[0m" << '\n';
	}

	return 0;
}

void rps(void)
{
	str input1;
	str input2;

	str_vec options = { "rock", "paper", "scissors" };
	
	do
	{
		std::cout << "\x1b[1;32mPlayer 1 (rock, paper, scissors):\x1b[0m ";
		std::getline(std::cin >> std::ws, input1);
		input1 = trim(lower(input1));

		if (std::cin.fail() || !includes(options, input1))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\x1b[1;31mInvalid input! Insert a valid option.\x1b[0m" << '\n';
		}

	} while (!includes(options, input1));

	do
	{
		std::cout << "\x1b[1;32mPlayer2 (rock, paper, scissors):\x1b[0m ";
		std::getline(std::cin >> std::ws, input2);
		input2 = trim(lower(input2));

		if (std::cin.fail() || !includes(options, input2))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\x1b[1;31mInvalid input! Insert a valid option.\x1b[0m" << '\n';
		}
	} while (!includes(options, input2));

	static const str_str_m winning_moves = {
		{"rock", "scissors"},
		{"paper", "rock"},
		{"scissors", "paper"},
	};

	if (input1.compare(input2) == 0)
	{
		std::cout << "\x1b[1;33mDraw!\x1b[0m" << '\n';
		return;
	}
	else if (winning_moves.at(input1) == input2)
	{
		std::cout << "\x1b[1;32mPlayer 1 wins!\x1b[0m" << '\n';
		return;
	}
	else
	{
		std::cout << "\x1b[1;32mPlayer 2 wins!\x1b[0m" << '\n';
		return;
	}
}

bool includes(const str_vec& data, str query)
{
	return std::find(data.begin(), data.end(), query) != data.end();
}

str trim(str original)
{
	size_t first = original.find_first_not_of(" \t\n\r\f\v");

	if (first == std::string::npos)
	{
		return "";
	}

	size_t last = original.find_last_not_of(" \t\n\r\f\v");

	return original.substr(first, last - first + 1);
}

str lower(const str& original)
{
	str result = original;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}