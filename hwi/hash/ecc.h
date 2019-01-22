#pragma once
#include <lmcu/device>

namespace lmcu::hash {

enum class ecc_result { success, corrected, error };

/**
 * @brief Calculate error correction code for 256 bytes data
 *
 * @param data - input data for ECC calculation
 * @param ecc  - ECC calculation result
*/
void ecc256_calculate(const uint8_t data[256], uint8_t ecc[3]);

/**
 * @brief Check data and correct 1 corrupted bit
 *
 * @param data     - input data
 * @param read_ecc - ECC code readed from data source
 * @param calc_ecc - ECC code calculated for input data
*/
ecc_result ecc256_correct(uint8_t data[256], const uint8_t read_ecc[3], const uint8_t calc_ecc[3]);

} // namespace lmcu::hash::ecc
