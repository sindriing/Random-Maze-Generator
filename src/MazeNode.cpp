#include "MazeNode.h"

MazeNode::MazeNode(const bool& wall, const bool& visited)
{
    this->visited = visited;
    this->wall = wall;
}

MazeNode::~MazeNode()
{
    //dtor
}

void MazeNode::carve()
{
    visited = true;
    wall = false;
}

bool MazeNode::is_wall() const
{
    return wall;
}

bool MazeNode::is_visited() const
{
    return visited;
}
