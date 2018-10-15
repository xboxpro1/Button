/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#include <Arduino.h>
#include "Button.h"

Button::Button(byte pin, bool state, unsigned long delay, bool has_changed, unsigned long ignore_until)
:  _pin(pin)
,  _state(HIGH)
,  _delay(80)
,  _has_changed(false)
,  _ignore_until(0)
{	
setup(pin, state, delay, has_changed, ignore_until);
}

Button::~Button()
{}

void Button::setup(byte pin, bool state, unsigned long delay, bool has_changed, unsigned long ignore_until){
  _pin = pin;
  _state = state;
  _defaultstate = state;
  _delay = delay;
  _has_changed = has_changed;
  _ignore_until = ignore_until;
  if(_state == HIGH){
	pinMode(_pin, INPUT_PULLUP);
  }
  else{
	pinMode(_pin, INPUT);
  }
}

// 
// public methods
// 

bool Button::read()
{
	// ignore pin changes until after this delay time
	if (_ignore_until > millis())
	{
		// ignore any changes during this period
	}
	
	// pin has changed 
	else if (digitalRead(_pin) != _state)
	{
		_ignore_until = millis() + _delay;
		_state = !_state;
		_has_changed = true;
	}
	
	return _state;
}

// has the button been toggled from on -> off, or vice versa
bool Button::toggled()
{
	read();
	return has_changed();
}

// mostly internal, tells you if a button has changed after calling the read() function
bool Button::has_changed()
{
	if (_has_changed == true)
	{
		_has_changed = false;
		return true;
	}
	return false;
}

// has the button gone from off -> on
bool Button::pressed()
{
	if (read() == !_defaultstate && has_changed() == true)
		return true;
	else
		return false;
}

// has the button gone from on -> off
bool Button::released()
{
	if (read() == _defaultstate && has_changed() == true)
		return true;
	else
		return false;
}
