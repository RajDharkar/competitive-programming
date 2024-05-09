#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

ll n, l, k; 
vector<ll> arr;
ll check(ll hIndex){
    ll used = 0;
    for(ll i = 0; i < hIndex; i++){
        used+=max(hIndex - arr[i], 0LL);
        if(hIndex - arr[i] > k){
            return false;
        }
    }
    return used<=l;
}
ll last_true(){
    ll low = 1;
    ll high = n;
    low--;
    while(low < high){
        int mid = low + (high - low + 1) / 2;
        if(check(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}
int main() {
  
    cin >> n >> k >> l;
    l = l*k;
    arr.resize(n);
    bool worksInstantly = true;
     for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < n){
            worksInstantly = false;
        }
    }            
    if(worksInstantly){
        cout << n << endl;
        return 0;
    }
    // for(int i = 0; i < n; i++){
    //     cout << i + 1 << " " << check(i + 1) << endl;
    // }                                               
    sort(arr.begin(), arr.end(), greater<ll>());
    cout << last_true();
}
