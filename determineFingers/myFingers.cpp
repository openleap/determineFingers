#include "myFingers.h"
#include "..\include\Leap.h"
using namespace Leap;
myFingers::myFingers(void)
{
}

myFingers::~myFingers(void)
{
}

Finger myFingers::GetrThumb() {
	return rThumb;
}

Finger myFingers::GetlThumb() {
	return rThumb;
}

Finger myFingers::GetrPointer() {
	return rPointer;
}

Finger myFingers::GetlPointer() {
	return lPointer;
}

Finger myFingers::GetrMiddle() {
	return rMiddle;
}

Finger myFingers::GetlMiddle() {
	return lMiddle;
}

Finger myFingers::GetrIndex() {
	return rIndex;
}

Finger myFingers::GetlIndex() {
	return lIndex;
}  

Finger myFingers::GetrPinkie() {
	return rPinkie;
}

Finger myFingers::GetlPinkie() {
	return lPinkie;
}

//void myFingers::setupFingers(const FingerList& fingers,const Frame& frame, const Hand& hand1, const Hand& hand2,const int count) {
void myFingers::setupFingers(const FingerList& fingers, const Frame& frame) {
	float vArray[10];
	int f  = 0;
	for(f; f < 10;f++)
	{
		vArray[f] = frame.fingers()[f].tipPosition().x;
	}
	std::sort(std::begin(vArray), std::end(vArray));
	f = 0;
	for(f; f < 10; f++)
	{
		if(vArray[0] ==frame.fingers()[f].tipPosition().x){lPinkie = frame.fingers()[f];}
		if(vArray[1] ==frame.fingers()[f].tipPosition().x){lIndex = frame.fingers()[f];}
		if(vArray[2] ==frame.fingers()[f].tipPosition().x){lMiddle = frame.fingers()[f];}
		if(vArray[3] ==frame.fingers()[f].tipPosition().x){lPointer = frame.fingers()[f];}
		if(vArray[4] ==frame.fingers()[f].tipPosition().x){lThumb = frame.fingers()[f];}
		if(vArray[5] ==frame.fingers()[f].tipPosition().x){rThumb = frame.fingers()[f];}
		if(vArray[6] ==frame.fingers()[f].tipPosition().x){rPointer = frame.fingers()[f];}
		if(vArray[7] ==frame.fingers()[f].tipPosition().x){rMiddle = frame.fingers()[f];}
		if(vArray[8] ==frame.fingers()[f].tipPosition().x){rIndex = frame.fingers()[f];}
		if(vArray[9] ==frame.fingers()[f].tipPosition().x){rPinkie = frame.fingers()[f];}
	}
}

void myFingers::onInit(const Controller& controller) {

	std::cout << "Initialized" << std::endl;
}

void myFingers::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
}

void myFingers::onDisconnect(const Controller& controller) {
	std::cout << "Disconnected" << std::endl;
}

void myFingers::onExit(const Controller& controller) {
	std::cout << "Exited" << std::endl;
}

bool myFingers::isLengthsZero(const FingerList& fingers,const Frame& frame) {
	bool check = true;
	int f = 0;
	for(f; f < 9; f++)
	{
		if(frame.fingers()[f].length() ==0)
		{
			check = false;
		}
	}
	return check;
}

void myFingers::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
	//const Hand hand1 = frame.hands()[0];
	//const Hand hand2 = frame.hands()[1];
	const HandList hands = frame.hands();
	if (!frame.hands().empty()) 
	{
		const FingerList fingers;
		frame.fingers()[0] = frame.fingers()[0];
		frame.fingers()[1] = frame.fingers()[1];
		frame.fingers()[2] = frame.fingers()[2];
		frame.fingers()[3] = frame.fingers()[3];
		frame.fingers()[4] = frame.fingers()[4];
		frame.fingers()[5] = frame.fingers()[5];
		frame.fingers()[6] = frame.fingers()[6];
		frame.fingers()[7] = frame.fingers()[7];
		frame.fingers()[8] = frame.fingers()[8];
		frame.fingers()[9] = frame.fingers()[9];

		/*frame.fingers()[0] = hand1.fingers()[0];
		frame.fingers()[1] = hand1.fingers()[1];
		frame.fingers()[2] = hand1.fingers()[2];
		frame.fingers()[3] = hand1.fingers()[3];
		frame.fingers()[4] = hand1.fingers()[4];
		frame.fingers()[0] = hand2.fingers()[0];
		frame.fingers()[1] = hand2.fingers()[1];
		frame.fingers()[2] = hand2.fingers()[2];
		frame.fingers()[3] = hand2.fingers()[3];
		frame.fingers()[4] = hand2.fingers()[4];*/
		// setupFingers(fingers,frame,hand1,hand2,count);
		setupFingers(fingers,frame);
		if(isLengthsZero(fingers,frame))
		{
		std::cout << "Left Hand Fingers  :  " << lThumb.length() <<  " " << lPointer.length() << " " << lMiddle.length() << " " << lIndex.length() << " " <<  lPinkie.length() <<  std::endl;
		std::cout << "Right Hand Fingers :  " << rThumb.length() << " " << rPointer.length() << " " <<  rMiddle.length() << " " << rIndex.length() << " " <<  rPinkie.length() <<  std::endl;
		}
	}
}		
