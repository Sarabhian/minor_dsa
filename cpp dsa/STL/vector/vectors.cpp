#include<iostream>
#include<vector>
using namespace std;

/*
Vectors are same as dynamic arrays with the ability to resize itself automatically
 when an element is inserted or deleted, with their storage being handled automatically by the container.
  Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.
   In vectors, data is inserted at the end. 
   Inserting at the end takes differential time, as sometimes there may be a need of extending the array. 
   Removing the last element takes only constant time because no resizing happens.
    Inserting and erasing at the beginning or in the middle is linear in time.
Certain functions associated with the vector are:
Iterators

begin() – Returns an iterator pointing to the first element in the vector
end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
cbegin() – Returns a constant iterator pointing to the first element in the vector.
cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

*/

int main(){
    vector<int> a; // vector initialize

    // adding values to vector array 

    for (int i = 0; i < 6; i++)
    {
        a.push_back(i);
        cout << " pushing "<<i << " in vector"<<endl;
    }

    //
    cout << "Output of begin and end: ";
    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
    cout << "\nOutput of cbegin and cend: ";
    for (auto i = a.cbegin(); i != a.cend(); ++i)
        cout << *i << " ";
  
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = a.rbegin(); ir != a.rend(); ++ir)
        cout << *ir << " ";
  
    cout << "\nOutput of crbegin and crend : ";
    for (auto ir =a.crbegin(); ir != a.crend(); ++ir)
        cout << *ir << " ";
  

/*
Capacity

size() – Returns the number of elements in the vector.
max_size() – Returns the maximum number of elements that the vector can hold.
capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
resize(n) – Resizes the container so that it contains ‘n’ elements.
empty() – Returns whether the container is empty.
shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
*/

vector<int> a1;
for (int i = 0; i <=5; i++)
{
    a1.push_back(i);
}

    cout<< "\nsize "<< a1.size();
    cout<< "\nmax_size "<<a1.max_size();
    cout<< "\ncapacity "<<a1.capacity();

    a1.resize(7);
    if (a1.empty()==false)
    {
        cout<<"\nvector is not empty "<<endl;
    }
    else
        cout<<"\nvector is empty "<<endl;
    
    a1.shrink_to_fit();
    cout<<"\nvector elements are: ";
    for(auto j=a1.begin();j!=a1.end();j++){
        cout<<*j<<" ";
    }



    
    /*
    Modifiers:

assign() – It assigns new value to the vector elements by replacing old ones
push_back() – It push the elements into a vector from the back
pop_back() – It is used to pop or remove elements from a vector from the back.
insert() – It inserts new elements before the element at the specified position
erase() – It is used to remove elements from a container from the specified position or range.
swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
clear() – It is used to remove all the elements of the vector container
emplace() – It extends the container by inserting new element at position
emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector
.
    */
// Assign vector
    vector<int> v;
  
    // fill the array with 10 five times
    v.assign(5, 10);
  
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
  
    // inserts 15 to the last position
    v.push_back(15);
    int n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
  
    // removes last element
    v.pop_back();
  
    // prints the vector
    cout << "\nThe vector elements are: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
  
    // inserts 5 at the beginning
    v.insert(v.begin(), 5);
  
    cout << "\nThe first element is: " << v[0];
  
    // removes the first element
    v.erase(v.begin());
  
    cout << "\nThe first element is: " << v[0];
  
    // inserts at the beginning
    v.emplace(v.begin(), 5);
    cout << "\nThe first element is: " << v[0];
  
    // Inserts 20 at the end
    v.emplace_back(20);
    n = v.size();
    cout << "\nThe last element is: " << v[n - 1];
  
    // erases the vector
    v.clear();
    cout << "\nVector size after erase(): " << v.size();
  
    // two vector to perform swap
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v2.push_back(3);
    v2.push_back(4);
  
    cout << "\n\nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
  
    // Swaps v1 and v2
    v1.swap(v2);
  
    cout << "\nAfter Swap \nVector 1: ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
  
    cout << "\nVector 2: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    return 0;

}