//
// Created by Allen on 23/4/2020.
//

#ifndef HEBUT_TEMP_H
#define HEBUT_TEMP_H

#include <iostream>


class temp {
public:
    virtual void speak(){
        std::cout << "who speak()" << std::endl;
    }
};

class dog : public temp{
public:
    void speak(){ std::cout << "dog speak()" << std::endl;}
};

class cat : public temp{
public:
    void speak(){ std::cout << "cat speak()" << std::endl;}
};

class Labrador : public dog{
    void speak(){ std::cout << "Labrador speak()" << std::endl;}
};


    /*temp* p = new temp;
    p->speak();

    temp* p1 = new dog;
    p1->speak();

    temp* p2 = new Labrador;
    p2->speak();

    dog* p3 = new Labrador;
    p3->speak();

    Labrador* p4 = new Labrador;
    Labrador* p5 = new dog;*/


#endif //HEBUT_TEMP_H
