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
#include <stack>
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
    vector<pi> instruct;
    vector<pair<pi, int>> array; //Number Line Interval, {between x and y}, Number of Times Hit.
    int pos = 0;
    array.push_back({{0, 0}, 0});
    for(int i = 0; i < n; i++){
        char a;
        int b;
        cin >> a >> b;
        int oldpos = pos;
        if(a =='R'){
            pos+=b;
        }
        else{
            pos-=b;
        }
        array.push_back({{pos, pos}, 0});
    }
    for(int i = 0; i < int(array.size()); i++){
        cout << array[i].f.f << " " << array[i].f.s << " ";
    }
    
    //you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/