#ifndef MAZENODE_H
#define MAZENODE_H

using namespace std;

class MazeNode
{
    public:
        MazeNode(const bool& wall, const bool& visited);
        virtual ~MazeNode();
        void carve();
        bool is_wall() const;
        bool is_visited() const;

    private:
        bool visited;
        bool wall;
};

#endif // MAZENODE_H
