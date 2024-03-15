#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    int zerocount = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            zerocount++;
        }
    }
    if(zerocount > n - zerocount){
        for(int i = 0; i < n -1; i++){
            cout << 0 + " ";
        }
        cout << 0 << endl;
    }
    for(int i = 0; i < n; i++){
        if(i + 1<= n-zerocount - zerocount)
            cout << i + 1;
        
    }
}

int main() {
    int t;
    for(int test = 0; test < t; test++){
        solve();
    }
}
