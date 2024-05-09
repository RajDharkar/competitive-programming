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
        int n, k;
        cin >> n >> k;
        vector<pl> pairs(n);
        set<ll> mainPoints;

        ll curPos = 0;
        for(int i = 0; i < n; i++){
            mainPoints.insert(curPos);
            char a;
            cin >> pairs[i].s >> a;
            if(a == 'R'){
                pairs[i].f = 1;
                curPos+=pairs[i].s;
            }
            else{
                pairs[i].f = -1;
                curPos-=pairs[i].s;
            }
        }
        mainPoints.insert(curPos);
        vector<ll> mainP(mainPoints.begin(), mainPoints.end());
        ll intervalSize = ll(mainP.size())-1;
        unordered_map<ll, ll> indexes;
        for(int i = 0; i < ll(mainP.size()); i++){
            // cout << mainP[i] << " ";
            indexes[mainP[i]] = i+1;
        }
        cout << endl;
        ll prev = 0;
        vector<pl> moves;
        vector<pl> movesPoints;
        for(ll i = 0; i < n; i++){
            moves.push_back({indexes[prev], indexes[prev + pairs[i].s*pairs[i].f]});
            prev+=pairs[i].s*pairs[i].f;
        }
        for(ll i = 0; i < ll(moves.size()); i++){
            // cout << moves[i].f << " " << moves[i].s << endl;
            if(moves[i].f < moves[i].s){
                movesPoints.push_back({moves[i].f+1, moves[i].s});
            }
            else{
                movesPoints.push_back({moves[i].f-1, moves[i].s});
            }
            // cout << movesPoints[i].f << " " <<  movesPoints[i].s << endl;
            if(moves[i].s < moves[i].f){
                ll hold = moves[i].f;
                moves[i].f = moves[i].s;
                moves[i].s = hold;
            }
            moves[i].s--;
        }
        vector<int> intervals(ll(mainP.size())-1); 
        ll nPoints = ll(mainP.size());
        // cout << nPoints << endl;
        ll n2 = ll(intervals.size());
        vector<int> diff(n2 + 1, 0);
        vector<int> diffPoints(nPoints+1, 0);
        // cout << n2 << endl;
        // vector<int> brute(n, 0);
        for(ll i = 0; i < ll(moves.size()); i++){
            ll a = min(moves[i].f, moves[i].s);
            ll b = max(moves[i].s, moves[i].f);
            ll a2 = min(movesPoints[i].f, movesPoints[i].s);
            ll b2 = max(movesPoints[i].f, movesPoints[i].s); 
            a2--;b2--;
            a--;b--;
            diff[a]++;
            diff[b+1]--;
            diffPoints[a2]++;
            diffPoints[b2+1]--;
        }
        vector<int> ans;
        vector<int> pointSum;
        ll start = 0;
        ll start2 = 0;
        for(ll i = 0; i < n2; i++){
            start+=diff[i];
            ans.push_back(start);
            // cout << ans[i] << " ";
        }
        cout << endl;
        for(ll i = 0; i < nPoints; i++){
            start2+=diffPoints[i];
            pointSum.push_back(start2);
        }
        ll answer = 0;
        for(ll i = 1; i < ll(mainP.size()); i++){
            if(ans[i-1] >= k){
                answer+=abs(mainP[i]-mainP[i-1]);
            }
        }
        int answer2 = 0;
        for(ll i = 0; i < nPoints; i++){
            // cout << pointSum[i] << " ";
            if(pointSum[i] >= k){
                answer2++;
            }
        }
        cout << answer << endl;
        //-11  -7  -4 -2 0 3
        //    1   
        // 0   1   2   3   4   5   6 
        //   1   2   3   4   5   6
        
        // you should actually read the stuff at the bottom
    }

    /* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
    */