#include "maze.h"

int main()
{
    Board board = Board(10, 10);
    board.generate_maze(board.at(0, 0));
    board.draw();
	return 0;
}
