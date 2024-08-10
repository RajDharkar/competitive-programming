#include <iostream>
using namespace std;
typedef long long ll;

ll sumXOR(int arr[], int n, int a, int b) 
{ 
    ll sum = 0; 
    for (int i = 0; i < 64; i++)  
    { 
        ll o = 0, z = 0;
        ll ans = 0;  
        for (int j = a-1; j < b; j++) 
        { 
            if (arr[j] % 2 == 0) {
                z++; 
            } else {
                o++; 
            }
            arr[j] /= 2; 
        } 
        ans = o * z * (1 << i);  
        sum += ans;  
    } 
    return sum; 
} 
  
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;  
        cout << sumXOR(arr, n, a, b) << endl;
    }
}
