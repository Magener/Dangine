#include "Window.h"

#include <GL/glew.h>
#include <SDL_image.h>
#include <iostream>

namespace Dangine {
	
	Window::Window(int width, int height, const char *title)
		: m_Width(width), m_Height(height) {
		SDL_Init(SDL_INIT_VIDEO);

		m_Instance = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		SDL_GLContext context = SDL_GL_CreateContext(m_Instance);

		glewExperimental = GL_TRUE;
		GLenum error = glewInit();

		if (error != GLEW_OK) {
			std::cout << glewGetErrorString(error) << std::endl;
		}

		IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP);

		SDL_ShowWindow(m_Instance);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		glViewport(0, 0, width, height);
	}

	Window::~Window() {
		SDL_Quit();
		IMG_Quit();
	}

	void Window::clearScreen() {
		SDL_GetWindowSize(m_Instance, &m_Width, &m_Height);
		glViewport(0, 0, m_Width, m_Height);

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	SDL_Event *Window::checkForEvents() {
		SDL_PollEvent(&m_Event);

		return &m_Event;
	}

	bool Window::closed() {
		return m_Event.type == SDL_QUIT;
	}

	void Window::close() const {
		SDL_DestroyWindow(m_Instance);
	}

	void Window::swapFrames() const {
		SDL_GL_SwapWindow(m_Instance);
	}

}
