#pragma once
#include "glad.h";
#include <glfw/glfw3.h>;
#include <functional>;
#include <string>;
#include <iostream>

enum class Modifier
{
	NoModifier = 0,
	Shift = 1,
	Control = 2,
	Alt = 4,
	Super = 8,
};

enum class Action
{
	Release = 0,
	Press = 1,
	Repeat = 2,
};

enum class ButtonCode
{
	Button_0 = 0,
};

enum class KeyCode
{
	UNKNOWN = -1,
	Space = 32,
	UP = 265,
	DOWN = 264,
	LEFT = 263,
	RIGHT = 262
};

class GLWindow
{
	friend void KeyCallbackFunc(GLFWwindow*, int, int, int, int);
	friend void CursorPos(GLFWwindow*, double, double);
	friend void MouseCallbackFunc(GLFWwindow*, int, int, int);
	friend void ScrollCallbackFunc(GLFWwindow*, double, double);

public:
	using KeyCallback = std::function<void(KeyCode, Action, Modifier)>;
	using CursorPosCallback = std::function<void(double, double)>;
	using MouseCallback = std::function<void(ButtonCode, Action, Modifier, double, double)>;
	using ScrollCallback = std::function<void(double, double)>;

	GLWindow(const std::string& title, uint32_t width, uint32_t height);
	~GLWindow();
	uint32_t getWidth() const;
	uint32_t getHeight() const;
	void SetKeyCallback(const KeyCallback& callback);
	void setCursorPosCallback(const CursorPosCallback& callback);
	void setMouseCallback(const MouseCallback& callback);
	void setScrollCallback(const ScrollCallback& callback);

	GLFWwindow* getGLFWHandle() const;

private:
	uint32_t Width;
	uint32_t Height;
	GLFWwindow* handle;
	KeyCallback key_callback;
	CursorPosCallback cursor_callback;
	MouseCallback mouse_callback;
	ScrollCallback scroll_callback;
	//TODO
};