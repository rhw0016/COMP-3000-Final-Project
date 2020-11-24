#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <array> 
using namespace std;

void writeCVSLoop()
{
    // Create an output filestream object
    std::ofstream myFile("fooLoop.csv");

    // Send data to the stream
    int i = 0;

    myFile << "Foo\n";
    while (i<6)
    {
        myFile <<pow(2,i)<<"\n";
        i = i + 1;
    }    
    // Close the file
    myFile.close();
    cout << "A Different File was also written"<<endl<<"It must be search in the Project folder"<<endl ;
}
void readSaveCVS()
{

    ifstream myFile;
    myFile.open("Budget.csv"); //Save this to a CSV Comma delim>>>>> 1,1000,100,10,1,2,2000,200,20,2,3,3000,300,30,3
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
}

int main() 
{

    cout << "Reading CVS File..." << endl;
    readSaveCVS();
 
    //Find a way to use projectData[][] outside of readSaveCVS function
    cout << endl << "Writing a different CVS" << endl;
    writeCVSLoop();
}