#include "Media.h"
#include <iostream>
using namespace std;

Media::Media() {
	AccountName = "";
	Identifier = "";
	RunTime = 0;
}

Media::Media(string MediaID, string MediaAN, double MediaRT) {
	this->AccountName = MediaAN;
	this->Identifier = MediaID;
	this->RunTime = MediaRT;
}

Media::~Media() {}

bool Media::ReadData(istream& in) {
	getline(in, Identifier);
	getline(in, AccountName);
	in >> RunTime;
	return true;
}

bool Media::WriteData(ostream& out) {
	out << Identifier << endl;
	out << AccountName << endl;
	out << RunTime << endl;
	return true;
}

void Media::SetIdentifier(string MediaID) {
	this->Identifier = MediaID;
}

void Media::SetAccountName(string MediaAN) {
	this->AccountName = MediaAN;
}

void Media::SetRunTime(double MediaRT) {
	this->RunTime = MediaRT;
}

string Media::GetAccountName() {
	return AccountName;
}

double Media::GetRunTime() {
	return RunTime;
}

string Media::GetIdentifier() const {
	return Identifier;
}



