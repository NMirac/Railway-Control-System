#ifndef EMP_H
#define EMP_H
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



class Emp
{
	public:

		
		void addEmp();
		void editEmp();
		void delEmp();
		void showEmp();
		void infoEmp();
		
				
	private:
		
	int Emp_ID,Shift;
	char Name[44];
	char Surname[44];
	char Job[44];
    MYSQL* obj;
    MYSQL_ROW row;
    MYSQL_RES* res;

};

#endif
