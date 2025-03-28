#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
//KADANE'S ALGORITHM
int main(){
    int n;
    cin >> n;
    ordered_set<int> ost;

    int k;
    k = 1;

    for(int i = 1; i <= n; i++){
        ost.insert(i);
    }
    int pos = k%n;
    while(!ost.empty()){
        int r = *ost.find_by_order(pos);
        ost.erase(r);
        // pos++;
        if(sz(ost))
            pos = (pos+k)%sz(ost);
        // if(sz(ost)==1)break;
        cout << r << " ";
    }
}


