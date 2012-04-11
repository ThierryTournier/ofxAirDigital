#pragma once

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include "ofxXmlSettings.h"
#include "ofAHandCoordinates.h"
#include "ofAUserAction.h"
#include "SkeletalViewer.h"
#include "ofADisplayManager.h"
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxXmlSettings XML;
		ofAObject obj;
		//ofADisplayManager displayer;
		

private:
		ofARoom toto;
		ofAObject handr;
		ofAObject handl;
		ofAUserAction *userAction;
		ofAHandCoordinates *handCoordinates;
		ofTrueTypeFont	verdana14;

		
};
