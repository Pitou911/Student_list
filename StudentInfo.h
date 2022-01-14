/*

Group 2: UFO Alien
Member: Mengly Sovan, Pitou Song, Kim Chhorng Try, Maiza Nasyrova, Pognakvuth Meth
Section: 1

*/

#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <iostream>
#include <string>
using namespace std;

class StudentInfo 
{
    private:
        string name;
        int age;
        string id;
        string contact;
        char gender;
    public:
        StudentInfo();
        StudentInfo(string, int, int, int);
        void setName(string);
        string getName();
        void setId(string);
        string getId();
        void setAge(int);
        int getAge();
        void setGender(char);
        char getGender();
        void setContact(string);
        string getContact();
        bool operator == (StudentInfo);
        void trimId();
        void trimName();
        void print();
};

#endif