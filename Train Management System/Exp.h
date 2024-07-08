#ifndef EXP_H
#define EXP_H
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



class Exp
{
	public:

		
		void addExp();
		void revExp(int Exp_ID,char* Date,char* Time,char* Start,char* Destination,char* Train,int Seat, char* Conducter, char* Machinist, char* Hostess);
		void editExp();
		void delExp();
		void showExp();
		void infoExp();
		void checkExp(int id);
		
		//void pickEmp();
		
				
	private:
		
	int Exp_ID,Seat;
	char* Train;
	char Start[44];
	char Destination[44];
	char Date[11];
	char Time[9];
	char* Conducter;
	char* Machinist;
	char* Hostess;
	string city;
    MYSQL* obj;
    MYSQL_ROW row;
    MYSQL_RES* res;

};

#endif
