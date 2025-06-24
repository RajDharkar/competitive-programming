#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);  

typedef long long ll;
typedef pair<ll, ll> pii;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vvi vector<vi>
#define res(x, n) (x).resize(n)
class Solution {
public:
    bool checkEqualPartitions(vector<ll>& nums, long long target) {
        long long c = 1LL << sz(nums);
        for(ll j = 0; j < c; j++){
            ll x = 1;
            ll y = 1;
            for(ll i = 0; i < sz(nums); i++){
                if(j & (1 << i)){
                    x *= nums[i];
                    // cout << nums[i] << "_ ";
                } else{
                    y *= nums[i];
                }
            }
            // cout << '\n';
            // cout << x << " " << y << '\n';
            if(x == target && y == target){
                return 1;
            }
        }
        return 0;
    }
};

int main(){
    Solution s;
    ll n, m;
    cin >> n >> m;
    vi test(n);
    for(auto &x : test){
        cin >> x;
    }
    cout << s.checkEqualPartitions(test, m);
}