#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void printHM(map<int,string> &hm)
{
    for(auto &pair:hm)
    {
        cout<<pair.first<<"----->"<<pair.second<<endl;
    }
}

int main()
{
    map<int,string> hm;
    hm[1]="vikas";
    hm[2]="Ravi";
    //insert() function to add k-v pair in the map 
    hm.insert({3,"Prashant"});
    
    //---------------------------------------------------------
    //print each k-v in the hashmap.
    for(auto &p:hm)//P points to pair 
    {
        cout<<p.first<<"--->"<<p.second<<endl;
    }
    //==================================-----------------------
    //Check if the particular key is present in the HM or not.
    if(hm.find(1) !=hm.end())
    {
        cout<<"Roll Number 1 is present"<<endl;
    }
    
    auto it = hm.find(2);
    //find() function return the iterator to that key, if key is present.
    //If the key is not present the it return the iterator to===> hm.end()
    cout<<it->first<<"----"<<it->second<<endl;
    //---------------------------------------------------------
    //Remove the k-v pair from the HM.
    // hm.erase(1);
    cout<<hm.erase(1)<<endl;//1 
    cout<<hm.erase(5)<<endl;//0
    
    /*
    erase(key) ==> 
    take the key and remove the k-v pair from the hm.
    If the key is not present, erase(key) simply does nothing and returns 0 
    (indicating no elements were erased). No errors or exceptions are thrown.
    */
    //---------------------------------------------------------
    printHM(hm);

    return 0;
}
