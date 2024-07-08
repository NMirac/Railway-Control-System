#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



class Passenger
{
	public:
		
		void bookTicket();
		void editTicket();
		void delTicket();
		void showTicket();
		void infoTicket();
		
				
	private:
		
	char Phone[11];
	char Name[44];
	char Surname[44];
	int Exp,Ticket;
    MYSQL* obj;
    MYSQL_ROW row;
    MYSQL_RES* res;

};

#endif
