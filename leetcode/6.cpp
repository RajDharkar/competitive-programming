#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

class Solution
{
public: //bro are we ddeas vscode c++ formatter is SO CHOPPED 
    int minMoves(vector<string> &classroom, int energy)
    {
        ll n = sz(classroom);
        ll m = sz(classroom[0]);
        pii start = {-1, -1};
        vector<pii> pos;
        ll k = 0;
        map<pii, ll> cc;
        for (ll j = 0; j < sz(classroom); j++)
        {
            string x = classroom[j];
            for (ll i = 0; i < sz(x); i++)
            {
                if (x[i] == 'S')
                {
                    start = {j, i};
                }
                else if (x[i] == 'L')
                {
                    pos.pb({j, i});
                    cc[pos.back()] = sz(pos) - 1;
                    k++;
                }
            }
        }
        assert(start.f != -1);
        bool vis[20][20][51][1LL<10];
        ll fullMask = (1LL<<k)-1;
        auto func = [&]() -> ll
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int e = 0; e <= energy; e++)
                    {
                        for (int z = 0; z <= fullMask; z++)
                        {
                            vis[i][j][e][z] = 0;
                        }
                    }
                }
            }
            queue<array<ll, 5>> q;
            q.push({start.f, start.s, energy, 0, 0});
            vis[start.f][start.s][energy][0] = 1;
            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();
                ll x = cur[0], y = cur[1], e = cur[2], z = cur[3], dep = cur[4];
                if (z == fullMask)
                    return dep;
                if (e == 0 && classroom[x][y] != 'R')
                    continue;
                for (ll d = 0; d < 4; d++)
                {
                    ll nx = x + dx[d];
                    ll ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    char ch = classroom[nx][ny];
                    if (ch == 'X')
                        continue;
                    ll ne = (ch == 'R') ? energy : e - 1;
                    if (ne < 0)
                        continue;
                    ll nmask = z;
                    if (ch == 'L')
                    {
                        auto it = cc.find({nx, ny});
                        if (it != cc.end())
                        {
                            nmask |= (1LL << it->s);
                        }
                    }
                    if (!vis[nx][ny][ne][nmask])
                    {
                        vis[nx][ny][ne][nmask] = 1;
                        q.push({nx, ny, ne, nmask, dep + 1});
                    }
                }
            }
            return -1;
        };
        return func();
    }
};

int main(){
    Solution s;
    ll n, e;
    cin >> n >> e;
    vector<string> arr(n);
    for(auto &x : arr)cin >> x;
    cout << s.minMoves(arr, e); 
}