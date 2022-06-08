//
// Created by Chris Kay on 2022/06/02.
//

#include <memory>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;

void vectorIterators (void) {
    int arr[4] = {4, 5, 6, 7};
    std::vector<int> vectName(arr, arr + 4); // initialize with start and 1+end pointers.

    typedef std::vector<int>::const_iterator iter; //make new typedef from old.

    for (iter it = vectName.begin(); it != vectName.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    vectName.push_back(8);

    for (int &a: vectName) { // for each returns actual value.
        cout << a << endl;
    }
}

int main(){
    //vectorIterators();
    std::vector<int> a = {3,4,5,7,8,6};
//    for( auto it=a.begin(); it!=a.end(); it++){
//        std::cout << *it << std::endl;
//    }
//
//
//    std::vector<std::string> b = {"srdgf", "wefd","ergdvfc"};
//    for( auto it=b.begin(); it!=b.end(); it++){ // iterator will have a "pointer"
//        std::cout << *it << std::endl;
//    }
//    for (std::string c : b){ //for each loop will have the actual value
//        cout << c << endl;
//    }
//move through vector in multiples. ensure vector elements # is a multiple of stepper number.
    for( auto it=a.begin(); it!=a.end(); std::advance(it,2)){
        std::cout << *it << std::endl;
    }

}

