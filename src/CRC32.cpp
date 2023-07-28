#include <CRC32/CRC32.h>

namespace CRC32
{

    uint32_t crc32(const uint8_t *data, size_t size)
    {
        uint32_t generatorPolynomial = 0xEDB88320; // This is the reversed polynomial 0x04C11DB7
        uint32_t remainderPolynomial = 0xFFFFFFFF;

        for (size_t i = 0; i < size; i++)
        {
            remainderPolynomial ^= data[i];
            for (int j = 0; j < 8; j++)
            {
                if (remainderPolynomial & 1)
                {
                    remainderPolynomial = (remainderPolynomial >> 1) ^ generatorPolynomial;
                }
                else
                {
                    remainderPolynomial >>= 1;
                }
            }
        }

        return remainderPolynomial ^ 0xFFFFFFFF;
    }

    uint32_t crc32c(const uint8_t *data, size_t size)
    {
        uint32_t generatorPolynomial = 0x82F63B78; // This is the reversed polynomial 0x1EDC6F41
        uint32_t remainderPolynomial = 0xFFFFFFFF;

        for (size_t i = 0; i < size; i++)
        {
            remainderPolynomial ^= data[i];
            for (int j = 0; j < 8; j++)
            {
                if (remainderPolynomial & 1)
                {
                    remainderPolynomial = (remainderPolynomial >> 1) ^ generatorPolynomial;
                }
                else
                {
                    remainderPolynomial >>= 1;
                }
            }
        }

        return remainderPolynomial ^ 0xFFFFFFFF;
    }

} // namespace CRC32
