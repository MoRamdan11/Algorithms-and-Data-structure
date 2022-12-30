// Section 19: IO and Streams
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void print_header() {
    cout << std::left << std::setw(20) << "Student"
         << std::right << std::setw(10) << "Score" << endl;
    cout << std::setw(30) << std::setfill('-') << "" << endl;
    cout << std::setfill(' ');
}

int process_response(std::string model_answer, std::string student_answer) {
    int student_score{};
    for(size_t i{}; i < model_answer.length(); i++) {
            if(student_answer.at(i) == model_answer.at(i))
                student_score++;
    }
    return student_score;
}

void print_footer(int scores_sum, int student_num) {
    cout << std::setw(30) << std::setfill('-') << "" << endl;
    cout << std::setfill(' ');
    cout << std::left << std::setw(20) << "Average"
         << std::right << std::setw(10) 
         << (static_cast<double>(scores_sum) / student_num) << endl;
}

int main() {
    std::string student_name{}, model_answer{}, student_answer{};
    int student_score{}, student_num{}, scores_sum{};
    std::ifstream file{"./responses.txt"};
    if(!file) {
        cout << "File Not Found" << endl;
        return 1;
    }
    file >> model_answer;
    print_header();
    while(!file.eof()) {
        student_score = 0;
        file >> student_name >> student_answer;
        student_score = process_response(model_answer, student_answer);
        cout << std::left << std::setw(20) << student_name ;        
        cout << std::right << std::setw(10) << student_score << endl;
        scores_sum += student_score;
        student_num++;
    }
    print_footer(scores_sum, student_num);
    return 0;
}

