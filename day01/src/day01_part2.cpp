#include <iostream>
#include <fstream>
#include <vector>

int read_input_file(const char* filename, std::vector<int>& vector);
void calculate_windowed_sums(const std::vector<int>& values, std::vector<int>& sums);
int count_increases(const std::vector<int>& values);

int main() {

    std::vector<int> depth_values;

    if (!read_input_file("../input.txt", depth_values)) {
        std::cout << "Cound not open input file.\n";
        return EXIT_FAILURE;
    }
    
    std::vector<int> sums;
    calculate_windowed_sums(depth_values, sums);

    int num_increases = count_increases(sums);

    std::cout << "The sums increased " << num_increases << " times.\n";

    return EXIT_SUCCESS;
}

int read_input_file(const char* filename, std::vector<int>& vector) {
    std::ifstream f_input;
    f_input.open(filename);

    if (!f_input.is_open()) {
        return 0;
    }
    
    int val;
    while (f_input >> val) {
        vector.push_back(val);
    }

    f_input.close();
    return 1;
}

void calculate_windowed_sums(const std::vector<int>& values, std::vector<int>& sums) {

    for (auto it = values.begin(); it != (values.end() - 2); it++) {
        int sum = *it + *(it + 1) + *(it + 2);
        sums.push_back(sum);
    }

}

int count_increases(const std::vector<int>& values) {
    
    int count = 0;
    int last = values.at(0);
    int curr;
    for (auto it = (values.begin() + 1); it != values.end(); it++) {
        curr = *it;
        if (curr > last) {
            count++;
        }
        last = curr;
    }

    return count;
}