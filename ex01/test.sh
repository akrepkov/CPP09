#!/bin/bash

./RPN "3 +"
echo -e "Should be Error: Not enough arguments before operator\n"

./RPN "+"
echo -e "Should be Error: Not enough arguments before operator\n"

./RPN "3 4 +"
echo -e "Should be 7\n"

./RPN "3 4 5 +"
echo -e "Should be Error: Invalid input\n"

./RPN "3 0 /"
echo -e "Should be Error: Division by zero\n"

./RPN "3 4 &"
echo -e "Should be Error: Invalid operator\n"

./RPN "3 5 -"
echo -e "Should be -2\n"

./RPN "7 10 -"
echo -e "Should be Error: Invalid input\n"

./RPN "3 4 2 * +"
echo -e "Should be 11\n"

./RPN "10 5 2 / +"
echo -e "Should be Error: Invalid input\n"

./RPN ""
echo -e "Should be Error: Invalid input\n"

./RPN "3"
echo -e "Should be 3\n"

./RPN "3 5 2 * + 6 2 / +"
echo -e "Should be 16\n"

./RPN "2 3 + 5 * 7 +"
echo -e "Should be 32\n"

./RPN "3 a +"
echo -e "Should be Error: Invalid input\n"

./RPN "3 4 + a"
echo -e "Should be Error: Invalid input\n"

./RPN "8 2 *"
echo -e "Should be 16\n"

./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
echo -e "Should be 10\n"
