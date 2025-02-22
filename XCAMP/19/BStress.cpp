#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
vector<vector<pii>> adj;

ll dfs_found = 0, brute_found = 0;

ll dfs(ll node, ll parent, ll k)
{
    vector<ll> edge_lengths;
    for (auto [lower, length] : adj[node])
    {
        if (lower == parent)
        {
            continue;
        }
        ll le = dfs(lower, node, k);
        if (length + le >= k)
        {
            dfs_found++;
        }
        else
        {
            edge_lengths.push_back(length + le);
        }
    }

    sort(edge_lengths.begin(), edge_lengths.end());
    if (edge_lengths.empty())
        return 0;
    ll lp = 0, rp = edge_lengths.size() - 1;
    int oldlp = 0, ret = 0;
    while (lp < rp)
    {
        oldlp = lp;
        if (lp != rp && edge_lengths[lp] + edge_lengths[rp] >= k)
        {
            dfs_found++; // Pair found
            // cout << edge_lengths[lp] << " " << edge_lengths[rp] << endl;
            rp--;
            lp++;
        }
        else
        {
            ret = lp;
            lp++;
        }
    }
    if (lp == rp)
    {
        // cout << "HERE";
        return edge_lengths[lp];
    }
    else if (lp == rp + 1 && ret != 0)
    {
        return edge_lengths[ret];
    }
    else
    {
        return 0;
    }
    // 15
    //[1, 3, 5, 6, 7, 8] ++
}

ll brute_dfs(ll node, ll parent, ll k)
{
    multiset<ll> edge_lengths;
    for (auto [lower, length] : adj[node])
    {
        if (lower == parent)
        {
            continue;
        }
        ll le = brute_dfs(lower, node, k);
        if (length + le >= k)
        {
            brute_found++;
        }
        else
        {
            edge_lengths.insert(length + le);
        }
    }

    while (!edge_lengths.empty())
    {
        int len = *edge_lengths.rbegin();
        edge_lengths.erase(--edge_lengths.end());
        auto it = edge_lengths.lower_bound(k - len);
        if (it == edge_lengths.end())
            return len;
        else
        {
            brute_found++;
            edge_lengths.erase(it);
        }
    }
    return 0;
}

void generate_test_case(int n)
{
    adj.clear();
    adj.resize(n);
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
    {
        int parent = rand() % i;
        int weight = rand() % 1000 + 1;
        adj[parent].push_back({i, weight});
        adj[i].push_back({parent, weight});
        edges.push_back({parent, i});
    }
}

int main()
{
    srand(time(0));

    for (int t = 0; t < 300; t++)
    {                            // Running multiple test cases
        int n = 5; // Small cases for brute-force checking
        generate_test_case(n);

        ll k = rand() % 1000 + 1; // Random threshold
        dfs_found = 0, brute_found = 0;

        dfs(0, -1, k);
        brute_dfs(0, -1, k);

        if (dfs_found != brute_found)
        {
            cout << "Mismatch detected! k=" << k << " DFS: " << dfs_found << " Brute: " << brute_found << endl;

            for (int i = 0; i < n; i++)
            {
                for (auto [node, length] : adj[i])
                {
                    cout << i << node << " " << length << endl;
                }
            }
            return 1;
        }
    }
    cout << "All tests passed!" << endl;
}
