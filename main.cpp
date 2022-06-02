#include "ttt.h"
// Driver code
int main()
{
    int size = 3;
    char **board;
    board = new char *[size];

    for (char i = 0; i < size; i++)
        board[i] = new char[size];

    // char new_board[3][3] =
    //     {
    //         {'x', 'o', 'x'},
    //         {'o', 'o', 'x'},
    //         {'_', '_', '_'}};

    char new_board[3][3] =
        {
            {'_', '_', '_'},
            {'_', '_', '_'},
            {'_', '_', '_'}};


    for (char i = 0; i < size; i++)
    {
        for (char j = 0; j < size; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }



    TTT game(size);
    // Move bestMove = game.findBestMove(board);

    // printf("The Optimal Move is :\n");
    // printf("ROW: %d COL: %d\n\n", bestMove.row+1,
    //        bestMove.col+1);

    game.startGame(board);
    return 0;
}
