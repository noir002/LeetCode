//Write a fcn to swap max and min number of an array

#include<iostream>
using namespace std;

int interchange(int arr[],int n, int var1, int var2){
    for(int i = 0; i < n ; i++){
        if(arr[i] < var1){
            var1 = arr[i] ;
        }
    }

    for(int j = 0;j < n ; j++){
        if(arr[j] < var2){
            var2 = arr[j];
        }
    }

    


    

    
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    int var1= INT_MAX;
    int var2= INT_MIN;

    for(int i =0; i < n ; i++){
        cin >> arr[n];
    }


}