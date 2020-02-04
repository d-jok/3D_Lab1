#include "GLRenderSystem.h"

void GLRenderSystem::init()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

void GLRenderSystem::clearDisplay(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void GLRenderSystem::setViewport(double x, double y, double width, double height)
{
	glViewport(x, y, width, height);
}

void GLRenderSystem::setupLight(uint32_t index, glm::vec3 position, glm::vec3 Ia, glm::vec3 Id, glm::vec3 Is)
{
	float A[] = { Ia[0], Ia[1], Ia[2] };
	float D[] = { Id[0], Id[1], Id[2] };
	float S[] = { Is[0], Is[1], Is[2] };
	float P[] = { position[0], position[1], position[2], 0.0f };

	/*for (int i = 0; i < Ia.length(); i++)
	{
		std::cout << P[i] << "; ";
	}*/

	if (index == 0)
	{
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, A);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, D);
		glLightfv(GL_LIGHT0, GL_SPECULAR, S);
		glLightfv(GL_LIGHT0, GL_POSITION, P);
	}
}

void GLRenderSystem::turnLight(uint32_t index, bool enable)
{

}

void GLRenderSystem::renderTriangleSoup(const std::vector<Vertex>& vertices)
{
	double ViewPortParams[4];
	glGetDoublev(GL_VIEWPORT, ViewPortParams);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, ViewPortParams[2], 0, ViewPortParams[3], 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);
		for (int i = 0; i < vertices.size(); i++)
		{
			glNormal3f(vertices[i].normals.x, vertices[i].normals.y, vertices[i].normals.z);
			glVertex3f(vertices[i].position.x, vertices[i].position.y, vertices[i].position.z);
		}
	glEnd();
}

//GET AND SET
//WorldMatrix
void GLRenderSystem::setWorldMatrix(const glm::mat4& matrix)
{
	WorldMatrix = matrix;
}

const glm::mat4& GLRenderSystem::getWorldMatrix() const
{
	return WorldMatrix;
}

//ViewMatrix
void GLRenderSystem::setViewMatrix(const glm::mat4& matrix)
{
	ViewMatrix = matrix;
}

const glm::mat4& GLRenderSystem::getViewMatrix() const
{
	return ViewMatrix;
}

//ProjMatrix
void GLRenderSystem::setProjMatrix(const glm::mat4& matrix)
{
	ProjMatrix = matrix;
}

const glm::mat4& GLRenderSystem::getProjMatrix() const
{
	return ProjMatrix;
}