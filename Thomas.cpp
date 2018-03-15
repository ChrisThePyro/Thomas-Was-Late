#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{

	// Associate a texture with a sprite.
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45f;

} // End function Thomas().

//=======================================================================

bool Thomas::handleInput()
{
	// Always start assuming you're not jumping.
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		// Start a jump if not already jumping, but only if on a block and not falling.
		if (!m_IsJumping && !m_IsFalling)
		{

			// Perform Jump
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;

		} // End if not jumping or falling.
	} // End if keyboard pressed W.
	else
	{
		// Stop jump early if W is not held down.
		m_IsJumping = false;
		m_IsFalling = true;

	} // End W not pressed.

	// Check left.
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	// Check Right.
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	// Return weather we just jumped or not.
	return m_JustJumped;

} // End functhion handleInput().