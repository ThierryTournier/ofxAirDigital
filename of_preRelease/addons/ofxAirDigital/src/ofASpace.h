#ifndef OFASPACE_H
#define OFASPACE_H
#include "ofAUniverse.h"

/*
It's the level 1 of the container system, it repreent a basic space , which can be personnalised in order to make your own super space.
The fact that this space is the second level, allow us to make the universe contains some special space derivated from this class.

*/

using namespace std;

class ofASpace : public ofAUniverse
{
	public:

		// constructosr and destructor
		ofASpace();
		ofASpace(int i);
		~ofASpace();
		
		void AddSpace();
		void RemoveSpace(int ident);
		void MoveUpSpace();
		void MoveDownSpace();
		void Moveto(int ident);

		//function for internal management
		int getId();
		void setId(int number);
		bool IsSelected();
		void setSelected();
		void setDeSelected();

		void listSpace();// test function
		
		// draw the space
		void draw();
		//special getter
		vector<ofASpace*> getSpace();

		

	protected:
		//ressources for internal purpose
		int id;
		int current;
		bool selected;
		//reflexive container
		vector<ofASpace*> *spaces;
		
};

#endif;



