#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{

	if (m_NewLevelRequired)
	{
		loadLevel();
	}

	if (m_Playing)
	{

		// Update Thomas and Bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		// Detect collisions and see if the characters have reached the goal.
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New level required.
			m_NewLevelRequired = true;

			// TODO: Play sound for reaching goal.
		}
		else
		{
			// Run bob collision detection.
			detectCollisions(m_Bob);
		}

		// let Bob and Thomas jump on each others heads.
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}

		if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the time the player has left.
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}// End of if playing.

	// Set the view around the appripriate character.
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCentre());
		m_RightView.setCenter(m_Bob.getCentre());
	}
	else
	{
		if (m_Character1) // If we should focus on Thomas.
		{
			m_MainView.setCenter(m_Thomas.getCentre());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCentre());
		}
	}

}// End of update function.