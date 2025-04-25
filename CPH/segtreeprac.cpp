#include<bits/stdc++.h>

using namespace std;

vector<int> tree;
int n;

void u(int i, int v){
    i += n;
    while(i >= 1){
        if(i*2+1 <= 2*n){
            tree[i] = tree[i*2] + tree[i*2+1];
        } else{
            tree[i] += v;
        }
        i/=2;
    }
}

int q(int p, int q){
    int l = p+n;
    int r = q+n;
    int ret = 0;
    while(l <= r){
        if(l % 2 == 1)ret += tree[l++];
        if(r % 2 == 0)ret += tree[r--];
        l /= 2;r /= 2;
    }
    return ret;
}

int ql(int l, int r, int k, int x, int y){
    cout << l << " " << r << " " << k << " " << x << " " << y << endl;
    if(r < x || l > y) return 0;  // l, r, x, y -> return 0
    if(l <= x && r >= y){ //l, x, y, r -> return tree[current position]
        return tree[k];
    }
    int mid = (x + y) / 2;
    return ql(l, r, k*2, x, mid) + ql(l, r, k*2+1, mid+1, y);
}

int qlazy(int l, int r){
    return ql(l, r, 1, 0, n-1);
}

int main(){
    cin >> n;
    tree.resize(2*n+1);

    for(int i = 0; i < 15; i++){
        int k; cin >> k;
        u(i, k);
    }

    for(int i = 0; i < 1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << qlazy(a, b) << endl;
    }

    u(2, 5);

    for(int i = 0; i < 0; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << q(a, b) << endl;
    }
}