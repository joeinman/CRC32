#include <CRC32/CRC32.h>

namespace CRC32
{
    constexpr uint32_t CRC32_POLYNOMIAL  = 0x04C11DB7;
    constexpr uint32_t CRC32C_POLYNOMIAL = 0x1EDC6F41;
    constexpr uint32_t BIT_31_MASK       = 0x80000000;
    constexpr int      BYTE_TO_BIT_SHIFT = 24;

    uint32_t crc32(const uint8_t *data, size_t size)
    {
        uint32_t remainderPolynomial = 0;

        for (size_t i = 0; i < size; i++)
        {
            remainderPolynomial ^= (data[i] << BYTE_TO_BIT_SHIFT);

            for (int j = 0; j < 8; j++)
            {
                if (remainderPolynomial & BIT_31_MASK)
                {
                    remainderPolynomial = (remainderPolynomial << 1) ^ CRC32_POLYNOMIAL;
                }
                else
                {
                    remainderPolynomial = (remainderPolynomial << 1);
                }
            }
        }

        return remainderPolynomial;
    }

    uint32_t crc32c(const uint8_t *data, size_t size)
    {
        uint32_t remainderPolynomial = 0;

        for (size_t i = 0; i < size; i++)
        {
            remainderPolynomial ^= (data[i] << BYTE_TO_BIT_SHIFT);

            for (int j = 0; j < 8; j++)
            {
                if (remainderPolynomial & BIT_31_MASK)
                {
                    remainderPolynomial = (remainderPolynomial << 1) ^ CRC32C_POLYNOMIAL;
                }
                else
                {
                    remainderPolynomial = (remainderPolynomial << 1);
                }
            }
        }

        return remainderPolynomial;
    }

} // namespace CRC32
