#pragma once
#include <glm/glm.hpp>
#include "glad.h"
#include <glfw/glfw3.h>
#include <iostream>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normals;
};

class GLRenderSystem
{
public:
	void init();

	void clearDisplay(float r, float g, float b);
	void setViewport(double x, double y, double width, double height);
	void renderTriangleSoup(const std::vector<Vertex>& vertices);
	void setupLight(uint32_t index, glm::vec3 position, glm::vec3 Ia, glm::vec3 Id, glm::vec3 Is);
	void turnLight(uint32_t index, bool enable);

	void setWorldMatrix(const glm::mat4& matrix);
	const glm::mat4& getWorldMatrix() const;

	void setViewMatrix(const glm::mat4& matrix);
	const glm::mat4& getViewMatrix() const;

	void setProjMatrix(const glm::mat4& matrix);
	const glm::mat4& getProjMatrix() const;

private:
	glm::mat4 WorldMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ProjMatrix;
	//TODO
};