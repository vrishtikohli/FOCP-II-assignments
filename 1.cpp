#include <iostream>
#include <string>
using namespace std;
bool canTurnOff(string &s, int n, int k, int l) {
    int ops = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ops++;
            if (ops > k) return false;
            i += l;
        } else {
            i++;
        }
    }
    return ops <= k;
}
int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int left = 1, right = n;
    int ans = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canTurnOff(s, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}