#include<iostream>

int main(){
    std:: cout<<"hello world\n";
    #include<iostream>

// check cpp version
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
    return 0;
}

//// to run and check output

// use g++ .\helloworld.cpp
// .\a.exe

// cls to clcean terminal 
// ctrl +shift +  p ==> termonal:clear (add shift + z  )
