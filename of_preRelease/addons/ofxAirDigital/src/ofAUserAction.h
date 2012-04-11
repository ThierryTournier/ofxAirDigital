#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;

class ofAUserAction
{
	HANDLE m_hMutex;
	HANDLE m_hEvent;

	bool isRecording;
	bool isOnZone;
	bool isReady;
	string movementName;

public:
	ofAUserAction(void);
	~ofAUserAction(void);
	void setIsRecording(bool b);
	void setIsOnZone(bool b);
	void setIsReady(bool b);
	void setMovementName(string s);
	LPCWSTR convert(char *a);

	bool getIsRecording();
	bool getIsOnZone();
	bool getIsReady();
	string getMovementName();
};

