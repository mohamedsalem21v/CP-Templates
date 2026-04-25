#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
#define ll long long
#define ld long double
#define int long long
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define debug cout << "\n======================\n"
const int MOD = 1e9 + 7;
const int inf = 2e18;
#define input(v)       \
    for (auto &it : v) \
    cin >> it
#define output(v)      \
    for (auto &it : v) \
    cout << it << " "
using namespace std;

void FastIo()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}

struct node
{
    node *child[26];
    int prefix;
    bool isEnd;
    node()
    {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        prefix = 0;
        isEnd = false;
    }
};

struct trie
{
    node *root;
    trie()
    {
        root = new node();
    }

    void insert(string s)
    {
        node *curr = root;
        for (char c : s)
        {
            int idx = c - 'a';
            if (curr->child[idx] == nullptr)
                curr->child[idx] = new node();
            curr = curr->child[idx];
            curr->prefix++;
        }
        curr->isEnd = true;
    }

    int countPrefix(string s)
    {
        node *curr = root;
        for (char c : s)
        {
            int idx = c - 'a';
            if (curr->child[idx] == nullptr)
                return 0;
            curr = curr->child[idx];
        }
        return curr->prefix;
        // return curr->isEnd ? 1 : 0; // for counting exact words
    }
};

void solve()
{
    trie t;
    int n, q;
    cin >> n >> q;
    while (n--)
    {
        string s;
        cin >> s;
        t.insert(s);
    }
    while (q--)
    {
        string s;
        cin >> s;
        cout << t.countPrefix(s) << endl;
    }
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