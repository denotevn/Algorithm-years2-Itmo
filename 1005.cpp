#include <iostream>
#include<math.h>

using namespace std;

int main(){
    // number of stone
    int n;
    cin>>n;
    auto weights = new int [n];
    // Enter weight for each stone
    for(int i=0; i<n; i++){
        cin>>weights[i];
    }

    // default 
    int result = 100000*n;

    for(int mask = 0; mask < (1<<n); mask++){
        // The mass of the number 1 is denoted by sum1 .
        int sum1 = 0;
        // The mass of the number 2 is denoted by sum0 .
        int sum0 = 0;
        for(int i = 0; i < n; i++){
            if((mask >> i) & 1 == 1 ){
                sum1 += weights[i];
            }else{
                sum0 += weights[i];
            }
        }
        int a = abs(sum1 - sum0);
        result  = min(result,a);
    }
    
    cout<<result<<endl;

    return 0; // default
}