#include<bits/stdc++.h>

using namespace std;

#define MAXN 10001

int main(){
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &a : arr)cin >> a;
    int dp[MAXN] = {0};
    for(int i = 0; i < n; i++){
        int skill = arr[i];
        for(int j = 0; j<k; j++){
            int ind = i-j;
            if(ind<0)break;
            skill = max(skill, arr[ind]);
            dp[i]=max(dp[i], (ind == 0 ? 0 : dp[ind-1]) +skill*(j+1));
        }
    }
    cout<<dp[n-1];
}