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

struct Figure{
    string name;
    int dir;
};

int main() {
	// read read read
    ll n, m;
    cin >> n >> m;
    vector<Figure> circle(n);
    for(int i = 0; i < n; i++){
        cin >> circle[i].dir >> circle[i].name;
    }
    int index = 0;
    for(int i = 0; i < m; i++){
        int dir, size;
        cin >> dir >> size;
        if((!dir && !circle[index].dir)){
            index-=size;
        }
        else if(!dir && circle[index].dir){
            index+=size;
        }
        else if(dir && !circle[index].dir){
            index += size;
        }
        else if(dir && circle[index].dir){
            index -= size;
        }
        index += n;
        index %= n;
        //cout << index << endl;
    }
    cout << circle[index].name;




	// you should actually read the stuff at the bottom
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/