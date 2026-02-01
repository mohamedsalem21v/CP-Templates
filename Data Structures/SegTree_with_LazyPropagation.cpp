#include <bits/stdc++.h>
#define sp " "
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
#define ull unsigned long long
#define ve vector<int>
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()
#define fixed(n) fixed << setprecision(n)
#define debug cout << "\n======================\n"
const int MOD = 1e9 + 7;
const int inf = 1e18;
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

struct Node
{
    int sum;
    int lazy;
    bool isLazy;
    Node()
    {
        sum = 0;
        lazy = 0;
        isLazy = false;
    }
    Node(int val)
    {
        sum = val;
        lazy = 0;
        isLazy = false;
    }
    void change(int val, int lx, int rx)
    {
        sum += (rx - lx) * val;
        lazy += val;
        isLazy = true;
    }
};

struct segTree
{
    int treeSize;
    vector<Node> segData;

    segTree(int n)
    {
        treeSize = 1;
        while (treeSize < n)
            treeSize *= 2;

        segData.assign(2 * treeSize, Node());
    }

    // changeable
    Node merge(Node &lf, Node &ri)
    {
        Node ans = Node();
        ans.sum = lf.sum + ri.sum;
        return ans;
    }

    void build(vector<int> &arr, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)arr.size())
                segData[ni] = Node(arr[lx]);
            return;
        }

        int mid = (rx + lx) / 2;
        build(arr, 2 * ni + 1, lx, mid);
        build(arr, 2 * ni + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void build(vector<int> &arr)
    {
        build(arr, 0, 0, treeSize);
    }

    void set(int idx, int val, int ni, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            segData[ni].change(val, lx, rx);
            return;
        }

        int mid = (rx + lx) / 2;
        if (idx < mid)
        {
            set(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            set(idx, val, 2 * ni + 2, mid, rx);
        }
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void set(int idx, int val)
    {
        set(idx, val, 0, 0, treeSize);
    }

    void propagate(int ni, int lx, int rx)
    {
        if (rx - lx == 1 or !segData[ni].isLazy)
            return;

        int mid = (lx + rx) / 2;
        segData[2 * ni + 1].change(segData[ni].lazy, lx, mid);
        segData[2 * ni + 2].change(segData[ni].lazy, mid, rx);
        segData[ni].lazy = 0;
        segData[ni].isLazy = false;
    }

    Node get(int l, int r, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if (lx >= r or rx <= l)
            return Node();
        if (lx >= l and rx <= r)
            return segData[ni];

        int mid = (rx + lx) / 2;
        Node left = get(l, r, 2 * ni + 1, lx, mid);
        Node right = get(l, r, 2 * ni + 2, mid, rx);

        return merge(left, right);
    }
    int get(int l, int r)
    {
        return get(l, r, 0, 0, treeSize).sum;
    }

    void update(int l, int r, int val, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);

        if (lx >= r or rx <= l)
            return;
        if (lx >= l and rx <= r)
        {
            segData[ni].change(val, lx, rx);
            return;
        }

        int mid = (rx + lx) / 2;
        update(l, r, val, 2 * ni + 1, lx, mid);
        update(l, r, val, 2 * ni + 2, mid, rx);
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
    void update(int l, int r, int val)
    {
        update(l, r, val, 0, 0, treeSize);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    ve v(n,0);
    segTree st = segTree(n);
    // input(v);
    st.build(v);
    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int x;
            cin >> x;
            st.update(l, r, x);
        }
        else
            cout << st.get(l, r) << endl;
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