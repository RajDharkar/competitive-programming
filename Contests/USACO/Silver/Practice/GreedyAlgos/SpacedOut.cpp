#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int n;
int grid[1001][1001];
int rowSums[1001][2]; //0 even // 1 odd;
int colSums[1001][2];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            rowSums[i][j % 2]+=grid[i][j];
            colSums[j][i % 2]+=grid[i][j];
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << rowSums[i][0] << " " << rowSums[i][1] << " ";
    //     cout << colSums[i][0] << " " << colSums[i][1] << '\n';
    // }
    int maxRowSum = 0;
    int maxColSum = 0;
    for(int i = 0; i < n; i++){
        maxRowSum+=max(rowSums[i][0], rowSums[i][1]);
        maxColSum+=max(colSums[i][0], colSums[i][1]); 
    }
    cout << max(maxRowSum, maxColSum);

}
