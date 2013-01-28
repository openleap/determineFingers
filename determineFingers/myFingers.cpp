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

FingerList myFingers::CompareFinger(const FingerList& fingers, const Hand& hand){
	for(int i = 0; i < fingers.count(); i++)
	{
		if( hand.fingers()[i].length() == rThumb.length())
		{
			std::cout << " you are attempting to use your right thumb " << std::endl;
		}
		if( hand.fingers()[i].length() == lThumb.length())
		{
			std::cout << " you are attempting to use your Left thumb " << std::endl;
		}

		if( hand.fingers()[i].length() == rPointer.length())
		{
			std::cout << " you are attempting to use your right Pointer " << std::endl;
		}
		if( hand.fingers()[i].length() == lPointer.length())
		{
			std::cout << " you are attempting to use your left Pointer " << std::endl;
		}

		if( hand.fingers()[i].length() == rMiddle.length())
		{
			std::cout << " you are attempting to use your right Middle " << std::endl;
		}
		if( hand.fingers()[i].length() == lMiddle.length())
		{
			std::cout << " you are attempting to use your left Middle " << std::endl;
		}

		if( hand.fingers()[i].length() == rIndex.length())
		{
			std::cout << " you are attempting to use your right Index " << std::endl;
		}
		if( hand.fingers()[i].length() == lIndex.length())
		{
			std::cout << " you are attempting to use your left Index " << std::endl;
		}

		if( hand.fingers()[i].length() == rPinkie.length())
		{
			std::cout << " you are attempting to use your right Pinkie " << std::endl;
		}
		if( hand.fingers()[i].length() == lPinkie.length())
		{
			std::cout << " you are attempting to use your left Pinkie " << std::endl;
		}
	}
	return fingers;
}

void myFingers::setupFingers(const FingerList& fingers, const Hand& hand) {
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
			// I dont want anything to be zero so I am using this for testing purposes to display lengths . 
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

bool myFingers::isFingerLengthZero(Finger finger){
	bool lengthisZero;
	if(finger.length() == 0)
	{
		lengthisZero = true;
	} else {
		lengthisZero = false;
	}
	return lengthisZero;
}

void myFingers::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
	const Hand hand = frame.hands()[0];
	myFingers myFingers;
	if (!frame.hands().empty()) 
	{
		const FingerList fingers = hand.fingers();
		FingerList detectedfingers;
		if ( !fingers.empty() )
		{	
		myFingers.setupFingers(fingers,hand);
		if(isFingerLengthZero(rThumb) || !isFingerLengthZero(rPointer) && !isFingerLengthZero(rMiddle) && !isFingerLengthZero(rIndex) && !isFingerLengthZero(rPinkie)){
			std::cout << "Left Hand Fingers  :  " << myFingers.lThumb.length() <<  " " << myFingers.lPointer.length() << " " << myFingers.lMiddle.length() << " " << myFingers.lIndex.length() << " " <<  myFingers.lPinkie.length() <<  std::endl;
		}
		if(isFingerLengthZero(lThumb)  || !isFingerLengthZero(lPointer) && !isFingerLengthZero(lMiddle) && !isFingerLengthZero(lIndex) && !isFingerLengthZero(lPinkie)){

			std::cout << "Right Hand Fingers :  " << myFingers.rThumb.length() << " " << myFingers.rPointer.length() << " " <<  myFingers.rMiddle.length() << " " << myFingers.rIndex.length() << " " <<  myFingers.rPinkie.length() <<  std::endl;
		}
		detectedfingers = CompareFinger(fingers,hand);
		}
	}
}		
