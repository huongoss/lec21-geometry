#include <iostream>
#include <math.h>
struct vec2{
    float x;
    float y;
};
float dot(const vec2 a, const vec2 b){
    return a.x * b.x + a.y * b.y;
}
float len(const vec2 a){
    return std::sqrt(a.x * a.x + a.y * a.y);
}
vec2 norm(const vec2 a){
    const float l = len(a);
    return {a.x/l,a.y/l};
}
vec2 projectPointOnLine(const vec2 p, const vec2 q){
    const vec2 n = norm(q);
    const float d = dot(p,n);
    return {n.x * d, n.y * d};
}

void testProjectPointOnLine(){
    vec2 p = {15 , 3};
    vec2 q = {10 , 10};
    vec2 pp = projectPointOnLine(p,q);
    std::cout<<"Project on line " << pp.x << " " << pp.y << std::endl ;
}

int main(){
    std::cout<<"Hello geo\n";
    testProjectPointOnLine();
    return 0;
}
