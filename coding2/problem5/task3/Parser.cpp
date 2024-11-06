#include <cstring>
#include "Parser.h"

class Parser {
public:
    Parser(uint16_t reg1, uint16_t reg2, int mode, int scale)
            : reg1_(reg1), reg2_(reg2), mode_(mode), scale_(scale) {}

    int32_t parse() {
        uint32_t combined;
        switch (mode_) {
            case 1:
                combined = (static_cast<uint32_t>(reg2_) << 16) | reg1_;
                return static_cast<int32_t>(combined) * scale_;
            case 2:
                combined = (static_cast<uint32_t>(reg1_) << 16) | reg2_;
                return static_cast<int32_t>(combined) * scale_;
            case 3: {
                combined = (static_cast<uint32_t>(reg2_) << 16) | reg1_;
                float value;
                std::memcpy(&value, &combined, sizeof(float));
                return static_cast<int32_t>(value * scale_);
            }
            case 4: {
                combined = (static_cast<uint32_t>(reg1_) << 16) | reg2_;
                uint32_t swapped = ((combined & 0xFF) << 24) |
                                   ((combined & 0xFF00) << 8) |
                                   ((combined & 0xFF0000) >> 8) |
                                   ((combined & 0xFF000000) >> 24);
                float value;
                std::memcpy(&value, &swapped, sizeof(float));
                return static_cast<int32_t>(value * scale_);
            }
            default:
                return 0;
        }
    }

private:
    uint16_t reg1_;
    uint16_t reg2_;
    int mode_;
    int scale_;
};

extern "C" API void* createParser(uint16_t reg1, uint16_t reg2, int mode, int scale) {
    return new Parser(reg1, reg2, mode, scale);
}

extern "C" API void destroyParser(void* parser) {
    delete static_cast<Parser*>(parser);
}

extern "C" API int32_t parse(void* parser) {
    Parser* p = static_cast<Parser*>(parser);
    return p->parse();
}
