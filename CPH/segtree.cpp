#include<bits/stdc++.h>

using namespace std;

vector<int> tree;
int n;

void update(int i, int val){
    i--;i+=n;
    while(i >= 1){
        if(i*2+1<=2*n)
            tree[i] = tree[i*2] + tree[i*2+1];
        else
            tree[i] += val;
        i /= 2;
    }
}

int query(int l, int r){
    l--;r--;
    l+=n;r+=n; 
    int ret = 0;
    while(l <= r){
        if(l % 2 == 1){ //right tree node
            ret += tree[l]; 
            l++;
        } 
        if(r % 2 == 0){ //left tree node converge on each other
            ret += tree[r];
            r--;
        }
        l/=2;r/=2;
    } 
    return ret;
}

int main(){
    int t;
    cin >> n >> t;
    tree.resize(2*n+1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        update(i+1, x);
        for(auto x : tree)cout << x << " ";
        cout << endl;
    }
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1){
            continue; }
        else{
            cout << query(b, c) << endl; 
        }                                                                                                                                                                                                                                                                                                  }
    for(auto x : tree)cout << x << " ";
}