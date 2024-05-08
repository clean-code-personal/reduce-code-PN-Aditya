#pragma once
#include <cstdint>

class IPixelProcessor {
public:
	virtual uint8_t processPixel(uint8_t pixelGrayscale, uint8_t brightness) = 0;
};
