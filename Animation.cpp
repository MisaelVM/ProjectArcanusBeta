#include "Animation.h"

// -- CONSTRUCTOR --
Animation::Animation(sf::Sprite &_sfSprite, sf::Texture &_sfTexture, float _fFrameTime, int _nFrameWidth, int _nFrameHeight, int _nStartingFramePos, int _nFinalFramePos) {
	// -- Initializing member variables -- //
	fFrameChronometer = 0.f;
	fFrameTime = _fFrameTime;

	nFrameWidth = _nFrameWidth;
	nFrameHeight = _nFrameHeight;

	nStartingFramePos = _nStartingFramePos;
	nFinalFramePos = _nFinalFramePos;

	sfSprite = _sfSprite;
	sfTexture = _sfTexture;
	// ----------------------------------- //

	//IntRect(starting_position_x, starting_position_y, frame_width, frame_height)
	sfFrame = sf::IntRect(nStartingFramePos * nFrameWidth, nStartingFramePos * nFrameHeight, nFrameWidth, nFrameHeight); // Sets the first frame of the animation

	sfSprite.setTexture(sfTexture, true); // Sets the Animation Sheet
	sfSprite.setTextureRect(sfFrame); // Sets the starting frame of the Animation Sheet
}

void Animation::play(const float &fElapsedTime) {
	fFrameChronometer += 100.f * fElapsedTime; // Starts the "Frame chronometer"
	if (fFrameChronometer >= fFrameTime) {
		fFrameChronometer = 0.f; // Restarts the "Frame chronometer"

		// Moves to the next frame in the animation
		if (sfFrame.left != nStartingFramePos)		// if the end is not reached
			sfFrame.left += nFrameWidth;			// moves to the next frame
		else										// else
			sfFrame.left = nStartingFramePos;		// goes back to the starting frame
		sfSprite.setTextureRect(sfFrame);	// Updates the Frame that will be used in the Sprite
	}
}