#include<bits/stdc++.h>
using namespace std;
/*
Convert a sentence into its equivalent mobile numeric keypad sequence

Input : GEEKSFORGEEKS                                            
Output : 4333355777733366677743333557777

Input : HELLO WORLD
Output : 4433555555666096667775553
 a=2 , b = 22 , c =222 
 d=3 , e = 33 , f =333
 ...

*/
string printmobile(string arr[], string input){
    string output ="";

    int n = input.length();
    for( int i=0; i< n;i++){
        if(input[i]== ' '){
            output += "0";
        }
        else{
            int pos = input[i] - 'A';
            output+= arr[pos];
        }
    }
    return output;
}
int main(){
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
                   };
    string input = "ABCDEFGH";
    cout<<printmobile(str,input);
   return 0;
}