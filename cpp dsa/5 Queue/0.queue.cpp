////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
****************  Queue  DATA STRUCTURE ******************************

- STACK is linear data structture
- based on memory allocation it can be classified as ;
    - 1. static stack .............. (stack using  array)
    - 2. dynamic stack ..............(stack using linked list) 

-  FILO or LIFO .... 
   first in last out =  element entering first will leave stack at the last 
   last in fast out = element entering last will leave stack at first position
   
   |__|--
        |
        |
        insert from top , remove from top, 
   |---------| 
   |---------|
   |---------|
   |---------|
   |---------|<-- top = 0
   |____2____| <-- bottom is closed


   - basic functions of stack :
        1. push() -- insert element at top
        2. pop()   -- delete element at location top
        3. isempty() -- check stack is empty or not
        4. peek()/top()  -- return element at top of stack
        5. display() --display the stack.

-applications of stack 
     1. reverse the string
     2. undo function
     3. recurssion/ function call
     4. balance of {} paranthesis
     5. dfs
     6. tower of hanoi 
     7.infix to postfix 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
s