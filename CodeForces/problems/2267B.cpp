#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main() {
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n), ans(n);
        for(auto &x : arr)cin >> x;

        sort(all(arr), greater<int>());
        map<int, int> freq;

        for(auto &x : arr){
            freq[x]++;
        }

        vector<pair<int, int>> mp;
        for(auto &[x, y] : freq){
            for(int i = 0; i < y; i++) mp.pb({i, -x});
        }
        sort(all(mp));
        for(int i = 0; i < n; i++){
            cout << -mp[i].second << " \n"[i == n - 1];
        }

    
    }
}