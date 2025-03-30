// LC1 OF ARRAY
//write a function to calculate sum and product of all function in an array

#include<iostream>
using namespace std;

void add(int arr[],int n, int sum){
    
    for(int i = 0; i< n ; i++){
        sum = sum + arr[i];

    }

    cout << sum << endl;
}

void multiply(int arr[], int n, int prod){
    for(int i = 0; i < n; i++){
        prod = prod * arr[i];
    }

    cout << prod << endl;
}


int main(){
    int n;
    cin >> n;

    int sum = 0;
    int prod = 1;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    add(arr,n,sum);

    multiply(arr,n,prod);



    


}