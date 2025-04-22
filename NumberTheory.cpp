#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
#define st string
const int MOD = 1e9+7;
#define ll long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define de deque<int>
#define pb(n) push_back(n)
#define pf(n) push_front(n)
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
using namespace std;
void FastIo()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
//==================================================================
vector<ll> div(ll n)
{
    vector<ll> divisors;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i * i != n)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}
vector<ll> primeFactorization(ll n)
{
    vector<ll> factors;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}
bool isprime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
//==================================================================
const int N = 1e7+10;
vector<bool> prime(N,true);
void sieve()
{
    prime[0] = false;
    prime[1] = false;

    for(ll i=2;i*i<N;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<N;j+=i)
            {
                prime[j] = false;
            }
        }
    }
}
vector<bool>is_prime(N,1);vector<int>primes;
void linearSieve()
{
    is_prime[0]= 0; is_prime[1]= 0;
    for(ll i=2;i<N;i++)
    {
        if(is_prime[i]) primes.push_back(i);
        for(auto it:primes)
        {
            if(i*it>=N) break;
            is_prime[i*it]=0;
            if(i%it==0) break;
        }
    }
}
//==================================================================
ll powmod(ll a, ll b)
{
    if (b==0)   return 1;
    if (b==1)   return a;
    ll res = a ;
    ll res2 = 1 ;
    while (b >= 2)
    {
        if (b % 2)
            res2 = (res*res2) % MOD ;
        b /= 2;
        res = (res*res) % MOD;
    }
    return (res*res2) % MOD;
}
ll add(ll a,ll b)
{
    return ((a%MOD)+(b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
    return ((((a%MOD)-(b%MOD))%MOD)+MOD)%MOD;
}
ll divide(ll a,ll b)
{
    return mul(a,powmod(b,MOD-2));
}
//==================================================================
void solve()
{

}

int main()
{
    FastIo();
    int test = 1;
    // cin >> test;
    for (int tc = 1; tc <= test; tc++)
    {
        solve();
    }
}
