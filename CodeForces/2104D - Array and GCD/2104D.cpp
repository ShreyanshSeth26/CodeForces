#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> ns(t);
    vector<vector<int>> arr(t);
    int max_n = 0;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ns[i] = n;
        max_n = max(max_n, n);
        arr[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    const int MAXP = 6000000;
    vector<char> is_prime(MAXP + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; (long long)i * i <= MAXP; i++) {
        if (is_prime[i]) {
            for (long long j = 1LL * i * i; j <= MAXP; j += i)
                is_prime[j] = 0;
        }
    }

    vector<int> primes;
    primes.reserve(max_n);
    for (int i = 2; i <= MAXP && (int)primes.size() < max_n; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
    vector<long long> P_sum(max_n + 1, 0);
    for (int i = 1; i <= max_n; i++) {
        P_sum[i] = P_sum[i - 1] + primes[i - 1];
    }

    for (int ti = 0; ti < t; ti++) {
        int n = ns[ti];
        auto &v = arr[ti];
        sort(v.begin(), v.end(), greater<int>());

        long long sum = 0;
        int best = 0;
        for (int j = 0; j < n; j++) {
            sum += v[j];
            int k = j + 1;
            if (sum >= P_sum[k]) {
                best = k;
            }
        }

        cout << (n - best) << "\n";
    }
    return 0;
}
