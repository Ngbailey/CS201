#include <iostream>
#include <fstream>
#include <string>
#include "Media.h"
#include "Audio.h"
#include "Video.h"

using namespace std;

int main() {
	ifstream in;
	ofstream outAudio, outVideo;
	string fileOne = "Program5Data.txt";
	string fileTwo = "Audio Files.txt";
	string fileThree = "Video Files.txt";
	Media* MediaFiles[200] = { NULL };
	int readerIndex = 0;
	int writerIndex = 0;
	char Identifier = ' ';
	bool checker = true;

	cout << "Please enter Program Data, i.e. 'Program5Data.txt'" << endl;
	cin >> fileOne;
	
	
	in.open(fileOne);
	while (checker == true) {
		if (!in.is_open()) {
			cout << "Couldn't open file" << endl;
			cout << "Please try entering Program Data again, i.e. 'Program5Data.txt'" << endl;
			cin >> fileOne;
			in.open(fileOne);
		}
		else {
			outAudio.open(fileTwo);
			outVideo.open(fileThree);
			if (!outAudio.is_open() || !outVideo.is_open()) {
				cout << "Failed to open " << fileTwo << " or " << fileThree << endl;
			}
			else {
				while (in >> Identifier) {
					in.ignore();
					for (readerIndex; readerIndex < 200; readerIndex++) {
						if (Identifier == 'A') {
							MediaFiles[readerIndex] = new Audio;
							break;
						}
						if (Identifier == 'V') {
							MediaFiles[readerIndex] = new Video;
							break;
						}
					}
					MediaFiles[readerIndex]->ReadData(in);
					readerIndex++;
				}
				checker = false;
			}
		}

	}
	while (MediaFiles[writerIndex] != NULL && writerIndex <= readerIndex) {
		if (MediaFiles[writerIndex]->GetIdentifier() == "Audio") {
			MediaFiles[writerIndex]->WriteData(outAudio);
		}
		else {
			MediaFiles[writerIndex]->WriteData(outVideo);
		}
		writerIndex++;
	}
	in.close();
	outAudio.close();
	outVideo.close();
	
	





	return 0;
}