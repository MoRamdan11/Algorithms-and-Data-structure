// Section 20: The Standard Template Library (STL)
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing:\n" << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for(const auto &song : playlist)
        std::cout << song << std::endl;
    std::cout << "Current Song:\n" << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char choice{};
    while(choice != 'q') {
        display_menu();
        std::cin >> choice;
        choice = tolower(choice);
        switch(choice) {
            case 'f':
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            case 'n':
                current_song++;
                if(current_song == playlist.end())
                    current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            case 'p':
                if(current_song == playlist.begin()) {
                    current_song = playlist.end();
                }
                current_song--;
                play_current_song(*current_song);
                break;
            case 'a': {
                std::cout << "Enter song name: ";
                std::string song_name;
                std::cin >> song_name;
                std::cout << "Enter song artist: ";
                std::string song_artist;
                std::cin >> song_artist;
                std::cout << "Enter song rating (1 - 5): ";
                int song_rating;
                std::cin >> song_rating;
                while(song_rating < 1 || song_rating > 5) {
                    std::cout << "Please Enter song rating between 1 to 5: ";
                    std::cin >> song_rating;
                }
                playlist.insert(current_song, Song{song_name, song_artist, song_rating});
                play_current_song(*current_song);
                break;
            }
            case 'l':
                display_playlist(playlist, *current_song);
                break;
            default:
                std::cout << "Wrong input! Please enter correct choice from menu";
                display_menu();
                break;
        }
    }
    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
