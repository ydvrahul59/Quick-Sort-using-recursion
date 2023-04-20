#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];

    int cnt = 0;

    for(int i = s+1; i<=e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
    // place pivot at right position 
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left & right part sambhal leten hain
    int i = s, j=e; //2 pointer le liyen

    while(i< pivotIndex && j>pivotIndex){
        // if koi elemnt pivot se alredy chota hai
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        // if upar wla ye 2 case nhi hai tph swap krna hai
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e){

    // base case(0 or 1 elemnt hogen toh sorted hin manuga)
    if(s >= e)
        return ;

    // partition karnge
    int p = partition(arr,s,e);

    // left part sort krnge
    quickSort(arr, s, p-1);

    // right part sort krnge
    quickSort(arr,p+1,e);

}
int main(){

    int arr[7] = {6 ,2 ,3, 8, 9 ,9, 9 };
    int n = 7;

    quickSort(arr,0,n-1);

    // sorted array ko pront kara liya
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
 
}