#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
#define f first
#define s second

struct cow{
    int time, x, y, index;
};

bool cmp(cow a, cow b){
    return a.x > b.x;
}

int main() {
    int n, T, X, Y;
    cin >> n >> T >> X >> Y;
    vector<cow> cows(n);
    for(int i=0;i<n;i++){
        cin >> cows[i].time >> cows[i].x >> cows[i].y;
        cows[i].index = i;
    }

    for(int i = 0; i < n; i++){
        int x = cows[i].x;
        int idx = 0;
        for(int q = 0; q < T; q++){
            int lefty = 0;
            int righty = 1e9;
            for(;idx < n && cows[i].time <= q; idx++){
                if(cows[idx].x < x){
                    lefty = max(cows[idx].y, lefty);
                }
                else{
                    righty = min(cows[idx].y, righty);
                }
            }
            assert(lefty <= righty);
        }
    }
}

