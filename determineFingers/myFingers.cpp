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

void myFingers::setupFingers(const FingerList fingers, const Hand& hand) {
	float vArray[9];
	for(int f = 0; f < fingers.count();f++)
	{
		vArray[f] = hand.fingers()[f].tipPosition().x;
	}

	if(vArray[0] != 0 && vArray[1] != 0 && vArray[2] != 0 && vArray[3] != 0 && vArray[4] != 0 &&
		vArray[5] != 0 && vArray[6] != 0 && vArray[7] != 0 && vArray[8] != 0 && vArray[9] != 0)
	{
		std::sort(std::begin(vArray), std::end(vArray));
		for(int f = 0; f < fingers.count(); f++)
		{
			if(vArray[0] ==hand.fingers()[f].tipPosition().x){lPinkie = hand.fingers()[f];}
			if(vArray[1] ==hand.fingers()[f].tipPosition().x){lIndex = hand.fingers()[f];}
			if(vArray[2] ==hand.fingers()[f].tipPosition().x){lMiddle = hand.fingers()[f];}
			if(vArray[3] ==hand.fingers()[f].tipPosition().x){lPointer = hand.fingers()[f];}
			if(vArray[4] ==hand.fingers()[f].tipPosition().x){lThumb = hand.fingers()[f];}
			if(vArray[5] ==hand.fingers()[f].tipPosition().x){rThumb = hand.fingers()[f];}
			if(vArray[6] ==hand.fingers()[f].tipPosition().x){rPointer = hand.fingers()[f];}
			if(vArray[7] ==hand.fingers()[f].tipPosition().x){rMiddle = hand.fingers()[f];}
			if(vArray[8] ==hand.fingers()[f].tipPosition().x){rIndex = hand.fingers()[f];}
			if(vArray[9] ==hand.fingers()[f].tipPosition().x){rPinkie = hand.fingers()[f];}
		}
		if( rPinkie.length() != 0 && rIndex.length() != 0 && rMiddle.length() != 0 && rPointer.length() != 0 && rThumb.length() != 0 && 
			lPinkie.length() != 0 && lIndex.length() != 0 && lMiddle.length() != 0 && lPointer.length() != 0 &&  lThumb.length()  != 0 )
		{
			// I dont want anything to be zero so I am using this to test and display when nothing is zero . 
			std::cout << " lPinkie Length " << lPinkie.length() <<  " lIndex Length " << lIndex.length() <<  " lMiddle Length " << lMiddle.length() <<  " lPointer Length " << lPointer.length() <<  " lThumb Length " << lThumb.length() << std::endl;
			std::cout << " rThumb Length " << rThumb.length() <<  " rPointer Length " << rPointer.length() <<  " rMiddle Length " << rMiddle.length() <<  " rIndex Length " << rIndex.length() <<  " rPinkie Length " << rPinkie.length() << std::endl;
			SetupComplete = true;
		}
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

void myFingers::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
	const Hand hand = frame.hands()[0];
	myFingers myFingers;
	if (!frame.hands().empty()) {
		const FingerList fingers = hand.fingers();
		if ( !fingers.empty() ) {	
			myFingers.setupFingers(fingers,hand);
			std::cout << "Left Hand Fingers  :  " << myFingers.lThumb.length() <<  " " << myFingers.lPointer.length() << " " << myFingers.lMiddle.length() << " " << myFingers.lIndex.length() << " " <<  myFingers.lPinkie.length() <<  std::endl;
			std::cout << "Right Hand Fingers :  " << myFingers.rThumb.length() << " " << myFingers.rPointer.length() << " " <<  myFingers.rMiddle.length() << " " << myFingers.rIndex.length() << " " <<  myFingers.rPinkie.length() <<  std::endl;

		}
	}		
	// Now you can use fingers to your fingers.
}