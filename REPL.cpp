#include <iostream>
#include "stdint.h"
#include <string>

int main()
{
	uint8_t tape[30000]{};
	uint16_t dp{};

	std::cout << "Simple Brainfuck REPL\n";

	while (true)
	{
		char input{};

		std::cout << ">> ";

		std::string code{};
		std::getline(std::cin, code);

		for (uint16_t ip = 0; ip < code.size(); ip++)
		{
			switch (code[ip])
			{
			case '>':
				dp = (dp + 1) % 30000;
				break;
			case '<':
				dp = (dp + 29999) % 30000;
				break;
			case '+':
				tape[dp]++;
				break;
			case '-':
				tape[dp]--;
				break;
			case '.':
				std::cout << tape[dp] << "\n";
				break;
			case ',':
				std::cin >> input;
				tape[dp] = input;
				break;
			case '[':
				if (tape[dp] == 0)
				{
					int depth = 1;
					while (ip < code.size() && depth > 0)
					{
						ip++;

						if (code[ip] == '[') depth++;
						else if (code[ip] == ']') depth--;
					}
				}
				break;
			case ']':
				if (tape[dp] != 0)
				{
					int depth = 1;
					while (ip > 0 && depth > 0)
					{
						ip--;

						if (code[ip] == ']') depth++;
						else if (code[ip] == '[') depth--;
					}
				}
				break;
			default:
				break;
			}
		}
	}
}
