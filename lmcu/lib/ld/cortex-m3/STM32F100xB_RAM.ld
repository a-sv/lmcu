MEMORY
{
  IROM(rx):  ORIGIN = 0x20000000, LENGTH = 5K
  IRAM(xrw): ORIGIN = 0x20001400, LENGTH = 3K
}

INCLUDE cortex-m3.ld
