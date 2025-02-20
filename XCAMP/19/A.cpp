    #include <bits/stdc++.h>
    using namespace std;


    template<class T>
    using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

    // void example() {
    // 	Tree<int> t, t2; t.insert(8);
    // 	auto it = t.insert(10).first;
    // 	assert(it == t.lower_bound(9));
    // 	assert(t.order_of_key(10) == 1);
    // 	assert(t.order_of_key(11) == 2);
    // 	assert(*t.find_by_order(0) == 8);
    // 	t.join(t2);  assuming T < T2 or T > T2, merge t2 into t
    // }

    int main(){
        int n, m, q;
        cin >> n >> m >> q;
        vector<Tree<int>> trees(n); //n rows
        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            
        } 
    




    }