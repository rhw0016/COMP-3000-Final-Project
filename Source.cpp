#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector> 
#include <array> 
#include <stdlib.h>
using namespace std;
////
////void writeCVSLoop()
////{
////    // Create an output filestream object
////    std::ofstream myFile("fooLoop.csv");
////
////    // Send data to the stream
////    int i = 0;
////
////    while (i<6)
////    {
////        myFile <<pow(2,i)<<",";
////        i = i + 1;
////    }    
////    // Close the file
////    myFile.close();
////    cout << "A Different File was also written"<<endl<<"It must be search in the Project folder"<<endl ;
////}
////void readSaveCVS()
//{
//
//    ifstream myFile;
//    myFile.open("Budget.csv"); //Save this to a CSV Comma delim>>>>> 1,1000,100,10,1,2,2000,200,20,2,3,3000,300,30,3
//    int projectData[3][5];
//    int i = 0;
//    int j = 0;
//
//    while (myFile.good())
//    {
//        string line;
//        getline(myFile, line, ',');
//
//        projectData[i][j] = stoi(line);//Needed to convert CVS to INT will only convert numbers
//        j++;
//        if (j == 5) {
//            i++;
//            j = 0;
//        }
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 5; j++)
//        {
//            cout << projectData[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//}
//
//


int main() 
{


    string workerData[4] = { "Names","Bob", "Dylan", "Chad" };
    //------------------------------------------------
    //Read Project Workers with index
    cout << "Printed Worker List" << endl;
    int key = 1;


    while (key < 4)
    {
        cout << "        "<<workerData[key]<<" " ;//Needed to convert CVS to INT will only convert numbers
        key++;
    }
    cout << endl;

   


    //--------------------------------------------------------------
 
    //readSaveCVS();
    //---------------------------------------------------------------
    cout << "\nPrinted Project List \n";
    ifstream myFile;
    myFile.open("projectList.csv"); //Save this to a CSV Comma delim>>>>> 1,1000,100,10,1,2,2000,200,20,2,3,3000,300,30,3
    int projectData[3][5];
    int i = 0;
    int j = 0;

    while (myFile.good())
    {
        string line;
        getline(myFile, line, ',');

        projectData[i][j] = stoi(line);//Needed to convert CVS to INT will only convert numbers
        j++;
        if (j == 5) {
            i++;
            j = 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << projectData[i][j] << " ";
        }
        cout << endl;
    }

    //---------------------------------------------------------------
    //Find a way to use projectData[][] outside of readSaveCVS function
    //cout << endl << "Writing a different CVS" << endl;
    //writeCVSLoop();
   // readString();

    int totalBudget = 0;
    int budgetGoal = 100000;
    int budgetDiff = 0;
    totalBudget = (projectData[0][1] + projectData[1][1] + projectData[2][1]);
    if (totalBudget < budgetGoal)
        budgetDiff = budgetGoal - totalBudget;
    cout << "You are under-budget. You have currently used $" << totalBudget << ". Your remaining budget is $" << budgetDiff << endl;
    if (totalBudget > budgetGoal)
    {
        budgetDiff = budgetGoal - totalBudget;
        cout << "You are over budget by $" << budgetDiff << endl;
    }



}
