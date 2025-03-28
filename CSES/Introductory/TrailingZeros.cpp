#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll ans = 0;
     //n = 30, n = 6, n = 1, 
    while(n!=0){
        n/=5;
        ans += n;
    }
    cout << ans;
}