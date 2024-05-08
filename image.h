#pragma once
#include <cstdint>
#include <iostream>
#include "ipixelprocessor.h"

class Image {
public:
	Image(uint16_t rows, uint16_t columns): m_rows(rows), m_columns(columns) {
		m_pixels = new uint8_t[m_rows * m_columns];
	}
	~Image() {
		std::cout << "freeing pixel memory.\n";
		delete[] m_pixels;
	}
	bool imageSizeIsValid() {
		return m_rows <= 1024 && m_columns <= 1024;
	}

	void pixelRunner(IPixelProcessor* pixelProcessor, std::shared_ptr<Image> imageToAdd = 0) {
		std::cout << "-- pixelRunner: interface version\n";
		for (int x = 0; x < m_rows; x++) {
			for (int y = 0; y < m_columns; y++) {
				int pixelIndex = x * m_columns + y;
				m_pixels[pixelIndex] = pixelProcessor->processPixel(m_pixels[pixelIndex], imageToAdd? imageToAdd->m_pixels[pixelIndex]: 25);
			}
		}
	}

	const uint16_t m_rows;
	const uint16_t m_columns;
	uint8_t* m_pixels; // max 1k x 1k image
};
