#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
	cin >> n;
    ll hgt[n];
    ll max[n];
    for(int i = 0; i < n; i++){
        cin >> hgt[i];
    }
    for(int i = 0; i < n; i++){
        cin >> max[i];
    }
    sort(hgt, hgt + n);
    sort(max, max + n);
    ll count = 0;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        count = 0;
        ll themax = max[i];
        for(int j = 0; j < n; j++){
            if(hgt[j]<=themax){
                count++;
            }
        }
        ans*=(count - i);
    }
    cout << ans;
}
