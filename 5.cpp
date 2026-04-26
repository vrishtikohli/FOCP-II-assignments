#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MovieTicket {
private:
    // Maps Movie ID -> Set of Customer IDs who have booked
    unordered_map<string, unordered_set<string>> movieBookings;
    const int MAX_SLOTS = 100;

public:
    bool book(string customerId, string movieId) {
        // Check if the movie already has a set; if not, it's implicitly created
        auto& bookings = movieBookings[movieId];

        // Condition: Already booked OR movie is full
        if (bookings.find(customerId) != bookings.end() || bookings.size() >= MAX_SLOTS) {
            return false;
        }

        bookings.insert(customerId);
        return true;
    }

    bool cancel(string customerId, string movieId) {
        // Check if movie exists and customer is in the set
        if (movieBookings.count(movieId) && movieBookings[movieId].count(customerId)) {
            movieBookings[movieId].erase(customerId);
            return true;
        }
        return false;
    }

    bool is_booked(string customerId, string movieId) {
        if (movieBookings.count(movieId)) {
            return movieBookings[movieId].count(customerId) > 0;
        }
        return false;
    }

    int available_tickets(string movieId) {
        if (movieBookings.count(movieId)) {
            return MAX_SLOTS - (int)movieBookings[movieId].size();
        }
        return MAX_SLOTS;
    }
};

int main() {
    int Q;
    if (!(cin >> Q)) return 0;

    MovieTicket system;
    string command, X, Y;

    while (Q--) {
        cin >> command;

        if (command == "BOOK") {
            cin >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << endl;
        } 
        else if (command == "CANCEL") {
            cin >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << endl;
        } 
        else if (command == "IS_BOOKED") {
            cin >> X >> Y;
            cout << (system.is_booked(X, Y) ? "true" : "false") << endl;
        } 
        else if (command == "AVAILABLE_TICKETS") {
            cin >> Y;
            cout << system.available_tickets(Y) << endl;
        }
    }

    return 0;
}
