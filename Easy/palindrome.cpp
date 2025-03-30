#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    
        int rem = 0;
        int temp = x;

        while(temp > 0){
            int n = temp % 10;
            rem = rem*10 + n;
            temp = temp / 10;


        }

        if(x == rem){
            return true;
        }
        else{
            return false;
        }

        
        
    }



int main(){

        int x;
        cin >> x;

        
        bool result = isPalindrome(x);
        cout << result << endl ;


        
}
       
