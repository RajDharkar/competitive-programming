// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int maxeven[n];
    int maxodd[n];
    int mineven[n];
    int minodd[n]; 
    for(int i = 0; i < m; i++){
        maxeven[i] = -1;
        maxodd[i] = -1;
        mineven[i] = 1e9 + 7;
        minodd[i] = 1e9 + 7;
        for(int j = 0; j < k; j++){
            int num; 
            cin >> num;
            if(num % 2 == 0){
                maxeven[i] = max(maxeven[i], num);
                mineven[i] = min(mineven[i], num);
            }
            else{
                maxodd[i] = max(maxodd[i], num);
                minodd[i] = min(mineven[i], num);
            }   
        }
    }
    bool bestPlay[n]; //false = even true = odd
    int stones = n;
    int endsum[m+1];
    endsum[m] = 0;
    int stonesGained[n];
    for(int i = m-1; i >= 0; i--){
        if(maxeven[i] == -1){
            //all odd
            bestPlay[i] = true;
            stones+=minodd[i];
            endsum[i] = endsum[i+1] + minodd[i];
            stonesGained[i] = minodd[i];
        }
        else if(maxodd[i] == -1){
            //all even
            bestPlay[i] = false; //slightly redundant but doens't matte
            stones+=mineven[i];
            endsum[i] = endsum[i+1] + mineven[i];
            stonesGained[i] = mineven[i];
        }
        else{
            if(maxodd[i] > maxeven[i]){
                //we will lose less if we choose odd
                bestPlay[i] = true;
                stones-=maxeven[i];
                endsum[i] = endsum[i+1] - maxeven[i];
                stonesGained[i] = -maxeven[i];
            }
            else{
                //opposite as above
                bestPlay[i] = false;
                stones-=maxodd[i];
                endsum[i] = endsum[i+1] - maxodd[i];
                stonesGained[i] = -maxodd[i];
            }
        }
        if(stones <= 0){
            cout << -1 << '\n';
            return;
        }
    }
    int oldstones = 0;
    for(int i = 0; i < m; i++){
        if(bestPlay[i]){
            if(oldstones + maxodd[i] + endsum[i+1] < n){
                bestPlay[i] = false;
                stonesGained[i] = maxodd[i];
            }
            oldstones+=stonesGained[i];
        }
    }
    string ans = "";
    for(int i = 0; i < m-1; i++){
        if(bestPlay[i]){
            ans+= "Odd ";
        }
        else{
            ans+= "Even ";
        }
    }
    ans.append(" ");
    cout << ans << '\n';
    return;
}
int main() {
    setIO("moorbles");
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}
