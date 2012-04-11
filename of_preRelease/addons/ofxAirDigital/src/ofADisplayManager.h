#ifndef OFADISPLAYMANAGER_H
#define OFADISPLAYMANAGER_H

#include "ofAUniverse.h"
#include "ofASpace.h"
#include "ofASpaceClosed.h"
#include "ofARoom.h"

/*
this class is usefull in order to manage objects and spaces, it is there where you have to create your own world by using the other classes.
It's also the interface with your computer where all elements have to be linked.
*/

using namespace std;

class ofADisplayManager{

private:
	
	ofAUniverse universe;// It is the universe which will contains all elements of the concept created in this addon.
	string MainPath;// Main path of the main space
	int level;// the level of the container which will be mainly used.

	//Space allocated in order to store elements of the main space (from the computer)
	vector<string> dirList;
	vector<string>::iterator itdir;
	vector<string> filList;
	vector<string>::iterator itfil;

public:
	//constructor
	ofADisplayManager();
	~ofADisplayManager();

	void draw();// draw all
	void check();// update fucntion

};
#endif;