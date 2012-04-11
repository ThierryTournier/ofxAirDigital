#ifndef OFAOBJECT_H
#define OFAOBJECT_H

#include <string>
#include<vector>
#include "ofx3DModelLoader.h"
#include "ofAUserAction.h"
//#include "OfTool.h"


using namespace std;

/* class which represent every objects that we can put on our space management system. 
Elements can be files or directories on the computer but also object which don't have any relationship with the computer itself.
*/
class ofAObject
{

public:
	ofAObject();//constructor
	~ofAObject();//destructor

	void draw();// draw the object

	// geters and setters of the position
	float getpos_x();
	float getpos_y();
	float getpos_z();
	void setpos_x(float x);
	void setpos_y(float y);
	void setpos_z(float z);
	void setpos(float x, float y, float z);

	//other setters and getters
	string getName();
	int getID();
	string getPath();
	string getType();

	// Load the shape, actually the shape have the name of the one which is on the data directory of the example.
	void LoadShape();

	// enable or disable the fact that the object is an directory
	void EnableDirectory();
	void DisableDirectory();
	//enable the fact that the object is represented by a specific shape
	void EnableShape();
	// enable the fact that the object is a hand and set which one
	void setHand();
	void setLeft();
	void setRight();

	// function which make the object selected if an action is done
	void check(ofAObject hand,ofAObject handr, string act);
	
	// add object on itself
	void AddObject();
	ofAObject* getObj(int i);
	
	//if the object is selected
	bool selected;

protected:

	//position of the object
	float pos_x;
	float pos_y;
	float pos_z;
	//fake position of the center of the object (in the case where objects are shape and we need to define a center point)
	float center_x;
	float center_y;
	float center_z;
	//for information the type of the object
	string type;
	//its path
	string path;
	//its name
	string name;
	//id for internal management
	int id;
	//size for your own information
	float size;
	//if it is a directory
	bool isDirectory;
	//if it has a shape
	bool HasShape;
	// place to store other objects in the case of a directory
	vector<ofAObject*> *directory;
	// internal variable in order to manage directory system
	int current;
	//shape
	ofx3DModelLoader shape;
	//right or left
	bool rl;
	//in order to know if it is a boolean
	bool isHand;

};

#endif;