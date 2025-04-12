#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        char z = s[0];
        bool works = 0;
        for(int i = 0; i < sz(s); i++){
            if(s[i] != z){
                works = 1;
                break;
            }
        }
        if(!works){
            cout << "NO" << endl;
            continue;
        }
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l <= r){
            if(s[r] != s[l]){
                if(s[r] < s[l]){
                    ans++;
                }
                break;
            }
            l++;r--;
            if(l==r || l > r){
                if(k==0){
                    ans = 1e9;
                } else{
                    ans = 0;
                }
            }
        }   
        cout << (ans <= k ? "YES" : "NO") << endl;
    }
}

