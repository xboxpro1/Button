/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#ifndef Button_h
#define Button_h

#define DEFAULT_DEBOUNCE_DELAY 80
#define DEFAULT_STATE HIGH


class Button
{
	public:
		explicit Button(uint8_t pin = -1, bool state = DEFAULT_STATE, unsigned long delay = DEFAULT_DEBOUNCE_DELAY, bool has_changed = false, unsigned long ignore_until = 0);
		virtual ~Button();
		void setup(uint8_t pin, bool state = DEFAULT_STATE, unsigned long delay = DEFAULT_DEBOUNCE_DELAY, bool has_changed = false, unsigned long ignore_until = 0);
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
			
	private:
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		bool	 _defaultstate;
		bool     _has_changed;
		uint32_t _ignore_until;
};

#endif
