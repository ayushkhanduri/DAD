#include"iostream"
#include"algorithm"
#include"vector"
#include"dsSort.h"

class AllSearchAlgo {
    private:
        state s;
    public:
        //complexity O(n)
        state linearSearch(std::vector<int> ,int);
        //complexity O(Logn)
        state binarySearch(std::vector<int> , int);
        //complexity 0(root(n))
        state jumpSearch(std::vector<int> , int);
        state interpolationSearch(std::vector<int>,int);
        
        std::vector<int> returnSortedArr(std::vector<int>);

};

std::vector<int> AllSearchAlgo :: returnSortedArr(std::vector<int> arr){
    int sorted = std::is_sorted(arr.begin(),arr.end()) , size = arr.size();
     if(!sorted){
        std::sort(arr.begin(),arr.end()); 
        std::cout<<"New Sorted array!\n";
        for(int i= 0; i<size;i++){
            std::cout<<arr[i]<<"\t";
        }
        std::cout<<std::endl;
    }
 
    return arr;
}

state AllSearchAlgo :: linearSearch(std::vector<int> arr,int searchNum){
    int length = arr.size();
    for(int i=0; i<length;i++){
        if(arr[i]== searchNum){
            s.found=true;
            s.position = i+1;
            break;
        }
    }
    return s;
}

state AllSearchAlgo :: binarySearch(std::vector<int> arr, int searchNum){
    arr = returnSortedArr(arr);
    int left = 0 , right = arr.size()-1;
    while(left<= right){
        int middle = left + (right-left)/2;
        if(arr[middle]== searchNum){
            s.found = true;
            s.position = middle + 1;
            break;
        }else if(arr[middle]< searchNum){
            left= middle+1;
        }else if(arr[middle]> searchNum){
            right= middle-1;
        }
    }
    return s;
}

state AllSearchAlgo :: jumpSearch(std::vector<int> arr , int searchNum){
    int size = arr.size() ,notFound= 0, factor = std::sqrt(size), i=0 ,indexValue=factor*i ; 
    arr = returnSortedArr(arr);
    do{
        indexValue = factor * (++i);
        if(indexValue>size){
            notFound = -1;
            break;
        }
    }while(arr[indexValue] < searchNum);
        
    if(notFound!= -1){
        int loopStart = factor * (i-1);
        int loopEnd = factor * i;
        for(int i = loopStart ; i<=loopEnd;i++){
            if(arr[i] == searchNum){
                s.position = i+1;
                s.found = true;
                break;
            }
        }
    }
    
    return s;
}

state AllSearchAlgo :: interpolationSearch(std::vector<int> arr , int searchNum){
    int h= arr.size() - 1, l = 0;
    arr = returnSortedArr(arr);
    while(l <= h && searchNum >= arr[l] && searchNum<= arr[h]){
        int pos = l + (((double)(h-l) /(arr[h]-arr[l]))*(searchNum - arr[l]));
        if(arr[pos] == searchNum){
            s.found = true;
            s.position = pos;
            break;
        }else if(arr[pos]<searchNum){
            l  =  pos+1;
        }else{
            h =  pos -1;
        }        
    }
    return s;

}
