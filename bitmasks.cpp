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
bool knowTheBit(int n, int i) {
    return n&(1 << i);
}
int setBet1(int n, int i) {
    return n | (1 << i);
    // in this operation if the bit equals 0, then, when we do (bitwise or) with 1, it will be 1.
}
int setBit0(int n, int i) {
    return n & ~(1 << i);
}
int flipBit(int n, int i) {
    return n ^ (1 << i);
}
bool isPowerOfTwo(int n)
{
    if(n==0)    return 0;
    return !(n&(n-1));
}
void solve()
{

}

int main()
{
    FastIo();
    int test = 1;
    // cin >> test;
    for(int tc = 1; tc <= test; tc++)
    {
        solve();
    }
}
