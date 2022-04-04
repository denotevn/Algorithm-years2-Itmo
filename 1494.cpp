// DONE

#include <bits/stdc++.h>

using namespace std;
#define MAX_N 100000


int main(){

    int n;
    cin >> n;
    int taken_ball;
    int max_ball = 0;

    list<int> array_balls;

    for(int i = 0; i<n; i++){
        cin >> taken_ball;
        if( taken_ball > max_ball ){
            for (int j = max_ball +1 ; j < taken_ball ; j++)
            {
                array_balls.push_back(j);
            }   
            max_ball = taken_ball;
        }else{
            if( taken_ball == array_balls.back() ){
                array_balls.pop_back();
            }else{
                cout << "Cheater"<<endl;
                return 0;
            }
        }
    }
    cout<<"Not a proof"<<endl;
    return 0; // default
}