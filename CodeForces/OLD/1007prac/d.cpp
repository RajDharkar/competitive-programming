// #include <algorithm>
// #include <array>
// #include <bitset>
// #include <cassert>
// #include <chrono>
// #include <cmath>
// #include <complex>
// #include <cstring>
// #include <functional>
// #include <iomanip>
// #include <iostream>
// #include <map>
// #include <numeric>
// #include <queue>
// #include <random>
// #include <set>
// #include <vector>
// #include <climits>
// using namespace std;
 
// using ll = long long;
// using db = long double; // or double, if TL is tight
// using str = string; // yay python! 

// // pairs
// using pi = pair<int,int>;
// using pl = pair<ll,ll>;
// using pd = pair<db,db>;
// #define mp make_pair
// #define f first
// #define s second

// int main() {
// 	// read read read
// 	int t;
// 	cin >> t;
// 	while(t--){
// 		ll n, l, r;
// 		cin >> n >> l >> r;
// 		vector<int> ri(n);
// 		vector<int> xors;
// 		xors.resize(n);
// 		xors[0]=ri[0];
// 		for(int i = 0; i < n; i++){
// 			cin >> ri[i];
// 		}
// 		vector<int> pref(n+1);
// 		for(int i = 1; i <= n; i++)pref[i] = pref[i-1]+a[i];
// 		if(n%2==1)

// 		for(int i=n+1;i<=2*n;i++){
// 			if(i%2)
// 				ri.push_back(r[i]^r)
// 		}

// 		while(l > n){

// 		}

// 		//goto end;
// 		// for(auto x : ri){
// 		// 	cout << x << " ";
// 		// }
// 		// cout << endl;
// 		// //goto end;
// 		// for(auto x : xors){
// 		// 	cout << x << " ";
// 		// }
// 		// cout << endl;

// 		for(int i = n; i <= 100; i++){
// 			int x = ri[i-1];
// 			// cout << x << endl;
// 			if(i%2==1){
// 				cout << i << " ";
// 				int ind = i/2;
// 				cout << ind << " ";
// 				if(ind<=n){
// 					x^=xors[ind-1];
// 				}
// 				else{
// 					x^=ri[ind];
// 				}
// 			}
// 			// cout << i << ": " << ri[0] << " ";
// 			// for(int j = 1; j < i/2; j++){
// 			// 	x^=ri[j];
// 			// 	cout << ri[j] << " ";
// 			// }
// 			ri.push_back(x);
// 			cout << x << " \n";
// 		}
// 		cout << endl;


// 		for(auto x : ri){
// 			cout << x << " ";
// 		}
// 		cout << endl;
// 		end:;

// 	}
// 	// you should actually read the stuff at the bottom
// }

// /* stuff you should look for
// 	* int overflow, array bounds
// 	* special cases (n=1?)
// 	* do smth instead of nothing and stay organized
// 	* WRITE STUFF DOWN
// 	* DON'T GET STUCK ON ONE APPROACH
// */