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
    using namespace std;
    
    using ll = long long;
    using db = long double; // or double, if TL is tight
    using str = string; // yay python! 

    // pairs
    using pi = pair<int,int>;
    using pl = pair<ll,ll>;
    using pd = pair<db,db>;
    #define mp make_pair
    #define f first
    #define s second

    int main() {
        // read read read
        int n;
        cin >> n;
        vector<pl> pairs(n);
        set<ll> mainPoints;
        for(int i = 0; i < n; i++){
            cin >> pairs[i].f >> pairs[i].s;
            mainPoints.insert(pairs[i].f);
            mainPoints.insert(pairs[i].s);
        }
        vector<ll> mainP(mainPoints.begin(), mainPoints.end());
        ll intervalSize = ll(mainP.size())-1;
        unordered_map<ll, ll> indexes;
        for(int i = 0; i < ll(mainP.size()); i++){
            indexes[mainP[i]] = i+1;
        }
        ll prev = 0;
        vector<pl> moves;
        for(ll i = 0; i < n; i++){
            moves.push_back({indexes[pairs[i].f], indexes[pairs[i].s]});
            //cout << moves[i].f << " " << moves[i].s << endl;
        }
        ll n2 = ll(mainP.size());
        vector<int> diff(n2 + 1, 0);
        for(ll i = 0; i < ll(moves.size()); i++){
            ll a = min(moves[i].f, moves[i].s);
            ll b = max(moves[i].s, moves[i].f);
            a--;b--;
            diff[a]++;
            diff[b+1]--;
        }
        vector<int> ans;
        ll start = 0;
        int realAns = 0;
        for(ll i = 0; i < n2; i++){
            start+=diff[i];
            ans.push_back(start);
            realAns = max(ans[i], realAns);
        }
        cout << realAns << endl;
        // for(ll i = 0; i < nPoints; i++){
        //     start2+=diffPoints[i];
        //     pointSum.push_back(start2);
        // }
        // ll answer = 0;
        // for(ll i = 1; i < ll(mainP.size()); i++){
        //     if(ans[i-1] >= k){
        //         answer+=abs(mainP[i]-mainP[i-1]);
        //     }
        // }
        // int answer2 = 0;
        // for(ll i = 0; i < nPoints; i++){
        //     // cout << pointSum[i] << " ";
        //     if(pointSum[i] >= k){
        //         answer2++;
        //     }
        // }
        // cout << answer << endl;
        // //-11  -7  -4 -2 0 3
        // //    1   
        // // 0   1   2   3   4   5   6 
        // //   1   2   3   4   5   6
        
        // // you should actually read the stuff at the bottom
    }

    /* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
    */