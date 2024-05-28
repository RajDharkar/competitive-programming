#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()
#define f first
#define s second
int n;
int l;
 
vector<array<int, 3>> cows;

bool cmp(const array<int, 3>& a, const array<int, 3>& b){
    return a[1] < b[1];
}
int findTime(){
    vector<int> leftCows; //DISTANCE FROM THE END
    vector<int> rightCows; //DISTANCE FROM THE END
    for(int i = 0; i < n; i++){
        if(cows[i][2] == 1){
            rightCows.push_back(l - cows[i][1]);
        }
        else{
            leftCows.push_back(cows[i][1]);
        }
    }
    
    vector<pii> final; //<DISTANCE, WEIGHT - FINAL COW WEARING TOP HAT
    for(int i = 0; i < sz(leftCows); i++){
        final.push_back({leftCows[i], cows[i][0]});
    }
    for(int i = 0; i < sz(rightCows); i++){
        final.push_back({rightCows[i], cows[sz(leftCows) + i][0]}); //This finds the opposite aka corresponding cow in the leftCows section
    }

    sort(final.begin(), final.end());
    for(int i = 0; i < sz(final); i++){
        cout << final[i].f << " " << final[i].s << endl;
    }

    int total = 0;
    int curr = 0;
    for(int i = 0; i < sz(final); i++){
        total+=final[i].s;
    }

    for(int j = 0; j < sz(final); j++){
        curr += final[j].s;
        if((curr * 2) >= total){
            return final[j].f;
        }
    }
    return 0;
}
int main() {
    // ifstream cin("meetings.in");
    // ofstream cout("meetings.out");
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        array<int, 3> arr;
        cin >> arr[0] >> arr[1] >> arr[2];
        cows.push_back(arr);
    }

    sort(cows.begin(), cows.end(), cmp);
    int time = findTime();

    // cout << time << endl;
    vector<int> leftCows; //DISTANCE FROM THE END
    vector<int> rightCows; //DISTANCE FROM THE END
    for(int i = 0; i < n; i++){
        if(cows[i][2] == 1){
            rightCows.push_back(cows[i][1]);
        }
        else{
            leftCows.push_back(cows[i][1]);
        }
    }
    int ans = 0;
    for(int i = 0; i < sz(leftCows); i++){
        int end = lower_bound(rightCows.begin(), rightCows.end(), leftCows[i]) - rightCows.begin();
        int start = lower_bound(rightCows.begin(), rightCows.end(), leftCows[i] - 2 * time) - rightCows.begin();
        ans += end - start;
    }
    cout << ans;    
}


//NOTES
//original ideas, maybe some type of binary search, no ieda how to implement though
//SOLUTION - https://www.youtube.com/watch?v=W4ZYL456PVg&list=PLFfCaQZaHSRTgAES57AoS9D6cyLtrvIqh&index=14
//Next time I need to observe how simulating the collisions in O(1) isn't possible because idk its hard
//This is good solution, I'm still writing it right now, but I'm trying to figure out how T was calculated.
//after watching the top hat part again i understand it now
// The final array keeps track of which cow is holding the top hat and in which order
//