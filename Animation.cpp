#include "Animation.h"

// -- CONSTRUCTOR --
Animation::Animation(sf::Sprite &_sfSprite, sf::Texture &_sfTexture, float fTime, int nWidth, int nHeight) {
	fFrameChronometer = 0;
	sfSprite = _sfSprite;
	sfTexture = _sfTexture;

	//IntRect(starting_position_x, starting_position_y, frame_width, frame_height)
	sf::IntRect sfRect(1, 1, nWidth, nHeight); // Sets the first frame of the animation

	sfSprite.setTexture(sfTexture, true); // Sets the Animation Sheet
	sfSprite.setTextureRect(sfRect); // Sets the starting frame of the Animation Sheet
}

void Animation::play(const float &fElapsedTime) {
	fFrameChronometer += 100.f * fElapsedTime; // Starts the "Frame chronometer"

	if (fFrameChronometer >= 10.f) {
		fFrameChronometer = 0.f; // Restarts the "Frame chronometer"
		/* // Moves to the next frame	-- PSEUDOCODE --
		if (current_frame != final_frame) // -- if (end is not reached) --
			moves to next frame;
		else
			goes back to the starting frame
		*/
	}

}