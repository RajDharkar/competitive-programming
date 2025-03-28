#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; 
    cin >> n;
    vector<long long> arr(n);
    for(auto &x: arr)
        cin >> x;
        if(n < 4){ 
        cout << -1;
        return 0;
    }
    
    sort(arr.begin(), arr.end());
    long long m = arr.front(), M = arr.back();
    map<long long,int> freq;
    for(auto x: arr) 
        freq[x]++;
    long long best = -1;
    for (int i = n-2; i >= 0; i--){
        long long x = arr[i];
        if(x <= m || x >= M) continue; 
        if(2 * x < m + M) continue;
        long long y = m + M - x; 
        if(y <= m || y >= M) continue;
        if(freq.find(y) == freq.end()) continue;
        if(x == y && freq[x] < 2) continue;
        long long D = x - m; // (also M - y)
        best = max(best, D);
        break;
    }
 
    cout << best;
    return 0;
}
