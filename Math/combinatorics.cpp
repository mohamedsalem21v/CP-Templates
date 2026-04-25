#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
const int MOD = 1e9 + 7;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
#define int long long
using namespace std;

void FastIo()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

struct Combinatorics
{
private:
    const int Mod = 1e9 + 7;
    vector<ll> fac, inv_fact, inv;

public:
    // --- This is pecompute function --- //
    Combinatorics(int n, int mod = 1e9 + 7) : Mod(mod)
    {
        fac = inv_fact = inv = vector<ll>(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; i++)
            fac[i] = (fac[i - 1] * i) % Mod;

        inv[1] = 1;
        for (int i = 2; i <= n; i++)
            inv[i] = Mod - (Mod / i) * inv[Mod % i] % Mod;

        inv_fact[0] = 1;
        for (int i = 1; i <= n; i++)
            inv_fact[i] = (inv_fact[i - 1] * inv[i]) % Mod;
    }

    ll fact(int n) const
    {
        return fac[n];
    }

    ll powmod(ll x, ll y)
    {
        ll res = 1;
        x = x % MOD;
        if (x == 0)
            return 0;
        while (y > 0)
        {
            if (y & 1)
                res = (res * x) % MOD;
            y = y >> 1;
            x = (x * x) % MOD;
        }
        return res;
    }
    ll mul(ll a, ll b)
    {
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    ll divide(ll a, ll b)
    {
        return mul(a, powmod(b, MOD - 2));
    }
    // --- choosing r elements from n elements (order does not matters) --- //
    ll ncr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;

        return (fac[n] * inv_fact[r] % Mod) * inv_fact[n - r] % Mod;
    }
    // --- choosing r elements from n elements (order matters) --- //
    ll npr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;
        return (fac[n] * inv_fact[n - r]) % Mod;
    }

    ll catalan(int n)
    {
        return ncr(2 * n, n) * inv[n + 1] % Mod;
    }

    /* ---
      number of ways to put n indistinguishable balls into k distinguishable boxes
      number of ways to but k indistinguishable dividers between n indistinguishable items
      --- */
    ll stars_bars(int n, int k)
    {
        return ncr(n + k - 1, k - 1);
    }
};
const int N = 2e6 + 5;
Combinatorics x(N);

void solve()
{
    string s;   cin >> s;
    vector<int> freq(26, 0);
    int ans = x.fact(s.size());

    for(char c : s)
        freq[c - 'a']++;
    for(int i = 0; i < 26; i++)
        ans = x.divide(ans, x.fact(freq[i]));
    
    cout << ans << endl;
}

signed main()
{
    FastIo();
    int test = 1;
    // cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }
}
