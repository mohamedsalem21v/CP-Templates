#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
template <class T> 
using multi_ordered_set = tree<T, null_type, less_equal<T>,
rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key(n)  It returns to the number of items that are strictly smaller than our item k in O(logn)
//find_by_order(n)  It returns to an iterator to the kth element (counting from zero) in the set in O(logn)
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
    int sz = 1002;
    vector<vector<ull>> pfx2d(sz,vector<ull>(sz));
    while(n--)
    {
        int h,w;    cin >> h >> w;
        pfx2d[h][w] += h*w;
        
    }
    for(int row = 1; row < sz; row++)
    {
        for(int col = 1; col < sz; col++)
            pfx2d[row][col] += pfx2d[row][col-1];
    }

    for(int col = 1; col < sz; col++)
    {
        for(int row = 1; row < sz; row++)
            pfx2d[row][col] += pfx2d[row-1][col];
    }
    while(q--)
    {
        int a,b,x,y;    cin >> a >> b >> x >> y;
        ull ans = pfx2d[x-1][y-1] - pfx2d[a][y-1] - pfx2d[x-1][b] + pfx2d[a][b];
        cout << ans << endl;
    }

}

int main()
{
    FastIo();
 	int test = 1;
	cin >> test;
	for(int tc = 1; tc <= test; tc++)
	{
		solve();
	}
    
}