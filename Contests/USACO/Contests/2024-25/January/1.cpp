#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;

int main(){
    cin >> n;
    vector<ll> tree(n);
    vector<ll> cost(n);
    vector<ll> ctree; //compressed tree
    for(int i = 0; i < n; i++){
        cin >> tree[i] >> cost[i];
        ctree.push_back(tree[i]);
    }
    int q;cin>>q;
    vector<ll> qry(q);
    for(int i = 0; i < q; i++){
        cin >> qry[i];
        ctree.push_back(qry[i]);
    }
    // cout <<"before sorting";
    sort(ctree.begin(), ctree.end());
    ctree.resize(unique(ctree.begin(), ctree.end()) - ctree.begin()); //coordinate compression, sorting and unique subtracted by beginning iterator
    map<int, int> cc;
    for(int i = 0; i<int(ctree.size()); i++){
        cc[ctree[i]]=i;
    }

    for(int i = 0; i < int(ctree.size()); i++){
        cout << i << " " << ctree[i] << endl;
    }
    ll dp[n+1][n+1]; //
    for(int i = n-1; i >= 0; i--){
        if(2*i + 1 >= n){
            //no children
            //meaning that the cost to turn it into j is just cost[i], unless tree[i] is already equal to j -.-
            for(int k = 0; k < int(ctree.size()); k++){
                if(ctree[k] == tree[k])dp[i][j]=0;
                else{
                    dp[i][k]=cost[i];
                }
            }
        }
        //remember

    }



}