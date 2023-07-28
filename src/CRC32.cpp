#include <CRC32/CRC32.h>

namespace CRC32
{
    // Calculates the CRC32 checksum of a data array.
    uint32_t crc32(const uint8_t *data, size_t size)
    {
        // The generator polynomial for CRC32
        uint32_t generatorPolynomial = 0x04C11DB7;
        uint32_t remainderPolynomial = 0;

        // Iterate over each byte in the data
        for (size_t i = 0; i < size; i++)
        {
            // Multiply the current byte by x^n-1 and XOR it with the remainder polynomial
            remainderPolynomial ^= (data[i] << 24);

            // Perform polynomial division for each bit in the byte
            for (int j = 0; j < 8; j++)
            {
                // If the coefficient of x^n-1 of the remainder polynomial is 1
                if (remainderPolynomial & 0x80000000)
                {
                    // Multiply the remainder polynomial by x and XOR it with the generator polynomial
                    remainderPolynomial = (remainderPolynomial << 1) ^ generatorPolynomial;
                }
                else
                {
                    // Multiply the remainder polynomial by x
                    remainderPolynomial = (remainderPolynomial << 1);
                }
            }
        }

        // Return the final remainder polynomial as the CRC32 checksum
        return remainderPolynomial;
    }

    // Calculates the CRC32C (Castagnoli) checksum of a data array.
    uint32_t crc32c(const uint8_t *data, size_t size)
    {
        // The generator polynomial for CRC32C
        uint32_t generatorPolynomial = 0x1EDC6F41;
        uint32_t remainderPolynomial = 0;

        // The process is the same as for CRC32, but with a different generator polynomial
        for (size_t i = 0; i < size; i++)
        {
            remainderPolynomial ^= (data[i] << 24);

            for (int j = 0; j < 8; j++)
            {
                if (remainderPolynomial & 0x80000000)
                {
                    remainderPolynomial = (remainderPolynomial << 1) ^ generatorPolynomial;
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
