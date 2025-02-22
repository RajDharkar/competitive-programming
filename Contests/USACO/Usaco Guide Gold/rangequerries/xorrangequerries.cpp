#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//ll size = (2*1e5+1)
ll n;
ll tree[400005];

//finds the sum from index a -> index b

//parent = floor(index/2), child = n*2
//
ll range_xor(ll a, ll b){
    a += n; //going to the root, in this case just returns a 
    b += n; //going to the root

    ll ret = 0;
    while(a <= b){
        if(a&1)ret^=tree[a++];
        if(!(b&1))ret^=tree[b--];
        //cout << ret << endl;
        a/=2;b/=2;
    }
    return ret;
}
void add(ll k, ll x) {
    k += n;
    tree[k] ^= x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]^tree[2*k+1];
    }
}

int main(){
    ll q;
    cin >> n >> q;
    for(ll i = 0; i < n; i++){
        ll a;
        cin >> a;
        add(i, a);
    }
    // for(ll i=0; i < 2*n+1; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
    while(q--){
        ll a, b;
        cin >> a >> b;
        a--;b--;
        cout << range_xor(a, b) << endl;
    }
}

