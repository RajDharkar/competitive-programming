#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin >> n >> m;
    if(n==1){
        cout << 1;
        return 0;
    }
    vector<int> mp(n+1, 0);
    vector<int> arr(n);
    for(auto &x : arr)cin >> x;
    int i=0;
    for(auto x : arr){
        mp[x]=i;i++;
    }
    int ans = 1;
    for(i = 1; i <= n-1; i++){
        if(mp[i+1]<mp[i])ans++;
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        // if(arr[b] > arr[a])swap(a, b);
        set<pair<int, int>> tocheck = {
            {arr[a]-1, arr[a]}, {arr[b]-1, arr[b]},
            {arr[a], arr[a]+1}, {arr[b], arr[b]+1}
        };
        for(auto [x, y] : tocheck){
            if(x >= 1 && y <= n){
                if(mp[y] < mp[x])ans--;
            }
        }
        swap(mp[arr[a]], mp[arr[b]]);
        swap(arr[a], arr[b]);
        for(auto [x, y] : tocheck){
            if(x >= 1 && y <= n){
                if(mp[y] < mp[x])ans++;
            }
        }
        cout << ans << '\n';
    }
}

