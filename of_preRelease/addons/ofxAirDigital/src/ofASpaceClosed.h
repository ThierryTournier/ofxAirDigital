#ifndef OFASPACECLOSED_H
#define OFASPACECLOSED_H
/*
This is the level 2 of the container system.
It represent a space (herited from ofASpace) with some constraints about "walls"

*/

#include "ofAUniverse.h"
#include "ofASpace.h"


using namespace std;

class ofASpaceClosed : public ofASpace
{
	public:
		// constructors and destructors
		ofASpaceClosed();
		ofASpaceClosed(int i);
		~ofASpaceClosed();
		
		//management of the reflexive system
		void AddSpaceClosed();
		void RemoveSpaceClosed(int ident);
		void MoveUpSpaceClosed();
		void MoveDownSpaceClosed();
		void Moveto(int ident);

		//getters and setters for internal purpose
		int getId();
		void setId(int number);
		bool IsSelected();
		void setSelected();
		void setDeSelected();
		void listSpaceClosed();// test function
		// special getter
		vector<ofASpaceClosed*> getSpaceClosed();
		void draw();// this function must contains walls

	protected:
		// ressources for internal purpose
		int id;
		bool selected;
		int current;
		//reflexive container
		vector<ofASpaceClosed*> *spacesClosed;
};

#endif;