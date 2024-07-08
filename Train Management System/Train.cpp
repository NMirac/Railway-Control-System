#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include "Train.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";




void Train::addTrain()
{
	bool ProgramIsOpened = true;
	int answer;
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	while(ProgramIsOpened){
        int qstate = 0;
		
		cout<<"Enter Train ID: ";
        cin>>Train_ID;
        
        cout<<"Enter City: ";
        cin.getline(City,44,'\n');
        cin.ignore(44,'\n');
        
        Repair=0;
		cout << "Check Up: "<<Repair<<endl;

        stringstream ss;
        ss<<"INSERT INTO train(Train_ID, City, Repair) VALUES('"<<Train_ID<<"','"<<City<< "','" <<Repair<<"')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
            cout<<"Info added correctly."<<endl;
        }
		else{
            cout<<"ERROR:"<<mysql_error(obj)<<endl;
			//cout << "Press B to go back";
    		//cin >> dummy;
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
        //cout << "Press B to go back";
    	//cin >> dummy;
   		 }
   		
	}


void Train::editTrain()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;

        cout << "Enter Train ID: ";
        cin >> Train_ID;
        
        cout << "Enter City: ";
        cin.getline(City,44,'\n');
        cin.ignore(44,'\n');
        
        
		cout << "Check Up: ";
		cin>>Repair;

        stringstream ss;
        ss<<"UPDATE `management`.`train` SET `City` = '"<<City<<"', `Repair` = '"<<Repair<<"' WHERE (`Train_ID` = '"<<Train_ID<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
        if(qstate == 0){
        cout<<"Info edited correctly."<<endl;
        //cout << "Press B to go back";
    	//cin >> dummy;
        }
		else{
        cout<<"ERROR:"<<mysql_error(obj)<<endl;
       // cout << "Press B to go back";
    	//cin >> dummy;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
        //cout << "Press B to go back";
    	//cin >> dummy;
   		 }
}

void Train::delTrain()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
		int qstate=0;
        string Train_ID;
        
        cout << "Enter Train ID: ";
        cin >> Train_ID;
        stringstream ss;
        ss<<"DELETE FROM train where Train_ID ='"+Train_ID+"'";
            
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
         if(qstate == 0){
            cout<<"Info deleted correctly."<<endl;
            //cout << "Press B to go back";
    	//cin >> dummy;
        }
		else{
            cout<<"ERROR: "<<mysql_error(obj)<<endl;
            //cout << "Press B to go back";
    	//cin >> dummy;
        }
   		}
		else{
        cout<<"NO CONNECTION"<<endl;
        //cout << "Press B to go back";
    	//cin >> dummy;
   		 }
}


void Train::showTrain()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int qstate = mysql_query(obj, "SELECT * FROM train ");

        if(!qstate){
            res = mysql_store_result(obj);

            while(row = mysql_fetch_row(res)){
                cout<<row[0]<<"|" <<row[1]<<"|" <<row[2]<<endl<<endl;
             }
        }
    }
    
        int chhh;	
    while(chhh != 4)
    {	    
	cout<<"                      [1] ADD TRAIN      \n"<<endl;
	cout<<"                      [2] DELETE TRAIN         \n"<<endl;
	cout<<"                      [3] INFO TRAIN          \n"<<endl;
	cout<<"                      [4] BACK                  \n"<<endl;
	cin>>chhh;
	switch(chhh)
	{
		case 1:
			addTrain();
			break;
			case 2:
				delTrain();
				break;
				case 3:
					infoTrain();
					break;
					case 4:
						system("cls");
						getch();
						break;
				
	getch();
}
	}
    //cout << "Press B to go back";
    //cin >> dummy;
}

void Train::infoTrain()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        string Train_ID;
        
        cout<<"Enter Train ID : ";
        cin>>Train_ID;
        stringstream ss;
        ss<<"SELECT * FROM train where Train_ID ='"+Train_ID+"'";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
        res=mysql_store_result(obj);
            	
        while(row = mysql_fetch_row(res)){
        	
		
        cout<<row[0]<<"	 |	" <<row[1]<<"	|	" <<row[2]<<endl<<endl;
       }
   }
   //cout << "Press B to go back";
	//cin >> dummy;
}



