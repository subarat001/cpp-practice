#include <iostream>
using namespace std;

bool checkprime(int a) {
    if(a == 1) {
        return false;
    }
    for(int i=2; i<=a/2; i++) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int factroial(int a) {
    int mul = 1;
    for(int i=1 ; i<=a; i++){
        mul = i*mul ;
    }
    return mul;
}

int sumofnum(int a){
    int sum = 0;
    while(a>0){
        sum += a % 10;
        a = a/10;
    }
    return sum;
}

int main(){
    int n ;
    cout << "Enter a First number : " ;
    cin >> n;

    //second numer 
    // cout << "Enter Your second numer : " ;
    // cin >> m ;
    
    // int sum = 0;
    // for(int i=0 ; i<=n ; i++){
    //     sum += i * i ;
    // }
    // cout << sum ;

    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i ;
        
    }
    cout<< sum;
    cout << new ;

    return 0;
}
