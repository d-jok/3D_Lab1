#include "GLWindow.h"

//FRIEND FUNCTIONS
void KeyCallbackFunc(GLFWwindow* handle, int key, int scancode, int action, int mods)
{
	GLWindow* window = (GLWindow*)glfwGetWindowUserPointer(handle);

	if (window)
	{
		window->key_callback((KeyCode)key, (Action)action, (Modifier)mods);
		std::cout << "yes";
	}
}

void CursorPos(GLFWwindow* handle, double xpos, double ypos)
{
	GLWindow* window = (GLWindow*)glfwGetWindowUserPointer(handle);
	if (window)
	{
		window->cursor_callback((double)xpos, (double)ypos);
	}
}

void MouseCallbackFunc(GLFWwindow* handle, int button, int action, int mods)
{
	GLWindow* window = (GLWindow*)glfwGetWindowUserPointer(handle);

	double xpos;
	double ypos;

	glfwGetCursorPos(handle, &xpos, &ypos);

	if (window)
	{
		window->mouse_callback((ButtonCode)button, (Action)action, (Modifier)mods, (double)xpos, (double)ypos);
		std::cout << "ON";
	}
}

void ScrollCallbackFunc(GLFWwindow * handle, double xoffset, double yoffset)
{
	GLWindow* window = (GLWindow*)glfwGetWindowUserPointer(handle);

	if (window)
	{
		window->scroll_callback(xoffset, yoffset);
	}
}
//END OF FRIEND FUNCTIONS

GLWindow::GLWindow(const std::string& title, uint32_t width, uint32_t height)
{
	Width = width;
	Height = height;

	handle = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
	glfwMakeContextCurrent(handle);

	static bool initGLAD = false;
	if (!initGLAD)
	{
		initGLAD = true;
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	/*glfwSetWindowUserPointer(handle, this);
	glfwSetKeyCallback(handle, KeyCallbackFunc);
	glfwSetMouseButtonCallback(handle, MouseCallbackFunc);
	glfwSetCursorPosCallback(handle, CursorPos);*/
	/*glfwSetScrollCallback(handle, );*/
	/*while (true)
	{
		double xpos;
		double ypos;

		glfwGetCursorPos(handle, &xpos, &ypos);

		std::cout << xpos << " " << ypos << std::endl;
	}*/

}

GLWindow::~GLWindow()
{

}

GLFWwindow* GLWindow::getGLFWHandle() const
{
	return handle;
}

//GET width and height
uint32_t GLWindow::getWidth() const
{
	return Width;
}

uint32_t GLWindow::getHeight() const
{
	return Height;
}

//SetKeyCallback
void GLWindow::SetKeyCallback(const KeyCallback& callback)
{
	key_callback = callback;
	glfwSetKeyCallback(handle, KeyCallbackFunc);
}

//SetCursorPosCallback
void GLWindow::setCursorPosCallback(const CursorPosCallback& callback)
{
	cursor_callback = callback;
	glfwSetCursorPosCallback(handle, CursorPos);
}

//SetMouseCallback
void GLWindow::setMouseCallback(const MouseCallback& callback)
{
	mouse_callback = callback;
	glfwSetMouseButtonCallback(handle, MouseCallbackFunc);
}

//SetScrollCallback
void GLWindow::setScrollCallback(const ScrollCallback& callback)
{
	scroll_callback = callback;
	glfwSetScrollCallback(handle, ScrollCallbackFunc);
}

