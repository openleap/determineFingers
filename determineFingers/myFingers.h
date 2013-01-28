#include <algorithm>
#include "..\include\Leap.h"
#pragma once
using namespace Leap;
class myFingers : public Listener
{
public:
	myFingers(void);
	~myFingers(void);
	virtual void onInit(const Controller&);
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onExit(const Controller&);
	virtual void onFrame(const Controller&);

	void setupFingers(const FingerList& fingers, const Hand& hand);
	bool isFingerLengthZero(Finger finger);
	Finger GetrThumb();
	Finger GetrPointer();
	Finger GetrMiddle();
	Finger GetrIndex();
	Finger GetrPinkie();
	Finger GetlThumb();
	Finger GetlPointer();
	Finger GetlMiddle();
	Finger GetlIndex();
	Finger GetlPinkie();
	FingerList CompareFinger(const FingerList& fingers, const Hand& hand);
private:
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
	bool SetupComplete;
};

