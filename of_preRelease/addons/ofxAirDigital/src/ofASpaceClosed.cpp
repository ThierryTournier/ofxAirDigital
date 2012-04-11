#include "stdafx.h"
#include "ofASpaceClosed.h"

using namespace std;

ofASpaceClosed::ofASpaceClosed()
{
	id=0;
	selected=true;
	spacesClosed = new vector<ofASpaceClosed*>();
	current =0;
	
}

ofASpaceClosed::ofASpaceClosed(int number)
{
	id=0;
	spacesClosed = new vector<ofASpaceClosed*>();
	current =0;
	selected=true;
	
	for(int i=0;i<number;i++)
	{
		spacesClosed->push_back(new ofASpaceClosed()); 
		spacesClosed->at(i)->setId(id+i);
	}

	
}

ofASpaceClosed::~ofASpaceClosed()
{
	spacesClosed->~vector();
}

void ofASpaceClosed::AddSpaceClosed()//ok
{
	int temp;
	int idtemp;
	spacesClosed->push_back(new ofASpaceClosed());
	

	temp = spacesClosed->size();
	temp--;
	idtemp = spacesClosed->at(temp)->getId();
	spacesClosed->at(spacesClosed->size())->setId(idtemp+1);
	
}
		
void ofASpaceClosed::RemoveSpaceClosed(int ident)
{
	if(!this->spacesClosed->at(current)->selected)
	{
	int temp =0;
	int tempcurrent =0;
	while(tempcurrent!=this->spacesClosed->size())
	{
		if(spacesClosed->at(tempcurrent)->getId()==ident) delete spacesClosed->at(tempcurrent);
		tempcurrent++;
	}
	
	tempcurrent =0;
	while(tempcurrent!=this->spacesClosed->size())
	{
		spacesClosed->at(tempcurrent)->setId(temp);
		temp++;
	}
	}
}


void ofASpaceClosed::MoveUpSpaceClosed()
{
	spacesClosed->at(current)->setDeSelected();
	current++;
	spacesClosed->at(current)->setSelected();
}
		
void ofASpaceClosed::MoveDownSpaceClosed()
{
	spacesClosed->at(current)->setDeSelected();
	current--;
	spacesClosed->at(current)->setSelected();
}
	
void ofASpaceClosed::Moveto(int ident)
{
	spacesClosed->at(current)->setDeSelected();
	current =0;
	
	for(int i=0;i<spacesClosed->size();i++)
	{
		if(i == ident) spacesClosed->at(current)->setSelected();
	}
	
	
}

int ofASpaceClosed::getId()
{
	return id;
}

bool ofASpaceClosed::IsSelected()
{
	return this->selected;
}


//void ofASpace::setsize(){

	//this->universe.resize(1);
//}

void ofASpaceClosed::setSelected()
{
	this->selected=true;	
}

void ofASpaceClosed::setDeSelected()
{
	this->selected =false;
}

void ofASpaceClosed::setId(int number)
{
	this->id = number;
}

void ofASpaceClosed::listSpaceClosed()
{
	
	int tempcurrent = 0;
	
	for(tempcurrent; tempcurrent<spacesClosed->size();tempcurrent++)
	{
	cout<<"il y a un espace dans cet espace";
	
	}


}

vector<ofASpaceClosed*> ofASpaceClosed::getSpaceClosed()
{

	return *spacesClosed;
}


void ofASpaceClosed::draw()
{


}