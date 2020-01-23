#include "timer.h"

template<>
volatile uint8_t lmcu::delay::timer<uint8_t>::counter_ = 0;

template<>
volatile uint16_t lmcu::delay::timer<uint16_t>::counter_ = 0;

template<>
volatile uint32_t lmcu::delay::timer<uint32_t>::counter_ = 0;

template<>
volatile uint64_t lmcu::delay::timer<uint64_t>::counter_ = 0;
