// Offsets.hpp
// Overwatch 2 reversed offsets - Last updated: latest
#pragma once
#include <cstdint>

namespace OW {
    namespace offset {

        // ============================================================================
        // Base addresses for core game structures
        // ============================================================================
        constexpr std::uint64_t Address_viewmatrix_base      = 0x399C5D0;
        constexpr std::uint64_t Address_viewmatrix_base_test = 0x399C5D0; // SIG: 48 8B 0D ? ? ? ? 45 33 C0 E8 ? ? ? ? 48 8B F0
        constexpr std::uint64_t Address_entity_base          = 0x39F4430;

        // ============================================================================
        // View matrix offsets and encryption/decryption keys
        // ============================================================================
        constexpr std::uint64_t offset_viewmatrix_ptr        = 0x0000007E0ULL; // Offset to viewmatrix pointer
        constexpr std::uint64_t offset_viewmatrix_xor_key    = 0x1027AD25A75F4B1i64; // XOR key 1
        constexpr std::uint64_t offset_viewmatrix_xor_key2   = 0x743CF867A977545Bi64; // XOR key 2
        constexpr std::uint64_t offset_viewmatrix_xor_key3   = 0x34F79E3A5B5276BEULL; // XOR key 3

        // ============================================================================
        // Component decryption (XOR decoding for component pointers)
        // ============================================================================
        constexpr std::uint64_t ComponentXorByte             = 0x3840C84;
        constexpr std::uint64_t ComponentXorQword            = 0x3B4FA80;
        constexpr std::uint64_t ComponentXorQwordOffset      = 0xAE;

        // ============================================================================
        // Field of view and other camera/input settings
        // ============================================================================
        constexpr std::uint64_t changefov                    = 0x03550BB8ULL; // SIG: F3 0F 11 05 ? ? ? ?

        // ============================================================================
        // Player controller and input offsets
        // ============================================================================
        constexpr std::uint64_t SensitivePtr                 = 0x00002064ULL; // Mouse sensitivity pointer
        constexpr std::uint64_t view_angle                   = 0x000011A0ULL; // Viewing angle offset
        constexpr std::uint64_t Input                        = 0x0000115CULL; // Input offset

    } // namespace offset
} // namespace OW

// ============================================================================
// Signature references for manual offset finding (IDA/Ghidra)
// ============================================================================
// decryptcomp:      48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 56 48 83 ec ? 49 8b f1 49 8b e8
// HeapManager SIG:  84 C0 74 19 48 8B 0D ? ? ? ? (fifth sub)
// ============================================================================
