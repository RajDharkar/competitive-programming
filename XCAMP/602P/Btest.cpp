#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

string gen_test_case(int n, int q) {
    string res;
    res += to_string(n) + "\n";
    for (int i = 0; i < n; i++) {
        int val = rand() % 2001 - 1000; // values between -1000 and 1000
        res += to_string(val) + (i == n-1 ? "\n" : " ");
    }

    res += to_string(q) + "\n";
    for (int i = 0; i < q; i++) {
        int type = rand() % 2;
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if (type == 1 && l > r) swap(l, r);
        if (type == 0) {
            int val = rand() % 2001 - 1000;
            res += "0 " + to_string(l) + " " + to_string(val) + "\n";
        } else {
            res += "1 " + to_string(l) + " " + to_string(r) + "\n";
        }
    }

    return res;
}

void write_file(const string &filename, const string &data) {
    ofstream fout(filename);
    fout << data;
    fout.close();
}

string run_program(const string &exe, const string &input_file) {
    string command = "./" + exe + " < " + input_file + " > temp_out.txt";
    system(command.c_str());

    ifstream fin("temp_out.txt");
    string output((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    return output;
}

int main() {
    srand(time(0));
    int t;cin >> t;
    int k = t;
    while(t--){
        int test = k - t + 1; 
        int n = rand() % 10 + 1;
        int q = rand() % 10 + 1;

        string input = gen_test_case(n, q);
        write_file("temp_in.txt", input);

        string out1 = run_program("Bsol", "temp_in.txt");
        string out2 = run_program("B", "temp_in.txt");

        if (out1 != out2) {
            cout << "❌ Mismatch found in test case #" << test << endl;
            cout << "Input:\n" << input << "\n";
            cout << "Output (Old):\n" << out1 << "\n";
            cout << "Output (New):\n" << out2 << "\n";
            return 1;
        } else {
            cout << "✅ Test case #" << test << " passed." << endl;
        }
    }

    cout << "🎉 All test cases passed!" << endl;
}
