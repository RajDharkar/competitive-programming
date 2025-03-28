#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    for(int mask = 0; mask < (1 << n); mask++){
        int k = mask ^ (mask >> 1); //GRAY CODE = NUMBER XOR NUMBER SHIFTED RIGHT BY ONE
        // cout << mask << endl;
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            ans += (k & (1 << i)) ? "1":"0";
        }
        cout << ans << endl;
        // cout << mask << endl;
    }
}