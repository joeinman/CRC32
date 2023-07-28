#include <CRC32/CRC32.h>
#include <iostream>
#include <cstdint>
#include <array>

int main()
{
    // Generate Some Data
    std::array<uint8_t, 5> data = {0x01, 0x02, 0x03, 0x04, 0x05};

    // Calculate The CRC32 Checksum
    uint32_t checksum = CRC32::crc32(data.data(), data.size());

    // Print The Checksum
    std::cout << "CRC32 Checksum: " << std::hex << checksum << "\n";

    return 0;
}