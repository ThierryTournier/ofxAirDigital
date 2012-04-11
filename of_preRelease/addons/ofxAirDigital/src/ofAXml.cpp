#include "stdafx.h"
#include "ofAXml.h"


ofAXml::ofAXml(void)
{
	XMLdeux.addTag("racine1");
	XMLdeux.addAttribute("racine1","number", "1",0);
	XMLdeux.pushTag("racine1");
	XMLdeux.addTag("test");
	XMLdeux.pushTag("test");
	XMLdeux.addTag("prout");
	XMLdeux.pushTag("prout");
	XMLdeux.addValue("racine:tast:prout","Valeur");
	XMLdeux.popTag();
	XMLdeux.popTag();
	XMLdeux.addTag("toto");
	XMLdeux.popTag();
	XMLdeux.addTag("racine1");
	XMLdeux.addAttribute("racine1","number","2",1);

	/*if(XMLdeux.getAttribute("racine1","number","0")== "2") 
	{
		XMLdeux.pushTag("racine1",1);
		XMLdeux.addTag("success");
	}*/
	XMLdeux.pushTag("racine1",1);
	XMLdeux.addTag("success");
	//cout << XMLdeux.getAttribute("racine1","number","0",1);


	XMLdeux.saveFile("test.xml");
}


ofAXml::~ofAXml(void)
{
}
