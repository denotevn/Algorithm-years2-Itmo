#include<bits/stdc++.h>

// DONE

using namespace std;


struct Point {
    LL num;
    LL x;
    LL y;
};

Point firstPoint;

bool compare(Point p1, Point p2){
    p1.x -= firstPoint.x;
    p1.y -= firstPoint.y;
    p2.x -= firstPoint.x;
    p2.y -= firstPoint.y;
    // 2D cross product between two vectors
    return (p1.x*p2.y - p1.y*p2.x) > 0 ; 
}



int main(){
    int n;
    cin>>n;
    if(!(n >= 4 && n<=10000)) return -1;

    auto points = new Point[n];

    // Enter the variables of point and find Point with x min and then y min
    int first = 0;
    for(int i=0; i<n; i++){
        cin>>points[i].x>>points[i].y;
        points[i].num = i;
        if(points[i].x < points[first].x || points[i].x == points[first].x && points[i].y < points[first].y){
            first = i;
        }
    }


    firstPoint = points[first];
    points[first] = points[0];
    points [0] = firstPoint;

    sort(points + 1, points + n, compare);

  
    cout << points[0].num + 1 << ' ' << (points[n/2].num) + 1 <<endl; 

    return 0;
}

