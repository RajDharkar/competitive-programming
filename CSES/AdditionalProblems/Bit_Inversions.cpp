#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    string s;
    cin >> s;
    set<int> ind;
    ind.insert(-1);
    multiset<int> ans;
    for(int i=0;i<sz(s);i++){
        if(s[i]=='1'){
            int en = *--ind.end();
            if(i-en-1 > 0)
                ans.insert(i-en-1);
            ind.insert(i);
        }
    }
    // while(!ans.empty()){
    //     int to = ans.top();
    //     cout << to << endl;
    //     ans.pop();
    // }

    for(auto &x : ind)cout << x << " ";
    cout << endl;
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;k--;
        if(ind.count(k)){
            // cout << k << endl;
            ind.erase(k);
            int lower = *ind.lower_bound(k);
            int high = *ind.upper_bound(k);
            cout << lower << " " << high << endl;
            ans.erase(ans.find(high-k-1));
            ans.erase(ans.find(k-lower-1));
            ans.insert(high - lower - 1);
        } else{
            int lower = *ind.lower_bound(k);
            int high = *ind.upper_bound(k);
            // ans.erase(ans.find(high-lower-1));
            ans.insert(high-k-1);
            ans.insert(k-lower-1);
            ind.insert(k);
        }
        cout << *--ans.end() << " ";
    }
}

int main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}

