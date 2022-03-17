#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <string>
#include <vector>
class Maze{
    private:
        const int width, height;
        std::vector<std::string> maze_map;
    public:
        Maze(const int w, const int h);
        std::pair<const int,const int> Find_Robot_current_location(void)const;
        void Generate_maze_map(const std::string str);
        bool is_obstacle(std::pair<int,int> pos)const;
        bool is_in_maze(std::pair<int,int> pos)const;
};
#endif