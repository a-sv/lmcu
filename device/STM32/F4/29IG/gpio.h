#pragma once
#include "device.h"
#include "../gpio.h"

namespace gpio {

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(A,0,  tim2_ch1__tim2_etr = 1, tim5_ch1 = 2, tim8_etr = 3, usart2_cts = 7,
                    uart4_tx = 8, eth_mii_crs = 11, eventout = 15);

lmcu_gpio_pin(A,1,  tim2_ch2 = 1, tim5_ch2 = 2, usart2_rts = 7, uart4_rx = 8,
                    eth_mii_rx_clk__eth_rmii_ref_clk = 11, eventout = 15);

lmcu_gpio_pin(A,2,  tim2_ch3 = 1, tim5_ch3 = 2, tim9_ch1 = 3, usart2_tx = 7, eth_mdio = 11,
                    eventout = 15);

lmcu_gpio_pin(A,3,  tim2_ch4 = 1, tim5_ch4 = 2, tim9_ch2 = 3, usart2_rx = 7, otg_hs_ulpi_d0 = 10,
                    eth_mii_col = 11, lcd_b5 = 14, eventout = 15);

lmcu_gpio_pin(A,4,  spi1_nss = 5, spi3_nss__i2s3_ws = 6, usart2_ck = 7, otg_hs_sof = 12,
                    dcmi_hsync = 13, lcd_vsync = 14, eventout = 15);

lmcu_gpio_pin(A,5,  tim2_ch1__tim2_etr = 1, tim8_ch1n = 3, spi1_sck = 5, otg_hs_ulpi_ck = 10,
                    eventout = 15);

lmcu_gpio_pin(A,6,  tim1_bkin = 1, tim3_ch1 = 2, tim8_bkin = 3, spi1_miso = 5, tim13_ch1 = 9,
                    dcmi_pixclk = 13, lcd_g2 = 14, eventout = 15);

lmcu_gpio_pin(A,7,  tim1_ch1n = 1, tim3_ch2 = 2, tim8_ch1n = 3, spi1_mosi = 5, tim14_ch1 = 9,
                    eth_mii_rx_dv__eth_rmii_crs_dv = 11, eventout = 15);

lmcu_gpio_pin(A,8,  tim1_ch1 = 1, i2c3_scl = 4, usart1_ck = 7, otg_fs_sof = 10, lcd_r6 = 14,
                    eventout = 15);

lmcu_gpio_pin(A,9,  tim1_ch2 = 1, i2c3_smba = 4, usart1_tx = 7, dcmi_d0 = 13, eventout = 15);

lmcu_gpio_pin(A,10, tim1_ch3 = 1, usart1_rx = 7, otg_fs_id = 10, dcmi_d1 = 13, eventout = 15);

lmcu_gpio_pin(A,11, tim1_ch4 = 1, usart1_cts = 7, can1_rx = 9, otg_fs_dm = 10, lcd_r4 = 14,
                    eventout = 15);

lmcu_gpio_pin(A,12, tim1_etr = 1, usart1_rts = 7, can1_tx = 9, otg_fs_dp = 10, lcd_r5 = 14,
                    eventout = 15);

lmcu_gpio_pin(A,13, eventout = 15);

lmcu_gpio_pin(A,14, eventout = 15);

lmcu_gpio_pin(A,15, tim2_ch1__tim2_etr = 1, spi1_nss = 5, spi3_nss__i2s3_ws = 6, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(B,0,  tim1_ch2n = 1, tim3_ch3 = 2, tim8_ch2n = 3, lcd_r3 = 9, otg_hs_ulpi_d1 = 10,
                    eth_mii_rxd2 = 11, eventout = 15);

lmcu_gpio_pin(B,1,  tim1_ch3n = 1, tim3_ch4 = 2, tim8_ch3n = 3, lcd_r6 = 9, otg_hs_ulpi_d2 = 10,
                    eth_mii_rxd3 = 11, eventout = 15);

lmcu_gpio_pin(B,2,  eventout = 15);

lmcu_gpio_pin(B,3,  tim2_ch2 = 1, spi1_sck = 5, spi3_sck__i2s3_ck = 6, eventout = 15);

lmcu_gpio_pin(B,4,  tim3_ch1 = 2, spi1_miso = 5, spi3_miso = 6, i2s3ext_sd = 7, eventout = 15);

lmcu_gpio_pin(B,5,  tim3_ch2 = 2, i2c1_smba = 4, spi1_mosi = 5, spi3_mosi__i2s3_sd = 6, can2_rx = 9,
                    otg_hs_ulpi_d7 = 10, eth_pps_out = 11, fmc_sdcke1 = 12, dcmi_d10 = 13,
                    eventout = 15);

lmcu_gpio_pin(B,6,  tim4_ch1 = 2, i2c1_scl = 4, usart1_tx = 7, can2_tx = 9, fmc_sdne1 = 12,
                    dcmi_d5 = 13, eventout = 15);

lmcu_gpio_pin(B,7,  tim4_ch2 = 2, i2c1_sda = 4, usart1_rx = 7, fmc_nl = 12, dcmi_vsync = 13,
                    eventout = 15);

lmcu_gpio_pin(B,8,  tim4_ch3 = 2, tim10_ch1 = 3, i2c1_scl = 4, can1_rx = 9, eth_mii_txd3 = 11,
                    sdio_d4 = 12, dcmi_d6 = 13, lcd_b6 = 14, eventout = 15);

lmcu_gpio_pin(B,9,  tim4_ch4 = 2, tim11_ch1 = 3, i2c1_sda = 4, spi2_nss__i2s2_ws = 5, can1_tx = 9,
                    sdio_d5 = 12, dcmi_d7 = 13, lcd_b7 = 14, eventout = 15);

lmcu_gpio_pin(B,10, tim2_ch3 = 1, i2c2_scl = 4, spi2_sck__i2s2_ck = 5, usart3_tx = 7,
                    otg_hs_ulpi_d3 = 10, eth_mii_rx_er = 11, lcd_g4 = 14, eventout = 15);

lmcu_gpio_pin(B,11, tim2_ch4 = 1, i2c2_sda = 4, usart3_rx = 7, otg_hs_ulpi_d4 = 10,
                    eth_mii_tx_en__eth_rmii_tx_en = 11, lcd_g5 = 14, eventout = 15);

lmcu_gpio_pin(B,12, tim1_bkin = 1, i2c2_smba = 4, spi2_nss__i2s2_ws = 5, usart3_ck = 7, can2_rx = 9,
                    otg_hs_ulpi_d5 = 10, eth_mii_txd0__eth_rmii_txd0 = 11, otg_hs_id = 12,
                    eventout = 15);

lmcu_gpio_pin(B,13, tim1_ch1n = 1, spi2_sck__i2s2_ck = 5, usart3_cts = 7, can2_tx = 9,
                    otg_hs_ulpi_d6 = 10, eth_mii_txd1__eth_rmii_txd1 = 11, eventout = 15);

lmcu_gpio_pin(B,14, tim1_ch2n = 1, tim8_ch2n = 3, spi2_miso = 5, i2s2ext_sd = 6, usart3_rts = 7,
                    tim12_ch1 = 9, otg_hs_dm = 12, eventout = 15);

lmcu_gpio_pin(B,15, tim1_ch3n = 1, tim8_ch3n = 3, spi2_mosi__i2s2_sd = 5, tim12_ch2 = 9,
                    otg_hs_dp = 12, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(C,0,  otg_hs_ulpi_stp = 10, fmc_sdnwe = 12, eventout = 15);

lmcu_gpio_pin(C,1,  eth_mdc = 11, eventout = 15);

lmcu_gpio_pin(C,2,  spi2_miso = 5, i2s2ext_sd = 6, otg_hs_ulpi_dir = 10, eth_mii_txd2 = 11,
                    fmc_sdne0 = 12, eventout = 15);

lmcu_gpio_pin(C,3,  spi2_mosi__i2s2_sd = 5, otg_hs_ulpi_nxt = 10, eth_mii_tx_clk = 11,
                    fmc_sdcke0 = 12, eventout = 15);

lmcu_gpio_pin(C,4,  eth_mii_rxd0__eth_rmii_rxd0 = 11, eventout = 15);

lmcu_gpio_pin(C,5,  eth_mii_rxd1__eth_rmii_rxd1 = 11, eventout = 15);

lmcu_gpio_pin(C,6,  tim3_ch1 = 2, tim8_ch1 = 3, i2s2_mck = 5, usart6_tx = 8, sdio_d6 = 12,
                    dcmi_d0 = 13, lcd_hsync = 14, eventout = 15);

lmcu_gpio_pin(C,7,  tim3_ch2 = 2, tim8_ch2 = 3, i2s3_mck = 6, usart6_rx = 8, sdio_d7 = 12,
                    dcmi_d1 = 13, lcd_g6 = 14, eventout = 15);

lmcu_gpio_pin(C,8,  tim3_ch3 = 2, tim8_ch3 = 3, usart6_ck = 8, sdio_d0 = 12, dcmi_d2 = 13,
                    eventout = 15);

lmcu_gpio_pin(C,9,  tim3_ch4 = 2, tim8_ch4 = 3, i2c3_sda = 4, i2s_ckin = 5, sdio_d1 = 12,
                    dcmi_d3 = 13, eventout = 15);

lmcu_gpio_pin(C,10, spi3_sck__i2s3_ck = 6, usart3_tx = 7, uart4_tx = 8, sdio_d2 = 12, dcmi_d8 = 13,
                    lcd_r2 = 14, eventout = 15);

lmcu_gpio_pin(C,11, i2s3ext_sd = 5, spi3_miso = 6, usart3_rx = 7, uart4_rx = 8, sdio_d3 = 12,
                    dcmi_d4 = 13, eventout = 15);

lmcu_gpio_pin(C,12, spi3_mosi__i2s3_sd = 6, usart3_ck = 7, uart5_tx = 8, sdio_ck = 12, dcmi_d9 = 13,
                    eventout = 15);

lmcu_gpio_pin(C,13, eventout = 15);

lmcu_gpio_pin(C,14, eventout = 15);

lmcu_gpio_pin(C,15, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(D,0,  can1_rx = 9, fmc_d2 = 12, eventout = 15);

lmcu_gpio_pin(D,1,  can1_tx = 9, fmc_d3 = 12, eventout = 15);

lmcu_gpio_pin(D,2,  tim3_etr = 2, uart5_rx = 8, sdio_cmd = 12, dcmi_d11 = 13, eventout = 15);

lmcu_gpio_pin(D,3,  spi2_sck__i2s2_ck = 5, usart2_cts = 7, fmc_clk = 12, dcmi_d5 = 13, lcd_g7 = 14,
                    eventout = 15);

lmcu_gpio_pin(D,4,  usart2_rts = 7, fmc_noe = 12, eventout = 15);

lmcu_gpio_pin(D,5,  usart2_tx = 7, fmc_nwe = 12, eventout = 15);

lmcu_gpio_pin(D,6,  spi3_mosi__i2s3_sd = 5, sai1_sd_a = 6, usart2_rx = 7, fmc_nwait = 12,
                    dcmi_d10 = 13, lcd_b2 = 14, eventout = 15);

lmcu_gpio_pin(D,7,  usart2_ck = 7, fmc_ne1__fmc_nce2 = 12, eventout = 15);

lmcu_gpio_pin(D,8,  usart3_tx = 7, fmc_d13 = 12, eventout = 15);

lmcu_gpio_pin(D,9,  usart3_rx = 7, fmc_d14 = 12, eventout = 15);

lmcu_gpio_pin(D,10, usart3_ck = 7, fmc_d15 = 12, lcd_b3 = 14, eventout = 15);

lmcu_gpio_pin(D,11, usart3_cts = 7, fmc_a16 = 12, eventout = 15);

lmcu_gpio_pin(D,12, tim4_ch1 = 2, usart3_rts = 7, fmc_a17 = 12, eventout = 15);

lmcu_gpio_pin(D,13, tim4_ch2 = 2, fmc_a18 = 12, eventout = 15);

lmcu_gpio_pin(D,14, tim4_ch3 = 2, fmc_d0 = 12, eventout = 15);

lmcu_gpio_pin(D,15, tim4_ch4 = 2, fmc_d1 = 12, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(E,0,  tim4_etr = 2, uart8_rx = 8, fmc_nbl0 = 12, dcmi_d2 = 13, eventout = 15);

lmcu_gpio_pin(E,1,  uart8_tx = 8, fmc_nbl1 = 12, dcmi_d3 = 13, eventout = 15);

lmcu_gpio_pin(E,2,  spi4_sck = 5, sai1_mclk_a = 6, eth_mii_txd3 = 11, fmc_a23 = 12, eventout = 15);

lmcu_gpio_pin(E,3,  sai1_sd_b = 6, fmc_a19 = 12, eventout = 15);

lmcu_gpio_pin(E,4,  spi4_nss = 5, sai1_fs_a = 6, fmc_a20 = 12, dcmi_d4 = 13, lcd_b0 = 14,
                    eventout = 15);

lmcu_gpio_pin(E,5,  tim9_ch1 = 3, spi4_miso = 5, sai1_sck_a = 6, fmc_a21 = 12, dcmi_d6 = 13,
                    lcd_g0 = 14, eventout = 15);

lmcu_gpio_pin(E,6,  tim9_ch2 = 3, spi4_mosi = 5, sai1_sd_a = 6, fmc_a22 = 12, dcmi_d7 = 13,
                    lcd_g1 = 14, eventout = 15);

lmcu_gpio_pin(E,7,  tim1_etr = 1, uart7_rx = 8, fmc_d4 = 12, eventout = 15);

lmcu_gpio_pin(E,8,  tim1_ch1n = 1, uart7_tx = 8, fmc_d5 = 12, eventout = 15);

lmcu_gpio_pin(E,9,  tim1_ch1 = 1, fmc_d6 = 12, eventout = 15);

lmcu_gpio_pin(E,10, tim1_ch2n = 1, fmc_d7 = 12, eventout = 15);

lmcu_gpio_pin(E,11, tim1_ch2 = 1, spi4_nss = 5, fmc_d8 = 12, lcd_g3 = 14, eventout = 15);

lmcu_gpio_pin(E,12, tim1_ch3n = 1, spi4_sck = 5, fmc_d9 = 12, lcd_b4 = 14, eventout = 15);

lmcu_gpio_pin(E,13, tim1_ch3 = 1, spi4_miso = 5, fmc_d10 = 12, lcd_de = 14, eventout = 15);

lmcu_gpio_pin(E,14, tim1_ch4 = 1, spi4_mosi = 5, fmc_d11 = 12, lcd_clk = 14, eventout = 15);

lmcu_gpio_pin(E,15, tim1_bkin = 1, fmc_d12 = 12, lcd_r7 = 14, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(F,0,  i2c2_sda = 4, fmc_a0 = 12, eventout = 15);

lmcu_gpio_pin(F,1,  i2c2_scl = 4, fmc_a1 = 12, eventout = 15);

lmcu_gpio_pin(F,2,  i2c2_smba = 4, fmc_a2 = 12, eventout = 15);

lmcu_gpio_pin(F,3,  fmc_a3 = 12, eventout = 15);

lmcu_gpio_pin(F,4,  fmc_a4 = 12, eventout = 15);

lmcu_gpio_pin(F,5,  fmc_a5 = 12, eventout = 15);

lmcu_gpio_pin(F,6,  tim10_ch1 = 3, spi5_nss = 5, sai1_sd_b = 6, uart7_rx = 8, fmc_niord = 12,
                    eventout = 15);

lmcu_gpio_pin(F,7,  tim11_ch1 = 3, spi5_sck = 5, sai1_mclk_b = 6, uart7_tx = 8, fmc_nreg = 12,
                    eventout = 15);

lmcu_gpio_pin(F,8,  spi5_miso = 5, sai1_sck_b = 6, tim13_ch1 = 9, fmc_niowr = 12, eventout = 15);

lmcu_gpio_pin(F,9,  spi5_mosi = 5, sai1_fs_b = 6, tim14_ch1 = 9, fmc_cd = 12, eventout = 15);

lmcu_gpio_pin(F,10, fmc_intr = 12, dcmi_d11 = 13, lcd_de = 14, eventout = 15);

lmcu_gpio_pin(F,11, spi5_mosi = 5, fmc_sdnras = 12, dcmi_d12 = 13, eventout = 15);

lmcu_gpio_pin(F,12, fmc_a6 = 12, eventout = 15);

lmcu_gpio_pin(F,13, fmc_a7 = 12, eventout = 15);

lmcu_gpio_pin(F,14, fmc_a8 = 12, eventout = 15);

lmcu_gpio_pin(F,15, fmc_a9 = 12, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(G,0,  fmc_a10 = 12, eventout = 15);

lmcu_gpio_pin(G,1,  fmc_a11 = 12, eventout = 15);

lmcu_gpio_pin(G,2,  fmc_a12 = 12, eventout = 15);

lmcu_gpio_pin(G,3,  fmc_a13 = 12, eventout = 15);

lmcu_gpio_pin(G,4,  fmc_a14__fmc_ba0 = 12, eventout = 15);

lmcu_gpio_pin(G,5,  fmc_a15__fmc_ba1 = 12, eventout = 15);

lmcu_gpio_pin(G,6,  fmc_int2 = 12, dcmi_d12 = 13, lcd_r7 = 14, eventout = 15);

lmcu_gpio_pin(G,7,  usart6_ck = 8, fmc_int3 = 12, dcmi_d13 = 13, lcd_clk = 14, eventout = 15);

lmcu_gpio_pin(G,8,  spi6_nss = 5, usart6_rts = 8, eth_pps_out = 11, fmc_sdclk = 12, eventout = 15);

lmcu_gpio_pin(G,9,  usart6_rx = 8, fmc_ne2__fmc_nce3 = 12, eventout = 15);

lmcu_gpio_pin(G,10, lcd_g3 = 9, fmc_nce4_1__fmc_ne3 = 12, dcmi_d2 = 13, lcd_b2 = 14, eventout = 15);

lmcu_gpio_pin(G,11, eth_mii_tx_en__eth_rmii_tx_en = 11, fmc_nce4_2 = 12, dcmi_d3 = 13, lcd_b3 = 14,
                    eventout = 15);

lmcu_gpio_pin(G,12, spi6_miso = 5, usart6_rts = 8, lcd_b4 = 9, fmc_ne4 = 12, lcd_b1 = 14,
                    eventout = 15);

lmcu_gpio_pin(G,13, spi6_sck = 5, usart6_cts = 8, eth_mii_txd0__eth_rmii_txd0 = 11, fmc_a24 = 12,
                    eventout = 15);

lmcu_gpio_pin(G,14, spi6_mosi = 5, usart6_tx = 8, eth_mii_txd1__eth_rmii_txd1 = 11, fmc_a25 = 12,
                    eventout = 15);

lmcu_gpio_pin(G,15, usart6_cts = 8, fmc_sdncas = 12, dcmi_d13 = 13, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(H,0,  eventout = 15);

lmcu_gpio_pin(H,1,  eventout = 15);

lmcu_gpio_pin(H,2,  eth_mii_crs = 11, fmc_sdcke0 = 12, lcd_r0 = 14, eventout = 15);

lmcu_gpio_pin(H,3,  eth_mii_col = 11, fmc_sdne0 = 12, lcd_r1 = 14, eventout = 15);

lmcu_gpio_pin(H,4,  i2c2_scl = 4, otg_hs_ulpi_nxt = 10, eventout = 15);

lmcu_gpio_pin(H,5,  i2c2_sda = 4, spi5_nss = 5, fmc_sdnwe = 12, eventout = 15);

lmcu_gpio_pin(H,6,  i2c2_smba = 4, spi5_sck = 5, tim12_ch1 = 9, fmc_sdne1 = 12, dcmi_d8 = 13,
                    eventout = 15);

lmcu_gpio_pin(H,7,  i2c3_scl = 4, spi5_miso = 5, eth_mii_rxd3 = 11, fmc_sdcke1 = 12, dcmi_d9 = 13,
                    eventout = 15);

lmcu_gpio_pin(H,8,  i2c3_sda = 4, fmc_d16 = 12, dcmi_hsync = 13, lcd_r2 = 14, eventout = 15);

lmcu_gpio_pin(H,9,  i2c3_smba = 4, tim12_ch2 = 9, fmc_d17 = 12, dcmi_d0 = 13, lcd_r3 = 14,
                    eventout = 15);

lmcu_gpio_pin(H,10, tim5_ch1 = 2, fmc_d18 = 12, dcmi_d1 = 13, lcd_r4 = 14, eventout = 15);

lmcu_gpio_pin(H,11, tim5_ch2 = 2, fmc_d19 = 12, dcmi_d2 = 13, lcd_r5 = 14, eventout = 15);

lmcu_gpio_pin(H,12, tim5_ch3 = 2, fmc_d20 = 12, dcmi_d3 = 13, lcd_r6 = 14, eventout = 15);

lmcu_gpio_pin(H,13, tim8_ch1n = 3, can1_tx = 9, fmc_d21 = 12, lcd_g2 = 14, eventout = 15);

lmcu_gpio_pin(H,14, tim8_ch2n = 3, fmc_d22 = 12, dcmi_d4 = 13, lcd_g3 = 14, eventout = 15);

lmcu_gpio_pin(H,15, tim8_ch3n = 3, fmc_d23 = 12, dcmi_d11 = 13, lcd_g4 = 14, eventout = 15);

// ------------------------------------------------------------------------------------------------

lmcu_gpio_pin(I,0,  tim5_ch4 = 2, spi2_nss__i2s2_ws = 5, fmc_d24 = 12, dcmi_d13 = 13, lcd_g5 = 14,
                    eventout = 15);

lmcu_gpio_pin(I,1,  spi2_sck__i2s2_ck = 5, fmc_d25 = 12, dcmi_d8 = 13, lcd_g6 = 14, eventout = 15);

lmcu_gpio_pin(I,2,  tim8_ch4 = 3, spi2_miso = 5, i2s2ext_sd = 6, fmc_d26 = 12, dcmi_d9 = 13,
                    lcd_g7 = 14, eventout = 15);

lmcu_gpio_pin(I,3,  tim8_etr = 3, spi2_mosi__i2s2_sd = 5, fmc_d27 = 12, dcmi_d10 = 13,
                    eventout = 15);

lmcu_gpio_pin(I,4,  tim8_bkin = 3, fmc_nbl2 = 12, dcmi_d5 = 13, lcd_b4 = 14, eventout = 15);

lmcu_gpio_pin(I,5,  tim8_ch1 = 3, fmc_nbl3 = 12, dcmi_vsync = 13, lcd_b5 = 14, eventout = 15);

lmcu_gpio_pin(I,6,  tim8_ch2 = 3, fmc_d28 = 12, dcmi_d6 = 13, lcd_b6 = 14, eventout = 15);

lmcu_gpio_pin(I,7,  tim8_ch3 = 3, fmc_d29 = 12, dcmi_d7 = 13, lcd_b7 = 14, eventout = 15);

lmcu_gpio_pin(I,8,  eventout = 15);

lmcu_gpio_pin(I,9,  can1_rx = 9, fmc_d30 = 12, lcd_vsync = 14, eventout = 15);

lmcu_gpio_pin(I,10, eth_mii_rx_er = 11, fmc_d31 = 12, lcd_hsync = 14, eventout = 15);

lmcu_gpio_pin(I,11, otg_hs_ulpi_dir = 10, eventout = 15);

// ------------------------------------------------------------------------------------------------

namespace detail {

template<uint32_t r, port arg1, port ...args>
constexpr auto rcc_bits()
{
  constexpr auto bits = []() -> decltype(r)
  {
    if constexpr(arg1 == port::A) { return r | RCC_AHB1ENR_GPIOAEN; }
    if constexpr(arg1 == port::B) { return r | RCC_AHB1ENR_GPIOBEN; }
    if constexpr(arg1 == port::C) { return r | RCC_AHB1ENR_GPIOCEN; }
    if constexpr(arg1 == port::D) { return r | RCC_AHB1ENR_GPIODEN; }
    if constexpr(arg1 == port::E) { return r | RCC_AHB1ENR_GPIOEEN; }
    if constexpr(arg1 == port::F) { return r | RCC_AHB1ENR_GPIOFEN; }
    if constexpr(arg1 == port::G) { return r | RCC_AHB1ENR_GPIOGEN; }
    if constexpr(arg1 == port::H) { return r | RCC_AHB1ENR_GPIOHEN; }
    if constexpr(arg1 == port::I) { return r | RCC_AHB1ENR_GPIOIEN; }
    if constexpr(arg1 == port::J) { return r | RCC_AHB1ENR_GPIOJEN; }
    if constexpr(arg1 == port::K) { return r | RCC_AHB1ENR_GPIOKEN; }
    return r;
  };

  if constexpr(sizeof...(args) > 0) { return rcc_bits<bits(), args...>(); }
  return bits();
}

} // namespace detail

template<port ...args>
void enable() { RCC->AHB1ENR |= detail::rcc_bits<0, args...>(); }

template<port ...args>
void disable() { RCC->AHB1ENR &= ~detail::rcc_bits<0, args...>(); }

template<typename ...args>
void init()
{
  static_assert(sizeof...(args), "requires at least 1 argument");

  detail::configure<port::A, args...>(GPIOA);
  detail::configure<port::B, args...>(GPIOB);
  detail::configure<port::C, args...>(GPIOC);
  detail::configure<port::D, args...>(GPIOD);
  detail::configure<port::E, args...>(GPIOE);
  detail::configure<port::F, args...>(GPIOF);
  detail::configure<port::G, args...>(GPIOG);
  detail::configure<port::H, args...>(GPIOH);
  detail::configure<port::I, args...>(GPIOI);
  detail::configure<port::J, args...>(GPIOJ);
  detail::configure<port::K, args...>(GPIOK);
}

} // namespace gpio
