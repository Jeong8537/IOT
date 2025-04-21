#include "LedToggle.h"

LedToggle::LedToggle(int pin) {
	_pin = pin;
	_state = false;
	_timeDelay = 0;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
}

LedToggle::LedToggle(int pin, unsigned long timeDelay) {
	_pin = pin;
	_state = false;
	_timeDelay = timeDelay;
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
}

void LedToggle::toggle() {
	if (_timeDelay > 0) {
		delay(_timeDelay);
	}

	_state = !_state;
	digitalWrite(_pin, _state ? HIGH : LOW);
}