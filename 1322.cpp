#include <bits/stdc++.h>

using namespace std;

struct char_i{
    char c;
    int index;
};

// function Compare in ascending order of char
bool compare_char(const char_i a, const char_i b){
    return a.c < b.c;
}

int main(){
    int n;
    char c;
    cin >> n;n--;
    int length = 0;
    vector<char_i> array; // array of element
    while (cin.get(c))
    {
        if(length > 0 && (c == '\r' || c == '\n')){
            break;
        }else{
            if(isspace(c)){
                continue;
            }
        }
        array.push_back((char_i){c,length});
        length++;
    }

    stable_sort(array.begin(), array.end(), compare_char);

    for(int i =0; i < array.size(); i++){
        cout<<array[i].c << ' ';
    }
    cout << endl;
    int j = n;
    for(int i=0; i<length; i++,j = array[j].index){
        cout<<array[j].c;
    }
    
    return 0;
}