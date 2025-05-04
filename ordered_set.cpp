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
//order_of_key(n)  It returns the number of items that are strictly smaller than our item k in O(logn)
//find_by_order(n)  It returns an iterator to the kth element (counting from zero) in the set in O(logn)
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
