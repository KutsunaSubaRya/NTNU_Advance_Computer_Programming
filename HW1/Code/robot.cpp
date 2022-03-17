#include "robot.h"
Robot::Robot(const std::pair<const int,const int> pos, const int face):x(pos.first), y(pos.second), Face(face){}
bool Robot::is_visited_and_same_facetoward(const int _x, const int _y, const int _Face)const{
    for(auto i:visited)
        if(i.first.first==_x && i.first.second==_y && i.second==_Face)
            return true;
    return false;
}
std::pair<const int,const int> Robot::Get_Position(void)const{
    return std::make_pair(x,y);
}
std::pair<const int,const int> Robot::Next_Position(void)const{
    return std::make_pair(x+Face_Toward[Face][0],y+Face_Toward[Face][1]);
}
void Robot::Walk_Next(void){
    x+=Face_Toward[Face][0];
    y+=Face_Toward[Face][1];
}
void Robot::turn_right(void){
    Face=(Face+1)%4;
}
int Robot::Get_Robot_FaceToward(void)const{
    return Face;
}
void Robot::store_visited(std::pair<const int,const int> pos){
    visited.emplace_back(std::make_pair(pos,Face));
}
void Robot::find_final_state(const long long n, const long long current_n){
    long long i,loop_size=1,remain_n=n-current_n;
    const long long visited_length=visited.size();
    for(i=visited_length-1;i>=0;i--){
        if(visited[i].first.first==x && visited[i].first.second==y && visited[i].second==Face)
            break;
        loop_size++;
    }
    long long final_state=(remain_n%loop_size)+i;
    x=visited[final_state].first.first;
    y=visited[final_state].first.second;
    Face=visited[final_state].second;
}