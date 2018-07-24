#pragma once
#include <vector>


// [x]generowanie i uaktualnianie planszy
// [x]printowanie planszy
// [x]obsluga wejscia
// [x]sprawdzanie stanu gry
// [x]odkrywanie pol
// [x]stawianie flag gdzie jest bomba
// [x]reprezentacja pola
//          -> bool czy jest odkryte
//          -> bool czy jest postawiona flaga
//          -> int jako liczba bomb dookola (0:8)
//          -> bool bomba
// [x]czyszczenie planszy po grze (restart)
//

struct Point
{
    unsigned int x;
    unsigned int y;
};

enum class Status
{
    IN_PROGRESS,
    LOSS,
    WIN
};

class Field
{
public:
    void ToggleFlag();

    bool isOpen = false;
    bool isBomb = false;
    bool isFlag = false;
    unsigned int bombsCount = 0;
};

class Board
{
public:
    Board(unsigned int x,unsigned int y, std::vector<Point> bombs);
    void OpenField(unsigned int x, unsigned int y);
    void SetFlag(unsigned int x, unsigned int y);
    Status GetStatus();
    unsigned int GetX() const;
    unsigned int GetY() const;
    const Field& GetField(unsigned int x, unsigned int y);

private:
    unsigned int x;
    unsigned int y;
    unsigned int bombCount;
    std::vector<Field> board;
    Point Coords(unsigned int p);
    unsigned int Coords(Point p);
};

class Game
{
public:
    Game(unsigned int x,unsigned int y, std::vector<Point> bombs);
    void Display();
    char FieldDisplay(const Field& f);
    void Input();
    //void Restart();

private:

    Board board;
};
