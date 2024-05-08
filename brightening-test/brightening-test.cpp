#include "CppUnitTest.h"
#include "../brightener.h"
#include "../pixelbrightener.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace brighteningtest
{	
	TEST_CLASS(BrighteningTest)
	{
	public:
		std::shared_ptr<Image> m_image;
		BrighteningTest()
		{
			m_image = std::make_shared<Image>(2, 2);
			m_image->m_pixels[0] = 45; m_image->m_pixels[1] = 55;
			m_image->m_pixels[2] = 65; m_image->m_pixels[3] = 254;
		}
		TEST_METHOD(BrightensWholeImage)
		{

			ImageBrightener brightener(m_image);

			int attenuatedCount = brightener.BrightenWholeImage();
			Assert::AreEqual(1, attenuatedCount);
			Assert::AreEqual(90, int(m_image->m_pixels[2]));
		}

		TEST_METHOD(BrightensWithAnotherImage)
		{

			ImageBrightener brightener(m_image);
            
            // Test by brightening only the right part
            auto brighteningImage = std::make_shared<Image>(2, 2);
            brighteningImage->m_pixels[0] = 0; brighteningImage->m_pixels[1] = 25;
            brighteningImage->m_pixels[2] = 0; brighteningImage->m_pixels[3] = 25;

			int attenuatedCount = brightener.AddBrighteningImage(brighteningImage);
            Assert::IsTrue(attenuatedCount != -1);
            Assert::AreEqual(45, int(m_image->m_pixels[0])); // left-side pixel is unchanged
            Assert::AreEqual(80, int(m_image->m_pixels[1])); // right-side pixel is brightened
            Assert::AreEqual(1, attenuatedCount);
		}
	};
}
