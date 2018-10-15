/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#ifndef Button_h
#define Button_h

#define DEFAULT_DEBOUNCE_DELAY 100
#define DEFAULT_STATE HIGH


class Button
{
	public:
		explicit Button(uint8_t pin = -1, unsigned long delay = DEFAULT_DEBOUNCE_DELAY, bool state = DEFAULT_STATE, bool has_changed = false, unsigned long ignore_until = 0);
		virtual ~Button();
		void setup(uint8_t pin, unsigned long delay = DEFAULT_DEBOUNCE_DELAY, bool state = DEFAULT_STATE, bool has_changed = false, unsigned long ignore_until = 0);
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
		const static bool PRESSED = LOW;
		const static bool RELEASED = HIGH;
	
	private:
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		bool     _has_changed;
		uint32_t _ignore_until;
};

#endif
