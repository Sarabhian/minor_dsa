 #include<iostream>
 #include<string>
 #include<array>
 #include<vector>
 using namespace std;

int main(){


// 1. creating Array of stings in CPP 

    // a. using pointer 
    // b. using 2d array 
    // c. using string class
    // d. using vector class
    // e. using array class

    // a. using pointer 

    const char *color[3] = { "red","blue", "green "}; // always use " " not ' ' to define string 
    cout<<"\n____________________________________\n"<<"\nstring using pointer : ";
    for (int i = 0; i < 3; i++)
    {
        cout<<color[i]<<" ";
    }
    
    // b using 2d array 
    cout<<"\n____________________________________\n"<<"\nstring using 2d array : ";
    char color1[4][10] = { "red","blue", "green","orange"};
    for (int i = 0; i < 4; i++)
    {
        cout<<color1[i]<<" ";
    }
    // c uisng string class 

    cout<<"\n____________________________________\n"<<"\nstring using string class : ";
    string color2[5] = { "red","blue", "green","orange","yellow"};
    for (int i = 0; i < 5; i++)
    {
        cout<<color2[i]<<" ";
    }

    // d using vector class 
    cout<<"\n____________________________________\n"<<"\nstring using vector class : ";
    vector<string> color3 { "red","blue", "green","orange","yellow"};
    for (int i = 0; i < color3.size(); i++)
    {
        cout<<color3[i]<<" ";
    }

    // e using array class 
    cout<<"\n____________________________________\n"<<"\nstring using array class : ";
    array<string, 6> color4 { "red","blue", "green","orange","yellow","white"};
    for (int i = 0; i < 5; i++)
    {
        cout<<color4[i]<<" ";
    }

//------------------------------------------------------------------------------------------------------------------------------------------------------

// 2.  arrays in C :  printf scanf sprintf
 
    cout<<"\n____________________________________"<<endl;
    printf("color1 using printf: %s", color1[2]); // prints only one element :)

    // sprintf 

    char buffer[50];
    sprintf(buffer ,"%s %s %s" ,color1[0],color1[1],color[2]);
    printf("\nusing sprintf : %s",buffer);

//------------------------------------------------------------------------------------------------------------------------------------------------------

// 3. 


















































    string str1("ABHCDEFGH srfhisehfo"); // use " " to initialise the string 

    // initialize by another string 
    string str2(str1);
    // only part of str 
    string str3(str1 , 3 ,6) ;// fron 3rd index next 6 charaters 

    // string of repeating chars
    string str4(4, 'a' ); // use ' ' to represent char  can use only one char of size 1




} 
  