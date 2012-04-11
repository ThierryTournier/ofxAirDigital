#include "stdafx.h"
#include "ofASpaceClosed.h"
#include "ofASpace.h"
#include "ofARoom.h"
#include  <gl\GLU.h>
#include <Windows.h>
//#include "GLAux.h"
#include <gl\GL.h>
//#include "sdlglutils.h"
//#include "../../../../../of_preRelease_v007_vs2010/libs/openFrameworks/gl/ofTexture.h"
//#include "../addonsExamples/allAddonsExample/src/testApp.h"


using namespace std;


ofARoom::ofARoom()
{
	id=0;
	selected=true;
	house = new vector<ofARoom*>();
	current =0;
	
}

ofARoom::ofARoom(int number)
{
	id=0;
	house = new vector<ofARoom*>();
	current =0;
	selected=true;
	
	for(int i=0;i<number;i++)
	{
		house->push_back(new ofARoom()); 
		house->at(i)->setId(id+i);
	}

	
}

ofARoom::~ofARoom()
{
	house->~vector();
}

void ofARoom::AddRoom()//ok
{
	int temp;
	int idtemp;
	house->push_back(new ofARoom());
	

	temp = house->size();
	temp--;
	idtemp = house->at(temp)->getId();
	house->at(house->size())->setId(idtemp+1);
	
}
		
void ofARoom::RemoveRoom(int ident)
{
	if(!this->house->at(current)->selected)
	{
	int temp =0;
	int tempcurrent =0;
	while(tempcurrent!=this->house->size())
	{
		if(house->at(tempcurrent)->getId()==ident) delete house->at(tempcurrent);
		tempcurrent++;
	}
	
	tempcurrent =0;
	while(tempcurrent!=this->house->size())
	{
		house->at(tempcurrent)->setId(temp);
		temp++;
	}
	}
}


void ofARoom::MoveUpRoom()
{
	house->at(current)->setDeSelected();
	current++;
	house->at(current)->setSelected();
}
		
void ofARoom::MoveDownRoom()
{
	house->at(current)->setDeSelected();
	current--;
	house->at(current)->setSelected();
}
	
void ofARoom::Moveto(int ident)
{
	house->at(current)->setDeSelected();
	current =0;
	
	for(int i=0;i<house->size();i++)
	{
		if(i == ident) house->at(current)->setSelected();
	}
	
	
}

int ofARoom::getId()
{
	return id;
}

bool ofARoom::IsSelected()
{
	return this->selected;
}


//void ofASpace::setsize(){

	//this->universe.resize(1);
//}

void ofARoom::setSelected()
{
	this->selected=true;	
}

void ofARoom::setDeSelected()
{
	this->selected =false;
}

void ofARoom::setId(int number)
{
	this->id = number;
}

void ofARoom::listRoom()
{
	
	int tempcurrent = 0;
	
	for(tempcurrent; tempcurrent<house->size();tempcurrent++)
	{
	cout<<"il y a un espace dans cet espace";
	
	}


}

vector<ofARoom*> ofARoom::getRoom()
{

	return *house;
}

void ofARoom::draw()
{
	ofBackground(255,255,255);
	

	 //back wall
    
	
	ofSetColor(20, 20, 20);
    glBegin(GL_LINES);
		
        glVertex3f(0.0, ofGetHeight(), -1000);
        glVertex3f(ofGetWidth(), ofGetHeight(), -1000);
        glVertex3f(ofGetWidth(), 0.0, -1000);
        glVertex3f(0.0, 0.0, -1000);
		glVertex3f(0.0,ofGetHeight(),-1000);
		glVertex3f(0.0,0.0,-1000);
		glVertex3f(ofGetWidth(),ofGetHeight(),-1000);
		glVertex3f(ofGetWidth(),0.0,-1000);
		
   glEnd();
	
	// right wall
	ofSetColor(20, 20, 20);
	glBegin(GL_LINES);
		glVertex3f(0.0, ofGetHeight(), -1000);
		glVertex3f(0.0,ofGetHeight(), 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -1000);
	glEnd();

	//left wall
	ofSetColor(20, 20, 20);
	glBegin(GL_LINES);
		glVertex3f(ofGetWidth(), ofGetHeight(), -1000);
		glVertex3f(ofGetWidth(), ofGetHeight(), 0.0);
		glVertex3f(ofGetWidth(), 0.0, 0.0);
		glVertex3f(ofGetWidth(), 0.0, -1000);
	glEnd();

	//up wall
	ofSetColor(20, 20, 20);
	glBegin(GL_LINES);

		glVertex3f(0.0, 0.0, -1000);
		glVertex3f(ofGetWidth(), 0.0, -1000);
		glVertex3f(ofGetWidth(), 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	//down wall
	ofSetColor(20, 20, 20);
	glBegin(GL_LINES);
	
		glVertex3f(0.0, ofGetHeight(), 0);
		glVertex3f(ofGetWidth(),ofGetHeight(), 0);
		glVertex3f(ofGetWidth(),ofGetHeight(), -1000);
		glVertex3f(0.0, ofGetHeight(), -1000);

	glEnd();
	ofSetColor(255,255,255);

}

void ofARoom::showMovementIndicator(bool isOnZone, bool isRecording, bool isReady)
{
	if (isReady)
		ofSetColor(0,1000,0);
	else if (isOnZone)
		ofSetColor(1000,500,0);
	else if (isRecording)
		ofSetColor(1000,0,0);
	 
	else return;
	glBegin(GL_QUADS);

    //right : 
        glVertex3f(50,ofGetHeight()-50+30,0);
        glVertex3f(50,ofGetHeight()-50,0);
        glVertex3f(50,ofGetHeight()-50,20);
        glVertex3f(50,ofGetHeight()-50+30,20);
	glEnd();
	glBegin(GL_QUADS);
    //top
        glVertex3f(20,ofGetHeight()-50,0);
        glVertex3f(50,ofGetHeight()-50,0);
        glVertex3f(50,ofGetHeight()-50,20);
        glVertex3f(20,ofGetHeight()-50,20);
		glEnd();
		glBegin(GL_QUADS);
    //left
		glVertex3f(20,ofGetHeight()-50+30,0);
        glVertex3f(20,ofGetHeight()-50,0);
        glVertex3f(20,ofGetHeight()-50,20);
        glVertex3f(20,ofGetHeight()-50+30,20);
	glEnd();
		glBegin(GL_QUADS);
    //bottom
        glVertex3f(20,ofGetHeight()-50+30,0);
        glVertex3f(20,ofGetHeight()-50+30,20);
        glVertex3f(50,ofGetHeight()-50+30,20);
        glVertex3f(50,ofGetHeight()-50+30,0);
	glEnd();
	glBegin(GL_QUADS);
    //front
		glVertex3f(20,ofGetHeight()-50+30,0);
        glVertex3f(20,ofGetHeight()-50,0);
		glVertex3f(50,ofGetHeight()-50,0);
		glVertex3f(50,ofGetHeight()-50+30,0);
       
       
	glEnd();
}

void ofARoom::showMovementName(string movementName,	ofTrueTypeFont	verdana14)
{
	if (movementName=="")
	{
		ofSetColor(245, 58, 135);
		verdana14.drawString("Dernier mouvement effectué : ", 20, ofGetHeight()-50);

	}
	else 
	{

		ofSetColor(245, 58, 135);
		verdana14.drawString("Dernier mouvement effectué : "+movementName, 20, ofGetHeight()-50);
	}

}

void ofARoom::showHandCoord(double xr, double yr, double zr, double xl, double yl, double zl, ofTrueTypeFont	verdana14)
{
	ostringstream s;
	s<<"xr : "<<xr<<" yr : "<<yr<<" zr : "<<zr;
	ofSetColor(0, 0, 0);
	verdana14.drawString(s.str(), 20, 20);

	ostringstream s2;
	s2<<"xl : "<<xl<<" yl : "<<yl<<" zl : "<<zl;
	ofSetColor(0, 0, 0);
	verdana14.drawString(s2.str(), ofGetWidth()-300, 20);

}