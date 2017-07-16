#ifndef MAZE_H
#define MAZE_H

#include "MazeNode.h"
#include <vector>
#include <assert.h>
#include <iostream>
#include <cstdlib>

enum Direction {north, south, east, west, close};

class Maze
{
    public:
        Maze(const int& width, const int& height);
        virtual ~Maze();
        friend ostream& operator<<(ostream& out, const Maze& maze);
        void recursive_traverse(int x, int y);

    private:
        MazeNode determine_node_type(const int& i, const int& j, const int& width, const int& height);
        Direction get_directions(const int& x, const int& y);

        vector<vector<MazeNode> > grid;

};

#endif // MAZE_H
