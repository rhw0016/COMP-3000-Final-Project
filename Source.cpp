#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <array> 
#include <stdlib.h>
using namespace std;
int main()
{

    string workerData[4] = { "Names:", "Keel, james", "Smith, Will", "Joel, Billy" };
    //////////////////////////////////
    //Read Project Workers with index/
    //////////////////////////////////
    cout << "Worker Numbers:" << endl;
    int key = 1;
    int workerNumber = 1;
    while (key < 4)
    {
        cout << workerNumber << ". " << workerData[key] << " \n";//Needed to convert CVS to INT will only convert numbers
        key++;
        workerNumber++;
    }
    cout << endl;
    //
    //
    cout << "Project List:";
    cout << "\n+--------------------------------------------------------+\n";
    cout << "| Project |  Project Cost  |   J.K.  |   W.S.  |   B.J.  |";
    cout << "\n+--------------------------------------------------------+\n";
    ifstream myFile;
    myFile.open("projectList.csv");
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
            if (j == 0)
            {
                cout << "|    ";
            }

            cout << projectData[i][j] << "    |    ";

            if (j == 0)
            {
                cout << "  $";
            }

        }
        cout << "\n+--------------------------------------------------------+\n";
        ;
    }
    cout << "(A 1 implies the worker is working on the project, a 0 implies they are not working)\n";
//----------------------------------------------------------------------------------------------------------------------------------------------------------

    int totalBudget = 0;
    int budgetGoal = 100000;
    int budgetDiff = 0;
    string workerNames[4] = { "Names:", "Keel, James", "Smith, Will", "Joel, Billy" };
    int function;
    cout << "\nPlease choose a function by entering its number:";
    cout << "\n 1. Budget Report: Sums individual project costs and compares the sum to the total budget.";
    cout << "\n 2. Project Worker Report: Report the number of workers on a given project.";
    cout << "\n 3. General Project Table: Print a tabular report of the project and their workers.";
    cout << "\n 4. Toggle Worker: Add or remove a worker to or from a project.";
    cout << "\n 5. Project Cost Update: Allows the user to update the cost of a specified project.\n";
    cin >> function;
    switch (function)
    {
    case 1://------------------------ Sums project budgets and reports if over/under budget:
        totalBudget = (projectData[0][1] + projectData[1][1] + projectData[2][1]);
        if (totalBudget < budgetGoal)
            budgetDiff = budgetGoal - totalBudget;
        cout << "\nYou are under-budget. You have currently used $" << totalBudget << ". Your remaining budget is $" << budgetDiff << ".\n";
        if (totalBudget > budgetGoal)
        {
            budgetDiff = budgetGoal - totalBudget;
            cout << "\nYou are over budget by $" << budgetDiff << ".\n";
        }
        break;

    case 2:  //------------------------ Reports sum of workers on project:
        int project1Workers; int project2Workers; int project3Workers; int projectSelection;

        project1Workers = (projectData[0][2] + projectData[0][3] + projectData[0][4]);

        project2Workers = (projectData[1][2] + projectData[1][3] + projectData[1][4]);

        project3Workers = (projectData[2][2] + projectData[2][3] + projectData[2][4]);



        cout << "\nWhat project would you like to see the number of workers on? Please enter 1, 2, or 3. " << endl;

        cin >> projectSelection;



        switch (projectSelection) {

        case 1:

            cout << "There are " << project1Workers << " worker(s) on project 1." << endl;
            break;

        case 2:

            cout << "There are " << project2Workers << " worker(s) on project 2." << endl;
            break;

        case 3:

            cout << "There are " << project3Workers << " worker(s) on project 3." << endl;
            break;

        default:

            cout << "There isn't a project assigned that number. Please pick another number.";
            break;
        }
        break;

    case 3://------------------------ Report projects that each worker is on: 

        int workerSelection;

        cout << "\nWhat worker would you like to see the project report on? Please enter the number of the desired worker." << endl;

        cin >> workerSelection;

        switch (workerSelection)
        {
        case 1:
            cout << workerNames[1] << endl;
            cout << "Project Number:    1     2     3\n";
            cout << "Work Status:       " << projectData[0][2] << "     " << projectData[1][2] << "     " << projectData[2][2] << endl;
            break;

        case 2:
            cout << workerNames[2] << endl;
            cout << "Project Number:    1     2     3\n";
            cout << "Work Status:       " << projectData[0][3] << "     " << projectData[1][3] << "     " << projectData[2][3] << endl;
            break;

        case 3:
            cout << workerNames[3] << endl;
            cout << "Project Number:    1     2     3\n";
            cout << "Work Status:       " << projectData[0][4] << "     " << projectData[1][4] << "     " << projectData[2][4] << endl;
            break;

        default:
            cout << "There isn't a worker assigned that number. Please pick another number.";
            break;
        }
        break;


    case 4:  //-----------------------------------------------Toggle worker function
        int selectProject;
        int selectWorker;

        cout << "\nWhich project would you like to change the status of a worker within? " << endl;

        cin >> selectProject;



        switch (selectProject) {

        case 1:

            cout << "\nWhich worker would you like to switch the status of? " << endl;

            cin >> selectWorker;

            switch (selectWorker) {

            case 1:

                if (projectData[0][2] == 0)
                    projectData[0][2] = 1;

                else
                    projectData[0][2] = 0;

                break;

            case 2:

                if (projectData[0][3] == 0)
                    projectData[0][3] = 1;

                else
                    projectData[0][3] = 0;

                break;

            case 3:

                if (projectData[0][4] == 0)
                    projectData[0][4] = 1;

                else
                    projectData[0][4] = 0;

                break;

            default:
                cout << "There isn't a worker assigned that number. Please pick another number.";
                break;

            }



            break;

        case 2:

            cout << "\nWhich worker would you like to switch the status of? " << endl;

            cin >> selectWorker;

            switch (selectWorker) {

            case 1:

                if (projectData[1][2] == 0)
                    projectData[1][2] = 1;

                else
                    projectData[1][2] = 0;

                break;

            case 2:

                if (projectData[1][3] == 0)
                    projectData[1][3] = 1;

                else
                    projectData[1][3] = 0;

                break;

            case 3:

                if (projectData[1][4] == 0)
                    projectData[1][4] = 1;

                else
                    projectData[1][4] = 0;

                break;

            default:
                cout << "There isn't a worker assigned that number. Please pick another number.";
                break;
            }

            break;

        case 3:

            cout << "\nWhich worker would you like to switch the status of? " << endl;

            cin >> selectWorker;

            switch (selectWorker) {

            case 1:

                if (projectData[2][2] == 0)
                    projectData[2][2] = 1;

                else
                    projectData[2][2] = 0;

                break;

            case 2:

                if (projectData[2][3] == 0)
                    projectData[2][3] = 1;

                else
                    projectData[2][3] = 0;

                break;

            case 3:

                if (projectData[2][4] == 0)
                    projectData[2][4] = 1;

                else
                    projectData[2][4] = 0;

                break;

            default:
                cout << "There isn't a worker assigned that number. Please pick another number. ";
                system("pause");
                system("CLS");
                main();
                break;

            }
            break;

        default:
            cout << "There isn't a project assigned that number. Please pick another number. ";
            system("pause");
            system("CLS");
            main();
            break;

        }
        break;

    case 5:
        int selectCost;
        int updatedCost;

        cout << "\nWhich project cost would you like to edit?" << endl;
        cin >> selectCost;

        switch (selectCost) {
        case 1:
            cout << "\nWhat is the updated cost? " << endl;
            cin >> updatedCost;
            projectData[0][1] = updatedCost;
            break;

        case 2:
            cout << "\nWhat is the updated cost? " << endl;
            cin >> updatedCost;
            projectData[1][1] = updatedCost;
            break;

        case 3:
            cout << "\nWhat is the updated cost? " << endl;
            cin >> updatedCost;
            projectData[2][1] = updatedCost;
            break;

        default:
            cout << "That project does not exist. Please pick another number.";
            break;
        }
        break;

    default:
        cout << "There isn't a function assigned that number. Please pick another number. ";
        break;
    }



    //---------------------------------------------------------------------------------------------------------------------------------------------------------

       ////////////////////////////////////////////////////
       //--------------Write projectData to outputFile--///
       ////////////////////////////////////////////////////
                                                         // 
           // Create an output filestream object         //
    std::ofstream writeFile("projectList.csv");          //
                                                         //
    // Send data to the stream                           //
    int  icount = 0;                                     //
    i = 0;                                               //
    while (i < 3)                                        //
    {                                                    //
        j = 0;                                           //
        while (j < 5)                                    //
        {                                                //
            if (icount > 13)                             //
            {                                            //
                writeFile << projectData[i][j];          //
                break;                                   //
            }                                            //
            writeFile << projectData[i][j] << ",";       //
            j++;                                         //
            icount++;                                    //
        }                                                //      
        i++;                                             //
    }                                                    //
    j = 0;                                               //
    i = 0;                                               //                                                    
    // Close the file                                    //
    writeFile.close();                                   //
                                                         //
    cout << "\nChanges Saved\n\n";                       //
///////////////////////////////////////////////////////////
    system("pause"); //wait so user can read output from above options
    system("CLS"); //clears window for next iteration of main
    main(); //re-runs main so you dont have to restart
}
