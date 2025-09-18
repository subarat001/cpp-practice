#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map> 
using namespace std;


int kadansAlgorithm(vector<int>& nums) {
    int MaxVal = INT_MIN ;
    int current = 0 ; 
    for(int i : nums) {
        current += i ; 
        MaxVal = max(current , MaxVal) ;
        if(current < 0) {
            current = 0 ; 
        }
    }
    return MaxVal ; 
}

vector<int> pareSum(vector<int>& nums , int sum) {
    int st = 0 , end = nums.size()-1 ; 
    vector<int> ans ; 
    while(st <= end) {
        if(nums[st] + nums[end] == sum) {
            ans.push_back(st);
            ans.push_back(end) ;
            return ans;
        }else if(nums[st]+ nums[end] > sum) end--; 
        else st++ ; 
    }
    return ans ; 
}

int megurity(vector<int>& nums) {
    int preq = 0 , ans = 0 ; 

    for(int i : nums) {
        if(preq == 0){
            ans = i ; 
        }
        if(ans == i) {
            preq++ ; 
        }else {
            preq-- ; 
        }
    }
    return ans ; 
}


bool alphanumaric(char a){
    if(a >= '0' && a <= '9') return true ; 
    else if( tolower(a) >='a' && tolower(a) <= 'z') return false ;
    else return false ; 
}

bool validPalandrom(string s){
    int st = 0 , end = s.length()-1;

    while(st < end){
        if( !alphanumaric(s[st])){
            st++ ; continue;
        }else if(!alphanumaric(s[end])){
            end-- ; continue;
        }

        if(tolower(s[st]) != tolower( s[end])) return false ; 
        st++ ;
        end-- ;
    }

    return true ; 
}

int findingeliment(vector<int>& nums){

    int st = 0 , end = nums.size()-1;

    while(st <= end){
        int mid = st + (end - st)/2 ; 

        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) return mid ; 

        if(mid % 2 == 0) {
            if(nums[mid] == nums[mid-1]){
                end = mid - 1 ;
            }else {
                st - mid + 1 ;
            }
        }else {
            if(nums[mid] == nums[mid+1]) {
                end = mid -1 ;
            }else{
                st = mid + 1 ;
            }
        }
    }
    return -1 ; 
}

vector<int> findingFirstAndLast(vector<int>& nums , int t){
    int st = 0 , end = nums.size()-1 ;
    vector<int> new1(2 ,-1);
    while(st <= end){
        int mid = st + (end - st)/2 ;

        if(nums[mid] == t) {
            int l = mid , r = mid ;

            // finding left side 
            while(st <= l && nums[mid] == nums[l]){
                l-- ; 
            }
            new1[0] = l+1;

            //finding right side 
            while(end >= r && nums[mid] == nums[r]) {
                r++;
            }
            new1[1] = r-1 ;

            return new1 ; 
        }else if (t > nums[mid]) st = mid+ 1 ;     
        else end = mid-1 ;
    }

    return new1 ; 

    
}

int squarroot(int n) {
    if(n < 2) return n ;

    int st = 1 , end = n/2 , ans = 0 ; 
    while(st <= end){
       int mid = st +(end-st)/2 ; 
       long long sq = (long long)mid*mid ; 

       if(sq == n) return mid ;
        else if (sq < n){
            ans = mid ;
            st = mid +1 ; 
        }
        else end = mid - 1 ;
    }

    return ans ;
}

bool isFreqSame(int a[26] , int b[26]){ 
    for(int i=0 ; i<26; i++){
        if(a[i] != b[i]){
            return false ;
        }
    }
    return true ;
}

bool stringPer(string& s1 , string& s2){
    int freq[26] = {0};
    for(int i=0 ; i<s1.length() ;i++){
        freq[s1[i]-'a']++ ;
    }

    int window = s1.length() ; 
    for(int i=0 ; i<s2.length() ; i++){
        int windInx = 0 , inx = i ;
        
        int tempfreq[26] ={0};
        while(windInx < window && inx < s2.length()){ 
            tempfreq[s2[inx]-'a']++ ;
            windInx++ ; 
            inx++;
        }
        if(isFreqSame(freq , tempfreq) == true){
            return true ;
        }
    }
    return false ; 
}

string reverce(string name){

    int n = name.length() ;

    reverse(name.begin() , name.end()) ;
    string ans = "" ;

    for(int i=0; i<n ; i++){
        string val = "" ;
        while(i < n && name[i] != ' '){
            val += name[i] ;
            i++ ;
        }
        reverse(val.begin() , val.end());
        if(val.length() > 0){
            ans += val + " " ; 
        }

    }

    return ans.substr() ; 
}


bool isnumerprime(int nums){
    
    for(int i=2 ; i*i <= nums ; i++){
        if(nums % i == 0){
            return false ; 
        }
    }
    return true ; 

}

bool isarmstrong(int n ){
    int copy = n ; 
    int cubecout = 0 ; 

    while(n > 0){
        int dig = n % 10 ; 

        cubecout += (dig * dig * dig) ;
        n = n/10 ; 
    }

    return cubecout == copy ;
}

int gcd(int a , int b){
    while(a > 0 && b > 0){
        if(a > b ) a = a% b ; 
        else b = b % a ; 
    }

    if(a == 0) return b ;
    return a ; 
}


int lcm(int a , int b){
    return  a * b / gcd(a , b) ;
}


void insertionsort(vector<int>array){

    for(int i=1 ; i< array.size() ; i++){
        int prev = i - 1 ; 
        int current = array[i];

        while(prev >= 0 && array[prev] > current){
            array[prev + 1] = array[prev] ;
            prev-- ; 
        }

        array[prev+1] = current ;
    }
}



main(){
    vector<vector<int>> matrix = {{1,3,5,7} , {10,11,16,20} , {23,30,34,60}};
    cout << matrix.size() << endl ;
    cout << matrix[0].size() << endl ;
    if(7 >= 8){
        cout << "yes" ;
    }else{
       cout <<"no";
    }
    return 0 ; 
}
