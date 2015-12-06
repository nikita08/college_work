#include<iostream>
using namespace std;

struct Vertex {
    float x;
    float y;
};

float mod(float aFloat){
    if(aFloat>-0)
        return aFloat;
    return -aFloat;
}

float areaOfTriangle(Vertex a,Vertex b, Vertex c){
    float myArea = 0;
    myArea = ((a.x - c.x)*(b.y - a.y) - (a.x - b.x)*(c.y - a.y))/2.0;
    return mod(myArea);
}

struct Quadrilateral{
    Vertex vertices[4];
    float area(){
          float myArea = 0;
          myArea+=areaOfTriangle(vertices[0],vertices[1],vertices[2]);
          myArea+=areaOfTriangle(vertices[0],vertices[2],vertices[3]);
          return myArea;
    }
};

int main(){
    float data[4][2] = { { -2 , 19 } , { -2 , -23 } , { -12 , -23 } , { -12 , 9 } }; // Assume this has the 4 2D vertices of the Convex Quadrilateral
    Quadrilateral myQuadi;
    Vertex a[4];
    for(int i =0;i<4;i++){
        a[i].x = data[i][0];
        a[i].y = data[i][1];
    }
    for(int i=0;i<4;i++){
        myQuadi.vertices[i]=a[i];
    }
    float myArea = myQuadi.area();
    cout<<"Area = "<<myArea<<endl;
}
