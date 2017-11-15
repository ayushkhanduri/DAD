#include "iostream"

using namespace std;

int main(){
    int sizeArr=1;
    char ch= 'y';
    while(ch == 'y' || ch == 'Y'){
       cout<<"Enter the operation that you want to perform?\n1)Add a node\n2)Remove a node\n3)Remove an Edge\n4)Exit\n";
       int option= 0 ;
       cin>>option;
       switch(option){
           case 1 : cout<< "One option selected";
                    break;
           case 2 : cout<< "two option selected";
                    break;
           case 3 : cout<< "third option selected";
                    break;
           default : cout<< "One option selected";
                    break;
          
          
       }
       cout<<"Do you want to continue ? Y or N";
       cin>>ch;
    }

    return 0;
}
