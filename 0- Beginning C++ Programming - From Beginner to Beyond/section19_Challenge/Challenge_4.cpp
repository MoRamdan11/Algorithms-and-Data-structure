// Section 19: IO and Streams
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::ifstream in_file {"./romeoandjuliet", std::ios::in};
    if(!in_file) {
        std::cerr << "File not found";
        return 1;
    }
    std::ofstream out_file{"./romeoandjuliet_out", std::ios::out | std::ios::trunc};
    if(!out_file) {
        std::cerr << "Path not found";
        return 1;
    }
    std::string line{};
    int line_num{1};
    while(std::getline(in_file, line)) {
        if(line.length() != 0)
            out_file << std::setw(5)<< std::left << line_num++;
        out_file << line << std::endl;
    }
    return 0;

}

