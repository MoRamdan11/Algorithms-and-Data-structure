// Section 9: Controlling Program Flow
// Challenge
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    char selection{};
    vector<int> numbers{};
    do {
        cout << "P - Print numbers\n" << "A - Add a number\n" << "M - Display mean of the numbers\n"
            << "S - Display the smallest number\n" << "L - Display the largest number\n"
            << "F find\n" << "C clear\n" << "Q - Quit" << endl;
        cin >> selection;
        switch(selection) {
            case 'p':
            case 'P': {
                if(numbers.size() == 0)
                    cout << "[] - the list is empty" << endl;
                else {
                    cout << "[ ";
                    for(auto number : numbers)
                        cout << number << ", ";
                    cout << "]" << endl;
                }
                break;
            }
            case 'a':
            case 'A': {
                bool if_dupplicate{};
                int added_number{};
                cin >> added_number;
                for(auto number : numbers) {
                    if(number == added_number) {
                        cout << "duplicate number" << endl;
                        if_dupplicate = true;
                        break;
                    }
                }
                if(!if_dupplicate){
                    numbers.push_back(added_number);
                    cout << added_number << " added" << endl;
                }
                break;
            }
            case 'm':
            case 'M': {
                if(numbers.size() == 0) {
                    cout << "Unable to calculate the mean - no data" << endl;
                    break;
                }
                double sum{}, average{};
                for(auto number : numbers)
                    sum += number;
                average = sum / numbers.size();
                cout << "The mean is " << average << endl;
                break;
            }
            case 's':
            case 'S': {
                if(numbers.size() == 0) {
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                    break;
                }
                int smallest_number {numbers.at(0)};
                for(auto number: numbers) {
                    if(smallest_number < number)
                        smallest_number = number;
                }
                cout << "The smallest number is " << smallest_number << endl;
                break;
            }
            case 'l':
            case 'L': {
                if(numbers.size() == 0) {
                    cout << "Unable to determine the largest number - list is empty" << endl;
                    break;
                }
                int largest_number {numbers.at(0)};
                for(auto number: numbers) {
                    if(largest_number < number)
                        largest_number = number;
                }
                cout << "The largest number is " << largest_number << endl;
                break;
            }
            case 'f':
            case 'F': {
                int searched_number{}, index{-1};
                cin >> searched_number;
                for(int i = 0; i < numbers.size(); i++) {
                    if(searched_number == numbers.at(i))
                        index = i;
                        break;
                }
                if(index == -1)
                    cout << "Number " << searched_number << " not found in list" << endl;
                else
                    cout << "Number " << searched_number << " found in list @ " << index << endl;
                break;
            }
            case 'c':
            case 'C':
                numbers.clear();
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }
     }while(selection != 'q' && selection != 'Q');
    return 0;
}

