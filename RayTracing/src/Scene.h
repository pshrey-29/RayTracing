#pragma once

#include <glm/glm.hpp>

#include <vector>

struct Material
{
	glm::vec3 Albedo{ 1.0f };
	float Roughness = 1.0f;
	float Metallic = 0.0f;
};

struct Sphere
{
	glm::vec3 Position{ 0.0f };
	float Radius = 0.5f;

	int MaterialIndex = 0;
};

struct Light
{
	glm::vec3 LightDir = glm::normalize(glm::vec3(-1, -1, -1));
};

struct Scene
{
	int numSpheres = 3;
	std::vector<Sphere> Spheres;
	std::vector<Material> Materials;
	Light lights;
};