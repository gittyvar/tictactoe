#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

void displayBoard(char board[3][3])
{
    int counter = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    if (board[i / 2][j / 2] != ' ')
                    {
                        cout << " " << board[i / 2][j / 2] << " ";
                    }
                    else
                    {
                        cout << " " << counter << " ";
                    }
                    counter++;
                }
                else
                {
                    cout << "|";
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    cout << "---";
                }
                else
                {
                    cout << "+";
                }
            }
        }
        cout << endl;
    }
}

void updateBoard(int pos, char board[3][3], int turn)
{
    if (turn % 2 != 0)
    {
        board[pos / 3][pos % 3] = 'O';
    }
    else
    {
        board[pos / 3][pos % 3] = 'X';
    }

    displayBoard(board);
}

void checkStatus(char board[3][3], int pos)
{
    // j = (pos mod 3)
    // i = pos/3

    char x = board[pos / 3][pos % 3];

    int checker1 = 0;
    int checker2 = 0;

    // checking row and col
    for (int i = 0; i < 3; i++)
    {
        if (board[i][pos % 3] != x)
        {

            checker1++;
        }
        if (board[pos / 3][i] != x)
        {

            checker2++;
        }
    }

    if (checker1 == 0 || checker2 == 0)
    {
        cout << x << " has won!" << endl;
        exit(0);
    }

    int diagchecker1 = 0;
    int diagchecker2 = 0;
    if (pos / 3 == pos % 3)
    {
        for (int i = 0, j = 0; i < 3 && j < 3; i++, j++)
        {
            if (board[i][j] != x)
            {

                diagchecker1++;
            }
        }

        if (diagchecker1 == 0)
        {
            cout << x << " has won!" << endl;
            exit(0);
        }
    }

    if (pos / 3 + pos % 3 == 2)
    {
        for (int i = 0, j = 2; i < 3 && j >= 0; i++, j--)
        {
            if (board[i][j] != x)
            {

                diagchecker2++;
            }
        }

        if (diagchecker2 == 0)
        {
            cout << x << " has won!" << endl;
            exit(0);
        }
    }
}

int main()
{

    char board[3][3]{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    displayBoard(board);
    cout << "----------------------------------" << endl;
    int t = 9;
    while (t > 0)
    {
        int pos;

        if (t % 2 != 0)
        {
            cout << "Enter the position (P1/O): ";
        }
        else
        {
            cout << "Enter the position (P2/X): ";
        }
        cin >> pos;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter an interger." << endl;
            cout << "----------------------------------" << endl;
            continue;
        }
        if (pos > 8 || pos < 0)
        {
            cout << "Please enter position only from 0 to 8." << endl;
            cout << "----------------------------------" << endl;
            continue;
        }
        cout << endl;

        if (board[pos / 3][pos % 3] == ' ')
        {
            t--;
        }
        else
        {
            cout << "Please enter a valid postion." << endl;
            cout << "----------------------------------" << endl;
            continue;
        }
        updateBoard(pos, board, t + 1);

        checkStatus(board, pos);
        cout << "----------------------------------" << endl;
    }

    cout << "It's a draw!" << endl;
    return 0;
}
