#include<iostream>
using namespace std;
// streams : sequence of bytes in which data is being transfered 

/*
input stream and output stream 

header files :
1. iostream : cout , cin , cerr ,clog :: i/o stream most used header file
2. iomanip : setw , setprecision :: input output manipulator 
3. fstream : file handling 


cout : standard output stream --ostream -- used to print/display the content on screen
 (<< -- insertion operator--used to printout variables)

cin :  standart output stream-- istream -- used to take output 
(>> --extertion operator -- used to printin or take input from user)

cerr : unbuffered std error --ostream -- cout stores the message but cerr don't store the message it is just display the error and done
clog : buffered std error -- ostream -- inlike cerr the message is first stored in buffer and then displayed

endl and \n difference : endl flushes the ostream buffer while \n just goes to next line
*/

int main(){
    char name[]="enter your name ";
    char iname;
    cout << name <<endl;
    cin >> iname;
    cerr << "there is no error while taking input and printing output";
    clog << "\nthis is buffered error ";
} 
