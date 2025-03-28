#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, edges;
    cin >> n >> edges;
    int fullMask = 1 << n;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<int> adjMasks(n, 0);
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        mat[u][v] = mat[v][u] = 1;
        adjMasks[u] |= (1 << v);
        adjMasks[v] |= (1 << u);
    }

    int maskAll = (1 << n) - 1;
    vector<int> lack(n, 0);
    for(int i = 0; i < n; i++){
        int remain = maskAll ^ (1 << i);
        lack[i] = remain & ~adjMasks[i];
    }

    vector<int> popCnt(fullMask, 0);
    for(int s = 0; s < fullMask; s++){
        popCnt[s] = __builtin_popcount(s);
    }

    vector<int> subEdges(fullMask, 0);
    for(int s = 0; s < fullMask; s++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s & (1 << i)){
                for(int j = i + 1; j < n; j++){
                    if(s & (1 << j)){
                        cnt += mat[i][j];
                    }
                }
            }
        }
        subEdges[s] = cnt;
    }

    vector<int> subCost(fullMask, 0);
    for(int s = 0; s < fullMask; s++){
        int cPop = popCnt[s];
        if(cPop <= 1){
            subCost[s] = 0;
        } else {
            int totalPairs = cPop * (cPop - 1) / 2;
            int usedEdges = subEdges[s];
            subCost[s] = min(usedEdges, totalPairs - usedEdges);
        }
    }

    const int INF = 1000000000;
    vector<int> dpVal(fullMask, INF);
    dpVal[0] = 0;
    for(int s = 1; s < fullMask; s++){
        for(int t = s; t; t = (t - 1) & s){
            int left = s ^ t;
            int gap = 0;
            int tmp = t;
            while(tmp){
                int idx = __builtin_ctz(tmp);
                gap += __builtin_popcount(lack[idx] & left);
                tmp &= (tmp - 1);
            }
            dpVal[s] = min(dpVal[s], dpVal[left] + subCost[t] + gap);
        }
    }

    cout << dpVal[fullMask - 1];
}