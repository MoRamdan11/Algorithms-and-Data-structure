// Section 6: Variables and Constants
// Challenge 
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    const double small_room_price{25};
    const double large_room_price{35};
    const double tax_rate{6.0/100};
    const int valid_days {30};
    cout << "Hello, Welcome to Franks's carpet cleaning service\n\n";    
    cout << "How many small rooms? ";
    int small_rooms_number {0};
    cin >> small_rooms_number;
    cout << "How many large rooms? ";
    int large_rooms_number {0};
    cin >> large_rooms_number;
    cout << "Number of small rooms: " << small_rooms_number << endl;
    cout << "Number of large rooms: " << large_rooms_number << endl;
    cout << "Price per small room: " << small_room_price << endl;
    cout << "Price per large room: " << large_room_price << endl;
    double cost = (small_rooms_number * small_room_price) + (large_rooms_number * large_room_price);
    cout << "Cost: " << cost << endl;
    double tax = cost * tax_rate;
    cout << "Tax: " << tax << endl;
    cout << "====================================================" << endl;
    cout << "Total estimate: " << cost + tax << endl;
    cout << "The estimation is valid for " << valid_days << endl;
    return 0;
}