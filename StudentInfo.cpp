/*

Group 2: UFO Alien
Member: Mengly Sovan, Pitou Song, Kim Chhorng Try, Maiza Nasyrova, Pognakvuth Meth
Section: 1

*/

#include "StudentInfo.h"

StudentInfo::StudentInfo()
{
    this->name = "";
    this->id = "";
    this->age = -1;
    this->contact = "";
}

StudentInfo::StudentInfo(string name, int id, int age, int contact)
{
    this->name = name;
    this->id = id;
    this->age = age;
    this->contact = contact;
}

void StudentInfo::setName(string name)
{
    this->name = name;
}

string StudentInfo::getName()
{
    return name;
}

void StudentInfo::setId(string id)
{
    this->id = id;
}

string StudentInfo::getId()
{
    return id;
}

void StudentInfo::setAge(int age)
{
    this->age = age;
}

int StudentInfo::getAge()
{
    return age;
}

void StudentInfo::setContact(string contact)
{
    this->contact = contact;
}

string StudentInfo::getContact()
{
    return contact;
}

void StudentInfo::setGender(char gender)
{
    this->gender = gender;
}

char StudentInfo::getGender()
{
    return this->gender;
}

bool StudentInfo::operator == (StudentInfo studentInfo)
{
    if(this->getId() == studentInfo.getId())
        return true;
    else 
        return false;
}

void StudentInfo::trimId()
{
    for (int i = id.length(); i < 11; i++)
    {
        id+= " ";
    }
}

void StudentInfo::trimName()
{
    for (int i = name.length(); i < 27; i++)
    {
        name += " ";
    }
}

void StudentInfo::print()
{
    trimId();
    trimName();

    cout << "|  " << id << "  |  " << name << "  |\t" << gender << "\t|\t"<< age <<"\t|\t" << contact << "\t|" << endl;

}


