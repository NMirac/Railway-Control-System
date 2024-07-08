#ifndef ALG_H
#define ALG_H
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



class Alg
{
	public:

		
		char* pickCond();
		char* pickMach();
		char* pickHostess();
		char* pickTrain(string city);
		void resetShift(string reset);
		void increaseShift(string inc);
		void resetRepair(string resetrep);
		void increaseRepair(string rep);
		string condid(int cand2);
		string machid(int cand3);
		string hostid(int cand4);
		string trainid(int cand5, string city2);
		//void pickEmp();
				
	private:
		
	int cand;
	int tempx;
	int tempc;
	string shiftx;
	string shiftc;
	char* a;
	char* b;
	char* c;
	char* d;
	string job;
	char* cond_id;
	char* mach_id;
	char* host_id;
	char* train_id;
	string fulled;
	int newShift;
	char Start[44];
	char Destination[44];
	char Date[11];
	char Time[9];
	char* shift[300];
    MYSQL* obj;
    MYSQL_ROW row;
    MYSQL_RES* res;

};

#endif
