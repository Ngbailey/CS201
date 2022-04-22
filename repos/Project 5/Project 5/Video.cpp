#include "Media.h"
#include "Video.h"
#include <iostream>
using namespace std;


Video::Video() : Media() {
	Resolution = "";
	Format = "";
	Quality = "";
	Identifier = "Video";
}

Video::Video(string MediaID, string MediaAN, double MediaRT, string VideoResolution, string VideoFormat, string VideoQuality) : Media(MediaID, MediaAN, MediaRT) {
	this->Resolution = VideoResolution;
	this->Format = VideoFormat;
	this->Quality = VideoQuality;
	Identifier = "Video";
}

Video::~Video() {}

bool Video::ReadData(istream& in) {
	Media::ReadData(in);
	in.ignore();
	getline(in, Resolution);
	getline(in, Format);
	getline(in, Quality);
	return true;
}

bool Video::WriteData(ostream& out) {
	Media::WriteData(out);
	out << Resolution << endl;
	out << Format << endl;
	out << Quality << endl;
	out << "*****************NEXT VIDEO**********************" << endl;
	return true;
}

string Video::GetIdentifier()const {
	return Identifier;
}