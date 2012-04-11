#include "stdafx.h"
#include "ofASpace.h"

using namespace std;

ofASpace::ofASpace()
{
	id=0;
	selected=true;
	spaces = new vector<ofASpace*>();
	current =0;
	
}

ofASpace::ofASpace(int number)
{
	id=0;
	spaces = new vector<ofASpace*>();
	current =0;
	selected=true;
	
	for(int i=0;i<number;i++)
	{
		spaces->push_back(new ofASpace()); 
		spaces->at(i)->setId(id+i);
	}

	
}

ofASpace::~ofASpace()
{
	spaces->~vector();
}

void ofASpace::AddSpace()//ok
{
	int temp;
	int idtemp;
	spaces->push_back(new ofASpace());
	

	temp = spaces->size();
	temp--;
	idtemp = spaces->at(temp)->getId();
	spaces->at(spaces->size())->setId(idtemp+1);
	
}
		
void ofASpace::RemoveSpace(int ident)
{
	if(!this->spaces->at(current)->selected)
	{
	int temp =0;
	int tempcurrent =0;
	while(tempcurrent!=this->spaces->size())
	{
		if(spaces->at(tempcurrent)->getId()==ident) delete spaces->at(tempcurrent);
		tempcurrent++;
	}
	
	tempcurrent =0;
	while(tempcurrent!=this->spaces->size())
	{
		spaces->at(tempcurrent)->setId(temp);
		temp++;
	}
	}
}


void ofASpace::MoveUpSpace()
{
	spaces->at(current)->setDeSelected();
	current++;
	spaces->at(current)->setSelected();
}
		
void ofASpace::MoveDownSpace()
{
	spaces->at(current)->setDeSelected();
	current--;
	spaces->at(current)->setSelected();
}
	
void ofASpace::Moveto(int ident)
{
	spaces->at(current)->setDeSelected();
	current =0;
	
	for(int i=0;i<spaces->size();i++)
	{
		if(i == ident) spaces->at(current)->setSelected();
	}
	
	
}

int ofASpace::getId()
{
	return id;
}

bool ofASpace::IsSelected()
{
	return this->selected;
}


//void ofASpace::setsize(){

	//this->universe.resize(1);
//}

void ofASpace::setSelected()
{
	this->selected=true;	
}

void ofASpace::setDeSelected()
{
	this->selected =false;
}

void ofASpace::setId(int number)
{
	this->id = number;
}

void ofASpace::listSpace()
{
	
	int tempcurrent = 0;
	
	for(tempcurrent; tempcurrent<spaces->size();tempcurrent++)
	{
	cout<<"il y a un espace dans cet espace";
	
	}


}

vector<ofASpace*> ofASpace::getSpace()
{

	return *spaces;
}

void ofASpace::fonctiontest()
{
	cout << "je marche";
}

void ofASpace::draw()
{


}