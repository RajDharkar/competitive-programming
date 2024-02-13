#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("input");
    int t;
    cin >> t;
    while(t--){
        //65 is a
        int n;
        cin >> n;
        if(n <= 52){
            cout << char(65);
            n-=1;
        }
        else{
            int k = n-52;
            cout << char(k+64);
        }
    }
}
