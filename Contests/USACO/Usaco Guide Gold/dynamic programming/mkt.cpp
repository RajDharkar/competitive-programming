#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> score(n);
        for(auto &a : score)cin >> a;
        int dp[n+1];
        for(int i=0;i<n+1;i++)dp[i]=0;
        dp[0]=0;
        for(int i = 1; i <= n+1; i++){
            if(i>1){
                dp[i]=min(dp[i-1],dp[i-2]+score[i-2])+score[i-1];
            }
            else{
                dp[i]=score[i-1];
            }
            for(int i=0;i<n+1;i++)cout << dp[i] << " ";
            cout << endl;
        }
        cout << dp[n] << endl;
        for(int i=0;i<n+1;i++)cout << dp[i] << " ";
        cout<<'\n';
    }
}

