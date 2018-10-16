/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#include <Arduino.h>
#include "Button.h"

Button::Button(int pin, int pin_mode, int delay, bool has_changed, unsigned long ignore_until)
:  _pin(pin)
,  _pin_mode(INPUT_PULLUP)
,  _delay(80)
,  _has_changed(false)
,  _ignore_until(0)
{	
setup(pin, pin_mode, delay, has_changed, ignore_until);
}

Button::~Button()
{}

void Button::setup(int pin, int pin_mode, int delay, bool has_changed, unsigned long ignore_until){
  _pin = pin;
  _pin_mode = pin_mode;
  _delay = delay;
  _has_changed = has_changed;
  _ignore_until = ignore_until;
  if(_pin_mode == INPUT_PULLUP){
	_state = HIGH;
	_defaultstate = HIGH;
  }
  else{
	_state = LOW;
	_defaultstate = LOW;
  }
  pinMode(_pin, _pin_mode);
}

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
