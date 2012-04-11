#pragma once
#include "ofAHandCoordinates.h"
#include "ofAUserAction.h"
#include "Point3D.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//class use to record and analyze the user movements
class ofAGestureReconizer
{
	//hand coordinates shared data, this thread can only read the coordinates
	ofAHandCoordinates *handCoordinates;
	//result of the analyze of the user actions.
	ofAUserAction *userAction;
public:

	ofAGestureReconizer(void);
	ofAGestureReconizer(ofAHandCoordinates *hc, ofAUserAction *ua);
	~ofAGestureReconizer(void);

	//this function test if the user start a new movement (right hand in front of his right shoulder for more than one second)
	void testStartRecording();
	//this function test if the user has stop his movement (right hand not mooving for more than 1 second
	void testStopRecording();
	//this function record the movement of the user
	void record();

	//this function verify if the movement is a line 
	bool verifyLine();

	void process();
	static unsigned __stdcall ofAGestureReconizerStaticEntryPoint( void * pThis )
    {
        ofAGestureReconizer * pgr = (ofAGestureReconizer*)pThis; 
		pgr->process();
        return 1;   // the thread exit code
    }

private:
	//vector used to store the coordinates
	vector<Point3D> vectorPoints3D;
	

};

