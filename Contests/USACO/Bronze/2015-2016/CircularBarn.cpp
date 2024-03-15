#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("cbarn");
    int n;
	cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 2000000000;
    int count = 0;
   for(int k = 0; k < n; k++){
        int p = k - 1;
        if(k == 0){p = n -1;}
        int i = n -1;
        count = 0;
        while(i>0){
            count += arr[p]*i;
            if(p==0){
                p = n-1;
            }
            else{
                p--;
            }
            i--;
        }
        ans = min(ans, count);
   }
    cout << ans;
}
