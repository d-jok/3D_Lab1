#include "conio.h";
#include <iostream>;
#include <glm/gtc/matrix_transform.hpp>;
#include <glm/gtx/transform.hpp>;

#include "GLWindow.h";
#include "GLRenderSystem.h";

GLRenderSystem rs;

void renderScene(GLRenderSystem& rs)
{
	std::vector<Vertex> vertices;

	vertices.push_back(Vertex{ glm::vec3(100.0f, 200.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f) });
	vertices.push_back(Vertex{ glm::vec3(100, 100, 0), glm::vec3(0, 0, 1) });
	vertices.push_back(Vertex{ glm::vec3(200, 100, 0), glm::vec3(0, 0, 1) });

	vertices.push_back(Vertex{ glm::vec3(200, 100, 0), glm::vec3(0, 0, 1) });
	vertices.push_back(Vertex{ glm::vec3(200, 200, 0), glm::vec3(0, 0, 1) });
	vertices.push_back(Vertex{ glm::vec3(100, 200, 0), glm::vec3(0, 0, 1) });

	rs.renderTriangleSoup(vertices);
}

void moveCube(GLRenderSystem& rs, glm::vec3 offset)
{
	std::cout << " IN " << std::endl;
}

void onKeyCallback(KeyCode key, Action action, Modifier mods)
{
	if (key == KeyCode::UP)
	{
		moveCube(rs, glm::vec3(0.0f, 0.1f, 0.0f));
		std::cout << (int)key << " YES " << std::endl;
	}
	if (key == KeyCode::DOWN)
		moveCube(rs, glm::vec3(0.0f, -0.1f, 0.0f));
	if (key == KeyCode::LEFT)
		moveCube(rs, glm::vec3(-0.1f, 0.0f, 0.0f));
	if (key == KeyCode::RIGHT)
		moveCube(rs, glm::vec3(0.1f, 0.0f, 0.0f));
}

int main()
{
	glfwInit();
	GLRenderSystem rs;
	GLWindow window("myWindow", 640, 480);

	window.SetKeyCallback(onKeyCallback);

	rs.init();
	rs.setupLight(0, glm::vec3{ 0,5,0 }, glm::vec3{ 1,0,0 }, glm::vec3{ 0,1,0 }, glm::vec3{ 0,0,1 });
	rs.turnLight(0, true);

	glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rs.setViewMatrix(viewMatrix);

	glm::mat4 projMatrix = glm::perspective(glm::radians(60.0f), 640.0f / 480.0f, 0.1f, 500.0f);
	rs.setProjMatrix(projMatrix);

	while (!glfwWindowShouldClose(window.getGLFWHandle()))	//?????? "!"
	{
		rs.setViewport(0, 0, window.getWidth(), window.getHeight());
		rs.clearDisplay(0.5f, 0.5f, 0.5f);

		renderScene(rs);

		std::cout << "smth ";

		glfwSwapBuffers(window.getGLFWHandle());
		glfwWaitEvents();
	}
	
	//_getch();
	glfwTerminate();
	return 0;
}