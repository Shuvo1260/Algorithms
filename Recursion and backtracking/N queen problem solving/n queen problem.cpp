#include<iostream>
#include<cstdio>

using namespace std;

class chess
{
private:
    int number;
    char board[100][100];
public:
    chess()
    {
        cout << "Queen number : ";
        cin >> number;

        for(int row = 0; row < number; row++)
        {
            for(int column = 0; column < number; column++)
            {
                board[row][column] = '_';
            }
        }
    }
    void print_board();
    bool is_safe(int row, int column);
    bool set_queen(int column_number);
    void n_queen();
};

void chess :: print_board()
{
    static int counter = 1;
    printf("\n%d no solution:\n\n",counter++);
    for(int row = 0; row < number; row++)
    {
        for(int column = 0; column < number; column++)
        {
            cout << board[row][column];
            if(column == number - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    cout << endl;
}

bool chess :: is_safe(int row, int column)
{
    for(int column = 0; column < number; column++)
        if(board[row][column] == 'Q')
            return false;

    for(int r = row, c = column; r >= 0 && c >= 0; r--, c--)
        if(board[r][c] == 'Q')
            return false;

    for(int r = row, c = column; r < number && c >= 0; r++, c--)
        if(board[r][c] == 'Q')
            return false;
}

bool chess :: set_queen(int column)
{
    bool flag = false;
    if(column == number)
    {
        print_board();
        return true;
    }
    else
    {
        for(int row = 0; row < number; row++)
        {
            if(is_safe(row, column))
            {
                board[row][column] = 'Q';

                flag = set_queen(column+1) || flag;

                board[row][column] = '_';
            }
        }
    }
    return flag;
}

void chess :: n_queen()
{
    if(!set_queen(0))
        cout << endl << "Solution doesn't exist!!" << endl;
}


int main()
{
    chess play;

    play.n_queen();

    return 0;
}
