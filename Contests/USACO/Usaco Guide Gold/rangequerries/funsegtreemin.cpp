#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//ll size = (2*1e5+1)
ll n;
ll tree[400001];

void init(){
    for(int i=0;i<400001;i++)tree[i]=1e9;
}

//finds the sum from index a -> index b

//parent = floor(index/2), child = n*2
//
ll sum(ll a, ll b){
    a += n; //going to the root, in this case just returns a 
    b += n; //going to the root

    ll ret = 1e9;
    while(a <= b){
        if(a&1)ret = min(ret, tree[a++]);
        if(!(b&1))ret = min(tree[b--], ret);
        //cout << ret << endl;
        a/=2;b/=2;
    }
    return ret;
}
void add(ll k, ll x) {
    k += n;
    tree[k] = min(tree[k], x);
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = min(min(tree[2*k], x), min(x, tree[2*k+1]));
    }
}

int main(){
    ll q;
    cin >> n >> q;
    init();
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        add(i, a);
    }
    // cout << "ALL ADDED" << endl;
    // for(ll i=0; i < 2*n+1; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
    while(q--){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        cout << sum(a, b) << endl;
    }
}

