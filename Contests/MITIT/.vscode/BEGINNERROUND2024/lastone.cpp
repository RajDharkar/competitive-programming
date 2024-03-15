#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 10e9 + 7;
// ios_base::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    pii red[n];
    pii blue[n];
    int x, y;
    
    for(int i = 0; i < n; i++){
         cin >> red[i].first >> red[i].second;
    }
    
    for(int i = 0; i < n; i++){
         cin >> blue[i].first >> blue[i].second;
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(red[i].first < blue[j].first && red[i].second < blue[j].second){
                ans++;
                red[i].first = 1000;
                red[i].second = 1000;
                blue[j].first = -1;
                blue[j].second = -1;
            }
        }
    }
    
    cout << ans;
}
