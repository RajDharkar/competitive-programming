#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    int n;
    cin >> n;
    vector<ll> nums;
    for(auto &x : nums)cin >> x;
    
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> stk;

    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            left[i] = stk.top();
        }
        stk.push(i);
    }
    stk = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && nums[stk.top()] > nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            right[i] = stk.top();
        }
        stk.push(i);
    }
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += ll(i - left[i]) * (right[i] - i) * nums[i];
    }
    cout << sum << '\n';
}
 
int main(){
    int t = 1;
    while(t--){
        solve();
    }
}
