#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n;
    cin >> n;
    vector<pii> cow;
    int g = 0;
    int h = 0;
    for(int i = 0; i < n; i++){
        int a;
        char b;
        cin >> a >> b;
        if(b == 'G'){ // G = 0, H = 1
            cow.push_back({a, 1});
            g++;
        }
        else{
            cow.push_back({a, 0});
            h++;
        }
    }
    sort(cow.begin(), cow.end());
    for(pii a : cow){
        cout << a.first << " " << a.second << endl;
    }
    if(g == h || g == 0 || h == 0){
        cout << cow[n-1].first - cow[0].first << endl;
        return;
    }
    int ans = 0;
    int lp = 0;
    int rp = n - 1;
    while(lp < rp){
        bool moreG = false;
        if(g == h || g == 0 || h == 0){
            ans = cow[rp].first - cow[lp].first;
        }
        if(lp == rp){
            
        }
    }
}
