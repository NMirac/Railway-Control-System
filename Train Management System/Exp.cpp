#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include "Exp.h"
#include "Train.h"
#include "Alg.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";
Alg Alg;

void Exp::addExp()
{
	bool ProgramIsOpened = true;
	int answer;
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	while(ProgramIsOpened){
        int qstate = 0;
		
		cout<<"Enter Expendition ID: ";
        cin>>Exp_ID;
        cin.ignore(100, '\n');
        
        cout<<"Enter Start Point: ";
        cin.getline(Start,44,'\n');
        //cin.ignore(44,'\n');
        
       // city = Start;
        
        cout<<"Enter Destination: ";
        cin.getline(Destination,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Date: ";
		cin.getline(Date, 11, '\n');
				
		cout<<"Time: ";
		cin.getline(Time, 9, '\n');
				
		//cout<<"Train: ";
		//cin>>Train;
		//cin.ignore(100, '\n');
        
        Seat=60;
		cout << "Empty Seats: "<<Seat<<endl;
		
		Conducter = Alg.pickCond();
		Machinist = Alg.pickMach();
		Hostess = Alg.pickHostess();
		Train = Alg.pickTrain(Start);
		
		
        stringstream ss;
        ss<<"INSERT INTO Expendition(Exp_ID, Date, Time, Start, Destination, Train, Seat, Conducter, Machinist, Hostess) VALUES('"<<Exp_ID<<"','"<<Date<<"','"<<Time<<"','"<<Start<<"','"<<Destination<<"','"<<Train<<"','"<<Seat<<"','"<<Conducter<<"','"<<Machinist<<"','"<<Hostess<<"')";
		
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        this->revExp(Exp_ID, Date, Time, Start, Destination, Train, Seat, Conducter, Machinist, Hostess);
        
        
        
        if(qstate == 0){
        this->checkExp(Exp_ID);
        cout<<endl;
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
	
	
void Exp::revExp(int Exp_ID,char* Date,char* Time,char* Start,char* Destination,char* Train,int Seat, char* Conducter, char* Machinist, char* Hostess)
	{
	/*bool ProgramIsOpened = true;
	//int answer;
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);*/
    if(obj){
    //while(ProgramIsOpened){
    int qstate = 0;
    Exp_ID+=1;
	
        stringstream ss;
        ss<<"INSERT INTO Expendition(Exp_ID, Date, Time, Start, Destination, Train, Seat, Conducter, Machinist, Hostess) VALUES('"<<Exp_ID<<"','"<<Date<<"','"<<Time<<"','"<<Destination<<"','"<<Start<<"','"<<Train<<"','"<<Seat<<"','"<<Conducter<<"','"<<Machinist<<"','"<<Hostess<<"')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Reverse created correctly."<<endl;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj)<<endl;

        }
        /*cout<<endl<<"Another?"<<endl;
		cout<<"[1]: Yes" <<endl;
		cout<<"[0]: No" <<endl;
		cout<<"Answer: " <<endl;
		cin>>answer;
		cin.ignore(100, '\n');
		if (answer == 0)
		{
		ProgramIsOpened = false;
		}*/
		//}
	}
		else{
        cout<<"NO CONNECTION"<<endl;
   		}
   	}   		

void Exp::editExp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;

        cout<<"Enter Expendition ID: ";
        cin>>Exp_ID;
        
		cout << "Enter Start Point: ";
        cin.getline(Start,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Enter Destination: ";
        cin.getline(Destination,44,'\n');
        //cin.ignore(44,'\n');
        
        cout<<"Date: ";
		cin.getline(Date, 11, '\n');
				
		cout<<"Time: ";
		cin.getline(Time, 9, '\n');
				
		cout<<"Train: ";
		cin>>Train;
		cin.ignore(100, '\n');
        
        
		cout<<"Empty Seats: ";
		cin>>Seat;
		cin.ignore(100, '\n');

        stringstream ss;
        ss<<"UPDATE `management`.`expendition` SET `Start` = '"<<Start<<"', `Destination` = '"<<Destination<<"', `Date` = '"<<Date<<"', `Time` = '"<<Time<<"', `Train` = '"<<Train<<"', `Seat` = '"<<Seat<<"' WHERE (`Exp_ID` = '"<<Exp_ID<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Info edited correctly."<<endl;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj)<<endl;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
   		 }
}

void Exp::delExp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
		int qstate=0;
        string Exp_ID;
        
        cout<<"Enter Expendition ID: ";
        cin>>Exp_ID;
        stringstream ss;
        ss<<"DELETE FROM expendition where Exp_ID ='"+Exp_ID+"'";
            
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
         if(qstate == 0){
            cout<<"Info deleted correctly."<<endl;
        }
		else{
            cout<<"ERROR: "<<mysql_error(obj)<<endl;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
   		 }
}


void Exp::showExp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int qstate = mysql_query(obj, "SELECT * FROM expendition ");

        if(!qstate){
            res = mysql_store_result(obj);

            while(row = mysql_fetch_row(res)){
                cout<<row[0]<<"|" <<row[1]<<"	|	" <<row[2]<<"	|	" <<row[3]<<"	|	" <<row[4]<<"	|	" <<row[5]<<"	|	" <<row[6]<<endl<<endl;
             }
        }
    }
    
    int chh;	
    while(chh != 4)
    {
   	cout<<"                      [1] ADD EXPENDITION        \n"<<endl;
	cout<<"                      [2] DELETE EXPENDITION     \n"<<endl;
	cout<<"                      [3] INFO EXPENDITION       \n"<<endl;
	cout<<"                      [4] BACK                   \n"<<endl;
	cin>>chh;
	switch(chh)
	{
		case 1:
			addExp();
			break;
			case 2:
				delExp();
				break;
				case 3:
					infoExp();
					break;
				case 4:
				system("cls");
						getch();
						break;
				
}
	}

}

void Exp::infoExp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        string Exp_ID;
        
        cout<<"Enter Expendition ID : ";
        cin>>Exp_ID;
        stringstream ss;
        ss<<"SELECT * FROM expendition where Exp_ID ='"+Exp_ID+"'";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
        res=mysql_store_result(obj);
            	
        while(row = mysql_fetch_row(res)){
        	
		
        cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|" <<row[4]<<"|" <<row[5]<<"|" <<row[6]<<"|" <<row[7]<<"|" <<row[8]<<"|" <<row[9]<<endl<<endl;
       }
   }
}

void Exp::checkExp(int id)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        

        stringstream ss;
        ss<<"SELECT * FROM expendition where Exp_ID ='"<<id<<"'";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
        res=mysql_store_result(obj);
            	
        while(row = mysql_fetch_row(res)){
        	
		
       cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<"|" <<row[3]<<"|" <<row[4]<<"|" <<row[5]<<"|" <<row[6]<<"|" <<row[7]<<"|" <<row[8]<<"|" <<row[9]<<endl<<endl;
       }
   }
}


