#include <bits/stdc++.h>

using namespace std;

//toh(2, 1, 2)
//toh(1, 1, 3)
//

void toh(int n, int x, int y){
    if(n<=1){
        cout << x << " " << y << endl; 
        return;
    }
    toh(n-1, x, 6-x-y);
    toh(1, x, y);
    toh(n-1, 6-x-y, y);
}

int main(){
    int n;
    cin >> n;

    cout << (1<<n) - 1 << endl;
    toh(n, 1, 3);

}