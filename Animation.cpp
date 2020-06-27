#include "Animation.h"

// -- CONSTRUCTOR --
Animation::Animation(sf::Sprite &_sfSprite, sf::Texture &_sfTexture, float _fFrameTime, int _nFrameWidth, int _nFrameHeight, int _nStartingFramePosX, int _nStartingFramePosY, int _nFinalFramePosX, int _nFinalFramePosY)
	// Initializing references
	: sfSprite(_sfSprite), sfTexture(_sfTexture) {

	// -- Initializing member variables -- //
	fFrameChronometer = 0.f;
	fFrameTime = _fFrameTime;

	nFrameWidth = _nFrameWidth;
	nFrameHeight = _nFrameHeight;

	nStartingFramePosX = _nStartingFramePosX;
	nStartingFramePosY = _nStartingFramePosY;
	nFinalFramePosX = _nFinalFramePosX;
	nFinalFramePosY = _nFinalFramePosY;
	// ----------------------------------- //

	//IntRect(starting_position_x, starting_position_y, frame_width, frame_height)
	sfFrame = sf::IntRect(nStartingFramePosX * nFrameWidth, nStartingFramePosY * nFrameHeight, nFrameWidth, nFrameHeight); // Sets the first frame of the animation

	sfSprite.setTexture(sfTexture, true); // Sets the Animation Sheet
	sfSprite.setTextureRect(sfFrame); // Sets the starting frame of the Animation Sheet
}

void Animation::play(const float &fElapsedTime) {
	fFrameChronometer += 100.f * fElapsedTime; // Starts the "Frame chronometer"
	if (fFrameChronometer >= fFrameTime) {
		fFrameChronometer = 0.f; // Restarts the "Frame chronometer"

		// Moves to the next frame in the animation
		if (sfFrame.left != (nFinalFramePosX * nFrameWidth))	// if the end is not reached
			sfFrame.left += nFrameWidth;							// moves to the next frame
		else													// else
			sfFrame.left = nStartingFramePosX;						// goes back to the starting frame
		sfSprite.setTextureRect(sfFrame);	// Updates the Frame that will be used in the Sprite
	}
}