#include<bits/stdc++.h>

using namespace std;

int main(){
    int ans = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i * i + j * j + i + j == 3 * i * j){
                cout << i << " " << j << '\n';
                ans++;
            }
        }
    }
    cout << ans << endl;

    // (a - b)^2 + 1 = (a-1)(b-1)
    // 0+1 -> 1 * 1, so a = b = 2, so we get sols, {2, 2}
    // 1+1 -> 2, so (2 * 1), so a = 3, b = 2 which works, so we get sols, {2, 3} & {3, 2} 
    // 4+1 = 5 -> (5 * 1) so a = 6 and b = 2, which is invalid
    // 9+1 = 10 -> (10 * 1), not possible, (5 * 2), so a = 6 b = 3, which is valid, so {3, 6}, {6, 3}
    // 16 + 1 = 17, no sols
    // 25 + 1 = 26, no sols
    // 36 + 1 = 36, no sols
    // 49 + 1 = 50, 5 * 10, no sols
    // 64 + 1 = 67, no sols
    // 81 + 1 = 82, no sols
    // 100 + 1 = 101, no sols
}