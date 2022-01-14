/*

Group 2: UFO Alien
Member: Mengly Sovan, Pitou Song, Kim Chhorng Try, Maiza Nasyrova, Pognakvuth Meth
Section: 1

*/

#include <iostream>
#include <stdexcept>
#include "menuFunction.cpp"
using namespace std;



int main()
{

  Double_list<StudentInfo> studentList[20];
  string listName[20];
  int listNum = 0;
    
    //Input options
    int option;
    system("color a");

    while (option != 10)
    {
      system("cls");
      ////option
      cout << "**********************MENU***********************" << endl;
      cout << "|\tOption 0: Create student list\t\t|" << endl;
      cout << "|\tOption 1: Add student \t\t\t|" << endl;
      cout << "|\tOption 2: Remove student  \t\t|"<< endl;
      cout << "|\tOption 3: Find student\t\t\t|"<< endl;
      cout << "|\tOption 4: Update student information\t|" << endl;
      cout << "|\tOption 5: Print student list\t\t|" << endl;
      cout << "|\tOption 6: Delete the list\t\t|" << endl;
      cout << "|\tOption 7: Sort the list\t\t\t|" << endl;
      cout << "|\tOption 8: Append the list\t\t|" << endl;
      cout << "|\tOption 9: Merge the list\t\t|" << endl;
      cout << "|\tOption 10: Exit\t\t\t\t|" << endl;
      cout << "*************************************************" << endl;
      cout << "Enter the option: ";
      cin >> option;
      switch(option)
      {
        case 0: create(studentList, listNum, listName);
          break;
        case 1: addFunction(studentList, listNum, listName);
          break;
        case 2: removeFunction(studentList, listNum, listName);
          break;
        case 3: searchFunction(studentList, listNum, listName);
          break;
        case 4: update(studentList, listNum, listName);
          break;
        case 5: print(studentList, listNum, listName);
          break;
        case 6: deleteFunction(studentList, listNum, listName);
          break;
        case 7: chooseSortFunction(studentList, listNum, listName);
          break;
        case 8: appendFunction(studentList, listNum, listName);
          break;
        case 9: mergeFunction(studentList, listNum, listName);
          break;
        case 10: cout << "Program exited!!!" << endl;
          break;
        default:cout << "Wrong Input! Try to input correct option." << endl;
          system("pause");
          break;
      }
    }
  return 0; 
}   