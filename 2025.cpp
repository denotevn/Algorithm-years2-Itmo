#include<iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    int n; 
    int k;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cout<<endl;
        // team members
        int a = n/k; 
        //remainder members
        int y = n%k;
        // y team has a + 1 fighters
        // x team has a fighters
        int x = k - y;
        int result = y*(y-1)*pow(a+1,2)/2 + x*(x-1)*pow(a,2)/2 + x*y*(a+1)*a;
        cout<<result<<endl;
    }

    return 0;
}