#pragma ONCE
// C++ program to find the next optimal move for
// a player
#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define INF 2137483647

struct Move
{
    int row, col;
};

class TTT
{
    char player = 'x', opponent = 'o';
    int boardSize;
    int rowWinLength = 4;
    bool turn = false; // false for AI start

public:
    bool isMovesLeft(char **board);
    int evaluate(char **b);
    int minimax(char **board, int depth, char symbol, int alpha, int beta);
    Move findBestMove(char **board);
    bool AImakeMove(char **board);
    int startGame(char **board);
    void playerMove(char **board);
    int calculate_score(char **board);
    bool check_horizontal(char **board, char symbol);
    bool check_vertical(char **board, char symbol);
    bool check_win(char **board, char symbol);
    bool check_diagonal(char **board, char symbol);
    bool checkArrays(char symbol, char *diagonal, int j);
    void showBoard(char **board);
    TTT(int new_boardSize, int new_rowWinLength)
    {
        boardSize = new_boardSize;
        rowWinLength = new_rowWinLength;
    }
    TTT();
};
