#include <iostream>
#include <math.h>
struct vec3{
    float x;
    float y;
    float z;
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

int main(){
    std::cout<<"Hello geo\n";
    testProjectPointOnLine();
    testCross();
    return 0;
}
