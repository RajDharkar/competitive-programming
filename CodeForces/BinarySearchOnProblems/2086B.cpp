#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second
// ^ lol this makes everything look weird but I'll try it
// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define ft front()
#define bk back()
// loops
const int MOD = (int)1e9+7; // 998244353;
const int MX = (int)2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

void solve(){
	ll n, k, x;
	cin >> n >> k >> x;
	vector<ll> arr(n);
	for(auto &x : arr)cin >> x;
	ll sum = accumulate(all(arr), 0LL);
	assert(sum > 0);
	ll need = k * sum - x;

	if(need < 0){cout << 0 << endl;return;}

	ll full = need / sum;
	ll left = need % sum;

	ll ans = full * n;
	ll s = 0;
	for(int i = 0; i < n; i++){
		s += arr[i];
		ans++;
		if(s > left)break;
	}

	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
	ll t;
	cin >> t;
	while(t--){
		solve();
	}
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/