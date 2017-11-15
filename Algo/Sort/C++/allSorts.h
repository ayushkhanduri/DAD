#include"iostream"
#include"vector"
#include"algorithm"

using namespace std;

class AllSorts {
    public:
        //finds the smallest element and puts it at the beginning
        std::vector<int> SelectionSort(std::vector<int>);
        //in every pass the largest numbers goes to the end
        std::vector<int> BubbleSort(std::vector<int>);
    private:
        //helper functions 
        //swapping numbers
        std::vector<int> SwapNumbers(std::vector<int>,int , int);
};


std::vector<int> AllSorts::SwapNumbers(std::vector<int> arr, int i, int j){
    int swapped = arr[i];
    arr[i] = arr[j];
    arr[j] = swapped;
    return arr;
}

std::vector<int> AllSorts :: SelectionSort(std::vector<int> arr){
    int size = arr.size();
    cout<<"Using " << __func__ << " : ";
    for(int i=0 ;i<size ;i++){
        int smallest = i;
        for(int j=i+1; j<size;j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        arr = SwapNumbers(arr,i,smallest);
        //int swapped= arr[i];
        //arr[i] = arr[smallest];
        //arr[smallest] = swapped;
    }
    return arr;
}


std::vector<int> AllSorts::BubbleSort(std::vector<int> arr){
    int size = arr.size();
    cout<<"Using BubbleSort : \n";
    for(int i=0;i<size;i++){
        for(int j = 0;j<size-1;j++){
            if(arr[j] > arr[j+1]){
               arr= SwapNumbers(arr,i,j);
            }
        }
    }
    return arr;
}
