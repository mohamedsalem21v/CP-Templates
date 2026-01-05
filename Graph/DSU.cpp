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

template <typename T = int, int Base = 1>
struct DSU
{

    vector<T> parent, Gsize, nxt, tail, pos, roots;

    DSU(int MaxNodes)
    {
        parent = Gsize = roots = tail = pos = nxt = vector<T>(MaxNodes + Base);
        for (int i = Base; i < MaxNodes + Base; i++)
        {
            parent[i] = roots[i] = pos[i] = tail[i] = i;
            nxt[i] = -1, Gsize[i] = 1;
        }
    }

    T find_leader(int node) { return parent[node] = (parent[node] == node ? node : find_leader(parent[node])); }

    bool is_same_sets(int u, int v) { return find_leader(u) == find_leader(v); }

    void union_sets(int u, int v)
    {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v)
            return;
        // make leader_u is the leader with the larger component
        if (Gsize[leader_u] < Gsize[leader_v])
            swap(leader_u, leader_v);
        int p = pos[leader_v];
        Gsize[leader_u] += Gsize[leader_v];
        parent[leader_v] = leader_u;
        roots[p] = roots.back();
        pos[roots[p]] = p;
        roots.pop_back();
        nxt[tail[leader_u]] = leader_v;
        tail[leader_u] = tail[leader_v];
    }

    void print()
    {
        for (int root = Base; root < sz(roots); root++)
        {
            for (int u = roots[root]; ~u; u = nxt[u])
                cout << u << " \n"[!~nxt[u]];
        }
    }

    vector<vector<int>> get_components()
    {
        vector<vector<int>> components;
        for (int root = Base; root < sz(roots); root++)
        {
            vector<int> component;
            for (int u = roots[root]; ~u; u = nxt[u])
                component.push_back(u);
            components.push_back(component);
        }
        return components;
    }

    int get_size(int u) { return Gsize[find_leader(u)]; }

    int get_components_number() { return sz(roots) - Base; }
};

void solve()
{
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