#include <gtest/gtest.h>

#include "MineSweeper.hpp"

int main(int argc, char** argv)
{
    Game g1 = Game(5,5, {{3,3},{1,2},{2,3}});
    g1.Input();
    g1.Display();
    g1.Input();
    g1.Display();

    return 0;
}
