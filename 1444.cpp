#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Первую точку выбираем за основу, затем делим кукурузные зёрна на 2 части.
 * Часть 1 имеет координаты от 0 до 180 градусов.
 * часть 2 имеет координаты от 180 градусов до менее 360 градусов.
 * Затем посмотрите на конец части 1 и начало части 2
 * чтобы определить,сколько слонов съест, чтобы получить максимальное количество тыкв.
 */

using namespace std;

struct  Point{
    int x;
    int y;
    int index;
};

int cross2DProduct (Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}

int distance(Point a){
    return a.x * a.x + a.y * a.y;
}

//comparator sort the points by cross 2d product and length
bool operator < (Point a, Point b) {
    return cross2DProduct(a,b) > 0 || (cross2DProduct(a, b) == 0 && distance(a) < distance(b));
}


int main(){
    int n; 
    cin >> n;
    vector<Point> P1, P2;
    Point st; 
    cin >> st.x >> st.y;
    for(int i = 2; i <= n; ++i){
        Point A; 
        cin >> A.x >> A.y;
        A.index = i;
        A.x = A.x - st.x; 
        A.y = A.y - st.y;
        if(A.y > 0 || (A.y == 0 & A.x > 0)){
            P1.push_back(A); // Set of points from 0 to 180
        }else{
            P2.push_back(A); // From 180 to less than 360 degrees
        }
    }
    // Sort the points by position and distance to the first point
    sort(P1.begin(),P1.end()); 
    sort(P2.begin(), P2.end());
    //print out the number of edible pumpkins will be n and the first one will default to 1
    cout << n << endl << 1 << endl;
    
    // If the angle is greater than 180 degrees there will be 
    //an intersection of lines, so if the end point of set P1 and the start point of set P2 are within 180 degrees.
    //We'll let Elephpotamuses post the pumpkins with the coordinates saved in episode P2 first.
    // all points of P2
    if(P1.size()==0){
        for(int i = 0; i < P2.size(); i++){
            cout<<P2[i].index <<endl;
        }
        return 0;
    }
    // all point of P1
    if(P2.size()==0){
        for(int i = 0; i < P1.size(); i++){
            cout<<P1[i].index<<endl;
        }
        return 0;
    }

    if(cross2DProduct(P1[P1.size() - 1], P2[0]) > 0){
        for (int i = 0; i < (int)P1.size(); ++i) {
            cout << P1[i].index << endl;
        }
        for (int i = 0; i < (int)P2.size(); ++i) {
            cout << P2[i].index << endl; 
        } 
        return 0;
    }else{
        for (int i = 0; i < (int)P2.size(); ++i) {
            cout << P2[i].index << endl; 
        }
        for (int i = 0; i < (int)P1.size(); ++i) {
            cout << P1[i].index << endl;
        }
    }
    return 0;
}
