#pragma once

#include <SDL.h>

namespace Dangine 
{
	
	class Window 
	{
	public:
		Window(int width, int height, const char *title);
		~Window();

		void clearScreen();

		SDL_Event *checkForEvents();

		bool closed();

		void close() const;

		void swapFrames() const;

		inline int getWidth() const 
		{
			return m_Width;
		}

		inline int getHeight() const
		{
			return m_Height;
		}

	private:
		SDL_Window *m_Instance;
		SDL_Event m_Event;
		int m_Width, m_Height;

	};

}
