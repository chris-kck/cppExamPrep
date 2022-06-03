//
// Created by Chris Kay on 2022/06/03.
//

#include <iostream>

//>>, <<, +, -, /, *, +=, *=, -=,!=, ++, —, [], (), >,<,~
using namespace std;
class Person {
public:
    string firstname;
    string middlename;
    string lastname;
    int age;
    char gender; // M/F
    Person(string first, string mid, string last, int age, char gender ): firstname(first), middlename(mid), lastname(last), age(age), gender(gender){
        setNet();
    }
    void setNet(){ netWorth=34; }
    friend std::ostream & operator<<(std::ostream & out, const Person & rhs); //could have been defined here as well. Friend MUST stay {}
    friend std::istream & operator>>(std::istream & in, Person & rhs){
        in >> rhs.netWorth >> rhs.age;
        return in;
    };
    void operator~(void){ gender='F'; } // unary overload.
    void operator+(int value){ netWorth+=value; }

    Person operator+(const Person & rhs){
        Person temp = *this;
        temp.firstname += " " + rhs.firstname;
        temp.middlename += " " + rhs.middlename;
        temp.lastname += " " + rhs.lastname;
        temp.age += rhs.age;
        temp.netWorth += rhs.netWorth;
        return temp;
    }
    friend Person & operator-=(Person & lhs ,const Person & rhs);
private:
    int netWorth;
};

// << operator can done outside class once friended.
std::ostream & operator<<(std::ostream & out, const Person & rhs){
    out << rhs.firstname + " " + rhs.middlename << " " << rhs.lastname << " " << rhs.age << " " << rhs.netWorth << " " << rhs.gender << endl;
    return out;
}


int main(){

}
