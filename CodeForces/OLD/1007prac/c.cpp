#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
using namespace std;
 
using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector<vector<ll>> depths;
vector<vector<ll>> adj;
void dfs(ll node, ll parent, ll depth){
	depths[depth].pb(node);
	for(auto x : adj[node]){
		if(x!=parent){
			dfs(x, node, depth+1);
		}
	}
}

int main() {
	// read read read
	int t;
	cin >> t;
	while(t--){
		ll n, st, en;
		cin >> n >> st >> en;
		st--;en--;
		depths.clear();adj.clear();
		depths.resize(n);
		adj.resize(n);
		for(int i=0;i<n-1;i++){
			int a, b;
			cin >> a >> b;
			a--;b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(en, -1, 0);
		vector<ll> ans;
		for(int i = n-1; i >= 0; i--){
			for(auto x : depths[i]){
				ans.pb(x+1);
				// cout << x+1 << " ";
			}
			// cout << endl;
		}
		for(auto x : ans){
			cout << x << " ";
		}
		cout << endl;

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