//
// Created by Chris Kay on 2022/05/29.
//
#include "string"
#include "iostream"
#include "fstream"
//#include "ostream"
#include "sstream"
#include <vector>

#define MyMacro(x,y) std::cout << "Normal Macro: " << (x * y) << std::endl
#define MyMacro1(x,y) std::cout << "Token concatenation Macro: " << (x##y) << std::dec << std::endl
using namespace std;


//struct defaults to public, class defaults to private.
struct MyStruct {
    MyStruct(int a, std::string b): a(a), b(b), c(89){ cout<<"Struct created \n"; };
    int a;
    std::string b;
    int getC() {return c;}
    ~MyStruct(){std::cout<<"\ndestruction boiz \n";}
private:
    int c;
protected:
    int d;
};

// class for const correctness and const_cast example.
class K{
public:
    const int k;
    int j;

    K(int k, int j):k(k), j(j){}

    void assign()const{
        const_cast<K*>(this)->j=5;
        std::cout << j;
    }
};
class Outer{
private:
    int i;
public:
    Outer():i(100){}
    class Inner{
    public:
        Inner(Outer &outer){
            cout << "Print outer's private members in constructor: " << outer.i << endl;
        }
    };
};

void testConstCorrectness(){
    K a = K(2,3);
    a.assign();
}

void testStruct(){
    MyStruct a(1,"56");
    cout<<a.getC();
}

void testIO(){

    std::ifstream in("./README.md", ios::binary); // InputFileStream ifstream
    std::ofstream out("./testOut.txt"); // OutputFileStream ofstream

    std:: string var;
    while (in.good()){ // in.good tests for in.eof() / in.bad() / in.fail() all in one.
        //std::cout << in.good();
        std::getline(in, var);
        //std::cout<< var << "\n"; //print to cout if needed
        out << "DUPLICATE "<< var << "\n";
    }
    in.close();
    out.close();

    string filename = "testOut.txt"; //filename to delete.
    const char *str = filename.c_str(); //convert string to null-terminated char array.
    //remove(str); //uncomment to delete file named filename


    std::cout << "printing hex to binary: " << 0xF << std::hex << endl;

    cout << "Convert string to String, int, double using memory i/o: \n";
    string t; int a,b; float c;
    string d = "IamaString 2 4.67";
    istringstream ins(d);
    ins >>  t >> a >> b >>c;
    cout << "individually stored variables \n";
    cout << t << a << b <<c << endl;
}

void nestedClass(){
    Outer outerClass;
    Outer::Inner innerClass(outerClass);
};

int & func(int &ty) {
     ty *= 10 ;
    //int &b = a;
    return ty;
}
int main(int argc, char * argv[]) {

//    nestedClass();
//    testIO();
//    testStruct();
//    MyMacro(4+4,2);
//    MyMacro1(3,5);
    //testConstCorrectness();
    //array of int vectors!
    /*
    std::vector<int> myC[5];// = {'3','r','t','\0'};

    for(int i=0; i<10; i++) {
        myC[i%4].push_back(4);
        std::cout << myC[i%4].size() << " " << endl;
    }
    */

    int a = 50;
    int &c = a;//func(a);
    std::cout<< &c << " " << &a;





}

/*
 *Variable qualifiers - static, const,
 * Type definitions - typedef, auto, decltype(xxx)
 */