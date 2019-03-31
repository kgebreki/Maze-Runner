#include <iostream>
#include "mazelayout4.txt"
using namespace std;
/*
 Kaleb Gebrekirstos
 CS 255 HW #4 (Maze Solver)
 02/20/19
 The aim of this assignment is to program a maze runner that seeks through a maze looking for a way out.
 It does this by using the right-hand rule algorithm to find paths that aren't blocked and pursuing them.
 The algorithm works by always going 'right' relative to the forward direction. Meaning, if the maze runner is
 facing North, it would look for a path East first. If it can't find one, it looks for a path North. If there isn't
 one, it looks for one West. If it can't find any of these, it backtracks.
 Furthermore, this program doesn't hard code the maze, instead it imports it from a text file.
 */

//Display function to show the current state of the maze
void display() {

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << maze [i][j] << " ";
            if (j == 11)
                cout << '\n';
        }
    }
}

//Main function
//Starting and ending positions inside the maze are imported from the mazelayout.txt file as well
int main() {

    int row = startRow;
    int col = startCol;
    maze[row][col] = '>';//Mark starting point with an '>'
    char direction = 'E';//Starting direction is facing East
    int index = 1;//Keeps track of how many generations the maze runner has lived through

    /*Switch structure enclosed in a do while loop. Loop iterates until the maze runner reaches the end of the
      maze. So the algorithm works by moving right relative to the forward direction first; if it can't it goes
      straight; if it can't do that, it goes left; if it still can't do that it turns back. All the while it marks
      paths its moved by placing an 'x' and whenever it backtracks, it places a '~'.
     */
    do{
        cout << "\ngeneration " << index << '\n';
        switch (direction)
        {
            case 'E':{
                if (maze[row+1][col] != '#')
                {
                    if (maze[row+1][col] == 'x')
                    {
                        row++;
                        maze[row][col] = '~';
                    }
                    else{
                        row++;
                        maze[row][col] = 'x';
                    }
                    direction = 'S';
                    display();
                    cout<<endl;
                }
                else if(maze[row][col+1] != '#')
                {
                    if (maze[row][col+1] == 'x')
                    {
                        col++;
                        maze[row][col] = '~';
                    }
                    else{
                        col++;
                        maze[row][col] = 'x';
                    }
                    direction = 'E';
                    display();
                    cout<<endl;
                }
                else if(maze[row-1][col] != '#')
                {
                    if (maze[row-1][col] == 'x')
                    {
                        row--;
                        maze[row][col] = '~';
                    }
                    else{
                        row--;
                        maze[row][col] = 'x';
                    }
                    direction = 'N';
                    display();
                    cout<<endl;
                }
                else
                {
                    maze[row][col] = '~';
                    direction = 'W';
                    display();
                    cout<<endl;
                }
            index++;
            break;
            }

            case 'N':{
                if (maze[row][col+1] != '#')
                {
                    if (maze[row][col+1] == 'x')
                    {
                        col++;
                        maze[row][col] = '~';
                    }
                    else{
                        col++;
                        maze[row][col] = 'x';
                    }
                    direction = 'E';
                    display();
                    cout<<endl;
                }
                else if(maze[row-1][col] != '#')
                {
                    if (maze[row-1][col] == 'x')
                    {
                        row--;
                        maze[row][col] = '~';
                    }
                    else{
                        row--;
                        maze[row][col] = 'x';
                    }
                    direction = 'N';
                    display();
                    cout<<endl;
                }
                else if(maze[row][col-1] != '#')
                {
                    if (maze[row][col-1] == 'x')
                    {
                        col--;
                        maze[row][col] = '~';
                    }
                    else{
                        col--;
                        maze[row][col] = 'x';
                    }
                    direction = 'W';
                    display();
                    cout<<endl;
                }
                else
                {
                    maze[row][col] = '~';
                    direction = 'S';
                    display();
                    cout<<endl;
                }
             index++;
             break;
            }
            case 'W':{
                if (maze[row-1][col] != '#')
                {
                    if (maze[row-1][col] == 'x')
                    {
                        row--;
                        maze[row][col] = '~';
                    }
                    else{
                        row--;
                        maze[row][col] = 'x';
                    }
                    direction = 'N';
                    display();
                    cout<<endl;
                }
                else if(maze[row][col-1] != '#')
                {
                    if (maze[row][col-1] == 'x')
                    {
                        col--;
                        maze[row][col] = '~';
                    }
                    else{
                        col--;
                        maze[row][col] = 'x';
                    }
                    direction = 'W';
                    display();
                    cout<<endl;
                }
                else if(maze[row+1][col] != '#')
                {
                    if (maze[row+1][col] == 'x')
                    {
                        row++;
                        maze[row][col] = '~';
                    }
                    else{
                        row++;
                        maze[row][col] = 'x';
                    }
                    direction = 'S';
                    display();
                    cout<<endl;
                }
                else
                {
                    maze[row][col] = '~';
                    direction = 'E';
                    display();
                    cout<<endl;
                }
            index++;
            break;
            }
            case 'S':{
                if (maze[row][col-1] != '#')
                {
                    if (maze[row][col-1] == 'x')
                    {
                        col--;
                        maze[row][col] = '~';
                    }
                    else{
                        col--;
                        maze[row][col] = 'x';
                    }
                    direction = 'W';
                    display();
                    cout<<endl;
                }
                else if(maze[row+1][col] != '#')
                {
                    if (maze[row+1][col] == 'x')
                    {
                        row++;
                        maze[row][col] = '~';
                    }
                    else{
                        row++;
                        maze[row][col] = 'x';
                    }
                    direction = 'S';
                    display();
                    cout<<endl;
                }
                else if(maze[row][col+1] != '#')
                {
                    if (maze[row][col+1] == 'x')
                    {
                        col++;
                        maze[row][col] = '~';
                    }
                    else{
                        col++;
                        maze[row][col] = 'x';
                    }
                    direction = 'E';
                    display();
                    cout<<endl;
                }
                else
                {
                    maze[row][col] = '~';
                    direction = 'N';
                    display();
                    cout<<endl;
                }
            index++;
            break;
            }
        }

    }while (maze[row][col] != maze[endRow][endCol]);

    maze[endRow][endCol] = '>';//Mark exit point with '>'
    display();
    system("pause");
    return 0;
}

