#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "Passenger.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";




void Passenger::bookTicket()
{
	bool ProgramIsOpened = true;
	int answer;
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	while(ProgramIsOpened){
        int qstate = 0;
		
		cout<<"Enter Phone Number: ";
        cin.getline(Phone,11,'\n');
        cin.ignore(11,'\n');
        
        cout<<"Enter Name: ";
        cin.getline(Name,44,'\n');
        cin.ignore(44,'\n');
        
        cout<<"Enter Surname: ";
        cin.getline(Surname,44,'\n');
        cin.ignore(44,'\n');
        
        cout<<"Choose Your Expendition: ";
        cin>>Exp;
        cin.ignore(100, '\n');
        
        cout<<"How Many Tickets Do You Want: ";
		cin>>Ticket;
        cin.ignore(100, '\n');

        stringstream ss;
        ss<<"INSERT INTO passenger(Phone, Name, Surname, Exp, Ticket) VALUES('"<<Phone<<",'"<<Name<<"','"<<Surname<<"',"<<Exp<<"',"<<Ticket<<"')";

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
        cout<<"NO CONNECTION"<<endl;
   		 }
   		
	}


void Passenger::editTicket()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;

		cout<<"Enter Phone Number: ";
        cin.getline(Phone,11,'\n');
        cin.ignore(11,'\n');
        
        cout<<"Enter Name: ";
        cin.getline(Name,44,'\n');
        cin.ignore(44,'\n');
        
        cout<<"Enter Surname: ";
        cin.getline(Surname,44,'\n');
        cin.ignore(44,'\n');
        
        cout<<"Choose Your Train: ";
        cin>>Exp;
        cin.ignore(100, '\n');
        
        cout<<"How Many Tickets Do You Want: ";
		cin>>Ticket;
        cin.ignore(100, '\n');
				
		
        stringstream ss;
        ss<<"UPDATE `management`.`passenger` SET `Name` = '"<<Name<<"', `Surname` = '"<<Surname<<"', `Exp` = '"<<Exp<<"', `Ticket` = '"<<Ticket<<"' WHERE (`Phone` = '"<<Phone<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Info added correctly."<<endl;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj)<<endl;
        }
   		}
		else{
        cout <<"NO CONNECTION"<<endl;
   		 }
}

void Passenger::delTicket()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
		int qstate=0;
        string Phone;
        
        cout<<"Enter Phone: ";
        cin >> Phone;
        stringstream ss;
        ss<<"DELETE FROM passenger where Phone ='"+Phone+"'";
            
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
         if(qstate == 0){
            cout<<"Info added correctly."<<endl;
        }
		else{
            cout<<"ERROR: "<<mysql_error(obj)<<endl;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
   		 }
}


void Passenger::showTicket()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int qstate = mysql_query(obj, "SELECT * FROM passenger ");

        if(!qstate){
            res = mysql_store_result(obj);

            while(row = mysql_fetch_row(res)){
                cout<<row[0]<<"\t|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|"<<row[4]<<endl<<endl;
             }
        }
    }
    
    int ch;	
    while(ch != 5){
    cout<<"                      [1] BOOK TICKET      \n"<<endl;
	cout<<"                      [2] DELETE TICKET         \n"<<endl;
	cout<<"                      [3] INFO TICKET          \n"<<endl;
	cout<<"                      [4] EDIT TICKET                  \n"<<endl;
	cout<<"                      [5] BACK                \n"<<endl;

	cin>>ch;
	switch(ch)
	{
		case 1:
			bookTicket();
			break;
			case 2:
				delTicket();
				break;
				case 3:
					infoTicket();
					break;
				case 4:
					editTicket();
					break;
					case 5:
						system("cls");
						getch();
						break;
				
	getch();
}
	}

}

void Passenger::infoTicket()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        string Phone;
        
        cout<<"Enter Phone : ";
        cin>>Phone;
        stringstream ss;
        ss<<"SELECT * FROM passenger where Phone ='"+Phone+"'";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
        res=mysql_store_result(obj);
            	
        while(row = mysql_fetch_row(res)){
        	
		
        cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|" <<row[4]<<endl<<endl;
       }
   }
}



