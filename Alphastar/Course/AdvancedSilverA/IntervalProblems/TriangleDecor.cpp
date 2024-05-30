#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <climits>
#include <unordered_set>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python!

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second
vector<pl> peaks;
vector<ll> ids;
bool cmp(int a, int b){
    if(peaks[a].f - peaks[a].s == peaks[b].f - peaks[b].f){
        return peaks[a].f + peaks[a].s > peaks[b].f + peaks[b].s;
    }
    return peaks[a].f - peaks[a].s < peaks[b].f - peaks[b].f;
}
int main() {
    // read read read
    int n;
    cin >> n; // read n
    peaks.resize(n);
    ids.resize(n);
    for(int i = 0; i < n; i++){
        cin >> peaks[i].f >> peaks[i].s;
        ids[i] = i;
    }
    sort(ids.begin(), ids.end(), cmp);
    
    ll maxP = -1e9;
    ll answer = 0;
    for(int i = 0; i < n; i++){
        if(maxP < peaks[ids[i]].f + peaks[ids[i]].s){
            maxP = peaks[ids[i]].f + peaks[ids[i]].s;
            answer++;
        }
    }
    cout << answer;
    // you should actually read the stuff at the bottom
}


/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
