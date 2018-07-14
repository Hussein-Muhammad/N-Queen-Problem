// SOLVE_N_QUEEN_PROBLEM  USING BACKTRACK ALGORITHM

#include <iostream>
#include<stdio.h>
using namespace std;
int N ;

void printSolution(int** board)
{
    static int k = 1;
    cout <<" # " << k++ << "\n\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << "  " << board[i][j] ;

        cout << endl;
    }
    cout << "\n\n";
}

bool isSafe(int** board, int row, int col)
{
    int i, j;

    // Check vertical attack
    for (i = 0; i < row; i++)
        if (board[i][col]==1)
            return false;

    // Check upper left diagonal
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j]==1)
            return false;

    // Check upper right diagonal
    for (i=row, j=col; i>=0 && j<N; i--, j++)
        if (board[i][j]==1)
            return false;

    return true;
}

void solve_next_queen(int** board, int row)
{
    // base case: If all queens are placed then print & return
    if (row == N )
    {
        printSolution(board);
        return;
    }

    /* Consider this row and try placing this queen in all columns one by one */
    for (int c = 0; c < N; c++)
    {
        /* Check if queen can be placed on board*/
        if ( isSafe(board, row, c) )
        {
            board[row][c] = 1;                   //Place this queen in board[i][col]
            solve_next_queen(board, row + 1) ;   // recur to place rest of the queens
            board[row][c] = 0;                   // BACKTRACK
        }
    }
}

void solve_N_Queen_problem()
{
    if (N==2||N==3) {cout << " THERE IS NO N QUEEN SOLUTION " ;return;}

//DECALRE 2D DYNAMIC ARRAY [ ARRAY OF POINTERS TO ARRAYS ]
    int** board ;
    board = new int*[N] ;
    for(int i = 0 ; i<N;  i++)
        board[i] = new int[N];

//INITIALIZE ALL 0'S
    for (int i = 0 ; i< N ; i++){
        for (int j = 0 ; j< N ; j++)
            board[i][j] = 0 ;
    }
    solve_next_queen(board, 0) ;
    return ;
}

int main()
{
    cout << " Enter the Number of the queens : " ;
    cin >> N ;

    solve_N_Queen_problem();
    return 0 ;
}
