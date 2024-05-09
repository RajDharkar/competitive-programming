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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool works = false;
        vector<int> e;
        e.push_back(b);
        e.push_back(c);
        sort(e.begin(), e.end());
        if(d >= e[0] && d <= e[1]){
            works = true;
        }
        if(works){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
    }

    /* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
        * DON'T GET STUCK ON ONE APPROACH
    */