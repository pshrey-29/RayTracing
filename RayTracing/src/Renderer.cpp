#include "Renderer.h"


void Renderer::OnResize(uint32_t width, uint32_t height) {

	if (!m_Image) {
		//resize not required
		if (m_Image->GetWidth() == width && m_Image->GetHeight() == height) {
			return;
		}

		m_Image->Resize(width, height);
	}
	else {
		m_Image = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
	}

	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];
}

void Renderer::Render() {
	//renders pixel

}