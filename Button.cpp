/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#include "Button.h"

Button::Button(uint8_t pin, unsigned long delay, bool state, bool has_changed, unsigned long ignore_until)
:  _pin(pin)
,  _delay(100)
,  _state(HIGH)
,  _has_changed(false)
,  _ignore_until(0)
{	
setup(pin, delay, state, has_changed, ignore_until);
}

Button::~Button()
{}

void Button::setup(uint8_t pin, unsigned long delay, bool state, bool has_changed, unsigned long ignore_until){
  _pin = pin;
  _delay = delay;
  _state = state;
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
	if (read() == PRESSED && has_changed() == true)
		return true;
	else
		return false;
}

// has the button gone from on -> off
bool Button::released()
{
	if (read() == RELEASED && has_changed() == true)
		return true;
	else
		return false;
}
