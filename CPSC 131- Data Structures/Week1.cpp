#include <iostream>
#include<array> // header files predefined array 
int main() {
    // Write C++ code here
    //traditional c declaration
    /*int arr[6];
    for(int i=0;i<6;i++){
        std::cin>>arr[i];
    }
    std::cout<<arr[0]<<std::endl;
    std::cout<<arr[4]<<std::endl;
    std::cout<<arr[10]<<std::endl;*/    // Throws garbage value
    //Advance CPP array declaration
    std::array<int,7> arr;
    for(int i=0;i<7;i++){
        std::cin>>arr[i];
    }
    std::cout<<arr[4]<<std::endl;
    // raw pointer declaration
    int *ptr;
    int a = 54;
    ptr = &a;
    std::cout<<"Address = "<<ptr<<std::endl;
    std::cout<<"value = "<<*ptr<<std::endl;
    //Problem Statement-find union and intersection 
    std::array<int,5>arr1 = {1,2,4,5,6};
    std::array<int,4>arr2 = {2,4,6,8};
    std::cout<<arr1.size()<<std::endl;
    std::cout<<arr2.size()<<std::endl;
    //Union of two arrays
    int i=0,j=0; // two indices for two arrays arr1 and arr2
    int m = arr1.size();    //Storing size of arr1 in m 
    int n = arr2.size();    //storing size of arr2 in n
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){            //if arr1[i]<arr2[j] then print arr1[i] and increment i
            std::cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr2[j]<arr1[i]){       //if arr2[j]<arr1[i] then print arr2[j] and increment j
            std::cout<<arr2[j]<<" ";
            j++;
        }
        else{
            std::cout<<arr2[j]<<" ";    // if both are equal print any one of them and increment both
            j++;
            i++;
        }
    }
    //Now add remaining elements since both are having different size
    while(i<m){
        std::cout<<arr1[i]<<" ";
        i++;
    }
    while(j<n){
        std::cout<<arr2[j]<<" ";
        j++;
    }               // Codde first will execute for m times then it will execute for either m or n times Time complexity = O(n+m)
    //Intersection of two arrays
    std::cout<<"Intersection of two arrays = "<<std::endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr1[i]==arr2[j]){
                std::cout<<arr1[i]<<std::endl;
            }
        }
    }   // Each element in arr1 is compared with each element of arr2 for each loop. So,Time complexity will be o(m*n)

    return 0;

}