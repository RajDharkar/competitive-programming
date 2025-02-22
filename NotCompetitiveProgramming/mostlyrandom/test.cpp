#include <iostream>
#include <vector>
#include <set>
#include <iomanip>  // For setw
#include <chrono>   // For timing progress

using namespace std;
using namespace chrono;

// Function to generate the table and return the grid
vector<vector<int>> generateTableAndReturnGrid(int r, int c, int targetRow, int targetCol) {
    // Set to track the used numbers in each row and column
    vector<set<int>> usedInRow(r);   // Set to track used numbers in rows
    vector<set<int>> usedInColumn(c); // Set to track used numbers in columns

    // Temporary 2D table for storing the values
    vector<vector<int>> grid(r, vector<int>(c, -1));

    int value = -1;

    // Start timing
    auto start_time = steady_clock::now();
    int totalCells = r * c;
    int cellsProcessed = 0;

    // Fill the grid column by column
    for (int col = 0; col < c; ++col) {
        for (int row = 0; row < r; ++row) {
            // Find the smallest unused number by looking for the first available one
            int num = 0;
            while (usedInRow[row].count(num) > 0 || usedInColumn[col].count(num) > 0) {
                ++num;
            }
            value = num;

            // Set the grid value and mark it as used in the row and column
            grid[row][col] = value;
            usedInRow[row].insert(value);
            usedInColumn[col].insert(value);

            // Track the number of cells processed
            cellsProcessed++;

            // Print progress every second
            auto elapsed = duration_cast<seconds>(steady_clock::now() - start_time).count();
            if (elapsed > 0) {
                int progress = (cellsProcessed * 100) / totalCells;
                cout << "Progress: " << progress << "% (" << elapsed << " seconds)\n";
                start_time = steady_clock::now(); // Reset timer for next second
            }
        }
    }

    return grid;  // Return the filled grid
}

int main() {
    int targetRow = 2;
    int targetCol = 3;

    // Generate the grid
    cout << "Generating grid...\n";
    vector<vector<int>> grid = generateTableAndReturnGrid(5, 5, targetRow, targetCol);

    // Output the value at the target position
    cout << "\nThe value at row " << targetRow << " and column " << targetCol << " is: " 
         << grid[targetRow][targetCol] << endl;

    return 0;
}
