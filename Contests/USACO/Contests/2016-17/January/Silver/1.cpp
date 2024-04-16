#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
int n, t;
vector<int> cows;
bool check(int k){
    int lastTime = 0;
	priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        if(pq.size() == k) {
            lastTime = pq.top();
            pq.pop();
        }
        if(lastTime + cows[i] > t) {
            return false;
        }
        pq.push(lastTime + cows[i]);
    }
    return true;
}
int main() {
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cows.push_back(a);
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << check(i) << endl;
    }
    // int low = 1;
    // int high = n - 1;
    // while(low != high){
    //     int mid = low + (high - low) / 2;
    //     if(check(mid) <= t){

    //     }
    // }

}
