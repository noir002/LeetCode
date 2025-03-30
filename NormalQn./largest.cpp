#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    int val = INT_MIN;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0;  i<n; i++ ){
        if(arr[i] > val){
            val = arr[i];
        }
    }

    cout << val << endl;
}
