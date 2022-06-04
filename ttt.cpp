// C++ program to find the next optimal move for
// a player
#include <bits/stdc++.h>
#include "ttt.h"
using namespace std;

// This function returns true if there are moves
// remaining on the board. It returns false if
// there are no moves left to play.
bool TTT::isMovesLeft(char **board)
{
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

// This is the evaluation function as discussed
// in the previous article ( http://goo.gl/sJgv68 )
int TTT::evaluate(char **b)
{
    for (char i = 0; i < boardSize; i++)
    {
        cout << "{";
        for (char j = 0; j < boardSize; j++)
        {
            cout << " |" << b[i][j] << "| ";
        }
        cout << "}\n";
    }
    cout << "\n________________________________\n";
    // Checking for Rows for X or O victory.
    for (int row = 0; row < boardSize; row++)
    {
        if (b[row][0] == b[row][1] &&
            b[row][1] == b[row][2])
        {
            char tmp = b[row][0];
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col < boardSize; col++)
    {
        if (b[0][col] == b[1][col] &&
            b[1][col] == b[2][col])
        {
            if (b[0][col] == player)
                return +10;

            else if (b[0][col] == opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}

int TTT::calculate_score(char **board)
{
    for (char i = 0; i < boardSize; i++)
    {
        cout << "{";
        for (char j = 0; j < boardSize; j++)
        {
            cout << " |" << board[i][j] << "| ";
        }
        cout << "}\n";
    }
    cout << "\n________________________________\n";
    // int board[boardSize][boardSize];
    // for (char i = 0; i < boardSize; i++)
    // {
    //     for (char j = 0; j < boardSize; j++)
    //     {
    //         board[i][j] = board[i][j];
    //     }
    // }
    int score = 0;
    int temp = 0;
    int i, j;
    for (i = 0; i < boardSize; i++)
    {
        temp = 0;
        for (j = 0; j < boardSize; j++)
        {
            if (board[i][j] == opponent)
                temp += 1;
            else if (board[i][j] == '_')
            {
                temp = 0;
                break;
            }
            if (temp != 0)
                score += pow(10, temp);
        }
    }
    for (i = 0; i < boardSize; i++)
    {
        temp = 0;
        for (j = 0; j < boardSize; j++)
        {
            if (board[j][i] == opponent)
                temp += 1;
            else if (board[j][i] == '_')
            {
                temp = 0;
                break;
            }
        }
        if (temp != 0)
            score += pow(10, temp);
    }

    temp = 0;

    for (i = 0; i < boardSize; i++)
    {
        if (board[i][i] == opponent)
            temp += 1;
        else if (board[i][i] != '_')
        {
            temp = 0;
            break;
        }

        if (temp != 0)
            score += pow(10, temp);
    }
    temp = 0;

    for (i = 1; i < boardSize; i++)
    {
        if (board[boardSize - i][i - 1] == opponent)
            temp += 1;
        if (board[boardSize - i][i - 1] != opponent && board[boardSize - 1][i - 1] != '_')
        {
            temp = 0;
            break;
        }
    }
    if (temp != 0)
        score += pow(10, temp);
    return score;
}

bool TTT::check_horizontal(char **board, char symbol)
{
    // '''
    // Checks the horizontal axis to see if there is a winner
    // '''
    for (int i = 0; i < boardSize; i++)
    {
        int line = 0;
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == symbol)
                line += 1;
            else if (board[i][j] != symbol)
                line = 0;
            else if (line == 0 && boardSize - j < rowWinLength)
                break;
            if (line >= rowWinLength)
                return true;
        }
    }
    return false;
}

bool TTT::check_win(char **board, bool isMax)
{
    char symbol;
    if (isMax)
        symbol = opponent;
    else
        symbol = player;
    // DZIAŁA DOBRZE
    if (check_horizontal(board, symbol))
        return true;
    if (check_vertical(board, symbol))
        return true;
    if (check_diagonal(board, symbol))
        return true;

    return false;
}

bool TTT::check_vertical(char **board, char symbol)
{
    // '''
    // Checks the vertical axis to see if there is a winner
    // '''
    for (int j = 0; j < boardSize; j++)
    {
        int line = 0;
        for (int i = 0; i < boardSize; i++)
        {
            if (board[i][j] == symbol)
                line += 1;
            else if (board[i][j] != symbol)
                line = 0;
            else if (line == 0 && boardSize - i < rowWinLength)
                break;
            if (line >= rowWinLength)
                return true;
        }
    }
    return false;
}

bool TTT::checkArrays(char symbol, char *diagonal, int j)
{
    for (int i = j; i < j + rowWinLength; i++)
    {
        if (!(symbol == diagonal[i]))
            return false;
    }
    return true;
}

bool TTT::check_diagonal(char **board, char symbol)
{
    // '''
    // Checks the diagonal axis to see if there is a winner
    // '''
    // char win[rowWinLength];
    // for (int i = 0; i < rowWinLength; i++)
    //     win[i] = symbol;
    char diagonal[boardSize + rowWinLength];
    int x;
    int y;
    int idx;

    for (int i = 0; i < (boardSize - rowWinLength + 1); i++)
    {

        x = i;
        y = 0;
        idx = 0;
        for (int j = 0; j < boardSize - i; j++)
        {
            diagonal[idx] = board[x][y];
            idx++;
            x += 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(diagonal) - rowWinLength + 1; j++)
        {
            if (checkArrays(symbol, diagonal, j))
                return true;
        }

        x = 0;
        y = i;
        idx = 0;
        for (int j = 0; j < boardSize - i; j++)
        {
            diagonal[idx] = board[x][y];
            idx++;
            x += 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(diagonal) - rowWinLength + 1; j++)
        {
            if (checkArrays(symbol, diagonal, j))
                return true;
        }

        x = boardSize - 1 - i;
        y = 0;
        idx = 0;
        for (int j = 0; j < boardSize - i; j++)
        {
            diagonal[idx] = board[x][y];
            idx++;
            x -= 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(diagonal) - rowWinLength + 1; j++)
        {
            if (checkArrays(symbol, diagonal, j))
                return true;
        }

        x = boardSize - 1;
        y = 0 + i;
        idx = 0;
        for (int j = 0; j < boardSize - i; j++)
        {
            diagonal[idx] = board[x][y];
            idx++;
            x -= 1;
            y += 1;
        }
        for (int j = 0; j < sizeof(diagonal) - rowWinLength + 1; j++)
        {
            if (checkArrays(symbol, diagonal, j))
                return true;
        }
    }
    return false;
}

// This is the minimax function. It considers all
// the possible ways the game can go and returns
// the value of the board
int TTT::minimax(char **board, int depth, bool isMax, int a, int b)
{
    if (check_win(board, isMax))
    {
        if (isMax == true)
            return pow(10, 8);
        else
            return -pow(10, 8);
    }

    // int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    // if (score == 10)
    //     return score;

    // // If Minimizer has won the game return his/her
    // // evaluated score
    // if (score == -10)
    //     return score;

    // // If there are no more moves and no winner then
    // // it is a tie
    if (isMovesLeft(board) == false || depth == 0)
    {
        if (isMax)
            return calculate_score(board);
        else
            return -calculate_score(board);
    }
    // else
    //     return score;
    char symbol;
    if (isMax)
        symbol = opponent;
    else
        symbol = player;
    int best_score = 0;
    int m=0;
    if (symbol == player)
    {
        symbol = opponent;
        best_score = -INF;
    }
    else
    {
        symbol = player;
        best_score = INF;
    }
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (board[i][j] == '_')
            {
                if (symbol == opponent)
                {
                    board[i][j] = symbol;
                    m = minimax(board, depth - 1, isMax, a, b);
                    if (best_score < m)
                        best_score = m;
                    if (a < best_score)
                        a = best_score;
                    board[i][j] = '_';
                    if (a >= b)
                        return best_score;
                }
                else
                {
                    board[i][j] = symbol;
                    m = minimax(board, depth - 1, !isMax, a, b);
                    if (best_score > m)
                        best_score = m;
                    if (b > best_score)
                        b = best_score;
                    board[i][j] = '_';
                    if (a >= b)
                        return best_score;
                }
            }
        }
    }
    return best_score;
    // // If this maximizer's move
    // if (isMax)
    // {
    //     int best = INF;

    //     // Traverse all cells
    //     for (int i = 0; i < boardSize; i++)
    //     {
    //         for (int j = 0; j < boardSize; j++)
    //         {
    //             // Check if cell is empty
    //             if (board[i][j] == '_')
    //             {
    //                 // Make the move
    //                 board[i][j] = player;

    //                 // Call minimax recursively and choose
    //                 // the maximum value
    //                 int result = minimax(board, depth - 1, !isMax, alpha, beta);
    //                 if (best > result)
    //                     best = result;

    //                 if (beta > best)
    //                     beta = best;
    //                 // Undo the move
    //                 board[i][j] = '_';
    //                 if (alpha >= beta)
    //                     return best;
    //             }
    //         }
    //     }
    //     return best;
    // }

    // // If this minimizer's move
    // else
    // {
    //     int best = -INF;

    //     // Traverse all cells
    //     for (int i = 0; i < boardSize; i++)
    //     {
    //         for (int j = 0; j < boardSize; j++)
    //         {
    //             // Check if cell is empty
    //             if (board[i][j] == '_')
    //             {
    //                 // Make the move
    //                 board[i][j] = opponent;

    //                 // Call minimax recursively and choose
    //                 // the minimum value
    //                 int result = minimax(board, depth - 1, isMax, alpha, beta);
    //                 if (best < result)
    //                     best = result;
    //                 if (alpha < best)
    //                     alpha = best;

    //                 // Undo the move
    //                 board[i][j] = '_';
    //                 if (alpha >= beta)
    //                     return best;
    //             }
    //         }
    //     }
    //     return best;
    // }
}

// This will return the best possible move for the AI
Move TTT::findBestMove(char **board)
{
    int bestVal = -INF;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // char **cpyBoard = new char *[boardSize];

    // for (char i = 0; i < boardSize; i++)
    //     cpyBoard[i] = new char[boardSize];

    // for (int i = 0; i < boardSize; i++)
    // {
    //     for (int j = 0; j < boardSize; j++)
    //     {
    //         cpyBoard[i][j] = board[i][j];
    //     }
    // }

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            // Check if cell is empty
            if (board[i][j] == '_')
            {
                // Make the move
                board[i][j] = opponent;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 5, true, -INF, INF);

                // Undo the move
                board[i][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    printf("The value of the best Move is : %d\n\n",
           bestVal);

    return bestMove;
}

bool TTT::AImakeMove(char **board)
{
    Move bestMove;
    bestMove = findBestMove(board);
    if (bestMove.col != (-1) && bestMove.row != (-1))
    {
        board[bestMove.row][bestMove.col] = opponent;
        return true;
    }
    else
        return false;
}

bool TTT::startGame(char **board)
{
    bool finished = false;
    while (finished == false)
    {

        playerMove(board);
        if (check_win(board, false) == true || isMovesLeft(board) == false)
            finished = true;
        AImakeMove(board);
        for (char i = 0; i < boardSize; i++)
        {
            cout << "{";
            for (char j = 0; j < boardSize; j++)
            {
                cout << " |" << board[i][j] << "| ";
            }
            cout << "}\n";
        }
        if (check_win(board, true) == true || isMovesLeft(board) == false)
            finished = true;
    }
}

void TTT::playerMove(char **board)
{
    int i, k;
    cout << "Podaj numer kolumny: ";
    cin >> k;
    cout << "\nPodaj numer wiersza: ";
    cin >> i;
    cout << "\n";
    board[i - 1][k - 1] = player;
}