#include"vector"
#include"iostream"
#include"allSorts.h"

using namespace std;

int main(){
    AllSorts a;
    std::vector<int> arr = {324,1,56,145,2,7,334,1};
    std::vector<int>::iterator it;
    arr = a.SelectionSort(arr);
    for(it= arr.begin();it!=arr.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}
