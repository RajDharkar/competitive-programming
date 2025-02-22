#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll med(ll x, ll y, ll z) {
    return x ^ y ^ z ^ min({x, y, z}) ^ max({x, y, z});
}

int main(){
    ll n;
    cin >> n;
    vector<ll> tree(n);
    vector<ll> cost(n);
    vector<ll> ctree; // Compressed tree

    for(int i = 0; i < n; i++){
        cin >> tree[i] >> cost[i];
        ctree.push_back(tree[i]);
    }

    int q;
    cin >> q;
    vector<ll> qry(q);
    for(int i = 0; i < q; i++){
        cin >> qry[i];
        ctree.push_back(qry[i]);
    }

    sort(ctree.begin(), ctree.end());
    ctree.resize(unique(ctree.begin(), ctree.end()) - ctree.begin());

    map<int, int> cc;
    for(int i = 0; i < int(ctree.size()); i++){
        cc[ctree[i]] = i;
    }

    ll dp[101][101];    
    for(int i = n - 1; i >= 0; i--){
        if(2 * i + 1 >= n){
            for(int k = 0; k < int(ctree.size()); k++){
                dp[i][k] = (ctree[k] == tree[i] ? 0 : cost[i]);
            }
            continue;
        }
        for(int j=0;j<101;j++)dp[i][j]=1e15;
        for(int j = 0; j < ctree.size(); j++){
            for(int a = 0; a < ctree.size(); a++){
                for(int b = 0; b < ctree.size(); b++){
                    ll median = med(a, b, j);
                    dp[i][median] = min(dp[i][median], (ctree[j] == tree[i] ? 0 : cost[i]) + dp[2*i+1][a] + dp[2*i+1+1][b]);
                }
            }
        }
    }


	// for(int i = 0;i < n;++i) {
    //     cout << i <<": ";
    //     for(int j = 0; j < int(ctree.size()); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
	// }
    for(int i = 0; i < q; i++){
        //if(dp[0][cc[qry[i]]] == 1e15) cout << "-1\n"; // Unreachable case
        cout << dp[0][cc[qry[i]]] << '\n';
    }

    return 0;
}
