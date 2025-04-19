#include <bits/stdc++.h>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard()
{
    cout<<"\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout<<"\n";
}

bool available(int slot)
{
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentMarker;
        return true;
    }
    else
        return false;
}
int winner()
{

    // row
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return currentPlayer;
    }

    // col
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return currentPlayer;
    }

    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return currentPlayer;

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return currentPlayer;

    return 0;
}

void swapPlayerAndMarker()
{
    if (currentMarker == 'X')
        currentMarker = 'O';
    else
        currentMarker = 'X';

    if (currentPlayer == 1)
        currentPlayer = 2;
    else
        currentPlayer = 1;
}
void game()
{
    cout << "Player choose your marker: X or O \n";
    char markerp1;
    cin >> markerp1;

    currentPlayer = 1;
    currentMarker = markerp1;
    drawBoard();

    int playerwon;
    for (int i = 0; i < 9; i++)
    {
        cout << "It's player" << currentPlayer << "'s turn Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "it is not valid move, you can try again!";
            i--;
            continue;
        }
        if (!available(slot))
        {
            cout << "This slot is not available ,so try again!\n";
            i--;
            continue;
        }
        drawBoard();
        playerwon = winner();
        if (playerwon == 1)
        {
            cout << "player 1 wins";
            break;
        }
        else if (playerwon == 2)
        {
            cout << "player 2 wins";
            break;
        }

        swapPlayerAndMarker();
    }
    if (playerwon == 0)
        cout << "Its a Tie!\n";
}

int main()
{
    game();
    return 0;
}