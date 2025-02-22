#include<bits/stdc++.h>
//#include "C:\Users\rajve\Documents\GitHub\competitive-programming\debugging.h"
using namespace std;

typedef long long ll;
ll n;
vector<ll> tree;
vector<ll> arr;

ll lsb(ll val){
    return val & -val;
}

void update(ll index, ll val){
    while(index <= n){
        tree[index] += val;
        index += lsb(index);
    }
}

ll psum(ll a){
    ll sum = 0;
    while(a > 0){
        sum += tree[a];
        a -= lsb(a);
    }
    return sum;
}

ll query(ll a, ll b){
    return psum(b)-psum(a-1);
}

int main(){
    ll q;
    cin >> n >> q;
    tree.resize(n+1);
    arr.resize(n+1);

    for(int i = 0; i < n; i++){
        cin >> arr[i+1];
        update(i+1, arr[i+1]);
    }

    for(int i = 0; i < q; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 2){
            cout << query(b, c) << endl;
        }else{
            update(b, c-arr[b]);
            arr[b] = c;
        }
    }
}