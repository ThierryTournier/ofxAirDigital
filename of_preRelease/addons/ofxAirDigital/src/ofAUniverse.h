#ifndef OFAUNIVERSE_H
#define OFAUNIVERSE_H
#include "ofMain.h"
#include <vector>
#include "ofAObject.h"

/*
The ofAUniverse class is the super class of the space container system.
It represent a space without any constraint, with an object container system.
Every class of the space system will be herited from this one.
It's the level 0 of this system.
*/

using namespace std;

class ofAUniverse
{
	public:
		//constructors and destructor
		ofAUniverse();
		ofAUniverse(int number);
		~ofAUniverse();

		//function in order to manage the conteiner system of universe
		void AddUniverse();
		void RemoveUniverse(int ident);
		void MoveUpUniverse();
		void MoveDownUniverse();
		void Moveto(int ident);
		// getters and setters  for internal purpose
		int getId();
		void setId(int number);
		//indicators of selection
		bool IsSelected();
		void setSelected();
		void setDeSelected();
		// test function
		void listUniv();
		//get the universe container
		vector<ofAUniverse*> getUniverse();
		//draw the universe
		void draw();

  protected:
		// for internal management
		int id;
		int current;
		bool selected;
		//reflexive system
		vector<ofAUniverse*> *universe;
		//for all universe and herited spaces from this class there will be an object container
		vector<ofAObject> elements;
		vector<ofAObject>::iterator it;
		
		// we allow herited class to access to these two previous elements
		vector<ofAObject> getElements();
		vector<ofAObject>::iterator getIt();

	
};


#endif;