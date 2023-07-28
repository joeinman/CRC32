#pragma once

#include <cstdint>
#include <cstddef>

/**
 * @namespace CRC32
 * @brief Contains functions for calculating CRC32 and CRC32C checksums.
 */
namespace CRC32
{
    /**
     * @brief Calculates the CRC32 checksum of a data array.
     * @param data A pointer to the data array.
     * @param size The size of the data array.
     * @return The CRC32 checksum.
     */
    uint32_t crc32(const uint8_t *data, size_t size);

    /**
     * @brief Calculates the CRC32C (Castagnoli) checksum of a data array.
     * @param data A pointer to the data array.
     * @param size The size of the data array.
     * @return The CRC32C checksum.
     */
    uint32_t crc32c(const uint8_t *data, size_t size);
}
