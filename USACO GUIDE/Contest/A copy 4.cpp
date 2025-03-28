#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> ans(n);
        int idx = 0;
        for(int i = n; i >= n/2+1; i--){
            ans[idx] = i;
            idx+=2;
        }
        idx = 1;
        for(int i = 1; i<=n/2;i++){
            ans[idx]=i;
            idx+=2;
        }
        for(int i = 0; i < n; i++){
            if(i==0){
                cout << ans[0];
                continue;
            }
            cout << " " << ans[i];  
        }
        cout << endl;
        // for(ll i= 0; i<n; i++){
            // if(i%2==0)k*=ans[i];
            // if(i%2)k/=ans[i];
        // }
        // cout << k << endl;
    }
}

