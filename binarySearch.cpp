#include<iostream>
#include<vector>
using namespace std;
int binarySeach(vector<int>&arr,int size,int key){
    int left=0,right=size-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==key){
            return mid;
        

        }
        else if(arr[mid]<key){
            left=mid+1;
        }
        else{
            right=mid+1;
        }
       
    }
    return -1;
}

int main(){
    int n,key,size;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the key:";
    cin>>key;
    int result=binarySeach(arr,size,key);
    cout<<"Result:"<<result;
    return 0;

}