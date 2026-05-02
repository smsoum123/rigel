#pragma once
#include "IDAdefs.h"
#include <intrin.h>
#include <vector>
#include <iostream>

#define ISVALID(x) ((x) && (x) != INVALID_HANDLE_VALUE)
#define ROR8(x, y) _rotr64(x, y)
#define ROL8(x, y) _rotl64(x, y)

namespace OW {

    uint64_t FnSkillStruct(__m128* a1, uint16_t* a2) {
        __m128 v1 = *a1;
        __m128i v2 = _mm_cvtsi32_si128(a2[0]);
        __m128i v3 = _mm_cvtsi32_si128(a2[1]);
        __m128 v4 = _mm_cvtepi32_ps(_mm_unpacklo_epi32(v2, v3));
        __m128 v5 = _mm_shuffle_ps(v1, v1, 0);
        __m128 v6 = _mm_shuffle_ps(v1, v1, 85);
        __m128 v7 = _mm_shuffle_ps(v1, v1, 170);
        __m128 v8 = _mm_mul_ps(v4, v5);
        __m128 v9 = _mm_mul_ps(v4, v6);
        __m128 v10 = _mm_mul_ps(v4, v7);
        __m128 v11 = _mm_add_ps(v8, _mm_shuffle_ps(v1, v1, 255));
        __m128 v12 = _mm_add_ps(v9, _mm_shuffle_ps(v1, v1, 255));
        __m128 v13 = _mm_add_ps(v10, _mm_shuffle_ps(v1, v1, 255));
        __m128i v14 = _mm_cvtps_epi32(v11);
        __m128i v15 = _mm_cvtps_epi32(v12);
        __m128i v16 = _mm_cvtps_epi32(v13);
        __m128i v17 = _mm_unpacklo_epi32(v14, v15);
        __m128i v18 = _mm_unpacklo_epi32(v16, _mm_setzero_si128());
        __m128i v19 = _mm_unpacklo_epi64(v17, v18);
        return _mm_cvtsi128_si64(v19);
    }

    class HPComponent {
    public:
        char pad_0001[0xDC]; Vector2 Health; char pad_0002[0x21C]; Vector2 Armor; char pad_0003[0x35C]; Vector2 Barrier;
        Vector2 GetHealth() {
            Vector2 HP = SDK->RPM<Vector2>((uint64_t)&this->Health);
            Vector2 Ar = SDK->RPM<Vector2>((uint64_t)&this->Armor);
            Vector2 Br = SDK->RPM<Vector2>((uint64_t)&this->Barrier);
            return { HP.X + Ar.X + Br.X ,HP.Y + Ar.Y + Br.Y };
        }
    };

    struct health_compo_t { union { OFF_MEMB(float, health, 0xE0); OFF_MEMB(float, health_max, 0xDC); OFF_MEMB(float, armor, 0x220); OFF_MEMB(float, armor_max, 0x21C); OFF_MEMB(float, barrier, 0x360); OFF_MEMB(float, barrier_max, 0x35C); OFF_MEMB(bool, isImmortal, 0x4A9); OFF_MEMB(bool, isBarrierProjected, 0x4A8); }; };
    struct obj_compo_t { union { OFF_MEMB(XMFLOAT3, obj_pos, 0xE0); }; };
    struct velocity_compo_t { union { OFF_MEMB(XMFLOAT3, velocity, 0x50); OFF_MEMB(XMFLOAT3, location, 0x1B0 + 0x50); OFF_MEMB(uint64_t, bonedata, 0x8C0); }; };
    struct hero_compo_t { union { OFF_MEMB(uint64_t, heroid, 0xE0); }; };
    struct vis_compo_t { union { OFF_MEMB(uint64_t, key1, 0xA0); OFF_MEMB(uint64_t, key2, 0x98); }; };

    inline uint64_t DecryptComponent(uint64_t Entity, uint8_t ComponentID) {
        if (!Entity) return 0;
        uint64_t list = SDK->RPM<uint64_t>(Entity + 0x80);
        uint32_t count = SDK->RPM<uint32_t>(Entity + 0x88);
        if (count > 0x400 || !list) return 0;

        uint8_t  var_byte  = SDK->RPM<uint8_t>(SDK->dwGameBase + 0x3762243);
        uint64_t var_qword = SDK->RPM<uint64_t>(SDK->RPM<uint64_t>(SDK->dwGameBase + 0x3A75970) + 0x1D4);

        for (uint32_t i = 0; i < count; i++) {
            uint64_t e = SDK->RPM<uint64_t>(list + i * 8);
            if (!e) continue;
            e ^= var_qword;
            e = ROR8((var_byte ^ (ROR8(e ^ 0xDC01B58B9BDFFB4Bull, 32) + 0x24620C984E36588LL)) - 0x7D957CD64821F39Bull, 60);
            e = ROR8(e, 57);
            if (SDK->RPM<uint8_t>(e + 0x10) == ComponentID) return e;
        }
        return 0;
    }

    inline unsigned __int64 DecryptVis(unsigned __int64 a1) {
        unsigned __int64 v2 = (SDK->dwGameBase + offset::VisFN);
        unsigned __int64 v3 = v2 + 0x8;
        __int64 v5 = SDK->RPM<uintptr_t>(SDK->dwGameBase + offset::VisRead + 8ull * (((uint8_t)a1 + 0x4D) & 0x7F) + (((unsigned __int64)(a1 + offset::Vis_Key1) >> 7) & 7)) ^ v2 ^ (a1 + offset::Vis_Key1);
        if (v5) {
            __m128i v8 = _mm_setzero_si128(); __m128i v9 = _mm_setzero_si128();
            unsigned __int64 temp = v2;
            for (int i = 0; i < 4; ++i) {
                v8 = _mm_xor_si128(v8, _mm_loadu_si128((const __m128i*)temp));
                v9 = _mm_xor_si128(v9, _mm_loadu_si128((const __m128i*)(temp + 0x10)));
                temp += 0x20;
            }
            __m128i tmp = _mm_xor_si128(v8, v9);
            __m128i final = _mm_xor_si128(tmp, _mm_srli_si128(tmp, 8));
            v5 = *(__int64*)&final; v2 = temp;
        }
        for (; v2 < v3; v2 += 8) v5 ^= SDK->RPM<DWORD_PTR>(v2);
        return v5 ^ \~v3 ^ 0x3C0AA484DAE5234Di64;
    }

    inline bool IsSkillActive(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2) {
        __m128 skillStruct{}; uint16_t skillId[15] = { skillIdx, skillIdx2 };
        skillStruct.m128_u64[1] = base + 0xD0;
        uint64_t skill = FnSkillStruct(&skillStruct, skillId);
        if (!skill) return false;
        return SDK->RPM<bool>(skill + 0x60);
    }

    inline bool IsSkillActivate1(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2) {
        return IsSkillActive(base, skillIdx, skillIdx2);
    }

    inline float readult(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2) {
        __m128 skillStruct{}; uint16_t skillId[15] = { skillIdx, skillIdx2 };
        skillStruct.m128_u64[1] = base + 0xD0;
        uint64_t skill = FnSkillStruct(&skillStruct, skillId);
        if (!skill) return 0.0f;
        return SDK->RPM<float>(skill + 0x60);
    }

    inline float readskillcd(uint64_t base, uint16_t skillIdx, uint16_t skillIdx2) {
        __m128 skillStruct{}; uint16_t skillId[15] = { skillIdx, skillIdx2 };
        skillStruct.m128_u64[1] = base + 0xD0;
        uint64_t skill = FnSkillStruct(&skillStruct, skillId);
        if (!skill) return 0.0f;
        return SDK->RPM<float>(skill + 0x48);
    }

    inline uintptr_t GetHeapManager(uint8_t index) {
        uintptr_t dummy0 = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x3882880);
        uintptr_t dummy1 = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x38672D3);
        uintptr_t v5 = SDK->RPM<uintptr_t>(dummy0 + 0x160) ^ (dummy1 + 0x6DE0CEEB548519C3i64);
        if (v5) return SDK->RPM<uintptr_t>(v5 + 8i64 * index);
        return 0;
    }

    inline uintptr_t GetSenstivePTR() {
        uintptr_t heap = GetHeapManager(6);
        if (heap) return heap + offset::SensitivePtr;
        return NULL;
    }

    inline uintptr_t GetOutlineStruct(uintptr_t a1) {
        __try {
            int v1 = SDK->RPM<uint32_t>(a1 + 0x68);
            if (v1 <= 0) return 0;
            return (uint64_t)(0x20 * v1 + SDK->RPM<uint64_t>(a1 + 0x60) - 0x20);
        } __except (EXCEPTION_EXECUTE_HANDLER) {}
        return 0;
    }

    inline void SetBorderLine(uint32_t BorderType, DWORD_PTR base) {
        uint64_t BorderStruct = GetOutlineStruct(base + 0x20);
        uint64_t DecryptData = 0;
        SDK->WPM<uint32_t>(BorderStruct + 0x10, (DecryptData ^ BorderType));
    }

    // ====================== SYSTEME CACHE 16K+ ======================
    inline std::vector<std::pair<uint64_t, uint64_t>> get_ow_entities() {
        std::vector<std::pair<uint64_t, uint64_t>> result;

        uintptr_t possible_bases[] = {0x3A19628, 0x3A1F2B0, 0x36EB8A0, 0x3A2B4C0, 0x3918638, 0x3A1A000, 0x39C0600, 0x3B76970, 0x3A19628};
        uintptr_t entity_list = 0;

        for (auto b : possible_bases) {
            entity_list = SDK->RPM<uintptr_t>(SDK->dwGameBase + b);
            if (entity_list && (entity_list & 0xF) == 0 && entity_list > 0x100000000) {
                std::cout << "[DEBUG] Entity list base VALID = 0x" << std::hex << entity_list << std::dec << std::endl;
                break;
            }
        }

        if (!entity_list) {
            std::cout << "[DEBUG] Forcing base 0x3A19628\n";
            entity_list = SDK->RPM<uintptr_t>(SDK->dwGameBase + 0x3A19628);
        }

        uint8_t priority[] = {0x4, 0x34, 0x52, 0x21, 0x37, 0x39, 0x3B, 0x27, 0x2F, 0x35, 0x43, 0x25, 0x2D, 0x32, 0x33, 0x41, 0x5A, 0x5B};

        std::cout << "[DEBUG] Starting 16K+ cache scan...\n";

        for (int i = 0; i < 524288; ++i) {   // Cache 16K+ (524288 slots)
            uintptr_t ent = SDK->RPM<uintptr_t>(entity_list + i * 0x10);
            if (!ent) continue;

            uint64_t common = 0;
            for (uint8_t id : priority) {
                common = DecryptComponent(ent, id);
                if (common) break;
            }
            if (common) {
                uint32_t uid = SDK->RPM<uint32_t>(common + 0xD4);
                if (uid && uid != 0xFFFFFFFF) {
                    result.emplace_back(ent, common);
                    std::cout << "[VALID ENTITY] 0x" << std::hex << ent << " | link 0x" << common << " | UID 0x" << uid << std::dec << std::endl;
                }
            }
        }
        std::cout << "[DEBUG] Entities found in cache: " << result.size() << std::endl;
        return result;
    }

    inline Vector3 GetPosition(uint64_t common) {
        if (!common) return {0,0,0};
        Vector3 pos = SDK->RPM<Vector3>(common + 0xC4);
        if (fabs(pos.X) > 0.01f && fabs(pos.Y) > 0.01f && fabs(pos.Z) > 0.01f) {
            std::cout << "[GOOD POS DIRECT 0xC4] " << pos.X << ", " << pos.Y << ", " << pos.Z << std::endl;
            return pos;
        }
        uint64_t mesh = DecryptComponent(common, 0x4);
        if (mesh) {
            Vector3 mpos = SDK->RPM<Vector3>(mesh + 0x50);
            if (fabs(mpos.X) > 0.01f && fabs(mpos.Y) > 0.01f && fabs(mpos.Z) > 0.01f) {
                std::cout << "[GOOD POS MESH] " << mpos.X << ", " << mpos.Y << ", " << mpos.Z << std::endl;
                return mpos;
            }
        }
        return {0,0,0};
    }

    inline std::string GetHeroEngNames(uint64_t HeroID) {
        switch (HeroID) {
            case 0x2E0000000000002: return "Reaper";
            case 0x2E0000000000003: return "Tracer";
            case 0x2E0000000000004: return "Mercy";
            case 0x2E0000000000005: return "Hanzo";
            case 0x2E0000000000006: return "Torbjörn";
            case 0x2E0000000000007: return "Reinhardt";
            case 0x2E0000000000008: return "Pharah";
            case 0x2E0000000000009: return "Winston";
            case 0x2E000000000000A: return "Widowmaker";
            case 0x2E0000000000015: return "Bastion";
            case 0x2E0000000000016: return "Symmetra";
            case 0x2E0000000000020: return "Zenyatta";
            case 0x2E0000000000029: return "Genji";
            case 0x2E0000000000040: return "Roadhog";
            case 0x2E0000000000042: return "Cassidy";
            case 0x2E0000000000047: return "Juno";
            case 0x2E0000000000065: return "Junkrat";
            case 0x2E0000000000068: return "Zarya";
            case 0x2E000000000006E: return "Soldier: 76";
            case 0x2E0000000000079: return "Lúcio";
            case 0x2E000000000007A: return "D.Va";
            case 0x2E00000000000DD: return "Mei";
            case 0x2E000000000012E: return "Sombra";
            case 0x2E000000000012F: return "Doomfist";
            case 0x2E000000000013B: return "Ana";
            case 0x2E000000000013E: return "Orisa";
            case 0x2E0000000000195: return "Brigitte";
            case 0x2E00000000001A2: return "Moira";
            case 0x2E00000000001CA: return "Wrecking Ball";
            case 0x2E00000000001EC: return "Sojourn";
            case 0x2E0000000000200: return "Ashe";
            case 0x2E0000000000206: return "Echo";
            case 0x2E0000000000221: return "Baptiste";
            case 0x2E0000000000231: return "Kiriko";
            case 0x2E0000000000236: return "Junker Queen";
            case 0x2E000000000023B: return "Sigma";
            case 0x2E000000000028D: return "Ramattra";
            case 0x2E0000000000291: return "Lifeweaver";
            case 0x2E000000000030A: return "Mauga";
            case 0x2E000000000031C: return "Illari";
            case 0x2E000000000032A: return "Freja";
            case 0x2E000000000032B: return "Venture";
            case 0x2E0000000000362: return "Hazard";
            case 0x2E00000000003C3: return "Wuyang";
            case 0x2E0000000000472: return "Vendetta";
            case 0x2E00000000004C4: return "Domina";
            case 0x2E00000000004D2: return "Sierra";
            case 0x2E00000000004D8: return "Emre";
            case 0x2E00000000004DD: return "Anran";
            case 0x2E00000000004E3: return "Mizuki";
            case 0x02E0000000000516: return "Jetpack Cat";
            default: return "Unknown";
        }
    }
}
