#pragma once

#include "ofMain.h"
#include"ofMath.h"

class ofApp : public ofBaseApp {

public:
	int x, y, x1, y1;
	int dx, dy, a, b,d, difE, difNE, Subebaja , unoOmenosUno;
	bool filtroDeAlberca;
	ofTexture textura;
	ofPixels pixeles;
	void putPixel(int x, int y, int red, int green, int blue, int A);
	void getPixel();
	void line(int x1,int y1,int x2,int y2,int r,int g , int b , int a);
	void circleLine(int x, int y, int radio, int r, int g, int b, int a);

	void setup();
	void update();
	void draw();




	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


};
