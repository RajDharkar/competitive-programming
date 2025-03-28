#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> bar;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        bar.pb({a, b});
    }
    sort(all(bar), cmp);
    ll t = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(bar[i].f>=t){
            t=bar[i].s;
            ans++;
        }
    }
    cout << ans << endl;
}
