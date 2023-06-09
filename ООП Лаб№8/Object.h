#pragma once
#include <iostream>
#include "Event.h"
using namespace std;

class Object
{
public:
	virtual void HandleEvent(const TEvent& e) = 0;
	Object(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object(void);
};
