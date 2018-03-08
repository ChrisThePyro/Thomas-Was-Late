#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSecond)
{
	if (m_Playing)
	{
		// Count down the time the player has left.
		m_TimeRemaining -= dtAsSecond;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}
	}// End of if playing.
}// End of update function.