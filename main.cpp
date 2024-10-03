#include <iostream>
#include <math.h>
#include <vector>
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

bool convexHullCheck(std::vector<vec3> points){
    for(int i = 0; i < points.size(); i++){
            int cur = i;
            int next = i < points.size()-1? i+1:0;
        for(int j = 0; j < points.size(); j++){
            if(j == cur || j == next) continue;
            
            int side = lineSideCheck( points[cur], points[next], points[j] );
            if(side < 0) return false;
        }
    }
    return true;
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

void testConvexHull(){
    vec3 v1 = {0,0,0};
    vec3 v2 = {100,0,0};
    vec3 v3 = {100,100,0};
    vec3 v4 = {0,100,0};
    std::cout << "testConvexHull " << (convexHullCheck({v1,v2,v3,v4}) ? "true" : "false") << std::endl;

    vec3 v1n = {0,0,0};
    vec3 v2n = {100,0,0};
    vec3 v3n = {30,30,0};
    vec3 v4n = {0,100,0};
    std::cout << "testConvexHull " << (convexHullCheck({v1n,v2n,v3n,v4n}) ? "true" : "false") << std::endl;
}

//gcc main.cpp -lstdc++ -lm -o main
int main(){
    std::cout<<"Hello geo\n";
    testProjectPointOnLine();
    testCross();
    testLineSideCheck();
    testConvexHull();
    return 0;
}
