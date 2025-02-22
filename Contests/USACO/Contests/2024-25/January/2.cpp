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
int n, m;
string a;
vector<bool> on;
ll ret;

vector<int> parents;
vector<int> sizes;

int find(int node){
    if(parents[node] != node){
        parents[node] = find(parents[node]);
    }
    return parents[node];
}

void unite(int a, int b){
    if((a=find(a))==(b=find(b))){
        return;
    }
    ret += (ll)sizes[a]*sizes[b];
    parents[a]=b;
    sizes[b]+=sizes[a];
}



int main() {
    cin >> n >> m >> a;
    on.resize(n, 0);
    parents.resize(n,0);
    sizes.resize(n,0);
    vector<ll> ans(n);
    ans[n-1]=0;


    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    iota(parents.begin(), parents.end(), 0);
    for(int i = 0; i < n; i++){
        if(a[i]&1){
            on[i]=1;
            for(auto x : adj[i]){
                if(on[x]){
                    // cout << x << " " << i << endl;
                    unite(x, i);
                }
            }
        }
    }
    // cout << endl;
   // cout << ret << endl   ;

    for(int i = n - 1; i >= 0; i--){
        if(!(a[i]&1)){
           // cout<<"HERE";
            on[i] = 1;
            for(auto x : adj[i]){
                if(on[x]){
                    unite(x, i);
                }
            }
        }
        ret += sizes[find(i)]++;
        ans[i] = ret;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
	// read read read




    
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
