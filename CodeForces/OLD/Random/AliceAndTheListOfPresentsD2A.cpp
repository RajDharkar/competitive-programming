#include<bits/stdc++.h>


using namespace std;

typedef long long ll;;

#define MOD 1000000007

ll binexp(ll a, ll b){
    if(a==0)return 0;
    ll ret = 1;
    while(b>0){
        if(b%2 == 1){
            ret *= a;
            ret %= MOD;
        }
        b/=2;
        a*=a;
        a %= MOD;
    }
    return ret;
}

int main(){
    ll n, m;
    cin >> n >> m;
    cout << binexp((binexp(2, m) - 1), n); 
}