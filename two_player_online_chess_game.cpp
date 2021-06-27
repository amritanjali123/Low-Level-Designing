//I have writen this code by taking 30 min in concedration because generally
//in interview we get 45 min time where 15 min in introduction and understanding
//the problem statement and cross questioning
/*syntex might be wrong*/

#include <bits/stdc++.h>
using namespace std;
//abstract class

class Piece
{
    bool killed = false;
    bool white = false;
public:

    Piece(bool white)
    {
        this->setWhite(white);
    }
public:
    void setWhite(bool white)
    {
        this->white = white;
    }
    bool isWhite()
    {
        return this->white == white;
    }
    bool isKilled()
    {
        return this->killed == killed;
    }
    void setKilled(bool killed)
    {
        this->killed = killed;
    }
    virtual bool canMove(Board board, Box start, Box end) = 0;

};

class Box {
private:
    Piece piece;
    int x;
    int y;
public:
    Box(int x, int y, Piece piece)
    {
        this->piece = piece;
        this->x = x;
        this->y = y;
    }
    void setPiece(Piece piece)
    {
        this->piece = piece;
    }
    Piece getPiece()
    {
        return piece;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

};


class King : public Piece {
public:
    King(white);

    bool canMove(Board board, Box start, Box end)
    {
        if (end.getPiece().isWhite == this->isWhite())
        {
            return false;
        }

        int x = abs(start.getX() - end.getX());
        int y = abs(start.getY() - end.getY());
        return x * y == 2;
        //check if king can move to the destination position
    }
}
//similar to king I will create for all the pices

class Board {
    vector<vector<Box>> boxes;
public:
    Board{
        this->initBoard();
    }
public:
    void initBoard()
    {
        //set the pice according the chess rule
    }

};

class Player {
private:
    Person person;//assume a class that will have person details
    bool whiteSide = false;
public:
    Player(Person person, bool whiteSide)
    {
        this->person = person;
        this->whiteSide = whiteSide;
    }

};

class Game {
private:
    vector<Player> players;
    Board board;
    Player currentTurn;
    GameStatus status;
public:
    Game(Player p1, Player p2)
    {
        Players[0] = p1;
        Players[1] = p2;
        if (p1.isWhite())
        {
            this->currentTurn = p1;
        }
        else {
            this.currentTurn = p2;
        }
    }

//every time player play this function will be called
    string playerMove(Player player int startX, int startY, int endX, int endY)
    {
        //if wrong player move then this will return 0
        if (player != currentTurn)
        {
            return "It is not your turn";
        }

        Box start = board[startX][startY];
        Box end = board[endX][endY];
        Piece sourcePiece = start.getPiece();
        if (!sourcePiece.canMove(board, start, end)) return "can't move to selected position";
        Piece destPiece = end.getPiece();
        if (destPiece != NULL)
        {
            destPiece.setkilled(true);
        }

        end.setPiece(sourcePiece);

        //every time the currentPlayer switch
        if (this->currentTurn == players[0])
        {
            this->currentTurn = players[1];
        }
        else {
            this->currentTurn = players[0];
        }

        return "done";
    }


};


int32_t main()
{


}
