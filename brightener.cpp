#include "brightener.h"
#include "pixelbrightener.h"

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage): m_inputImage(inputImage) {
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    PixelBrightener pixelBrightener;
    m_inputImage->pixelRunner(&pixelBrightener);
    return pixelBrightener.m_attenuatedPixelCount;
}

int ImageBrightener::AddBrighteningImage(std::shared_ptr<Image> imageToAdd) {
    if (imageToAdd->m_rows != m_inputImage->m_rows || imageToAdd->m_columns != m_inputImage->m_columns) {
        return -1;
    }
    else
    {
        PixelBrightener pixelBrightener;
        m_inputImage->pixelRunner(&pixelBrightener, imageToAdd);
        return pixelBrightener.m_attenuatedPixelCount;
    }
}

