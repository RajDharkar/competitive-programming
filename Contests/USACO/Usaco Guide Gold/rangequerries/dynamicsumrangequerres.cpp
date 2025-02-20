#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

template<class T> class SegmentTreeSum{
    private:
        const T DEFAULT = 0;

        int len;
        vector<T> tree;
    public:
        SegmentTreeSum(int len) : len(len){
            tree = vector<T>(len * 2, DEFAULT);
        }

        void set(int ind, T val){
            ind += len;
            tree[ind] = val;
            for(; ind > 1; ind /= 2){
                tree[ind / 2] = (tree[ind] + tree[ind ^ 1]); //+ 1, and + 0
            }
        }

        T range_sum(int start, int end){
            T ret = DEFAULT;
            for(start += len, end += len; start < end; start /= 2, end /= 2){ //iterating through the different segments
                if(start % 2 == 1) {
                    ret += tree[start++];
                }
                if(end % 2 == 1){
                    ret += tree[--end];
                }
            }
            return ret; // very cool very demure approach
        }
};        
    
int main(){
    int n, q;
    cin >> n >> q;
    SegmentTreeSum<ll> mst(n);
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        mst.set(i, a);
    }
    for(int i = 0; i < q; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 2){
            cout << mst.range_sum(b-1, c) << endl;
        }
        else{
            mst.set(b-1, c);
        }
    }

}

    