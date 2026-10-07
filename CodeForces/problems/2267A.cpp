#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n; char b;
        cin >> n >> b;
        string s;
        cin >> s;
        int l = 0, r = n - 1;
        int ans = 0;
        while(l <= r) {
            if(s[l] == s[r]){
 
            }
            else{
                ans += 2 - (s[r] == b || s[l] == b);
            }
            l++;r--;
        }
        cout << ans << '\n';
    }
}