#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int readInt(){
    int integer;
    cin >> integer;
    return integer;
}
int* readArray(int size){
    int* t_array = new int[size];
    for(int i = 0; i < size; i++){
        cin >> t_array[i];
    }
    return t_array;
}
vector<int> readVector(int size){
    vector<int> t_vector(size);
    for(int i = 0; i < size; i++){
        cin >> t_vector[i];
    }
    return t_vector;
}

int main() {
    int n = readInt(); 
    vector<int> arr = readVector(n); 

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
