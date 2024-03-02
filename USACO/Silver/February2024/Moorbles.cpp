// Source: https://usaco.guide/general/io
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int maxeven[m];
    int maxodd[m];
    int mineven[m];
    int minodd[m]; 
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
                maxodd[i] = max(maxeven[i], num);
                minodd[i] = min(minodd[i], num);
            }   
        }
    }
    bool bestPlay[m]; //false = even true = odd
    int stones = 0;
    int endsum[m+1];
    endsum[m] = 0;
    int stonesGained[n];
    for(int i = m-1; i >= 0; i--){
        if(maxeven[i] == -1){
            //all odd
            bestPlay[i] = true;
            endsum[i] = endsum[i+1] - minodd[i];
            stonesGained[i] = minodd[i];
        }
        else if(maxodd[i] == -1){
            //all even
            //bestPlay[i] = false; redundant
            endsum[i] = endsum[i+1] - mineven[i];
            stonesGained[i] = mineven[i];
        }
        else{
            if(maxodd[i] >= maxeven[i]){
                //we will lose less if we choose odd
                bestPlay[i] = true;
                stones+=maxeven[i];
                endsum[i] = endsum[i+1] + maxeven[i];
                stonesGained[i] = -maxeven[i];
            }
            else{
                //opposite as above
                //bestPlay[i] = false; redundant
                stones+=maxodd[i];
                endsum[i] = endsum[i+1] + maxodd[i];
                stonesGained[i] = -maxodd[i];
            }
            
        }
        endsum[i] = max(0, endsum[i]);
        // cout << stonesGained[i] << '\n';
    }
    if(endsum[0] >= n){
        cout << -1 << '\n';
        return;
    }
    int oldsum = 0;
    for(int i = 0; i < m; i++){
        // cout << oldsum << " " << endsum[i+1] << "\n";
        if(bestPlay[i]){
            if(oldsum + maxodd[i] + endsum[i+1] < n){ //all odd(notice that this covers both cases, all odd, and some odd some even)
                bestPlay[i] = false;
                oldsum+=maxodd[i];
            }
            else{ //only choice is to go odd
                //bestPlay[i] = true; redundant
                if(maxeven[i] == -1){ //all odds and we chose odd
                    oldsum-=minodd[i];
                }
                else{ //there are some evens so we subtract the maxeven
                    oldsum+=maxeven[i];
                }
            }
        }
        else{
            //best choice is to go even so we just calculate the amount to add
            if(maxodd[i] == -1){ //all evens 
                oldsum-=mineven[i];
            }
            else{ //there are some odds
                oldsum+=maxodd[i];
            }
         }
    }
    string ans = "";
    for(int i = 0; i < m; i++){
        if(bestPlay[i]){
            ans+= "Odd ";
        }
        else{
            ans+= "Even ";
        }
    }
    ans.pop_back();
    cout << ans << '\n';
    return;
}
int main() {
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}
