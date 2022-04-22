#pragma once
#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <string>
#include <fstream>
#include "Media.h"

class Audio : public Media {
public:
	Audio();
	Audio(string Identifier, string AccountName, double RunTime, string Format, string Quality);
	~Audio();
	bool ReadData(istream& in);
	bool WriteData(ostream& out);
	string GetIdentifier() const;


private:
	string Identifier;
	string Format;
	string Quality;
};
#endif