// for descending
//  while(arr[i] >= pivot && i <= high){  
//             i++;
//         }
//         while (arr[j] < pivot && j >= low)
//         {
//             j--;
//         }



#include <iostream>
using namespace std;
int qs(int arr[] , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high){  
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
    
}
void quickS(int arr[] , int low , int high){
    if (low < high)
    {
        int pindex = qs(arr , low , high);
        quickS(arr , low , pindex - 1);
        quickS(arr , pindex + 1 , high);
    }
}
int main(){
    int n;
    cout << "enter arr size\n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickS(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
return 0;
}