#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check if the column on this row has already been occupied
    for(int i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return false;
    }
    
    // Check if the upper left diagonal has any queen already
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return false;
    }
    
    // Check if the upper right diagonal has any queen already
    for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
        if(board[i][j] == 1)
            return false;
    }
    
    return true;
}

bool solve(vector<vector<int>>& board, int row) {
    // Base case: if all rows are filled, return true
    if(row == board.size())
        return true;
    
    // Recursive case: try placing a queen on each column of this row
    for(int col = 0; col < board.size(); col++) {
        if(isSafe(board, row, col)) {
            board[row][col] = 1; // place the queen
            
            // Recursively try to place the remaining queens on the next rows
            if(solve(board, row+1))
                return true;
            
            // Backtrack: remove the queen from this cell and try the next cell
            board[row][col] = 0;
        }
    }
    
    // If we have tried all columns on this row and couldn't place a queen, return false
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;
    
    // Initialize an n x n chessboard with all cells set to 0
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if(solve(board, 0)) {
        // If a solution is found, print the board
        cout << "Solution found:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        // If no solution is found, print a message
        cout << "No solution found." << endl;
    }
    
    return 0;
}
// Enter the size of the chessboard: 8
// Solution found:
// 1 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0 
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 1 0 0 0 0