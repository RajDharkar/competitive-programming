#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }
    sort(times.begin(), times.end());
    int answer = 0;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(times[i] + time > m){
            break;
        }
        else{
            answer++;
            time+=times[i];
        }
    }
    cout << answer;
}
