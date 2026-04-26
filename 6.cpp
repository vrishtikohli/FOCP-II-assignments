#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Bank {
    unordered_map<string, long long> users;

public:
    string create(string x, long long y) {
        if (users.find(x) != users.end()) {
            users[x] += y;
            return "false";
        } else {
            users[x] = y;
            return "true";
        }
    }

    string debit(string x, long long y) {
        if (users.find(x) != users.end() && users[x] >= y) {
            users[x] -= y;
            return "true";
        }
        return "false";
    }

    string credit(string x, long long y) {
        if (users.find(x) != users.end()) {
            users[x] += y;
            return "true";
        }
        return "false";
    }

    long long balance(string x) {
        if (users.find(x) != users.end()) {
            return users[x];
        }
        return -1;
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bank;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "CREATE") {
            string x; long long y;
            cin >> x >> y;
            cout << bank.create(x, y) << endl;
        } else if (query == "DEBIT") {
            string x; long long y;
            cin >> x >> y;
            cout << bank.debit(x, y) << endl;
        } else if (query == "CREDIT") {
            string x; long long y;
            cin >> x >> y;
            cout << bank.credit(x, y) << endl;
        } else if (query == "BALANCE") {
            string x;
            cin >> x;
            cout << bank.balance(x) << endl;
        }
    }
    return 0;
}
