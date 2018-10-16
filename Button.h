/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#include <Arduino.h>

#ifndef Button_h
#define Button_h

#define DEFAULT_DEBOUNCE_DELAY 80
#define DEFAULT_MODE INPUT_PULLUP


class Button
{
	public:
		explicit Button(int pin = -1, int pin_mode = DEFAULT_MODE, int delay = DEFAULT_DEBOUNCE_DELAY, bool has_changed = false, unsigned long ignore_until = 0);
		virtual ~Button();
		void setup(int pin, int pin_mode = DEFAULT_MODE, int delay = DEFAULT_DEBOUNCE_DELAY, bool has_changed = false, unsigned long ignore_until = 0);
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
			
	private:
		int	_pin;
		int	_pin_mode;
		int	_delay;
		bool	_state;
		bool	_default_state;
		bool	_has_changed;
		unsigned long	_ignore_until;
};	

#endif
