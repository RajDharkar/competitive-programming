#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

ll eugcd(ll a, ll b){
    cout << a << " " << b << endl;  
    return b ? gcd(b, a % b) : a; //Euclids Lemma, GCD(A, B) = GCD(B, A MOD B)
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << eugcd(a, b) << endl;
}

