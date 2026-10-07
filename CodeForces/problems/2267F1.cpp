#include <algorithm>
#include<bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n), ans(n);
        for(auto &x : arr)cin >> x;
ans.clear();

        while(1){
            ans.pb(*max_element(all(arr)) - *min_element(all(arr)));
            if(*max_element(all(arr)) == 0)break;

            priority_queue<int> pq;
            // vector<int> xors;
            for(int i = 0; i < n; i++){
                for(int j= i + 1; j < n; j++){
                    // xors.pb(arr[i]^arr[j]);

                    if(sz(pq) < n){
                        pq.push(arr[i] ^ arr[j]);
                        continue;
                    }
                    if((arr[i] ^ arr[j]) < pq.top()){
                        pq.pop();
                        pq.push(arr[i] ^ arr[j]);
                    }
                }
            }
            arr.clear();

            while(!pq.empty()){
                arr.pb(pq.top());
                pq.pop();
            }
        }
        while(q--){
            int k;
            cin >> k;
            if(k < sz(ans)){
                cout << ans[k];
            }
            else{
                cout << 0;
            }
            cout << '\n';
        }
    }
}