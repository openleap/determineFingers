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
	bool check = false;
	int f = 0;
	for(f; f < 9; f++)
	{
		if(frame.fingers()[f].length() ==0)
		{
			check = true;
		}
	}
	return check;
}

void myFingers::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
	const HandList hands = frame.hands();
	if (!frame.hands().empty()) 
	{
		const FingerList fingers;
		for(int f=0; f < 9; f++)
		{
			frame.fingers()[f] = frame.fingers()[f];
		}

		setupFingers(fingers,frame);

		if(!isLengthsZero(fingers,frame))
		{
			std::cout << "Left Hand Fingers  :  " << lThumb.length() <<  " " << lPointer.length() << " " << lMiddle.length() << " " << lIndex.length() << " " <<  lPinkie.length() <<  std::endl;
			std::cout << "Right Hand Fingers :  " << rThumb.length() << " " << rPointer.length() << " " <<  rMiddle.length() << " " << rIndex.length() << " " <<  rPinkie.length() <<  std::endl;
			SetupComplete = true;
		}
	}
}		
