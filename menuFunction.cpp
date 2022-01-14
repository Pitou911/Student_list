#include "Double_list.cpp"
#include "Double_node.cpp"
#include "StudentInfo.cpp"
#include <fstream>
#include <cstdlib>


//This function read all data from text file
void readFromTxt(Double_list<StudentInfo> studentList[], int listNum, string txtFile)
{
    //choose the text file that user want to read
    if (txtFile == "0")
    {
        txtFile = "StudentList1.data";
    }

    if (txtFile == "1")
    {
        txtFile = "StudentList2.data";
    }

    ifstream studentTxt(txtFile);
    int count;

    //read the count number from text file
    studentTxt >> count;

    //Reading from selected text file by looping for "count" times
    for(int i = 0; i < count; i++)
    {
        //initializing the temp to read from text file one by one
        StudentInfo temp;
        string idTemp;
        string nameTemp;
        char genderTemp;
        int ageTemp;
        string contactTemp;

        //reading ID, Name, Gender, Age and Contact from text file to temp
        studentTxt >> idTemp;
        studentTxt.ignore();
        getline(studentTxt, nameTemp);
        studentTxt >> genderTemp >> ageTemp >> contactTemp;
        
        //set all data to StudentInfo object as temp
        temp.setId(idTemp);
        temp.setName(nameTemp);
        temp.setGender(genderTemp);
        temp.setAge(ageTemp);
        temp.setContact(contactTemp);

        //push data to the list
        studentList[listNum].push_back(temp);
    }
    studentTxt.close();
}

//This function print create option and reading user input
void create(Double_list<StudentInfo> studentList[], int &listNum, string listName[])
{
    system("cls");

    //cheack whether the list is created to Maximun number (20)
    if (listNum >= 20)
    {
        cout << "Maximun list, Cannot create more list!!!" << endl;
        system("pause");
    }
    else
    {
        int option = -1;
        //Loop until user input the correct option
        while (!(option == 0 || option == 1))
        {
            system("cls");
            //prompt the users to input the option above
            cout << "**********************MENU***********************" << endl;
            cout << "Option 0: Create an  empty list" << endl;
            cout << "Option 1: Create a list by reading from text file" << endl;
            cout << "*************************************************" << endl;
            cout << "Input the option: ";
            cin >> option;

            //check user input if option = 1 increase the number of list
            if (option == 0)
            {
                listNum++;
            }
            else if(option == 1)
            {
                system("cls");
                string fileSelect;
                //prompt the user to choose the text file by inputting the number of option
                cout << "**********************MENU***********************" << endl;
                cout << "Option 0: StudentList1.data" << endl;
                cout << "Option 1: StudentList2.data" << endl;
                cout << "*************************************************" << endl;
                cout << "Select the text file by input the number or file name: ";
                cin >> fileSelect;

                //looping until user input the correct option
                while (!(fileSelect == "0" || fileSelect == "1" || fileSelect == "StudentList1.data" || fileSelect != "StudentList2.data"))
                {
                    cout << "Wrong Input, Please input it again correctly: ";
                    cin >> fileSelect;
                }

                //read the selected text file to the list
                readFromTxt(studentList, listNum, fileSelect);
                listNum++;
            }
            else
            {
                cout << "Wrong input, please try to input correctly" << endl;
                system("pause");
            }

        }

        //prompt the user to input the list name
        cout << "Please input the list name: ";
        cin >> listName[listNum - 1];

        //print successfull message
        cout << "Student list has been created successfully!!" << endl;

        system("pause");
    }
}

//This function prompt user to select the list
int listSelect(int listNum, string listName[], int display)
{
    int selectNum = -1;

    //prompt the  user to select the created list
    while (selectNum < 0 || selectNum > listNum - 1)
    {
        system("cls");

        //check display number since there will be difference display
        if (display == 1)
        {
            cout << "Choose the loist that you want to append" << endl;
        }
        else if (display == 2)
        {
            cout << "Choose the list that you want to append to the first selected list" << endl;
        }
        else if (display == 3)
        {
            cout << "Choose the list that you want to merge" << endl;
        }
        else if (display == 4)
        {
            cout << "Choose the list that you want to merge to the first selected list" << endl;
        }

        cout << "**********************MENU***********************" << endl;

        //Check the list number, if there is no list display error message. Otherwise, display all the list that have been created
        if (listNum == 0)
        {
            cout << "  There  is no list, please create the first!!!" << endl;
            cout << "*************************************************" << endl;
            system("pause");
            break;
        }
        else
        {
            for (int i = 0; i < listNum; i++)
            {
                cout << "Option " << i << ": " << listName[i] << endl; 
            }
        }
        cout << "*************************************************" << endl;

        //prompt user to select the list
        cout << "Select the list: ";
        cin >> selectNum;

        //if the user input incorrectly, Display error message
        if (selectNum < 0 || selectNum > listNum - 1)
        {
            cout << "Please enter the option correctly." << endl;
            system("pause");
        }
    }

    return selectNum;
}

//This function print all student information from selected list
void print(Double_list<StudentInfo> studentList[], int listNum, string listName[])
{
    //Getting list index by calling function "listSelect"
    int listIndex = listSelect(listNum, listName, -1);

    //check if there is exiting list. If there is no list, end the function.
    //Otherwise, Display student information
    if (listIndex != -1)
    {
        system("cls");
        cout << "=========================================================================================================" << endl;
	    cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        
        //Check: if the list empty, Display error message. Otherwise, display all student information from selected list
        if (studentList[listIndex].empty())
        {
            cout << "\t\t\tThere is no any data in the list!!!" << endl;
        }
        else
        {
            Double_node<StudentInfo> * temp = studentList[listIndex].head();

            //looping to access the node and print data one by one
            while (temp != NULL)
            {
                //print student informaton by calling function "print"
                temp->getData().print();
                temp = temp->getNext();
            }
        }
        cout << "=========================================================================================================" << endl;
        system("pause");
    }
}

//Adding student information to selected list
void addFunction(Double_list<StudentInfo> studentList[], int listNum, string listName[])
{
    //Getting list index by calling function "listSelect"
    int listIndex = listSelect(listNum, listName, -1);

    //check if there is exiting list. If there is no list, end the function.
    if (listIndex != -1)
    {
        int option = -1;
        
        //Looping until the user input correct option
        while (!(option == 0 || option == 1))
        {
            system("cls");
            cout << "**********************MENU***********************" << endl;
            cout << "Option 0: Adding at the front" << endl;
            cout << "Option 1: Adding at the back" << endl;
            cout << "*************************************************" << endl;
            cout << "Choose the option to add the list: ";
            cin >> option;

            //if the user input incorrect option, display error message
            if (!(option == 0 || option == 1))
            {
                cout << "Please input the option correctly!!!" << endl;
                system("pause");
            }
        }
        
        //initializing the temp to read user input
        StudentInfo temp;
        string idTemp;
        string nameTemp;
        char genderTemp;
        int ageTemp;
        string contactTemp;

        //prompt the user to input student information
        cout << "Input student ID: ";
        cin >> idTemp;
        cin.ignore();
        cout << "Input student Name: ";
        getline(cin, nameTemp);
        cout << "Input student Gender: ";
        cin >> genderTemp;
        cout << "Input student age: ";
        cin >> ageTemp;
        cout << "Input student Contact: ";
        cin >> contactTemp;
        
        //set all data to StudentInfo object as temp
        temp.setId(idTemp);
        temp.setName(nameTemp);
        temp.setGender(genderTemp);
        temp.setAge(ageTemp);
        temp.setContact(contactTemp);

        //check user input option
        //if the user choose option 0, adding student information to the list form the front.
        //if the user choose option 1, adding student information to the list form the back.
        if (option == 0)
        {
            studentList[listIndex].push_front(temp);
        }
        else
        {
            studentList[listIndex].push_back(temp);
        }

        //Display successful message
        cout << "New student has been added successfully!!!" << endl;
        system("pause");
    }
}

//return a pointer to the node that matches the key
Double_node<StudentInfo>* searchId(const Double_list<StudentInfo>& list, string key)
{
    Double_node<StudentInfo>* temp = list.head();
    
    //tranverse through the list
    while(temp != NULL)
    {
        if(temp->getData().getId() == key) // check the id of the current node
            return temp;
        else 
            temp = temp->getNext(); //move to next node
    }

    return temp;
}

//return a pointer to the node that matches the key
Double_node<StudentInfo>* searchName(const Double_list<StudentInfo>& list, string key)
{
    Double_node<StudentInfo>* temp = list.head();

    //tranverse through the list
    while(temp != NULL)
    {
        if(temp->getData().getName() == key) //check the name of the current node
            return temp;
        else 
            temp = temp->getNext(); //move to next node
    }

    return temp;
}

void searchFunction(Double_list<StudentInfo> list[], int listNum, string listName[])
{
    //ask the users to choose the list they want to find a student
    int listIndex = listSelect(listNum, listName, -1);
    if (listIndex != -1)
    {
        if (!list[listIndex].empty())
        {
            //ask the users to choose the option to find by ID or name
            int option = -1;
            while (!(option == 0 || option == 1))
            {
                system("cls");
                cout << "**********************MENU***********************" << endl;
                cout << "Option 0: Find by ID" << endl;
                cout << "Option 1: Find by Name" << endl;
                cout << "*************************************************" << endl;
                cout << "Choose the option to find student info: ";
                cin >> option;
                cin.ignore();
                if (!(option == 0 || option == 1)) //ask the users to input again if the input is incorrect
                {
                    cout << "please try to input the option correctly!!" << endl;
                    system("pause");
                }
            }
            Double_node<StudentInfo> *temp;
            if (option == 0)
            {
                //ask the users to input the ID
                string idTemp; 
                cout << "Enter the ID: ";
                cin >> idTemp;
                cin.ignore();
                //search for that ID
                temp = searchId(list[listIndex], idTemp); 
            }
            else
            {
                //ask for the users to input the name
                string nameTemp;
                cout << "Enter the name: ";
                getline(cin, nameTemp);
                //search for that name
                temp = searchName(list[listIndex], nameTemp);
            }
            
            //display the result of the search
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            if (temp == NULL) //data is not found in the list
            {
                cout << "\t\tStudent is not found!!!" << endl;
            }
            else
            {
                //display the student's information
                temp->getData().print();
            }

            cout << "=========================================================================================================" << endl;
            system("pause");
        }
        else //no data in the list
        {
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\tThere is no any data in the list!!!" << endl;
            cout << "=========================================================================================================" << endl;
            system("pause");
        }
    }
}

void removeFunction(Double_list<StudentInfo> studentList[], int listNum, string listName[])
{
    //ask the users to choose the list that they wnat to remove a student
    int listIndex = listSelect(listNum, listName, -1);

    if (listIndex != -1)
    {
        //ask the users to choose the option how they want to remove the student
        int option = -1;

        //check if the list is empty
        if (studentList[listIndex].empty())
        {
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            try
            {
                cout << "\t\t\t\t";
                studentList[listIndex].front(); //if the list is empty, it will throw an exception
                cout << endl;
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';
            }
            cout << "=========================================================================================================" << endl; 
        }
        else
        {
            while (!(option == 0 || option == 1|| option == 2))
            {
                system("cls");
                cout << "**********************MENU***********************" << endl;
                cout << "Option 0: Removing from the front" << endl;
                cout << "Option 1: Removing from back" << endl;
                cout << "Option 2: Erasing by ID" << endl;
                cout << "*************************************************" << endl;
                cout << "Choose the option to add the list: ";
                cin >> option;

                if (!(option == 0 || option == 1 || option == 2)) //ask to input again if the input is incorrect
                {
                    cout << "Please input the option correctly!!!" << endl;
                    system("pause");
                }
            }

            string tempId = "-1";
            Double_node<StudentInfo> *temp;
            bool studentFounded = true;
            if (option == 2) //ask for the ID when the user choose to remove by ID
            {
                cout << "Input the ID to search for student Info: ";
                cin >> tempId;
                //search for that ID
                temp = searchId(studentList[listIndex], tempId);
            }
        
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
        
        
            if (option == 0)
            {
                //display the student's information before deleting
                StudentInfo temp = studentList[listIndex].front();
                temp.print();
            }
            else if (option == 1)
            {
                //display the student's information before deleting
                StudentInfo temp = studentList[listIndex].back();
                temp.print();
            }
            else
            {
                if (temp == NULL) //check if the input ID exist in the list
                {
                    cout << "\t\tStudent info not found!!!" << endl;
                    studentFounded = false;
                }
                else
                {
                    //display the student's information before deleting
                    StudentInfo temp2 = temp->getData();
                    temp2.print();
                }
            }
            cout << "=========================================================================================================" << endl;
            int deleted;
            
            //ask for confirmation to delete
            if (studentFounded)
            {
                cout << "Do you really want to delete this student data?" << endl;
                cout << "Input any number for Yes | 0 for No: ";
                cin >> deleted;
                
                if (deleted != 0)
                {
                    //delete the information
                    if (option == 0)
                    {
                        studentList[listIndex].pop_front();
                    }
                    else if (option == 1)
                    {
                        studentList[listIndex].pop_back();
                    }
                    else
                    {
                        studentList[listIndex].erase(temp->getData());
                    }
                    //display the message 
                    cout << "Student info has been deleted successfully!!!" << endl;
                }
                else
                {
                    //displat error message
                    cout << "Student info removing failed!!!" << endl;
                }
            }
        }

        system("pause");
    }
}

void sortName(Double_list<StudentInfo>& list)
{
    //create node temp that point to the head of the list
    Double_node<StudentInfo> *temp = list.head();
    //create node next that point to the next head of the list
    Double_node<StudentInfo> *next = temp->getNext();
    StudentInfo tempInfo;
    //check if the list is empty
    if(temp==NULL) 
    {
        return;
    }
    else{
        while(temp->getNext() != NULL){
            while(next!=NULL){
                //swap data
                if(temp->getData().getName() > next->getData().getName())
                {
                    //get data from the node next
                    tempInfo = next->getData();
                    //set data of the node next with data from node temp
                    next->setData(temp->getData());
                    //store data in node temp
                    temp->setData(tempInfo);  
                } 
                //update next to the next
                next = next->getNext();
            }
            //update temp to the next
            temp = temp->getNext();
            //update next to the next
            next = temp->getNext();
        }
    }
}

void sortId(Double_list<StudentInfo>& list)
{
    //create node temp that point to the head of the list
    Double_node<StudentInfo> *temp = list.head();
    //create node next that point to the next head of the list
    Double_node<StudentInfo> *next = temp->getNext();
    StudentInfo tempInfo;
    //check if the list is empty
    if(temp==NULL) 
    {
        return;
    }
    else{
        while(temp->getNext() != NULL){
            while(next!=NULL){
                //swap data
                if(temp->getData().getId() > next->getData().getId())
                {
                    //get data from the node next
                    tempInfo = next->getData();
                    //set data of the node next with data from node temp
                    next->setData(temp->getData());
                    //store data in node temp
                    temp->setData(tempInfo);  
                } 
                //update next to the next
                next = next->getNext();
            }
            //update temp to the next
            temp = temp->getNext();
            //update next to the next
            next = temp->getNext();
        }
    }
}


void chooseSortFunction(Double_list<StudentInfo> list[], int listNum, string listName[])
{
    //ask the users to choose the list that they want to sort
    int listIndex = listSelect(listNum, listName, -1);
    int input = -1;
    if (listIndex != -1)
    {
        if (!list[listIndex].empty())
        {
            while(!((input == 0) || (input == 1)))
            {
                //ask the user to choose if they want to sort by name or ID
                system("cls");
                cout << "**********************MENU***********************" << endl;
                cout << "Option 0: Sort by ID" << endl;
                cout << "Option 1: Sort by Name" << endl;
                cout << "*************************************************" << endl;
                cout << "Choose the option to add the list: ";
                cin >> input;
                //call out the sorting function accordingly
                if (input == 0)
                {
                    sortId(list[listIndex]);
                }
                else if (input == 1)
                {
                    sortName(list[listIndex]);
                }
                else //ask the user to input again if the input is incorrect
                {
                    cout << "Wrong Input, Please input it again correctly!!!" << endl;
                    system("pause");
                }
            }
            //display the message
            cout << "The list has been sorted successfully!!!" << endl;
        }
        else
        {
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\tThere is no any data in the list!!!" << endl;
            cout << "=========================================================================================================" << endl;
        }
        system("pause");
    }
}


void appendFunction(Double_list<StudentInfo> list[], int listNum, string listName[])
{
    int listIndex1 = listSelect(listNum, listName, 1);
    if (listIndex1 != -1)
    {
        int listIndex2 = listSelect(listNum, listName, 2);
        //list[listIndex1].append(list[listIndex2]);
        list[listIndex1] = list[listIndex1] + list[listIndex2];
        cout << "list" << listIndex1 + 1 << " has been appended successfully!!!" << endl;
        system("pause");
    }
}

bool updateName(Double_node<StudentInfo> *node, string name)
{
    if(node == NULL)
        return false; //node does not exist
    else  
    {
        (*node->getDataAddress()).setName(name); //set the new data
    }

    return true;
}

bool updateContact(Double_node<StudentInfo> *node, string contact)
{
    if(node == NULL)
        return false; //node does not exist
    else  
    {
        (*node->getDataAddress()).setContact(contact); //set the new data
    }

    return true;
}

bool updateGender(Double_node<StudentInfo> *node, char gender)
{
    if(node == NULL)
        return false; //node does not exist
    else  
    {
        (*node->getDataAddress()).setGender(gender); //set the new data
    }

    return true;
}

bool updateId(Double_node<StudentInfo> *node, string newId)
{
    if(node == NULL)
        return false; //node does not exist
    else  
    {
        (*node->getDataAddress()).setId(newId); //set the new data
    }

    return true;
}

bool updateAge(Double_node<StudentInfo> *node, int age)
{
    if(node == NULL)
        return false; //node does not exist
    else  
    {
        (*node->getDataAddress()).setAge(age); //set the new data
    }

    return true;
}

void update(Double_list<StudentInfo> studentList[], int listNum, string listName[])
{
    //Getting first list index by calling function "listSelect"
    int listIndex = listSelect(listNum, listName, -1);

    //check if there is exiting list. If there is no list, end the function.
    if(listIndex != -1)
    {

        if (!studentList[listIndex].empty())
        {
            //in order to update student info, the users first need to know the ID of student
            cout << "Input ID of the student that you want to update: ";
            string id;
            cin >> id;

            //Getting node pointer by calling function "searchId"
            Double_node<StudentInfo>* temp = searchId(studentList[listIndex], id);

            //Check wether ID is founded or not
            //Display the error message if ID not found
            if(temp == NULL)
            {
                cout << endl << "*************************************************" << endl;
                cout << "ID not found!!!" << endl;
            }
            else
            {
                int option = -1;

                //Looping until user input correct option
                while (!(option == 0 || option == 1 || option == 2 || option == 3 || option == 4))
                {
                    system("cls");
                    cout << "=========================================================================================================" << endl;
	                cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
                    cout << "---------------------------------------------------------------------------------------------------------" << endl;

                    //print founded student information after searching
                    temp->getData().print();

                    cout << "=========================================================================================================" << endl << endl;

                    //Prompt user to input the option, asking what student data that user want to update
                    cout << "**********************MENU***********************" << endl;
                    cout << "Option 0: Update name" << endl;
                    cout << "Option 1: Update ID" << endl;
                    cout << "Option 2: Update age" << endl;
                    cout << "Option 3: Update gender" << endl;
                    cout << "Option 4: Update contact" << endl;
                    cout << "*************************************************" << endl;
                    cout << "Input the option: ";
                    cin >> option;

                    //Checking user input, if user input option incorrectly, display error message
                    if (!(option == 0 || option == 1 || option == 2 || option == 3 || option == 4))
                    {
                        cout << "Wrong option input, please try input it again!!!" << endl;
                        system("pause");
                    }
                }
                    cin.ignore();
                bool updated;
                string name;
                string newId;
                int age;
                char gender;
                string contact;

                //Prompt user to input new student data (according to seleted option)
                switch (option)
                {
                    case 0:
                        cout << "Input new name: ";
                        getline(cin, name);
                        updated = updateName(temp, name);
                        break;
                    case 1:
                        cout << "Input new ID: ";
                        cin >> newId;
                        updated = updateId(temp, newId);
                        break;
                    case 2:
                        cout << "Input new age: ";
                        cin >> age;
                        updated = updateAge(temp, age);
                        break;
                    case 3:
                        cout << "Input new gender: ";
                        cin >> gender;
                        updated = updateGender(temp, gender);
                        break;
                    case 4:
                        cout << "Input new contact: ";
                        cin >> contact;
                        updated = updateContact(temp, contact);
                        break;
                    default:
                        break;
                }

                //Check wether update successful or not
                if(updated)
                {
                    //display the message
                    cout << endl << "*************************************************" << endl;
                    cout << "Updated Successfully!" << endl;
                }
                else
                {
                    //display the error message
                    cout << "Not updated!!! Problem encountered!" << endl;
                }
            }
            
        }
        else //if there is no data in the list, display error message
        {
            system("cls");
            cout << "=========================================================================================================" << endl;
	        cout << "|\tID\t|\t\tName\t\t|\tGender\t|\tage\t|\tContact\t\t|" << endl;
            cout << "---------------------------------------------------------------------------------------------------------" << endl;
            cout << "\t\tThere is no any data in the list!!!" << endl;
            cout << "=========================================================================================================" << endl;
        }
        system("pause");
    }
    
}

//This funnction can merge 2 diffent selected list and the same list.
void mergeFunction(Double_list<StudentInfo> list[], int listNum, string listName[])
{
    //Getting first list index by calling function "listSelect"
    int listIndex1 = listSelect(listNum, listName, 3);

    if (listIndex1 != -1)
    {
        //Getting second list index by calling function "listSelect"
        int listIndex2 = listSelect(listNum, listName, 4);

        //check if both selected are empty
        if ((listIndex1 == listIndex2 && list[listIndex2].empty()) || (listIndex1 != listIndex2 && list[listIndex1].empty() && list[listIndex2].empty()))
        {
            cout << "list: " << listName[listIndex1] << " can't be merge, since both list are empty!!!" << endl;
        }
        else
        {
            //merge 2 selected list by calling function "merge"
            list[listIndex1].merge(list[listIndex2]);
            //Display successful message
            cout << "list: " << listName[listIndex1] << " has been merged successfully!!!" << endl;
        }
        system("pause");
    }
}

//This function delete the selected list
void deleteFunction(Double_list<StudentInfo> list[], int& listNum, string listName[])
{
    //Getting list index by calling function "listSelect"
    int listIndex = listSelect(listNum, listName, -1);

    //check if there is exiting list. If there is no list, end the function.
    if (listIndex != -1)
    {
        //Delete the selected list by calling destructor "~Double_list("
        list[listIndex].~Double_list();

        //decrease the number of the list
        listNum--;

        //looping to fix list position in the array by copying data from the next list
        for (int i = listIndex; i < listNum; i++)
        {
            list[i] = list[i + 1];
            listName[i] = listName[i + 1];
        }

        //Delete the lastest list, since we've delete one list in array
        list[listNum].~Double_list();
        listName[listNum] = "";

        //Displlay successful message
        cout << "The list has been deleted successfully!!!" << endl;
        system("pause");
    }
}