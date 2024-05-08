#include "pixelbrightener.h"

uint8_t PixelBrightener::processPixel(uint8_t pixelGrayscale, uint8_t brightness)
{
	uint8_t outputGrayscale = pixelGrayscale;
	if (outputGrayscale > (255 - brightness)) {
		++m_attenuatedPixelCount;
		outputGrayscale = 255;
	}
	else {
		outputGrayscale += brightness;
	}

	return outputGrayscale;
}
