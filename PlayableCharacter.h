#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
// These veriables are shared with sub class children (Thomas and Bob).
protected:

	Sprite m_Sprite;

	// How long does a jump last?
	float m_JumpDuration;

	// Is the character currently jumping or falling?
	bool m_IsJumping;
	bool m_IsFalling;

	// Which direction is the character current moving in?
	bool m_LeftPressed;
	bool m_RightPressed;

	// How long has this jump lasted so far?
	float m_TimeThisJump;

	// Has the player just initiated a jump?
	bool m_JustJumped = false;

// These variables can only be edited and viewd by THIS class, NOT sub classes.
private:

	// What is gravery?
	float m_Gravity;

	// How fast is the character?
	float m_Speed = 400;

	// Where is the player?
	Vector2f m_Position;

	// Where are the characters various body parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_Texture;

// Public functions available to ALL other classes (and this one).
public:

	void spawn(Vector2f startPosition, float grabity);

	// This is a pure virtual fucntion, this means this class becomes an abstract class
	// Meaning we cannot create an instance of this class only sub classes and sub classes
	// We must impliment this function in order to create instances.

	bool virtual handleInput() = 0;

	// Where is the player?
	FloatRect getPosition();

	// A rectangle representing the position of different parts of the sprite.
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getLeft();
	FloatRect getRight();

	// Get a copy to the sprite
	Sprite getSprite();

	// Make the character stop moving.
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();
	Vector2f getCentre();

	// We will call this function once every frame.
	void update(float elapsedTime);

}; // End of playerableCharacter class.