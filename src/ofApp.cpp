#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	pixeles.allocate(1024, 768, OF_PIXELS_BGRA);
	textura.allocate(1024, 768, GL_BGRA);
	circleLine(ofGetWidth()/2 , ofGetHeight()/2 , 300, 255,255,255,255);

	///*line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() , ofGetHeight()/2+15 ); 
	//line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth()/2+15, ofGetHeight() );*/

	//line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() / 2 - 15, ofGetHeight());
	///*line(ofGetWidth() / 2, ofGetHeight() / 2, 0, ofGetHeight()/2+15);

	//line(ofGetWidth() / 2, ofGetHeight() / 2, 0, ofGetHeight() / 2 -15);
	//line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth()/2 -15, 0);*/

	//line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth() / 2 +15, 0);
	///*line(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2 - 15);*/
}

//--------------------------------------------------------------
void ofApp::update() {


	//putPixel(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
	getPixel();


}

//--------------------------------------------------------------
void ofApp::draw() {
	textura.draw(0, 0);

}

void ofApp::putPixel(int x, int y, int red, int green, int blue, int A)
{
	pixeles.setColor(x, y, (red, green, blue, A));
}

void ofApp::getPixel()
{
	textura.loadData(pixeles);
}

void ofApp::line(int x1, int y1, int x2, int y2, int r, int g, int b, int a)
{ 

	if (x1 > x2)// invierte
	{
	int xNew = x1;
	int yNew = y1;

	x1 = x2;
	y1 = y2;

	x2 = xNew;
	y2 = yNew;
	}
			

				if(y1>y2)// diferencia negativa?
				{
					unoOmenosUno = -1;
					dy = y1 - y2;
				}
				else
				{
					dy = y2 - y1;
					unoOmenosUno = 1;
				}
				dx = x2 - x1;
					if(dy>=dx)//  Base mayor 
					{
						a = dx;
						b = -dy;
						Subebaja = x1;
						filtroDeAlberca = true;
					}
					else
					{
						a = dy;
						b = -dx;
						Subebaja = y1;
						filtroDeAlberca = false;
					}

					d = 2 * a + b;
					difE = 2 * a;
					difNE = 2 * a + 2 * b;
					putPixel(x1,y1,r,g,b,a);
					if (!filtroDeAlberca)
					{
						for (int x = x1 + 1; x <= x2; x++)
						{
							if (d < 0)
							{
								d += 2 * a;
							}
							else
							{
								d += 2 * a + 2 * b;
								Subebaja += unoOmenosUno;
							}
							putPixel(x, Subebaja, r,g,b,a);
						}
					}
					else
					{
						cout << "el agua esa limpia" << endl;
						int elintquesepasodeverga;
						int otra=y2*=unoOmenosUno;
						for (int y = y1 + unoOmenosUno; (elintquesepasodeverga=y*unoOmenosUno) <= (otra); y+=unoOmenosUno)
						{
							if (d < 0)
							{
								d += 2 * a;
							}
							else
							{
								d += 2 * a + 2 * b;
								Subebaja ++;
							}
							putPixel(Subebaja,y, r, g, b, a);
						}

					}
	

	//-------------------------------------- 1
	/*int x, y, dx, dy, d, deltaE, deltaNE;

	x = x1;
	y = y1;

	dx = x2 - x1;
	dy = y2 - y1;

	d = 2 * dy - dx;

	deltaE = 2 * dy;
	deltaNE = 2 * dy - dx;

	putPixel(x, y, 255, 255, 255, 255);


	while (x < x2)
	{
		if (d < 0)
		{
			d = d + deltaE;
			
		}
		else {
			d = d + deltaNE;
			
			y++;
		}
		putPixel(x, y, 255, 255, 255, 255);
		x++;
	}

	*/
	//---------------------------------2
	//int x, y, dx, dy, d, deltaE, deltaNE;

	//x = x1;
	//y = y1;

	//dx = x2 - x1;
	//dy = y2 - y1;

	//d = 2 * dx - dy;

	//deltaE = 2 * dx;
	//deltaNE = 2 * dx - dy;

	//putPixel(x, y, 255, 255, 255, 255);


	//while (y < y2)
	//{
	//	if (d < 0)
	//	{
	//		d = d + deltaE;
	//	}
	//	else {
	//		d = d + deltaNE;
	//		
	//		x++;
	//	}
	//	y++;
	//	putPixel(x, y, 255, 255, 255, 255);

	//}
	//------------------- 3
	/*int xNew = x1;
	int yNew = y1;

	x1 = x2;
	y1 = y2;

	x2 = xNew;
	y2 = yNew;

	x = x1;
	y = y1;

	dx = x2 - x1;
	c

	d = 2 * dx - dy;

	deltaE = 2 * dx;
	deltaNE = 2 * dx - dy;

	putPixel(x1, y1, 255, 255, 255, 255);


	while (y > y2)
	{
		if (d < 0)
		{
			d = d + deltaE;
		}
		else {
			d = d + deltaNE;

			x++;
		}
		y--;
		putPixel(x, y, 255, 255, 255, 255);

	}*/

	//------------------------------------ 4
	/*int xNew = x1;
	int yNew = y1;

	x1 = x2;
	y1 = y2;

	x2 = xNew;
	y2 = yNew;

	x = x1;
	y = y1;

	dx = x2 - x1;
	dy = y1 - y2;

	d = 2 * dy - dx;

	deltaE = 2 * dy;
	deltaNE = 2 * dy - dx;

	putPixel(x, y, 255, 255, 255, 255);


	while (x < x2)
	{
	if (d < 0)
	{
	d = d + deltaE;

	}
	else {
	d = d + deltaNE;

	y--;
	}
	putPixel(x, y, 255, 255, 255, 255);
	x++;
	}*/

//------------------------------- 5
//int xNew = x1;
//int yNew = y1;
//
//x1 = x2;
//y1 = y2;
//
//x2 = xNew;
//y2 = yNew;
//
//x = x1;
//y = y1;
//
//dx = x2 - x1;
//dy = y2 - y1;
//
//d = 2 * dy - dx;
//
//deltaE = 2 * dy;
//deltaNE = 2 * dy - dx;
//
//putPixel(x, y, 255, 255, 255, 255);
//
//
//while (x < x2)
//{
//	if (d < 0)
//	{
//		d = d + deltaE;
//
//	}
//	else {
//		d = d + deltaNE;
//
//		y++;
//	}
//	putPixel(x, y, 255, 255, 255, 255);
//	x++;
//}

//------------------------------------- 6
//int xNew = x1;
//int yNew = y1;
//
//x1 = x2;
//y1 = y2;
//
//x2 = xNew;
//y2 = yNew;
//
//x = x1;
//y = y1;
//dx = x2 - x1;
//dy = y2 - y1;
//
//d = 2 * dx - dy;
//
//deltaE = 2 * dx;
//deltaNE = 2 * dx - dy;
//
//putPixel(x, y, 255, 255, 255, 255);
//
//
//while (y < y2)
//{
//	if (d < 0)
//	{
//		d = d + deltaE;
//	}
//	else {
//		d = d + deltaNE;
//		
//		x++;
//	}
//	y++;
//	putPixel(x, y, 255, 255, 255, 255);
//
//}
//------------------------------ 7


//x = x1;
//y = y1;
//
//dx = x2 - x1;
//dy = y1 - y2;
//
//d = 2 * dx - dy;
//
//deltaE = 2 * dx;
//deltaNE = 2 * dx - dy;
//
//putPixel(x1, y1, 255, 255, 255, 255);
//
//
//while (y > y2)
//{
//if (d < 0)
//{
//d = d + deltaE;
//}
//else {
//d = d + deltaNE;
//
//x++;
//}
//y--;
//putPixel(x, y, 255, 255, 255, 255);
//
//}
//----------------------------- 8
//x = x1;
//y = y1;
//
//dx = x2 - x1;
//dy = y1 - y2;
//
//d = 2 * dy - dx;
//
//deltaE = 2 * dy;
//deltaNE = 2 * dy - dx;
//
//putPixel(x, y, 255, 255, 255, 255);
//
//
//while (x < x2)
//{
//	if (d < 0)
//	{
//		d = d + deltaE;
//
//	}
//	else {
//		d = d + deltaNE;
//
//		y--;
//	}
//	putPixel(x, y, 255, 255, 255, 255);
//	x++;
//}







}

void ofApp::circleLine(int x, int y, int radio, int r, int g, int b, int a)
{
	float angles;
	int x2, y2;
	x2 = 0;
	y2 = 0; 

	for (int ActualAngle = 0; ActualAngle < 360; ActualAngle++)
	{
		angles = radio*cos(ActualAngle);
		x2 = round(angles);
		angles = radio*sin(ActualAngle);
		y2 = round(angles);

		line(x, y, x + x2, y + y2, r,g,b,a);



	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
