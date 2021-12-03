#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream f_input;
    f_input.open("../input.txt");

    if (!f_input.is_open()) {
        std::cout << "Could not open input file.\n";
    }

    std::vector<int> depth_values;
    int input_depth;

    while (f_input >> input_depth) {
        depth_values.push_back(input_depth);
    }
    f_input.close();

    int count = 0;
    int last_depth = depth_values.at(0);
    int curr_depth;
    for (auto it = (depth_values.begin() + 1); it != depth_values.end(); it++) {
        curr_depth = *it;
        if (curr_depth > last_depth) {
            count++;
        }
        last_depth = curr_depth;
    }

    // "The depth increased X times."
    std::cout << "The depth increased " << count << " times.\n";

    return 0;
}