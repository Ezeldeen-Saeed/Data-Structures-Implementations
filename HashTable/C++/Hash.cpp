#include <cstring>
#include <iostream>
#include <string>

class Hash {
public:
  // Compute 32-bit FNV-1 hash
  uint32_t Hash32(std::string str) {
    // Constants used for FNV-1 hash algorithm
    uint32_t OffsetBasis = 2166136261;
    uint32_t FNVPrime = 16777619;

    // Convert string to byte array
    const char *data = str.c_str();
    size_t len = str.length();
    uint8_t *bytes = new uint8_t[len];
    memcpy(bytes, data, len);

    // Compute hash using FNV-1 algorithm
    uint32_t hash = OffsetBasis;
    for (size_t i = 0; i < len; i++) {
      hash = hash ^ bytes[i];
      hash = hash * FNVPrime;
    }

    // Print result to console
    std::cout << str << ", " << hash << ", " << std::hex << hash << std::endl;

    // Clean up allocated memory
    delete[] bytes;

    return hash;
  }

  // Compute 64-bit FNV-1 hash
  uint64_t Hash64(std::string str) {
    // Constants used for FNV-1 hash algorithm
    uint64_t OffsetBasis = 14695981039346656037ull;
    uint64_t FNVPrime = 1099511628211ull;

    // Convert string to byte array
    const char *data = str.c_str();
    size_t len = str.length();
    uint8_t *bytes = new uint8_t[len];
    memcpy(bytes, data, len);

    // Compute hash using FNV-1 algorithm
    uint64_t hash = OffsetBasis;
    for (size_t i = 0; i < len; i++) {
      hash = hash ^ bytes[i];
      hash = hash * FNVPrime;
    }

    // Print result to console
    std::cout << str << ", " << hash << ", " << std::hex << hash << std::endl;

    // Clean up allocated memory
    delete[] bytes;

    return hash;
  }
};
