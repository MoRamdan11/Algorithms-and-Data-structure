// Section 19: IO and Streams
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};
void print_ref_line(int line_length) {
    for(int i{}; i < line_length / 10; i++)
        std::cout << "1234567890";
    std::cout << std::endl;
}

void print_title_middle(std::string title, int line_length) {
    int diff{line_length - static_cast<int>(title.length())};
    std::cout << std::setw(diff / 2) << "" << title << std::endl;
}
int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };
    const int full_width{70};
    const int country_width{20};
    const int city_width{25};
    const int population_width{10};
    const int price_width{15};
    //DOUBLE
    std::cout << std::fixed << std::setprecision(2) << std::showpoint;

    print_ref_line(full_width);
    print_title_middle(tours.title, full_width);
    std::cout << std::left << std::setw(country_width) << "Country"
              << std::left << std::setw(city_width) << "City" 
                          << std::right << std::setw(population_width) << "Population" 
                          << std::right << std::setw(price_width) << "Price" 
                          << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    bool country_line{true};
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::left << std::setw(country_width) << country.name;
        country_line = true;
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw((country_line)? 0 : country_width) << "";
            std::cout << std::left << std::setw(city_width) << city.name 
                          << std::right << std::setw(population_width) << city.population 
                          << std::right << std::setw(price_width) << city.cost 
                          << std::endl;
            country_line = false;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}