#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        if(a<b){
            swap(a, b);
        }
        bool works = !((a+b)%3);
        works &= (b*2)>=a;
        cout << (works ? "YES" : "NO") << endl;
        //1 2 
        //2 1
        //4 2
        //3 3
        //6 3
        
    }
}