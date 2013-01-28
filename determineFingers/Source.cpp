/******************************************************************************\
* Copyright (C) 2012-2013 Leap Motion, Inc. All rights reserved.               *
* Leap Motion proprietary and confidential. Not for distribution.              *
* Use subject to the terms of the Leap Motion SDK Agreement available at       *
* https://developer.leapmotion.com/sdk_agreement, or another agreement         *
* between Leap Motion and you, your company or other organization.             *
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "..\include\Leap.h"
using namespace Leap;

class SampleListener : public Listener {
public:
	virtual void onInit(const Controller&);
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onExit(const Controller&);
	virtual void onFrame(const Controller&);
	Finger rThumb;
	Finger rPointer;
	Finger rMiddle;
	Finger rIndex;
	Finger rPinkie;
	Finger lThumb;
	Finger lPointer;
	Finger lMiddle;
	Finger lIndex;
	Finger lPinkie;
};

void SampleListener::onInit(const Controller& controller) {
	std::cout << "Initialized" << std::endl;
}

void SampleListener::onConnect(const Controller& controller) {
	std::cout << "Connected" << std::endl;
}

void SampleListener::onDisconnect(const Controller& controller) {
	std::cout << "Disconnected" << std::endl;
}

void SampleListener::onExit(const Controller& controller) {
	std::cout << "Exited" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
	float vArray[9];
	if (!frame.hands().empty()) {
		const Hand hand = frame.hands()[0];
		const Tool tool = frame.tools()[0];
		const FingerList fingers = hand.fingers();
		const ToolList tools = hand.tools();

		if(!tools.empty())
		{
			std::cout << "Tool Length " << tool.length() << std::endl;
		}


		if (!fingers.empty()) {	

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
				}

			}
		}
	}
}

int main() {
	// Create a sample listener and controller
	SampleListener listener;
	Controller controller;

	// Have the sample listener receive events from the controller
	controller.addListener(listener);

	// Keep this process running until Enter is pressed
	std::cout << "Press Enter to quit..." << std::endl;
	std::cin.get();

	// Remove the sample listener when done
	controller.removeListener(listener);

	return 0;
}
