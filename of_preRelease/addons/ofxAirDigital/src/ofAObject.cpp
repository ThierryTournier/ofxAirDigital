#include "stdafx.h"
#include "ofAObject.h"

using namespace std;

ofAObject::ofAObject()
{
	
	//mandatory
	this->isDirectory = false;
	directory = new vector<ofAObject*>();
	current =0;
	this->HasShape = false;
	this->size = 100;
	this->isHand = false;
	this->selected = false;

	//a ranger
	this->pos_x = 300;
	this->pos_y = 300;
	this->pos_z = -300;

}

ofAObject::~ofAObject()
{
	//detruire la liste de vecteur dynamique

}

void ofAObject::LoadShape()
{
	//charger dynamiquement en fonction du xml donc prendre en parametre le fichier 3DS + add un booleen pour savoir si il y a un fichier 3DS par defaut
	if(this->isHand == true)
	{
	if(this->rl == true)this->shape.loadModel("handRight.3DS",10);
	if(this->rl == false)this->shape.loadModel("handLeft.3DS",10);
	}
}
void ofAObject::draw()
{
	//a mettre dans l'objet hand heritant dobjet
	if(this->HasShape == true)
	{
	glPushMatrix();
	ofSetColor(20,20,20);
	this->shape.setRotation(0, -45, 1, 0, 0);
	this->shape.setPosition(this->pos_x,this->pos_y,this->pos_z);
	this->shape.draw();
	glPopMatrix();
	}
	else
	{
		ofSetColor(20,20,20);
		glBegin(GL_QUADS);

    //bottom : mouse=top left corner
		glVertex3f(this->getpos_x(),this->getpos_y(),this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y(),this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y()+this->size,this->getpos_z());
        glVertex3f(this->getpos_x(),this->getpos_y()+this->size,this->getpos_z());

    //top
        glVertex3f(this->getpos_x(),this->getpos_y(),this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y(),this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y()+this->size,this->size+this->getpos_z());
        glVertex3f(this->getpos_x(),this->getpos_y()+this->size,this->size+this->getpos_z());

    //left
        glVertex3f(this->getpos_x(),this->getpos_y(),this->getpos_z());
        glVertex3f(this->getpos_x(),this->getpos_y(),this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y(),this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y(),this->getpos_z());

    //right
        glVertex3f(this->getpos_x(),this->getpos_y()+this->size,this->getpos_z());
        glVertex3f(this->getpos_x(),this->getpos_y()+this->size,this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y()+this->size,this->size+this->getpos_z());
        glVertex3f(this->getpos_x()+this->size,this->getpos_y()+this->size,this->getpos_z());

    glEnd();
	}
}

float ofAObject::getpos_x()
{
	return this->pos_x;
}

float ofAObject::getpos_y()
{
	return this->pos_y;
}

float ofAObject::getpos_z()
{
	return this->pos_z;
}

void ofAObject::setpos_x(float x)
{
	this->pos_x = x;
}

void ofAObject::setpos_y(float y)
{
	this->pos_y = y;
}

void ofAObject::setpos_z(float z)
{
	this->pos_z = z;
}

string ofAObject::getName()
{
	return this->name;
}

string ofAObject::getPath()
{
	return this->path;
}

int ofAObject::getID()
{
	return this->id;
}

string ofAObject::getType()
{
	return this->type;
}

void ofAObject::EnableDirectory()
{
	this->isDirectory = true;
}

void ofAObject::DisableDirectory()
{
	this->isDirectory = false;
}

void ofAObject::AddObject()
{
	if(this->isDirectory == true)
	{
		int temp =0;
		directory->push_back(new ofAObject());

		for(int i =0; i< directory->size();i++)
		{
			directory->at(i)->id=i;
		}

	}
}

ofAObject* ofAObject::getObj(int i)
{
	return directory->at(i);
}

void ofAObject::setpos(float x, float y, float z)
{
	
	this->pos_x = x;
	this->pos_y = y;
	this->pos_z = z;
}

void ofAObject::EnableShape()
{
	this->HasShape = true;
}

void ofAObject::check(ofAObject handl,ofAObject handr, string act)
{
	if((handl.getpos_x()<=this->pos_x +400)&&(handl.getpos_x()>=this->pos_x -200))
	{
		if((handl.getpos_y()<=this->pos_y +200)&&(handl.getpos_y()>=this->pos_y -100))
		{
			if((handl.getpos_z()>=this->pos_z -500)&&(handl.getpos_z()<=this->pos_z-200 ))
			{
				if(act == "Pousse")
				{
				this->selected = true;
				cout << this->id + "is selected";
				}
				else if(act == "Tire")
				{
					this->selected = false;
					cout << this->id + "is not selected";
				}
			}
		}
	}
	



}

void ofAObject::setRight()
{
	this->rl = true;
}
void ofAObject::setLeft()
{
	this->rl = false;
}
void ofAObject::setHand()
{
	this->isHand = true;
}