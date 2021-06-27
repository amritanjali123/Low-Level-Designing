//written this code with the help of gaurav sen video
#include <bits/stdc++.h>
using namespace std;

class TicTacToe {
private:
    vector<vector<int>> board;

public:
    TicTacToe(int n)
    {
        board.resize(n);
    }
public:
    int move(int player, int row, int col)
    {
        if (row < 0 || col < 0 || row >= n || col >= n)
        {
            //throw error
            return -2;
        }
        else if (board[row][col] != 0)
        {
            //throw error square is already filled
            return -2;
        }
        else if (player != 0 && player != 1)
        {
            //throw error inleagal player
            return -2;
        }
        else {
            board[row][col] = player = 0 ? -1 : +1;
            board[row][col] = player;
            bool wr = true, wc = true, wd = true, wrg = true;
            for (int i = 0; i < n; i++)
            {
                if (board[row][i] != player)
                {
                    wr = false;
                }
                if (board[i][col] != player)
                {
                    wc = false;
                }
                if (board[i][i] != player)
                {
                    wd = false;
                }
                if (board[i][n - 1 - i] != player)
                {
                    wrg = false;
                }
            }


            if (wc || wr || wrg || wd)
            {
                return player
            }
        }
    }
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}
