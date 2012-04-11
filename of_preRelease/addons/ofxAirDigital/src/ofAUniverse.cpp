#include"stdafx.h"
#include <iostream>
#include "ofAUniverse.h"

using namespace std;


ofAUniverse::ofAUniverse()
{
	id=0;
	selected=true;
	universe = new vector<ofAUniverse*>();
	current =0;
	
}

ofAUniverse::ofAUniverse(int number)
{
	id=0;
	universe = new vector<ofAUniverse*>();
	current =0;
	selected=true;
	
	for(int i=0;i<number;i++)
	{
		universe->push_back(new ofAUniverse()); 
		universe->at(i)->setId(id+i);
	}
	universe->at(0)->setSelected();

	
}

ofAUniverse::~ofAUniverse()
{
	universe->~vector();
}

void ofAUniverse::AddUniverse()//ok
{
	int temp;
	int idtemp;
	universe->push_back(new ofAUniverse());
	

	temp = universe->size();
	temp--;
	idtemp = universe->at(temp)->getId();
	universe->at(universe->size())->setId(idtemp+1);
	
}
		
void ofAUniverse::RemoveUniverse(int ident)
{
	if(!this->universe->at(current)->selected)
	{
	int temp =0;
	int tempcurrent =0;
	while(tempcurrent!=this->universe->size())
	{
		if(universe->at(tempcurrent)->getId()==ident) delete universe->at(tempcurrent);
		tempcurrent++;
	}
	
	tempcurrent =0;
	while(tempcurrent!=this->universe->size())
	{
		universe->at(tempcurrent)->setId(temp);
		temp++;
	}
	}
}


void ofAUniverse::MoveUpUniverse()
{
	universe->at(current)->setDeSelected();
	current++;
	universe->at(current)->setSelected();
}
		
void ofAUniverse::MoveDownUniverse()
{
	universe->at(current)->setDeSelected();
	current--;
	universe->at(current)->setSelected();
}
	
void ofAUniverse::Moveto(int ident)
{
	universe->at(current)->setDeSelected();
	current =0;
	
	for(int i=0;i<universe->size();i++)
	{
		if(i == ident) universe->at(current)->setSelected();
	}
	
	
}

int ofAUniverse::getId()
{
	return id;
}

bool ofAUniverse::IsSelected()
{
	return this->selected;
}


void ofAUniverse::setsize(){

	//this->universe.resize(1);
}

void ofAUniverse::setSelected()
{
	this->selected=true;	
}

void ofAUniverse::setDeSelected()
{
	this->selected =false;
}

void ofAUniverse::setId(int number)
{
	this->id = number;
}

void ofAUniverse::listUniv()
{
	
	int tempcurrent = 0;
	
	for(tempcurrent; tempcurrent<universe->size();tempcurrent++)
	{
	cout<<"il y a un univers dans cet univers";
	
	}


}

vector<ofAUniverse*> ofAUniverse::getUniverse()
{

	return *universe;
}

void ofAUniverse::draw()
{
	for(int i =0; i< universe->size();i++)
	{
		universe->at(i)->draw();
	}
}

vector<ofAObject> ofAUniverse::getElements()
{
	return elements;
}

vector<ofAObject>::iterator ofAUniverse::getIt()
{
	return it;
}
