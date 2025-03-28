#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

#define MOD 1000000007

int binexp(int a, int b){
    if(a==0)return 0;
    int ret = 1;
    while(b > 0){
        if(b%2){
            ret *= (a) % MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ret;
}

int main(){
    int n, k;
    cin >> n >> k;

    //for each row theres 2^n - 1 ways to place an N
    //for each coloumn theres 2^n - 1
    //THERES n! ways to place the 1's to cover everything properly!
    //then theres k^(n^2 - n) ways to place other stuff

    
}

