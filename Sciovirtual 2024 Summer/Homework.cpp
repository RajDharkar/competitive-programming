#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> time(n);
    for(int i = 0; i < n; i++){
        cin >> time[i];
    }
    int timeTaken = 0;
    int answer = 0;
    for(int i = 0; i < n; i++){
        if(time[i] + timeTaken > m){
            break;
        }
        timeTaken+=time[i];
        answer++;
    }
    cout << answer << endl;
}
