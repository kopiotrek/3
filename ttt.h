#pragma ONCE
// C++ program to find the next optimal move for
// a player
#include <bits/stdc++.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#define INF 2147483647

struct Move
{
    int row, col;
};

class TTT
{
    char player = 'x', opponent = 'o';
    int boardSize;
    int rowWinLength=3;
    bool turn = false; // false for AI start

public:
    bool isMovesLeft(char **board);
    int evaluate(char **b);
    int minimax(char **board, int depth, bool isMax);
    Move findBestMove(char **board);
    bool AImakeMove(char **board);
    bool startGame(char **board);
    void playerMove(char **board);
    int calculate_score(char **board);
    bool check_horizontal(char **board,char symbol);
    bool check_vertical(char **board,char symbol);
    bool check_win(char **board,char symbol);
    bool check_diagonal(char **board, char symbol);
    bool checkArrays(char *win, char *diagonal, int j);
    TTT(int new_boardSize) { boardSize = new_boardSize; }
    TTT();
};
