#include "ttt.h"
// Driver code
int main()
{
    int size;
    int rowWinLength; 
    
    cout << "\n Podaj wielkość planszy:\n";
    cin >> size;
    if (size < 3)
    {
        cout << "Za mała plansza, ustawiono wielkość 3";
        size = 3;
    }
    cout << "\n Podaj długość rzędu potrzebnego do wygranej:\n";
    cin >> rowWinLength;
    if (rowWinLength < 3 || rowWinLength > size)
    {
        cout << "Zła długość, ustawiono " << size << ".";
        rowWinLength = size;
    }
    char **board;
    board = new char *[size];

    for (char i = 0; i < size; i++)
        board[i] = new char[size];
    for (char i = 0; i < size; i++)
    {
        for (char j = 0; j < size; j++)
        {
            board[i][j] = '_';
        }
    }

    TTT game(size, rowWinLength);
    // Move bestMove = game.findBestMove(board);

    // printf("The Optimal Move is :\n");
    // printf("ROW: %d COL: %d\n\n", bestMove.row+1,
    //        bestMove.col+1);

    game.startGame(board);
    return 0;
}
