#pragma once

#include "ofxXmlSettings.h"

#define NUM_PTS 800

class ofAXml
{
public:
	ofAXml(void);
	~ofAXml(void);

	ofxXmlSettings XML;
	ofxXmlSettings XMLdeux;
	ofTrueTypeFont TTF;

		string xmlStructure;
		string xmlStructuredeux;
		string message;

		ofPoint dragPts[NUM_PTS];

		int pointCount;
		int lineCount;
		int lastTagNumber;

		float red;
		float green;
		float blue;
};

