#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "Emp.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";




void Emp::addEmp()
{
	bool ProgramIsOpened = true;
	int answer;
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	while(ProgramIsOpened){
        int qstate = 0;
		
		cout<<"Enter Employee ID: ";
        cin>>Emp_ID;
        cin.ignore(100, '\n');
        
        cout<<"Enter Name: ";
        cin.getline(Name,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Enter Surname: ";
        cin.getline(Surname,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Enter Job: ";
        cin.getline(Job,44,'\n');
        //cin.ignore(44,'\n');
        
		Shift=0;
		cout<<"Shift: "<<Shift;
        cin.ignore(100, '\n');
				

        stringstream ss;
        ss<<"INSERT INTO employee(Emp_ID, Name, Surname, Job, Shift) VALUES('"<<Emp_ID<<",'"<<Name<<"','"<<Surname<<"',"<<Job<<"',"<<Shift<<"')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Info added correctly."<<endl;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj)<<endl;

        }
        cout<<endl<<"Another?"<<endl;
		cout<<"[1]: Yes" <<endl;
		cout<<"[0]: No" <<endl;
		cout<<"Answer: " <<endl;
		cin>>answer;
		cin.ignore(100, '\n');
		if (answer == 0)
		{
		ProgramIsOpened = false;
		}
		cout<<endl;
		}
	}
		else{
        cout << "NO CONNECTION" << endl;
   		 }
   		
	}


void Emp::editEmp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;

        cout<<"Enter Employee ID: ";
        cin>>Emp_ID;
        
		cout<<"Enter Name: ";
        cin.getline(Name,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Enter Surname: ";
        cin.getline(Surname,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Enter Job: ";
        cin.getline(Job,44,'\n');
        //cin.ignore(44,'\n');
        
 		cout<<"Enter Shift: ";
        cin>>Shift;
        cin.ignore(100, '\n');
				
		
        stringstream ss;
        ss<<"UPDATE `management`.`employee` SET `Name` = '"<<Name<<"', `Surname` = '"<<Surname<<"', `Job` = '"<<Job<<"', `Shift` = '"<<Shift<<"' WHERE (`Emp_ID` = '"<<Emp_ID<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Info added correctly."<<endl;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj) << endl;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
   		 }
}

void Emp::delEmp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
		int qstate=0;
        string Emp_ID;
        
        cout<<"Enter Employee ID: ";
        cin>>Emp_ID;
        stringstream ss;
        ss<<"DELETE FROM employee where Emp_ID ='"+Emp_ID+"'";
            
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
         if(qstate == 0){
            cout<<"Info added correctly." <<endl;
        }
		else{
            cout<<"ERROR: " << mysql_error(obj) << endl;
        }
   		}
		else{
        cout<<"NO CONNECTION" << endl;
   		 }
}


void Emp::showEmp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int qstate = mysql_query(obj, "SELECT * FROM employee ");

        if(!qstate){
            res = mysql_store_result(obj);

            while(row = mysql_fetch_row(res)){
                cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|" <<row[4]<<endl<<endl;
             }
        }
    }
    
    int c;	
    while(c != 5)
    {
    cout<<"                      [1] ADD EMPLOYEES         \n"<<endl;
	cout<<"                      [2] DELETE EMPLOYEES          \n"<<endl;
	cout<<"                      [3] EDIT EMPLOYEES                  \n"<<endl;
	cout<<"                      [4] INFO EMPLOYEES                  \n"<<endl;
	cout<<"                      [5] BACK                    \n"<<endl;

	cin>>c;
	switch(c)
	{
		case 1:
			addEmp();
			break;
			case 2:
				delEmp();
				break;
				case 3:
					editEmp();
					break;
				case 4:
					infoEmp();
					break;	
					case 5:
						system("cls");
						getch();
					break;
					default:
				
	getch();
}
	}

}

void Emp::infoEmp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        string Emp_ID;
        
        cout<<"Enter Employee ID : ";
        cin>>Emp_ID;
        stringstream ss;
        ss<<"SELECT * FROM employee where Emp_ID ='"+Emp_ID+"'";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
        res=mysql_store_result(obj);
            	
        while(row = mysql_fetch_row(res)){
        	
		
        cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|" <<row[4]<<endl<<endl;
       }
   }
}



