#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    set<ll> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll k;
        cin >> k;
        s.insert(k);
    }
    cout << int(s.size());
}