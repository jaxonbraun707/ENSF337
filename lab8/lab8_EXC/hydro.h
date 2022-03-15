//hydro.h
//ENSF 337 Lab 8 Exercise C
//Created by: Jaxon Braun

#ifndef HYDRO_H
#define HYDRO_H
#include "list.h"

void displayHeader();
//PROMISES: Displays introductory header

void readData(const char* infile, FlowList &data);
//PROMISES: Reads data from flow.txt text file 
//          Places data into linked list in ascending order by year
//          by using FlowList member function insert
//          Updates the record_count, which is part of the FlowList object
//          I felt having the record_count be a part of the FlowList Object made more sense

int menu();
//Promises: To display the main menu and return the user's choice

void display(FlowList &data);
//Promises: Displays years and flows in the linked list
//          shows the average of the flow in the list

void addData(FlowList &data);
//Promises: prompts user for new data entry
//          inserts data into list
//          updates the number of records

void removeData(FlowList &data);
//Promises: prompts user for the year they would like removed from list
//          only removes a single record
//          updates the number of records

double average(FlowList &data);
//Promises: calculates and returns the average flow for records in list

void saveData(const char* outfile, FlowList &data);
//Promises: opens flow.txt file 
//          writes the data from the list into the text file

void pressEnter();
//Promises: Displays the <<<<Press Enter to Continue>>>>, and waits for user input
//          returns after user input <Return Key> is detected

#endif