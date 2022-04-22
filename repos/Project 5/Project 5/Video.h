#pragma once
#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <fstream>
#include "Media.h"

class Video : public Media {
public:
	Video();
	Video(string Identifier, string AccountName, double RunTime, string Resolution, string Format, string Quality);
	~Video();
	bool ReadData(istream& in);
	bool WriteData(ostream& out);
	string GetIdentifier() const;


private:
	string Resolution;
	string Format;
	string Quality;
	string Identifier;
};
#endif