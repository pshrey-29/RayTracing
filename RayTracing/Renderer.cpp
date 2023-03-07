#include "src/Renderer.h";

#include "Walnut/Random.h"

void Renderer::OnResize(uint32_t width, uint32_t height) {

	if (m_FinalImage) {
		//resize not required
		if (m_FinalImage->GetWidth() == width && m_FinalImage->GetHeight() == height) {
			return;
		}

		m_FinalImage->Resize(width, height);
	}
	else {
		m_FinalImage = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];
}

void Renderer::Render() {
	//renders pixel
	for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++){

		for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++){

			glm::vec2 coord = { (float)x / (float)m_FinalImage->GetWidth(), (float)y / (float)m_FinalImage->GetHeight() };
			coord = coord * 2.0f - 1.0f;
			//making -1 -> +1 from 0 -> 1
			m_ImageData[x + y * m_FinalImage->GetWidth()] = PerPixel(coord);
		}
	}

	m_FinalImage->SetData(m_ImageData);
}

uint32_t Renderer::PerPixel(glm::vec2 coord) {
	
	glm::vec3 rayOrigin(0.0f, 0.0f, 2.0f);
	//ax,ay,az
	glm::vec3 rayDirection(coord.x, coord.y, -1.0f);
	//bx,by,bz
	// rayDirection = glm::normalize(rayDirection);
	float radius = 0.5f;

	// (bx^2 + by^2)t^2 + (2(axbx + ayby))t + (ax^2 + ay^2 - r^2) = 0
	// where,
	// r = radius
	// t = hit distance
	// we will write this eqn for 3d

	float a = glm::dot(rayDirection, rayDirection);
	float b = 2.0f * glm::dot(rayOrigin, rayDirection);
	float c = glm::dot(rayOrigin, rayOrigin) - radius * radius;

	// Quadratic forumula discriminant: b^2 - 4ac
	float discriminant = b * b - 4.0f * a * c;
	if (discriminant >= 0.0f) {
		return 0xff0099ff;
	}

	return 0xff000000;
}