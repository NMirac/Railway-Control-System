#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "Train.h"
#include "Exp.h"
#include "Emp.h"
#include "Passenger.h"
#include "Alg.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 
const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";

Train Train;
Exp Exp;
Emp Emp;
//Alg Alg;
Passenger Passenger;
int main()
{	
	int choice;
	
	while(choice != 5)
{
	cout<<"**********WELCOME TRAIN MANAGEMENT SYSTEM**********\n";
	getch();
	
	cout<<"\n\t\t\t[1] TRAIN MENU \n";
	cout<<"\n\t\t\t[2] EXPENDITION MENU \n";
	cout<<"\n\t\t\t[3] PASSENGER MENU \n";
	cout<<"\n\t\t\t[4] EMPLOYEES MENU \n";
	cout<<"\n\t\t\t[5] EXIT\n";

	cin>>choice;
 	
	 
	switch(choice){
	 	
	case 1:
	{
	Train.showTrain();
	break;
	}
	
	case 2:
	{
	Exp.showExp();
	break;
	}

	case 3:
	{
	Passenger.showTicket();
	break;
	}
	
	case 4:
	{
	Emp.showEmp();
	}
	case 5:
	{
	cout<<"Thanks to using Train management system"<<endl;
	break;
	}
}
}
	/*while(choice != 5)
{
	cout<<"\n\t\t\t[1] ADD TRAIN\n";
	cout<<"\n\t\t\t[2] SHOW TRAIN\n";
	cout<<"\n\t\t\t[3] ADD EXPENDITION\n";
	cout<<"\n\t\t\t[4] BACK\n";
	cin>>choice;
 	
	 
	switch(choice){
	 	
	case 1:
	{
	Passenger.infoTicket();
	break;
	}
	
	case 2:
	{
	Train.showTrain();
	Train.delTrain();
	Train.showTrain();
	break;
	}

	case 3:
	{
	Exp.addExp();
	break;
	}
	case 4:
	{
	//Alg.pickCond();
	}
}
}*/
}

