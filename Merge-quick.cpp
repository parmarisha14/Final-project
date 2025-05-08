#include<iostream>
#include<vector>
using namespace std;
// merge Sort
void merge(vector<int>&arr,int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1],R[n2];

    for (int i=0;i<n1;i++)
        L[i]=arr[left+i];
    for (int j=0;j<n2;j++)
        R[j]=arr[mid+1+j];

    int i=0,j=0,k=left;

    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else
        {
            arr[k++]= R[j++];
        }
    }
    while (i<n1)
        arr[k++]=L[i++];
    while (j<n2)
        arr[k++]= R[j++];
    
    
}
void merge_sort(vector<int>&arr,int left,int right)
{
    if (left<right)
    {
        int mid=left+(right - left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr, left,mid,right);
    }
}
// quick sort
int  partition(vector<int>&arr,int start,int end){
    int index=start-1,pivot=arr[end];
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            index++;
            swap(arr[j],arr[index]);
        }
    }
    index++;
    swap(arr[end],arr[index]);
    return index;
}
void quickSort(vector<int>&arr,int start,int end){
    if(start<end){
       int pivotIndex=partition(arr,start,end);
        quickSort(arr,start,pivotIndex-1);
        quickSort(arr,pivotIndex+1,end);
    }
}
int main(){
    int n,choice;
    cout<<"Enter the total number of elements:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    do{
        
        cout<<"Press 1 For the Merge Sort."<<endl
            <<"Press 2 For the Quick Sort."<<endl;
    
        cout<<"Enter the choice:";
        cin>>choice;
        switch(choice){
            case 1:
            merge_sort(arr,0,arr.size() - 1);
            cout << "Sorted array : ";
            for (int print :arr) {
                cout << print << " ";
            }
            cout << endl;
            break;
            case 2:
                quickSort(arr,0,arr.size()-1);
                    for(int print:arr){
                        cout<<print<<" ";
                    }
                    cout<<endl;
            break;
            case 0:
                cout<<"Exit the program."<<endl;
            break;
            default:
                cout<<"Invalid Choice."<<endl;
            break;
        }
    }while(choice!=0);
   
    return 0;
}