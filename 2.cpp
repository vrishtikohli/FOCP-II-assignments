#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

// Generate primes up to 3162
void generatePrimes() {
    int limit = 3162;
    vector<bool> isPrime(limit + 1, true);

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
}

int countDistinctPrimes(int n) {
    int count = 0;

    for (int p : primes) {
        if (p * p > n) break;

        if (n % p == 0) {
            count++;
            while (n % p == 0)
                n /= p;
        }
    }

    if (n > 1) count++; // remaining prime

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    generatePrimes();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = countDistinctPrimes(n);
        cout << (1 << k) << '\n'; // 2^k
    }

    return 0;
}