#pragma once
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



class Media {
	public:
		Media();
		Media(string Identifier, string AccountName, double RunTime);
		~Media();
		void SetIdentifier(string MediaID);
		void SetAccountName(string MediaAN);
		void SetRunTime(double MediaRT);
		virtual string GetIdentifier() const = 0;
		string GetAccountName();
		double GetRunTime();
		virtual bool ReadData(istream& in);
		virtual bool WriteData(ostream& out);


	protected:
		string Identifier;
		string AccountName;
		double RunTime;
};
#endif
