#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll BIG = (1LL << 60);

int n;
vector<int> p;
vector<ll> c;
vector<int> visit;
vector<bool> cyc;
vector<int> compId;
vector<vector<int>> rings;
vector<vector<int>> adj;
vector<vector<ll>> dpTree;
vector<bool> used;

ll nodeCost(int x){
    if(p[x] == x) return 0LL;
    return c[x];
}

void findRings() {
    int cid = 0;
    visit.assign(n + 1, 0);
    cyc.assign(n + 1, false);
    compId.assign(n + 1, -1);
    for(int i = 1; i <= n; i++){
        if(visit[i] != 0) continue;
        int cur = i;
        vector<int> stk;
        while(true){
            if(visit[cur] == 0){
                visit[cur] = 1;
                stk.push_back(cur);
                cur = p[cur];
            } else if(visit[cur] == 1){
                vector<int> ring;
                int pos = 0;
                for(int j = 0; j < (int)stk.size(); j++){
                    if(stk[j] == cur){
                        pos = j; 
                        break;
                    }
                }
                for(int k = pos; k < (int)stk.size(); k++){
                    ring.push_back(stk[k]);
                    cyc[stk[k]] = true;
                    compId[stk[k]] = cid;
                }
                rings.push_back(ring);
                cid++;
                for(auto &e : stk) visit[e] = 2;
                break;
            } else {
                for(auto &e : stk) visit[e] = 2;
                break;
            }
        }
    }
}

void dfs(int x) {
    used[x] = true;
    dpTree[x][0] = 0;
    dpTree[x][1] = nodeCost(x);
    for(auto &nx : adj[x]){
        if(cyc[nx]) continue;
        if(!used[nx]) dfs(nx);
        dpTree[x][0] += dpTree[nx][1];
        dpTree[x][1] += min(dpTree[nx][0], dpTree[nx][1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    p.resize(n + 1);
    c.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];

    findRings();

    adj.assign(n + 1, {});
    for(int i = 1; i <= n; i++){
        adj[p[i]].push_back(i);
    }

    dpTree.assign(n + 1, vector<ll>(2, 0));
    used.assign(n + 1, false);
    for(int i = 1; i <= n; i++){
        if(!cyc[i] && !used[i]) dfs(i);
    }

    vector<ll> pick(n + 1, 0), skip(n + 1, 0);
    for(int u = 1; u <= n; u++){
        if(!cyc[u]) continue;
        ll sPick = 0, sSkip = 0;
        for(auto &w : adj[u]){
            if(cyc[w]) continue;
            sPick += min(dpTree[w][0], dpTree[w][1]);
            sSkip += dpTree[w][1];
        }
        pick[u] = sPick;
        skip[u] = sSkip;
    }

    ll ans = 0;
    for(auto &r : rings){
        int len = (int)r.size();
        if(!len) continue;
        vector<ll> cPick(len), cSkip(len);
        for(int i = 0; i < len; i++){
            int node = r[i];
            cPick[i] = nodeCost(node) + pick[node];
            cSkip[i] = skip[node];
        }
        vector<vector<ll>> dp(len, vector<ll>(2, BIG));
        dp[0][1] = cPick[0];
        for(int i = 1; i < len; i++){
            dp[i][0] = dp[i - 1][1] + cSkip[i];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + cPick[i];
        }
        ll resRing = min(dp[len - 1][0], dp[len - 1][1]);
        if(len > 1){
            vector<vector<ll>> dp2(len, vector<ll>(2, BIG));
            dp2[0][0] = cSkip[0];
            dp2[1][1] = dp2[0][0] + cPick[1];
            for(int i = 2; i < len; i++){
                dp2[i][0] = dp2[i - 1][1] + cSkip[i];
                dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1]) + cPick[i];
            }
            resRing = min(resRing, dp2[len - 1][1]);
        }
        ans += resRing;
    }

    cout << ans << "\n";
    return 0;
}