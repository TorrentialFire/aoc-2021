#include <iostream>
#include <fstream>
#include <string>

int main() {

    //std::cout << "Hello, advent!\n";
    
    std::ifstream f_input;
    f_input.open("../input.txt");

    if (!f_input.is_open()) {
        std::cout << "Could not open input file.\n";
    }

    std::string forward("forward");
    std::string up("up");
    std::string down("down");

    std::string command;
    int value;

    int aim = 0;
    int pos_x = 0;
    int depth = 0;

    while (f_input >> command >> value) {
        if (command == forward) {
            pos_x += value;
            depth += (aim * value);
        } else if (command == up) {
            aim -= value;
        } else if (command == down) {
            aim += value;
        }
    }

    std::cout << "The product of the final position (" 
        << pos_x 
        << ") and depth (" 
        << depth 
        << ") is " 
        << pos_x * depth 
        << ".\n"; 

    return EXIT_SUCCESS;
}