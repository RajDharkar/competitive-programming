#include<bits/stdc++.h>

using namespace std;

vector<int> tree;
int n;

void update(int i, int v){
    for(int ind = i; ind <= n; ind += (ind & -ind)){                                                               
        tree[ind] += v;
    }
}

int q(int b){
    int ret = 0;
    for(int ind = b; ind >= 1; ind -= (ind & -ind)){
        ret += tree[ind];
    }
    return ret;
}

int query(int a, int b){
    return q(b) - q(a-1);
}

int main(){
    int t;
    cin >> n >> t;
    tree.resize(n+1);
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1){
            update(b, c);continue; }
        else{
            cout << query(b, c) << endl; 
        }                                                                                                                                                                                                                                                                                                  }
    for(auto x : tree)cout << x << " ";
}