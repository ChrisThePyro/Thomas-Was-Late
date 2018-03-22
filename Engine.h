#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"

using namespace sf;
// SARAH NOTE: Don't use "using" in .h files! Bad!

class Engine
{
private:
	// The Texture Holder.
	TextureHolder th;
	// Sarah Note: Don't name things "th" (single letter abbreviations).

	// Our playable characters Thomas and his friend Bob.
	Thomas m_Thomas;
	Bob m_Bob;

	// A class to manage the levels.
	LevelManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for background.
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Spriate and texture for background.
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or two the current focus?
	bool m_Character1 = true;
	// Sarah Note: Use enum instead, name better.

	// Full or split screen?
	bool m_SplitScreen = false;

	// Time left in current level?
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Is it time for a new/first level.
	bool m_NewLevelRequired = true;

	// The vertex array for the level tiles.
	VertexArray m_VALevel;

	// The 2D array with the map for the level (data) (0 - 3).
	// A pointer to a point (aka 2D array).
	int** m_ArrayLevel = NULL;

	// Texture for the levle tiles.
	Texture m_TextureTiles;

	// Private functions for internal use.
private:
	void input();
	void update(float dtAsSeconds);
	void draw();

	// Load a new level.
	void loadLevel();

	// Detect collisions.
	bool detectCollisions(PlayableCharacter& character);

public:
	// Constructor.
	Engine();

	// Run will call all the private functions in a loop.
	void run();


};