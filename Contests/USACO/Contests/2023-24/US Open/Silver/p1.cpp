#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pi = pair<int,int>;
using pl = pair<ll,ll>;

#define f first
#define s second

using str = string; 



int main() {
    int n, m;
    cin >> n >> m;
    vector<int> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }

    vector<int> ans(n, 0);
    priority_queue<int, vector<int>, greater<int>> sigmaqueue;
    
    for(int i = 1; i <= m; i++){
        sigmaqueue.push(i);
    }

    // while(!sigmaqueue.empty()){
    //     cout << sigmaqueue.top();
    //     sigmaqueue.pop();
    // }

    for(int i = 0; i < n; i++){
        cin >> ans[i];
    }
    current_cow = 0;
    while(true){
        farmer_available = sigmaqueue.top();
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