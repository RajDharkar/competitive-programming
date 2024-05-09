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
//ll value = (min(b.s+k/2, a.s+k/2) - max(b.s-k/2, a.s-k/2)) * (min(b.f+k/2, a.f+k/2) - max(b.f-k/2, a.f-k/2));
int n, k;
int overLaps = 0;
int area = 0;
vector<pi> original;
struct Event{
    int x, y, y2, id;
    bool isLeft;
};
vector<Event> points;

bool cmp(Event a, Event b){
    return a.x < b.x;
}
bool check(int a, int b){
    if(a == b){
        return 0;
    }
    //cout << a << " " << b << endl;
    bool overLappingX = max(original[a].f - k/2, original[b].f - k/2) < min(original[a].f + k/2, original[b].f + k/2);
    bool overLappingY = max(original[a].s - k/2, original[b].s - k/2) < min(original[a].s + k/2, original[b].s + k/2);
    bool overLapping = overLappingX && overLappingY;
    overLaps+=overLapping;
    if(overLapping){
        //cout << "HEREERHEHRHE";
        area += (min(original[a].s+k/2, original[b].s+k/2) - max(original[b].s-k/2, original[a].s-k/2)) * (min(original[a].f+k/2, original[b].f+k/2) - max(original[b].f-k/2, original[a].f-k/2));
    }
    return overLapping;
}
int main() {
	// read read read
    cin >> n >> k;
    points.resize(2*n);
    original.resize(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        int first = i*2;
        int second = i*2 + 1;
        original[i] = {a, b};
        points[first].x = a-k/2;
        points[second].x = a+k/2;
        
        points[first].y = b - k/2;
        points[second].y = b - k/2;
        points[first].y2 = b + k/2;
        points[second].y2 = b + k/2;
        
        points[first].isLeft = true;
        points[second].isLeft = false;
        
        points[first].id = i;
        points[second].id = i;
    }
    sort(points.begin(), points.end(), cmp);

    set<int> ids;
    for(int i = 0; i < 2*n; i++){
        if(ids.count(points[i].id)){
            ids.erase(points[i].id);
            for(auto id : ids){
                if(overLaps == 2){
                    break;
                }
                check(id, points[i].id);
            }
        }
        else{
            if(points[i].isLeft){
                ids.insert(points[i].id);
            }
        }
    }
    //cout << overLaps << endl;
    if(overLaps >= 2){
        cout << -1;
    }
    else{
        cout << area;
    }
}

