#pragma once

#include <glm/glm.hpp>

#include <vector>

struct Sphere
{
	glm::vec3 Position{ 0.0f };
	float Radius = 0.5f;

	glm::vec3 Albedo{ 1.0f };
};

struct Light
{
	glm::vec3 LightDir = glm::normalize(glm::vec3(-1, -1, -1));
};

struct Scene
{
	int numSpheres = 3;
	std::vector<Sphere> Spheres;
	Light lights;
};