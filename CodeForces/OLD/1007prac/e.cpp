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

int main() {
	// read read read
	
	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/#include <bits/stdc++.h>
using namespace std;

//int size = (2*1e5+1)
int n;
int tree[200005];

//finds the sum from index a -> index b

//parent = floor(index/2), child = n*2
//
int sum(int a, int b){
    a += n; //going to the root, in this case just returns a 
    b += n; //going to the root

    int ret = 0;
    while(a <= b){
        if(a&1)ret+=tree[a++];
        if(!(b&1))ret+=tree[b--];
        //cout << ret << endl;
        a/=2;b/=2;
    }
    return ret;
}
void add(int k, int x) {
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2*k]+tree[2*k+1];
    }
}

int main(){
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        add(i, a);
    }
    // for(int i=0; i < 2*n+1; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << sum(a, b) << endl;
    }
}

