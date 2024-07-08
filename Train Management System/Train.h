#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;



class Train
{
	public:
		
		void addTrain();
		void editTrain();
		void delTrain();
		void showTrain();
		void infoTrain();
		void BookTicket();
		void AddEmployee();
		void AddExp();
		
		
		/*void ViewInfo();
		void CancelTicket();
		void Back();
		void ViewPassengers();
		void DeleteTrain();
		void password(); //admin giriþi için þifre
		int getTrainNumber() const;
		int getExpedition() const;
		int getTime() const;
		int getDate() const;
		string getStartP() const;
		string getDest() const;
		string getName() const;
		int getPhoneNumber() const;
		void setTrainNumber();
		void setExpedition();
		void setTime();
		void setDate();
		void setStartP();
		void setDest();
		void setName();
		void setPhoneNumber();*/
		
				
	private:
		/*int TrainNumber;
		string Name;
		int PhoneNumber;
		int distance; 300 km ör
		*/
		
	int Train_ID,Repair;
	char City[44];
    MYSQL* obj;
    MYSQL_ROW row;
    MYSQL_RES* res;
    string dummy;

};

#endif
