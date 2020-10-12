# COMP-3000-Final-Project
final project

# Description: 
This is a project management system for engineering teams. 

The system will:

Track project workers by reading Project List and Worker List 
      - Overwrite/Update/Add Project/workers

Calculate if a program is over or under budget - use sub-task estimates of budget required

Calculate the estimated completion dates based off of sub-task lengths

Return how many workers are on a project

Return what project a worker is on


# Functions: 
Class "Project" with a constructor that accepts x arguments, use array "projarr" of y number of "Project" objects (also with x arguments, here x = 2)
      
      Project projarr[y=3] = {Project(A,B), Project(A,B), Project(A,B)};
      
Nest constructors/classes in order to create projects with sub tasks?

reads in a file until the end

sum sub-task budgets for project budgets and compare to budget goal, returns bool value true/false if under/over budget

sum number of workers on project and track with "Project" object

make the project name string be the first object - return first object for project name. If asked what project(s) a person is on, check array of strigs (peoples names) with == and output...

^^^ above comments made on loose understanding of how classes/constructors work. Needs work to flesh out. 

---------------------------------------------
Alex Cardona's pseudo code:

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
int pF="Project File.txt"
int nF="Name File.txt"

int readFile(Name)
{
	return //Something
}

bool budgetCalc
{
readFile(pF)
//Do some math

if (cost > budget)
	{

	return False
	}
else
{
	return True
} 
}

int projectWorker()
{
	readFile(nF)
	//Check who is true for each project 
	//Count trues in each project name
	// List Names
}

int main()
{

	//Ask the user what to do
	// Calculate Budget = 1
	// Who is working on a project =2

	switch (option)
	{
	case 1:
		//Pick a Project Name
		budgetCalc("Project Name");

	case 2:
		projectWorker("Project Name")
	}
}

-------------------
Robert Waudby's pseudo code:

class Project
{
public:
bool budgetCalc(string); //string is project name?
int projectWorkers(string); //string is project name?

private:
int score;
}; 

//member functions
bool Project::budgetCalc(string A)
{
readFile(pF)
	//Do some math
if (cost > budget)
{
return False
}
else
{
return True
}
}

      
      
# Empathy Map:
![Empathy Map Link](https://github.com/rhw0016/COMP-3000-Final-Project/blob/master/Empathy%20Map.docx)

![Empathy Map Download](https://github.com/rhw0016/COMP-3000-Final-Project/raw/master/Empathy%20Map.docx)
