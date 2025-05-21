#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

u64 mod_mul(u64 a, u64 b, u64 m) {
    u64 res = 0;
    a %= m;
    while (b) {
        if (b & 1) {
            res = res + a;
            if (res >= m) res -= m;
        }
        a = a << 1;
        if (a >= m) a %= m;
        b >>= 1;
    }
    return res;
}

u64 mod_pow(u64 a, u64 e, u64 m) {
    u64 r = 1;
    a %= m;
    while (e) {
        if (e & 1) r = mod_mul(r, a, m);
        a = mod_mul(a, a, m);
        e >>= 1;
    }
    return r;
}

bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (n % p == 0) return n == p;
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (u64 a : {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}) {
        if (a % n == 0) continue;
        u64 x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (u64 r = 1; r < s; r++) {
            x = mod_mul(x, x, n);
            if (x == n - 1) {
                comp = false;
                break;
            }
        }
        if (comp) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        u64 x;
        int k;
        cin >> x >> k;
        bool ok = false;
        if (k == 1) {
            ok = isPrime(x);
        } else if (x == 1 && k == 2) {
            ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
