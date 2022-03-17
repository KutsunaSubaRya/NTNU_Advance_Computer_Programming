#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <vector>
class Robot{
    private:
        int x,y,Face; // robot position
        static constexpr int Face_Toward[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
        std::vector<std::pair<std::pair<int,int>,int>> visited; 
        //first.first=>x, first.second=>y, second=>face direction which have visited 
    public:
        Robot(const std::pair<const int,const int> pos, const int face);
        bool is_visited_and_same_facetoward(const int _x, const int _y, const int _Face)const;
        std::pair<const int,const int> Get_Position(void)const;
        std::pair<const int,const int> Next_Position(void)const;
        void Walk_Next(void);        
        void turn_right(void);
        int Get_Robot_FaceToward(void)const;
        void store_visited(std::pair<const int,const int> pos);
        void find_final_state(const long long n, const long long current_n);
};
#endif