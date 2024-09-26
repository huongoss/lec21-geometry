#include <iostream>
#include <math.h>
struct vec3{
    float x;
    float y;
    float z;
    inline vec3 operator-(const vec3& a) {
        return {x - a.x,y - a.y};
    }
    inline vec3 operator+(const vec3& a) {
        return {a.x+x,a.y+y};
    }

};
float dot(const vec3 a, const vec3 b){
    return a.x * b.x + a.y * b.y;
}
vec3 cross(const vec3 a, const vec3 b){
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,a.x * b.y - a.y * b.x };
}
float len(const vec3 a){
    return std::sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
vec3 norm(const vec3 a){
    const float l = len(a);
    return {a.x/l,a.y/l,a.z/l};
}
vec3 projectPointOnLine(const vec3 p, const vec3 q){
    const vec3 n = norm(q);
    const float d = dot(p,n);
    return {n.x * d, n.y * d, n.z * d};
}
int lineSideCheck(vec3 v1, vec3 v2, vec3 v) {
    const float EPS = 1e-9;
    vec3 pp = cross(v2-v1,v-v1);
    if(pp.z == 0) return 0;
    else if(pp.z  > EPS) return 1;
    else return -1;
     
}

void testProjectPointOnLine(){
    vec3 p = {15 , 3 , 0};
    vec3 q = {10 , 10 , 0};
    vec3 pp = projectPointOnLine(p,q);
    std::cout<<"Project on line " << pp.x << " " << pp.y << " " << pp.z<< std::endl ;
}

void testCross(){
    vec3 p = {15 , 3 , 0};
    vec3 q = {10 , 10 , 0};
    vec3 pp = cross(p,q);
    std::cout<<"Cross " << pp.x << " " << pp.y << " " << pp.z<< std::endl ;
}

void testLineSideCheck(){
    vec3 v1 = {5 , 5 , 0};
    vec3 v2 = {10 , 10 , 0};
    vec3 v0 = {15, 15, 0};
    vec3 vp = {20,30,0};
    vec3 vn = {20,10,0};
    std::cout<<"testLineSideCheck " << lineSideCheck(v1,v2,v0) << " " << lineSideCheck(v1,v2,vp) << " " << lineSideCheck(v1,v2,vn)<< std::endl ;
}


int main(){
    std::cout<<"Hello geo\n";
    testProjectPointOnLine();
    testCross();
    testLineSideCheck();
    return 0;
}
