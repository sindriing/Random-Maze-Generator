#include "Maze.h"

Maze::Maze(const int& width, const int& height)
{
    assert(width * height % 2 == 1); //outputs an error if the maze is not constructed with odd numbers width and height
    for(int i = 0; i<width; i++)
    {
        vector<MazeNode> colum;
        for(int j=0; j<height; j++)
        {
            colum.push_back(determine_node_type(i, j, width, height));
        }
        grid.push_back(colum);
    }
}

//sets the private variables of each node based on its location in the mase
MazeNode Maze::determine_node_type(const int& i, const int& j, const int& width, const int& height)
{
    if(i == 0 || j == 0)
    {
        return MazeNode(true, true); // set as edge wall
    }
    if (i == width-1 || j == height-1)
    {
        return MazeNode(true, true); //set as edge wall
    }
    if(i % 2 == 0 || j % 2 == 0)
    {
        return MazeNode(true, false); //set as removable wall
    }
    else
    {
        return MazeNode(false, false); //set as tile
    }
}

//this is the function that carves the maze!
void Maze::recursive_traverse(int x, int y) //accepts only inputs with at least one even number
{
    grid[x][y].carve();
    Direction direction = get_directions(x, y); //gets one valid direction to go to next
    if(direction == close) //if no direction was found we take one step back in the recursion
    {
        return;
    }
    else if(direction == east)
    {
        grid[x+1][y].carve();
        recursive_traverse(x+2, y);
    }
    else if(direction == west)
    {
        grid[x-1][y].carve();
        recursive_traverse(x-2, y);
    }
    else if(direction == north)
    {
        grid[x][y-1].carve();
        recursive_traverse(x, y-2);
    }
    else if(direction == south)
    {
        grid[x][y+1].carve();
        recursive_traverse(x, y+2);
    }
    recursive_traverse(x, y); //this is necessary to when backtracking to start carving again after getting stuck in a dead end
}

//this function checks nearby tiles for valid directions to go to
Direction Maze::get_directions(const int& x, const int& y)
{
    vector<Direction> temp; //we put all eligible directions into a vector
    if(!grid[x+1][y].is_visited()) //first we check the adjacent wall
    {
        if(!grid[x+2][y].is_visited()) //then we check the tile behind the wall
        {
            temp.push_back(east);
        }
    }
    if(!grid[x-1][y].is_visited())
    {
        if(!grid[x-2][y].is_visited())
        {
            temp.push_back(west);
        }
    }
    if(!grid[x][y+1].is_visited())
    {
        if(!grid[x][y+2].is_visited())
        {
            temp.push_back(south);
        }
    }
    if (!grid[x][y-1].is_visited())
    {
        if(!grid[x][y-2].is_visited())
        {
            temp.push_back(north);
        }
    }
    if(temp.size() != 0) //a random direction is selected from the vector and returned
    {
        return temp[rand() % temp.size()];
    }
    else //if no valid direction was found we return "close"
    {
        return close;
    }
}

Maze::~Maze()
{
    //dtor
}

ostream& operator<<(ostream& out, const Maze& maze)
{
    for (unsigned i=0; i<maze.grid.size(); i++)
    {
        for (unsigned j=0; j<maze.grid[i].size(); j++)
        {
            if(maze.grid[i][j].is_wall())
            {
                out << "X ";
            }
            else
            {
                out << "  ";
            }
        }
        out << endl;
    }
    return out;
}

