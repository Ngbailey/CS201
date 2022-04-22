#include "Media.h"
#include "Audio.h"
#include <iostream>
using namespace std;

Audio::Audio() : Media() {
	Identifier = "Audio";
	Format = "";
	Quality = "";
}

Audio::Audio(string MediaID, string MediaAN, double MediaRT, string AudioFormat, string AudioQuality) : Media(MediaID, MediaAN, MediaRT) {
	Identifier = "Audio";
	this->Format = AudioFormat;
	this->Quality = AudioQuality;
}

Audio::~Audio() {}

bool Audio::ReadData(istream& in) {
	Media::ReadData(in);
	in.ignore();
	getline(in, Format);
	getline(in, Quality);
	return true;
}

bool Audio::WriteData(ostream& out) {
	Media::WriteData(out);
	out << Format << endl;
	out << Quality << endl;
	out << "******************NEXT AUDIO*********************" << endl;
	return true;
}

string Audio::GetIdentifier()const {
	return Identifier;
}