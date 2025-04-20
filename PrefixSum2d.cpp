#include <bits/stdc++.h>
#define endl "\n"
#define sp " "
#define ll long long
#define ld long double
#define ull unsigned long long
#define st string
#define pb(n) push_back(n)
#define pf(n) push_front(n)
#define ve vector<int>
#define de deque<int>
#define all(n) n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()
#define fixed(n) fixed << setprecision(n)
using namespace std;
void FastIo()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
}
void solve()
{
    int n,q;    cin >> n >> q;
    vector<vector<int>> pfx2d(n+1,vector<int>(n+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x; cin >> x;
        }
    }
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n; col++)
            pfx2d[row][col] += pfx2d[row][col-1];
    }

    for(int col = 1; col <= n; col++)
    {
        for(int row = 1; row <= n; row++)
            pfx2d[row][col] += pfx2d[row-1][col];
    }
    while(q--)
    {
        int a,b,x,y;    cin >> a >> b >> x >> y;
        int ans = pfx2d[x][y] - pfx2d[a-1][y] - pfx2d[x][b-1] + pfx2d[a-1][b-1];
        cout << ans << endl;
    }

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
