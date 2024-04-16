#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int mod;
bool cmp(int a, int b){
    return a%mod > b%mod;
}
int main() {
    // setIO("berries");
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int maxTest = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maxTest = max(maxTest, arr[i]);
    }   
    int ans = 0;
    for(int test = 1; test <= maxTest; test++){
        int buckets = 0;
        for(int i = 0; i < n; i++){
            buckets+=arr[i]/test;
        }    
        if(buckets < (k/2)){
            continue;
        }
        if(buckets >= k){
            ans = max(test*(k/2), ans);
        }
        mod = test;
        sort(arr.begin(), arr.end(), cmp);
        int curAns = ((k/2 - buckets) * test);
        for(int i = 0; i < n && buckets + i < k; i++){
            curAns+=(arr[i]%test);
        }
        ans = max(curAns, ans);
    }
    cout << ans << '\n';

}
