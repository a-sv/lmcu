#pragma once

// ------------------------------------------------------------------------------------------------
namespace lmcu {
// ------------------------------------------------------------------------------------------------

constexpr int
success   =  0,
eperm     = -1,  // Operation not permitted
eio       = -5,  // Input / output error
enomem    = -12, // Out of memory
ebusy     = -16, // Device or resource busy
einval    = -22, // Invalid argument
eagain    = -35, // Try again
etimedout = -60, // Operation timed out
enosys    = -78, // Function not implemented
ecanceled = -131 // Operation canceled
;

// ------------------------------------------------------------------------------------------------
} // namespace lmcu
// ------------------------------------------------------------------------------------------------
