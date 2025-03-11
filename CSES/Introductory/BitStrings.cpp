#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int pow(int base, int exp){
    int ret = 1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1){
            ret = (1LL *ret*base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp/=2;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    cout << pow(2, n);
}