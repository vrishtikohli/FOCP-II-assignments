#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;
int main() {
    // Seed random generator (different output each run)
    srand(time(0));
    // Take user input
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    // Roast templates (name is NOT at the beginning)
    vector<string> roasts = {
        "You bring everyone so much joy... when you leave the room, {name}.",
        "If laziness were an Olympic sport, you'd come second, {name}.",
        "Your brain is like the internet-lots of connections, but no useful content, {name}.",
        "I’d explain it to you, {name}, but I left my crayons at home.",
        "You have something on your chin... no, the third one down, {name}.",
        "I'd agree with you, {name}, but then we'd both be wrong.",
        "You're like a cloud, {name}. When you disappear, it’s a beautiful day.",
        "Somewhere out there is a tree tirelessly producing oxygen for you, {name}. You owe it an apology.",
        "You're not stupid; you just have bad luck thinking, {name}.",
        "If I had a dollar for every smart thing you said, I'd be broke, {name}."
    };
    // Pick random roast
    int randomIndex = rand() % roasts.size();
    string selectedRoast = roasts[randomIndex]
    // Replace {name} with actual name
    size_t pos = selectedRoast.find("{name}");
    while (pos != string::npos) {
        selectedRoast.replace(pos, 6, name);
        pos = selectedRoast.find("{name}", pos + name.length());
    }
    // Output result (removed emoji to avoid encoding issues)
    cout << "\nRoast: " << selectedRoast << endl;
    return 0;
}
