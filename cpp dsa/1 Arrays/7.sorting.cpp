#include<iostream>
#include<cmath>

using namespace std;

void selectionSort( int arr[], int n){
    for( int i =0 ; i<n ; i++ ){
        for( int j = i+1 ;j <n ; j++){
            if ( arr[j]< arr[i]){
                int temp = arr[j];
                arr[j]= arr[i];
                arr[i]= temp ;
            }
        }
    }

}

void bubbleSort( int arr [], int n){
    int count = 1 ;
    while( count<n){
        for(int i  =0 ; i< n-count ; i++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]= temp ; 
            }
        }
        count++;
    }
    cout <<"total count : "<<count;
}

void bubbleSortOptimized( int arr [], int n){
    int count = 1 , flag=0;
    while( count<n){

        for(int i  =0 ; i< n-count ; i++){
            if (arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]= temp ; 
                flag =1;
            }
        }
        if(flag ==0){break;}
        count++;
        flag =0 ;
    }
    cout <<"total count : "<<count;
}
int main()
{
    int n ;
    cout << " enter array length:";
    cin >> n;
    int arr[n];
    cout << "\nenter array elements :";
    for(int i =0 ; i<n; i++){cin>>arr[i];}

    // selectionSort(arr,n);
    // bubbleSort(arr,n);
    // bubbleSortOptimized(arr ,n);

    cout<<"\nsorted array : ";
    for (int i = 0; i < n; i++){cout<<i[arr]<<" ";}
    return 0;
}