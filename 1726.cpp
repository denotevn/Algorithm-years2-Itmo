#include<bits/stdc++.h>

using namespace std;
struct Point{
    int x;
    int y;
};


bool compare(Point a, Point b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main(){
    int n;
    cin >> n;
    Point points[n];
    
   for(int i = 0; i < n; i++){
       cin >> points[i].x >> points[i].y;
   }
   sort(points + 0, points + n, compare);
   /*
   for(int i =0 ; i < n ; i++){
       cout<<points[i].x << " "<<points[i].y<<endl;
   }
   */
    int res = 0;
   for(int i = 1; i < n; i++){
       int a = points[i].x - points[i-1].x;
       int b = points[i].y - points[i-1].y;
       res = (a+b)*i*(n-1)*2; // toh quang duong ca di va ve phai nhan 2
   }
   res = res/(n*(n-1));
   cout<<res<<endl;
   return 0;

}