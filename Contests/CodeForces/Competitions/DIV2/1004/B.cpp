#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> ar(n+1);
        vector<ll> count(1e5);
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            count[a]++;
        }

        bool works = 1;
        for(int i = 1; i <= n; i++){
            if(count[i] == 1){
                works = 0;
                break;
            }
            count[i+1] += max(0LL, count[i]-2);
        }

        cout << (works ? "Yes" : "No") << endl;

    }
}   