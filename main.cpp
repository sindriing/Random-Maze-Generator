#include <iostream>
#include "Maze.h"
#include <time.h>
//Made by Sindri Ingolfsson

void interface(int& height, int& width)
{
    cout << "--------------------------------------" << endl;
    cout << "This is a maze generating program! " << endl;
    cout << "--------------------------------------" << endl << endl;
    while (true)
    {
        cout << "Enter the size of the maze!" << endl;
        cout << "Width: ";
        if ((cin >> width) && (width > 0))
        {
            while (true)
            {
                if(width > 51)
                {
                    cout << "Warning a maze to wide won't print properly on the screen" << endl;
                }
                cout << "Height: ";
                if ((cin >> height) && (height > 0))
                {
                    height = height * 2 + 1;
                    width = width * 2 + 1;
                    return;
                }
            }
        }
    }
}

int main()
{
    //if you want more randomness include the line below
    srand(time(NULL));
    int width = 5, height = 5;
    char again = 'y';
    while (again == 'y')
    {
        interface(height, width);
        Maze maze(height, width);
        maze.recursive_traverse(1, 1);
        cout << maze << endl;

        while(true)
        {
            cout << "Do you wish to create another maze? (y/n) ";
            cin >> again;
            if (again == 'y' || again == 'n')
            {
                break;
            }
        }
    }
    return 0;
}
