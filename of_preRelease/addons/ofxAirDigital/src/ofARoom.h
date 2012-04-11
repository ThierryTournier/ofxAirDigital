#ifndef OFAROOM_H
#define OFAROOM_H

/*
This is the level 3 of the container system.
It represents a space closed with a camera unmovable where we can see all the space on the screen.
*/


#include "ofAUniverse.h"
#include "ofASpace.h"
#include "ofASpaceClosed.h"

using namespace std;

class ofARoom : public ofASpaceClosed
{
	public:
		//contructors and destructors
		ofARoom();
		ofARoom(int i);
		~ofARoom();

		// management functions of the reflexive system
		void AddRoom();
		void RemoveRoom(int ident);
		void MoveUpRoom();
		void MoveDownRoom();
		void Moveto(int ident);
		
		//finctions for internal management
		int getId();
		void setId(int number);
		bool IsSelected();
		void setSelected();
		void setDeSelected();

		void listRoom();// test function

		//special getter
		vector<ofARoom*> getRoom();

		// draw the space
		virtual void draw();


		//TiTi
		void showMovementIndicator(bool isOnZone, bool isRecording, bool isReady);
		void showMovementName(string movementName, 	ofTrueTypeFont	verdana14);
		void showHandCoord(double xr, double yr, double zr, double xl, double yl, double zl, ofTrueTypeFont	verdana14);
	
	protected:
		// internal ressources
		int id;
		bool selected;
		int current;
		//reflexive container
		vector<ofARoom*> *house;
		

};

#endif