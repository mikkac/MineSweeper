#include "MineSweeper.hpp"

#include <iostream>

void Field::ToggleFlag()
{
    isFlag = !isFlag;
}

Board::Board(unsigned int x,unsigned int y, std::vector<Point> bombs):x(x), y(y), bombCount(bombs.size())
{
    board.resize(x*y);

    for (auto el : bombs)
    {
        board[Coords(el)].isBomb = true;
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j<=1; ++j)
            {
                Point p = el;
                p.x += i;
                p.y += j;

                board[Coords(p)].bombsCount++;
            }
        }
    }
}

unsigned int Board::GetX() const
{
    return x;
}

unsigned int Board::GetY() const
{
    return y;
}

const Field& Board::GetField(unsigned int x, unsigned int y)
{
    Point p {x, y};
    return board[Coords(p)];
}

 Point Board::Coords(unsigned int p)
{
    Point result;
    result.x = p % y;
    result.y = p / x;

    return result;
}

 unsigned int Board::Coords(Point p)
{
    return p.y * x + p.x;
}

void Board::SetFlag(unsigned int x,unsigned int y)
{
    Point p{x,y};
    board[Coords(p)].ToggleFlag();
}

void Board::OpenField(unsigned int x, unsigned int y)
{
    Point p{x,y};
    if(!board[Coords(p)].isFlag)
    {
        board[Coords(p)].isOpen=true;
    }
}

Status Board::GetStatus()
{
    unsigned int closedFields = 0;
    for (auto el : board)
    {
        if (!el.isOpen) closedFields++;
        if (el.isOpen && el.isBomb) return Status::LOSS;
    }
    if (closedFields == bombCount) return Status::WIN;
    return Status::IN_PROGRESS;
}

Game::Game(unsigned int x,unsigned int y, std::vector<Point> bombs) : board(x,y,bombs)
{
}

void Game::Display()
{
   for (unsigned int y = 0 ; y < board.GetY(); ++y)
   {
       for (unsigned int x = 0 ; x < board.GetX(); ++x)
       {
           Field f = board.GetField(x, y);
           std::cout << FieldDisplay(f);
       }
       std::cout << std::endl;
    }
}

char Game::FieldDisplay(const Field& f)
{
    if (f.isOpen)
    {
        if(f.isBomb)
        {
            return '*';
        }
        if(f.bombsCount == 0)
        {
            return ' ';
        }
        return (f.bombsCount+'0');
    }
    else
    {
        if (f.isFlag)
        {
            return 'o';
        }
        return '#';
    }
}

void Game::Input()
{
    char x;
    unsigned int y;
    char operation;

    std::cin >> x >> y >> operation;

    if(tolower(operation) == 'f')
    {
        board.SetFlag(x-'a', y);
    }
    else
    {
        board.OpenField(x-'a', y);
    }

}






















