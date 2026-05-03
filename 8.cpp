#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
int main() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    vector<string> excuses = {
        "{name} tried to submit the homework, but the file developed stage fright.",
        "{name}'s dog emotionally connected with the homework and destroyed it.",
        "{name} finished everything but forgot to attach the file.",
        "{name}'s laptop froze at the exact moment of submission.",
        "{name} and the assignment had a misunderstanding.",
        "{name} started on time, but time didn't cooperate.",
        "{name} almost finished but got stuck on the last question.",
        "{name} wrote everything, but it mysteriously disappeared.",
        "{name} was about to upload when WiFi gave up.",
        "{name} took a short break that became a long one.",
        "{name} completed it but saved it in the wrong folder.",
        "{name}'s brain worked, but hands didn't."
    };
    // ✅ High-resolution seed (nanoseconds)
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<> dist(0, excuses.size() - 1);
    string excuse = excuses[dist(gen)];
    // Replace {name}
    size_t pos;
    while ((pos = excuse.find("{name}")) != string::npos) {
        excuse.replace(pos, 6, name);
    }
    cout << "\nYour excuse:\n" << excuse << endl;
    return 0;
}
   
