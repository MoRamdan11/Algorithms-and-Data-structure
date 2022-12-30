// Section 11: Functions
// Challenge

#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void displayMenu();
void get_selection(char &selection);
void printVector(const vector<int> &numbers);
void add_number_tolist(vector<int> &numbers);
void calc_list_mean(const vector<int> &numbers);
void display_smallest_inlist(const vector<int> &numbers);
void display_largest_inlist(const vector<int> &numbers);
int find_number_inlist(const vector<int> &numbers, int search_number);
void handle_find(const vector<int> &numbers);
void quit();

int main() {
    char selection{};
    vector <int> numbers;
    do {
        displayMenu();
        get_selection(selection);
        switch(selection) {
            case 'P':
                printVector(numbers);
                break;
            case 'A':
                add_number_tolist(numbers);
                break;
            case 'M':
                calc_list_mean(numbers);
                break;
            case 'S':
                display_smallest_inlist(numbers);
                break;
            case 'L':
                display_largest_inlist(numbers);
                break;
            case 'F':
                handle_find(numbers);
                break;
            case 'Q':
                quit();
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }
    } while(selection != 'Q');
    return 0;
}

void displayMenu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number"  << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number"  << endl;
    cout << "F - Find number in the list"     << endl;
    cout << "Q - Quit" << endl;
}

void get_selection(char &selection) {
    cout << "Enter your choice: ";
    cin >> selection;
    selection = toupper(selection);
}

void printVector(const vector<int> &numbers) {
    if(numbers.size() == 0)
        cout << "[] - the list is empty" << endl;
    else {
        cout << "[ ";
        for(int number : numbers)
            cout << number << " ";
        cout << "]" << endl;
    }
    
}

void add_number_tolist(vector<int> &numbers) {
    int number{};
    cout << "Enter a number: ";
    cin >> number;
    numbers.push_back(number);
    cout << number << " added" << endl;
}

void calc_list_mean(const vector<int> &numbers) {
    if(numbers.size() == 0)
        cout << "Unable to calculate the mean - no data" << endl;
    else {
        int sum{};
        double mean{};
        for(auto number : numbers)
            sum += number;
        mean = static_cast<double>(sum) / numbers.size();
        cout << "The mean of your list is " << mean << endl;
    }
}

void display_smallest_inlist(const vector<int> &numbers) {
    if(numbers.size() == 0)
        cout << "Unable to determine the smallest number - list is empty" << endl;
    else {
        int smallest{numbers.at(0)};
        for(int number : numbers) {
            if(smallest > number)
                smallest = number;
        }
        cout << "The smallest number is " << smallest << endl;
    }
}

void display_largest_inlist(const vector<int> &numbers) {
    if(numbers.size() == 0)
        cout << "Unable to determine the largest number - list is empty" << endl;
    else {
        int largest{numbers.at(0)};
        for(int number : numbers) {
            if(largest < number)
                largest = number;
        }
        cout << "The largest number is " << largest << endl;
    }
}

int find_number_inlist(const vector<int> &numbers, int search_number) {
    int index_of_number{};
    for(size_t i{}; i < numbers.size(); i++) {
        if(search_number == numbers.at(i)) {
            index_of_number = i;
            break;
        }
        index_of_number = -1;
    }
    return index_of_number;
}

void handle_find(const vector<int> &numbers) {
    int search_number{};
    cout << "Enter a number: ";
    cin >> search_number;
    if(numbers.size() == 0)
        cout << "List is empty" << endl;
    else {
        int index_of_number{find_number_inlist(numbers, search_number)};
        if(index_of_number == -1)
            cout << "Number " << search_number << " not found in the list" << endl;
        else
            cout << "Number " << search_number << " is found in list at [" << find_number_inlist(numbers, search_number) << "]" << endl;
    }
}

void quit() {
    cout << "Goodbye" << endl;
}