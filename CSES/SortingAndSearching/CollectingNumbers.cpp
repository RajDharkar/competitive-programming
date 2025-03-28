#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1;
        return 0;
    }
    map<int, int> mp;
    vector<int> arr(n);
    for(auto &x : arr)cin >> x;
    int i=0;
    for(auto x : arr){
        mp[x]=i;i++;
    }

    int ans = 1;
    for(i = 1; i <= n-1; i++){
        // cout << i << " " << mp[i] << " " << mp[i+1] << endl;
        if(mp[i+1]<mp[i])ans++;
    }
    cout << ans;
}

