#include <iostream>
#include <string>
#include <vector>
#include "maze.h"
#include "robot.h"
int main()
{
    int w,h;
    int direction=0; // direction 0,1,2,3 -> up, right, down, left
    long long n;
    std::pair<int,int> answer_pos;
    std::cin >> w >> h;
    Maze _maze(w,h);
    std::cin >> n;
    for (int i = 0; i < h; i++) {
        std::string line;
        std::cin >> line;
        _maze.Generate_maze_map(line);
    }
    std::pair<int,int> now_pos=_maze.Find_Robot_current_location();
    Robot _robot(now_pos, direction);
    for(long long i=0;i<n;i++){
        std::pair<int,int> next_pos=_robot.Next_Position();
        while(!_maze.is_in_maze(next_pos) || _maze.is_obstacle(next_pos)){
            _robot.turn_right();
            direction=_robot.Get_Robot_FaceToward();
            next_pos=_robot.Next_Position();
        }
        if(_robot.is_visited_and_same_facetoward(now_pos.first, now_pos.second, direction)){
            _robot.find_final_state(n,i);
            break;
        }
        else{
            _robot.store_visited(now_pos);
            _robot.Walk_Next();
            now_pos=_robot.Get_Position();
        }
    }
    answer_pos=_robot.Get_Position();
    std::cout << answer_pos.first << " " << answer_pos.second <<  std::endl;
}