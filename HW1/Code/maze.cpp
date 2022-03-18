#include "maze.h"
Maze::Maze(const int w, const int h):width(w), height(h){}
std::pair<const int,const int> Maze::Find_Robot_current_location(void)const{
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            if(maze_map[y][x]=='O'){
                return std::make_pair(x,y);
            }
        }
    }
    return std::make_pair(0,0);
}
void Maze::Generate_maze_map(const std::string str){
    maze_map.emplace_back(str);
}
bool Maze::is_obstacle(std::pair<int,int> pos)const{
    return maze_map[pos.second][pos.first]=='#';
}
bool Maze::is_in_maze(std::pair<int,int> pos)const{
    return (pos.first>=0 && pos.first<width && pos.second>=0 && pos.second<height);
}