#include <bits/stdc++.h>
using namespace std;

string solve(int N, vector<int>& A) {
    sort(A.rbegin(), A.rend()); // descending

    unordered_set<int> alexSet, bobSet;
    int alex = 0, bob = 0;
    bool alexTurn = true;

    for (int i = 0; i < N; i++) {
        if (alexTurn) {
            if (alexSet.count(A[i]) == 0) {
                alex += A[i];
                alexSet.insert(A[i]);
                alexTurn = false;
            }
        } else {
            if (bobSet.count(A[i]) == 0) {
                bob += A[i];
                bobSet.insert(A[i]);
                alexTurn = true;
            }
        }
    }

    return (alex > bob) ? "Alex" : "Bob";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        cout << solve(N, A) << endl;
    }
}
