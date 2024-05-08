#pragma once
#include "ipixelprocessor.h"

class PixelBrightener : public IPixelProcessor {
public:
	uint8_t processPixel(uint8_t pixelGrayscale, uint8_t brightness) override;

	// For brightening, we add a certain grayscale (25) to every pixel.
	// While brightening, some pixels may cross the max brightness. They are
	// called 'attenuated' pixels
	int m_attenuatedPixelCount = 0;
};
