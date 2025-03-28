#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

#define ROCK 0
#define PAPER 1
#define SCIS 2

ll winner(ll a, ll b){
    ll mod = ((a-b)+3)%3;
    return mod;
}

//ll size = (2*1e5+1)
ll n;
ll q;
ll tree[400001];
//finds the sum from index a -> index b

//parent = floor(index/2), child = n*2
//
ll query(ll a, ll b){
    a += n; //going to the root, in this case just returns a 
    b += n; //going to the root

    ll ret = 1e9;
    while(a <= b){
        if(a&1)ret = winner(ret, tree[a++]);
        if(!(b&1))ret = winner(tree[b--], ret);
        //cout << ret << endl;
        a/=2;b/=2;
    }
    return ret;
}

void update(ll k, ll x) {
    k += n;
    tree[k] = winner(tree[k], x);
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = winner(winner(tree[2*k], x), winner(x, tree[2*k+1]));
    }
}
ll chartoletter(char a){
    if(a == 'S'){
        return SCIS;
    }
    if(a == 'P'){
        return PAPER;
    }
    if(a == 'R'){
        return ROCK;
    }
    assert(1<0);
    return -1;
}

ll main(){
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> moves(n);
    for(ll i = 0; i < n; i++){
        moves[i] = chartoletter(s[i]);
    }

    for(ll i=0;i<400001;i++)tree[i]=moves[i];

    while(q--){
        ll a; char b;
        cin >> a >> b;
        ll move = chartoletter(b);
        update(a-1, move);
        cout << query(0, n-1) << endl;
    }
}

