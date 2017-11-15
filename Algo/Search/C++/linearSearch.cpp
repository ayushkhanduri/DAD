#include "iostream"
#include "vector"
#include "allSearches.h"

using namespace std;
int main(){
    vector<int> arr = {53,1,75,3,45,2,6} ; int number;
    AllSearchAlgo allAlgo;
    cout<<"Enter the number to be searched : ";
    cin>>number;
    state s = allAlgo.interpolationSearch(arr,number);
    s.found ? cout<<"Number found : "<< number << " at position " << s.position<<"\n" : cout << "Not found\n";
}
