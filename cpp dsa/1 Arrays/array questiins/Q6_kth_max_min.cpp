
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q find the kth max and min value of an array

// use of priority queue is best solution as per time complexity 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;


//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        int size =r-l+1 ;
        priority_queue <int, vector<int>> pq;
        for(int i=0;i<r-l+1;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }

    int kthLargest(int arr[], int l, int r, int k) {
        //code here
        
        int size =r-l+1 ;
        priority_queue <int, vector<int>,greater<int>> pq;
        for(int i=0;i<r-l+1;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// { Driver Code Starts.
 
int main()
{
        cout<<"input :"<<endl;
        int number_of_elements;
        cout<<"enter array size :";
        cin>>number_of_elements;
        int a[number_of_elements];
        cout<<"enter array elements :";
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cout<<"enter k value :";
        cin>>k;
        Solution ob;
        cout<<"\n\noutput :"<<endl;
        cout<< k <<"th smallest element :"<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
        cout<< k <<"th largest element :"<<ob.kthLargest(a, 0, number_of_elements-1, k)<<endl;
         return 0;
}  // } Driver Code Ends
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//output format
/*
input :
enter array size :6
enter array elements :99 87 23 43 56 6
enter k value :4

output :
4th smallest element :56
4th largest element :43
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////