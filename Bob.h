#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:

	// Constructor
	Bob();

	// This will implement the pure virtual function from PlayableCharacter.
	bool virtual handleInput();

}; // End class Bob.
