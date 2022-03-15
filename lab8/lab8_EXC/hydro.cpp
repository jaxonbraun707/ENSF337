//hydro.cpp
//ENSF 337 Lab 8 Exercise C
//Created by: Jaxon Braun

#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
#include "hydro.h"
#include "list.h"
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"

int main(){
    FlowList data; 
    const char* infile = "flow.txt"; //will need to alter file name if flow.txt is in a diectory different from directory program is compilled in at terminal
    displayHeader();
    readData(infile, data);

    int quit = 0;

    while (1)
    {
        switch(menu()){
            case 1:
                display(data);
                pressEnter();
                break;
            case 2:
                addData(data);
                pressEnter();
                break;
            case 3:
                saveData(infile, data);
                pressEnter();
                break;
            case 4:
                removeData(data);
                pressEnter();
                break;
            case 5:
                cout << "\nProgram Terminated!\n\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a Valid Input.\n";
                pressEnter();
                
        }
        if(quit == 1) break;
    }

    return 0;
}

void pressEnter(){
    cout << "\n<<<< Press Enter to Continue >>>>\n";
    cin.get();
    cin.ignore();   //added so it would actually pause for input 
                    //after first pressEnter call in main, but 
                    //now 2 enter presses are required on first use of pressEnter()
}

void displayHeader(){
    cout << "Program: Flow Studies - Fall 2021" << endl;
    cout << "Version: 1.0" << endl;
    cout << "Lab Section: B01" << endl;
    cout << "Produced by: Jaxon Braun" << endl;
    pressEnter();
}

int menu(){
    int user_input = 0;
    cout << "\nPlease Select An Operation:" << endl;
    cout << "1.\tDisplay Flow List, and the Average" << endl;
    cout << "2.\tAdd Data" << endl;
    cout << "3.\tSave Data Into the File" << endl;
    cout << "4.\tRemove Data" << endl;
    cout << "5.\tQuit" << endl;
    cout << "Enter Your Choice (1, 2, 3, 4, or 5):" << endl;
    cin >> user_input;
    return user_input;

}

void readData(const char* infile, FlowList &data){
    int year_tmp = 0;
    int flow_tmp = 0;
    ListItem ListItem_tmp;
    ifstream inData;
    inData.open(infile);
    if (inData.fail()) {
        cout << "Error: cannot open the file" << infile << endl;
        exit(1);
    }
    while (! inData.eof()){
        inData >> ListItem_tmp.year >> ListItem_tmp.flow;
        data.insert(ListItem_tmp);
    }
    inData.close();
}

double average(FlowList &data){
    double sum = 0;
    if (data.ptr != 0){
        for (const Node *p = data.ptr; p != 0; p = p->next)
            sum += p->item.flow;
    }
    double ave = sum / data.record_count;
    return ave;
}

void display(FlowList &data){
    cout << UNDERLINE << "Year\t" << CLOSEUNDERLINE << UNDERLINE << "Flow (in billions of cubic meters)" << CLOSEUNDERLINE << endl;
    data.print();
    cout <<  "\nNumber of Data Points: " << data.record_count;
    cout << "\nThe annual average of the flow is: " << average(data) << " billions of cubic meters" << endl;
}

void addData(FlowList &data){
    ListItem new_data_point;
    cout << "Please Enter a Year: ";
    cin >> new_data_point.year;
    cout << "Please Enter the flow: ";
    cin >> new_data_point.flow;
    if (data.searchForYear(new_data_point)){
        cout << "Error: Duplicate Data" << endl;
    }
    else{
        data.insert(new_data_point);
        cout << "New Record Inserted Successfully" << endl;
    }
}

void removeData(FlowList &data){
    ListItem doomed_data_point;
    cout << "Please Enter a Year to Remove it's Record: ";
    cin >> doomed_data_point.year;
    if (data.searchForYear(doomed_data_point)){
        data.remove(doomed_data_point);
        cout << "Record was successfully removed" << endl;
    }
    else
        cout << "Error: No such data with that year on record" << endl;
}

void saveData(const char* outfile, FlowList &data){
    ofstream outData;
    outData.open(outfile);
    if (! outData){
        cout << "Error: cannot open the file " << outfile << endl;
        return;
    }
    for (const Node *p = data.ptr; p != 0; p = p->next)
        outData << p->item.year << "\t" << p->item.flow << endl;
    outData.close();
    cout << "Data is saved into the file " << outfile << endl;
}