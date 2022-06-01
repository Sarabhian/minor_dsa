#include<iostream>
using namespace std;

/*
1. if statement
2. if..else statements
3. nested if statements
4. if-else-if ladder
5. switch statements
6. Jump Statements: 
        1.break : As soon as the break statement is encountered from within a loop, 
        the loop iterations stop there,
         and control returns from the loop immediately to the first statement after the loop. 

        2.continue : When the continue statement is executed in the loop, 
        the code inside the loop following the continue statement will be skipped 
        and the next iteration of the loop will begin. 

        3.goto : 
        Syntax1      |   Syntax2
        ----------------------------
        goto label;  |    label:  
        .            |    .
        .            |    .
        .            |    .
        label:       |    goto label;

In the above syntax, the first line tells the compiler to go to or jump to the statement marked as a label.
 Here label is a user-defined identifier that indicates the target statement. 
 The statement immediately followed after ‘label:’ is the destination statement.
 The ‘label:’ can also appear before the ‘goto label;’ statement in the above syntax. 
        4.return : 
        The return in C or C++ returns the flow of the execution to the function from where it is called. 
        This statement does not mandatorily need any conditional statements. As soon as the statement is executed, 
        the flow of the program stops immediately and return the control from where it was called.
         The return statement may or may not return anything for a void function, but for a non-void function, 
         a return value is must be returned. 
 
*/
int main(){
 int age; char a; int b;
    printf(" Do you want to vote y/n ");
    scanf("%c", &a);
    if (a=='y'| a=='Y')                    // 1. if  or for this example can  say   4. nested if  
    {
        printf("enter your age: ");
        scanf("%d",&age);
        if ( age >= 18 )                     
        {
            printf("you can vote\n");
        }
        else                                // 2. if else 
        {
            printf("you can't vote\n");
        }
        
     
        if ( age >= 18)                      // 3. if else if... ladder and nested if combined == nested if else ladder 
        {                                                        // ... most commnly used control statement 
            printf("you can watch anything \n");
            printf("what do you like?  movies/web series/anime ?\n");
            printf("1: anime\n2:movies\n3:web series \nenter 1, 2 or 3:");
            scanf("%d",&b);
            if (b==1 | b==2 | b==3)
            {
                printf("you should not waste your time, you should be studying right now -_-");
            }
            
        }
        else if (age<18 & age>8)
        {
            printf("You can watch cartoon \n");
        } 
        else
            printf("sorry You can't  watch TV \n");
    }
}