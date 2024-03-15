#include "bits/stdc++.h"
#define int long long
#define f first
#define s second
#define mp make_pair
using namespace std;

int n, m, k;
vector <pair<int,int> > v, tow;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        int y, x;
        cin >> y >> x;
        v.push_back(mp(y, x));
    }
    int ans = 0, prev = 0;
    sort(v.begin(), v.end());
    priority_queue <pair<int,int>, vector <pair<int,int> >, greater<pair<int,int> > > pq;
    int add;
    for(int i = 0; i < n; i++){
        add = min(m, v[i].s);
        if(m){
            ans += add;
            pq.push(mp(v[i].f, add));
            m -= add;
            v[i].s -= add;
        }
        add = 0;
        while(v[i].s && pq.size()){
            pair<int,int> top = pq.top();
            if(v[i].f - top.f < k) break;
            pq.pop();
            if(top.s > v[i].s){
                add += v[i].s;
                pq.push(mp(top.f, top.s - v[i].s));
                v[i].s = 0;
            }
            else add += top.s, v[i].s -= top.s;
        }
        ans += add;
        if(add != 0) pq.push(mp(v[i].f, add));
    }
    cout << ans << endl;
}