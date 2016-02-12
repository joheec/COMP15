//
//  maze.h
//  MazeCreator
//
//  Created by Chris Gregg on 2/8/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//

#ifndef __MazeCreator__maze__
#define __MazeCreator__maze__

class Maze 
{
public:
	Maze(int size, unsigned int rand_seed);

	void print_maze();
	void human_readable_maze();
	void generate_maze();
	void solve_maze_recursive() 
        {
		solve_maze_recursive(1, 1);
		maze[1][1] = 'S';
	}

	void solve_maze_stack()
        {
		solve_maze_stack(1, 1);
                maze[1][1] = 'S';
	}

	bool isSameSolutionAs(Maze anotherMaze);

private:
        // MAX  =  61 = 30 * 2 + 1
        // CELL = 900 = 30 * 30
        static const int MAX = 61;
        static const int CELL = 900;
        static const int WALL = 1;
        static const int PATH = 0;

	int maze[MAX][MAX];
	int maze_size;
	int maze_array_size;

	void init_maze();
	void maze_generator(int index, int backtrack_x[CELL],
                            int bactrack_y[CELL], int x, int y, int n,
                            int visited);
	int is_closed(int x, int y);
	bool solve_maze_recursive(int x, int y);
	void solve_maze_stack(int x, int y);
};

#endif /* defined(__MazeCreator__maze__) */
