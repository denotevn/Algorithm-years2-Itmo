#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // array containing the sum of prefixes
    long long *s = new long long [n];
    for(int i = 0; i<n; i++){
        if( i == 0 ){
            *(s+0) = arr[0];
        }
        if(i>0){
            *(s+i) = *(s+i-1) + arr[i];
        }
    }
    // Find the domain with the smallest value from about 1 to j
    // default = 0
    
    long long min_sum = 0;
    long long result = 0;

    for(int i = 0; i< n; i++){
        long long sum_ij_optimal = *(s+i) - min_sum;
        if(sum_ij_optimal > result) {
            result = sum_ij_optimal;
        }
        min_sum = min(min_sum, *(s+i));
    }

    cout<<result<<endl;

    delete[] s;
    return 0;
}