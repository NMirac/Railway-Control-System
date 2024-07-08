#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <cstdlib>
#include <typeinfo>
#include "Alg.h"
#include "Train.h"
#include <mysql.h>
#include <mysqld_error.h>
using namespace std; 

const char HOST[] = "localhost";
const char USER[] = "root";
const char PASS[] = "Nm761400*";

char* Alg::pickCond()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	

        int i=0;
        cand =0;
        stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job = 'Conducter'";
        
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);

        while(row = mysql_fetch_row(res)){
				shift[i] = new char[strlen(row[4]) + 1];
				strcpy(shift[i], row[4]);
				i++;
				
        }
        
        for(int x=0;x<i;x++)
        {
        	
        	shiftx = shift[x];
        	shiftc = shift[cand];
        	const char* c_str = shiftc.c_str();
        	tempc = atoi(shiftc.c_str());
        	c_str = shiftx.c_str();
        	tempx = atoi(shiftx.c_str());
        	//cout<<typeid().name();
        	if(tempx>=10)
        	{
        		condid(x);
        		resetShift(cond_id);
			}
			
			else{
			
				if(tempc>tempx)
        		{
        		cand = x;
				}
			}
		}  
		
		condid(cand);
		increaseShift(cond_id);
		a = cond_id;
		return a;
   	}
}

string Alg::condid(int cand2)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int i=0;
        stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job = 'Conducter'";
    
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);
	
	while(row = mysql_fetch_row(res)){
		
		if(i==cand2){
		
		cond_id = row[0];
			
		}
		i++;
        }
        return cond_id;
}
}

char* Alg::pickMach()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        
		int i=0;
        cand =0;
        
		stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job ='Machinist'";
 // 
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);

        while(row = mysql_fetch_row(res)){
        		
				shift[i] = new char[strlen(row[4]) + 1];
				strcpy(shift[i], row[4]);
				i++;
        }
        
        for(int x=0;x<i;x++)
        {
        	
        	shiftx = shift[x];
        	shiftc = shift[cand];
        	const char* c_str = shiftc.c_str();
        	tempc = atoi(shiftc.c_str());
        	c_str = shiftx.c_str();
        	tempx = atoi(shiftx.c_str());
        	//cout<<typeid().name();
        	if(tempx>=10)
        	{
        		machid(x);
        		resetShift(mach_id);
			}
			
			else{
				if(tempc>tempx)
        		{
        		cand = x;
				}
			}
		} 
		machid(cand);
		increaseShift(mach_id);
		b = mach_id;
		return b;
   	}
}

string Alg::machid(int cand3)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int i=0;
        stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job ='Machinist'";
    
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);
	
	while(row = mysql_fetch_row(res)){
		
		if(i==cand3){
		mach_id = row[0];
			
		}
		i++;
        }
        return mach_id;
}
}

char* Alg::pickHostess()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){

        int i=0;
        cand =0;
        stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job ='Hostess'";
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);

        while(row = mysql_fetch_row(res)){
				shift[i] = new char[strlen(row[4]) + 1];
				strcpy(shift[i], row[4]);
				//cout<<shift[i];
				i++;
        }
        
        for(int x=0;x<i;x++)
        {
        	
        	shiftx = shift[x];
        	shiftc = shift[cand];
        	const char* c_str = shiftc.c_str();
        	tempc = atoi(shiftc.c_str());
        	c_str = shiftx.c_str();
        	tempx = atoi(shiftx.c_str());
        	//cout<<typeid().name();
        	if(tempx>=10)
        	{
        		hostid(x);
        		resetShift(host_id);
			}
			
			else{
				if(tempc>tempx)
        		{
        		cand = x;
				}
			}
		}  
		hostid(cand);
		increaseShift(host_id);
		c = host_id;
		return c;
   	}
}

string Alg::hostid(int cand4)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
        int i=0;
        stringstream ss;
        ss<<"SELECT * FROM employee WHERE Job ='Hostess'";
    
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);
	
	while(row = mysql_fetch_row(res)){
		
		if(i==cand4){
		host_id = row[0];
		}
		
		i++;
        }
        return host_id;
}
}


char* Alg::pickTrain(string city)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
    	
		
        int i=0;
        cand =0;
        stringstream ss;
        ss<<"SELECT * FROM train WHERE City ='"+city+"'";
        
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);

        while(row = mysql_fetch_row(res)){
				shift[i] = new char[strlen(row[2]) + 1];
				strcpy(shift[i], row[2]);
				i++;
        }
        
        for(int x=0;x<i;x++)
        {
        	
        	shiftx = shift[x];
        	shiftc = shift[cand];
        	const char* c_str = shiftc.c_str();
        	tempc = atoi(shiftc.c_str());
        	c_str = shiftx.c_str();
        	tempx = atoi(shiftx.c_str());
        	//cout<<typeid().name();
        	if(tempx>=20)
        	{
        		trainid(x, city);
        		resetRepair(train_id);
			}
			
			else{
			
				if(tempc>tempx)
        		{
        		cand = x;
				}
			}
		}  
		
		trainid(cand, city);
		
		//increaseShift(train_id);
		d = train_id;
		increaseRepair(train_id);
		return d;
   	}
}

string Alg::trainid(int cand5, string city2)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    
	if(obj){
        int i=0;
        stringstream ss;
        ss<<"SELECT * FROM train WHERE City = '"+city2+"'";
    
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(obj, q);
        res = mysql_store_result(obj);
	
	while(row = mysql_fetch_row(res)){
		
		if(i==cand5){
		
		train_id = row[0];
			
		}
		i++;
        }
        return train_id;
}
}

void Alg::increaseRepair(string rep)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;
		
		
        stringstream ss;
        ss<<"UPDATE `management`.`train` SET `Repair` = `Repair`+2 WHERE (`Train_ID` = '"<<rep<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
    }
}

void Alg::resetShift(string reset)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;
		
		
        stringstream ss;
        ss<<"UPDATE `management`.`employee` SET `Shift` = '0' WHERE (`Emp_ID` = '"<<reset<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
    }
}

void Alg::increaseShift(string inc)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;
		
		
        stringstream ss;
        ss<<"UPDATE `management`.`employee` SET `Shift` = `Shift`+2 WHERE (`Emp_ID` = '"<<inc<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
    }
}

void Alg::resetRepair(string resetrep)
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int qstate = 0;
		
		
        stringstream ss;
        ss<<"UPDATE `management`.`train` SET `Repair` = '0' WHERE (`Train_ID` = '"<<resetrep<<"')";
        
		string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(obj, q);
        
    }
}

/*void Alg::pickEmp()
{
	obj = mysql_init(0);
    obj = mysql_real_connect(obj,HOST, USER, PASS, "management", 3306, NULL, 0);
    if(obj){
        int Exp_ID;
        
        cout<<"Enter Expendition ID : ";
        cin>>Exp_ID;
        stringstream ss;
        ss<<"SELECT *FROM employee WHERE Emp_ID =  ( SELECT MIN() FROM pieces )";
       
	    string query = ss.str();
		const char* q = query.c_str();
		mysql_query(obj,q);
	}
}*/
