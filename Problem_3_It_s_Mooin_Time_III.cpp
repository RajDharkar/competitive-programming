#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    vector<vector<int>> id(n);
    cin >> s;
    for(int g = 0; g < n; g++){
        id[s[g]-'a'].pb(g);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        for(int lt = 0; lt < 26; lt++){
            if(sz(id[lt])==0)continue;
            int i=0;
            if(s[l] != lt){
                for(int left = 0; left < 26; left++){
                    if(left == lt)continue;
                    if(sz(id[left]) == 0) continue;
                    auto it = lower_bound(all(id[left]), lt);
                    cout << lt << " " << left << " " << *it << endl;
                    if(it == id[left].begin())continue;
                    i = min(i, *it);
                }
                assert(1==0);
            } else{
                i=l;
            }
            int k=r;
            if(s[k] != lt){
                auto it = upper_bound(all(id[lt]), lt);
                k = *--upper_bound(all(id[lt]), lt);
            }
            if(i<l || k>r){
                cout << 0 << endl;
                continue;
            }

            cout << i << " " << k << endl;
        }
    }
}

int main(){
    int t;
    // cin >> t;
    t=1;
    while(t--){
        solve();
    }
}

