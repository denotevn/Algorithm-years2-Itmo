#include<bits/stdc++.h>
using namespace std;


/**
 * We find the maximum and minimum velocities of the given signals.
 * To avoid repeating too many high velocity signals after use, we subtract that signal by 1.
 * I create 2 functions to find the ids of the signals with the largest velocity and the smallest velocity.
 * Then in turn print to the screen when the signal at those ids has a velocity greater than 0
 */
struct Sign{
    int velocity;
    int id;
};

int max_velocity(Sign* arr,int k){
    int max_index = 0;
    int max_velocity = 0;
    for(int i = 0; i < k; i++){
        if(arr[i].velocity != 0 && arr[i].velocity >= max_velocity){
            max_index = i; ;
            max_velocity = arr[i].velocity;
        }
    }
    return max_index;
}
int min_velocity(Sign* arr, int k){
    int min_velocity = 10001;    
    int min_index = 0;
    for(int i = 0 ; i < k; i++){
        if(arr[i].velocity < min_velocity && arr[i].velocity != 0){
            min_velocity = arr[i].velocity;
            min_index = i;
        }
    }  
    return min_index;  
}
int main(){
    int k;
    int sum = 0;
    cin >> k;
    Sign signals[k];

    for(int i = 0; i < k; i++){
        cin >> signals[i].velocity;
        signals[i].id = i;
        sum += signals[i].velocity;
    }
    
    int min_index;
    int max_index;
    while (sum > 0)
    {
        min_index = min_velocity(signals,k);
        max_index = max_velocity(signals,k); 

        if (signals[max_index].velocity > 0) {
			cout << signals[max_index].id + 1<< ' ';
            signals[max_index].velocity--; //so as not to repeat this sign number too much
            sum--;
		}
        if(signals[min_index].velocity > 0){
            cout << signals[min_index].id + 1<<' ';
            signals[min_index].velocity--; //so as not to repeat this sign number too much
            sum--;
        }
    }
    return 0;
}