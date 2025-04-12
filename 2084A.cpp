#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

void solve(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << -1 << endl;
        return;
    }
    cout << n;
    for(int i = 1; i < n-1; i++){
        cout << " " << i;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

