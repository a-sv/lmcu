#pragma once
#include "../rcc.h"

namespace lmcu::rcc {

enum class rtchse_prediv
{
  div_2 = 2, div_3, div_4, div_5, div_6, div_7, div_8, div_9, div_10, div_11, div_12, div_13,
  div_14, div_15, div_16, div_17, div_18, div_19, div_20, div_21, div_22, div_23, div_24, div_25,
  div_26, div_27, div_28, div_29, div_30, div_31
};

#if defined(STM32F407ZG) || defined(STM32F429IG)

enum class pll_mux { hse, hsi };

enum class pll_m
{
  div_2 = 2, div_3, div_4, div_5, div_6, div_7, div_8, div_9, div_10, div_11, div_12, div_13,
  div_14, div_15, div_16, div_17, div_18, div_19, div_20, div_21, div_22, div_23, div_24, div_25,
  div_26, div_27, div_28, div_29, div_30, div_31, div_32, div_33, div_34, div_35, div_36, div_37,
  div_38, div_39, div_40, div_41, div_42, div_43, div_44, div_45, div_46, div_47, div_48, div_49,
  div_50, div_51, div_52, div_53, div_54, div_55, div_56, div_57, div_58, div_59, div_60, div_61,
  div_62, div_63
};

enum class pll_n
{
  mul_50 = 50, mul_51, mul_52, mul_53, mul_54, mul_55, mul_56, mul_57, mul_58, mul_59, mul_60,
  mul_61, mul_62, mul_63, mul_64, mul_65, mul_66, mul_67, mul_68, mul_69, mul_70, mul_71, mul_72,
  mul_73, mul_74, mul_75, mul_76, mul_77, mul_78, mul_79, mul_80, mul_81, mul_82, mul_83, mul_84,
  mul_85, mul_86, mul_87, mul_88, mul_89, mul_90, mul_91, mul_92, mul_93, mul_94, mul_95, mul_96,
  mul_97, mul_98, mul_99, mul_100, mul_101, mul_102, mul_103, mul_104, mul_105, mul_106, mul_107,
  mul_108, mul_109, mul_110, mul_111, mul_112, mul_113, mul_114, mul_115, mul_116, mul_117, mul_118,
  mul_119, mul_120, mul_121, mul_122, mul_123, mul_124, mul_125, mul_126, mul_127, mul_128, mul_129,
  mul_130, mul_131, mul_132, mul_133, mul_134, mul_135, mul_136, mul_137, mul_138, mul_139, mul_140,
  mul_141, mul_142, mul_143, mul_144, mul_145, mul_146, mul_147, mul_148, mul_149, mul_150, mul_151,
  mul_152, mul_153, mul_154, mul_155, mul_156, mul_157, mul_158, mul_159, mul_160, mul_161, mul_162,
  mul_163, mul_164, mul_165, mul_166, mul_167, mul_168, mul_169, mul_170, mul_171, mul_172, mul_173,
  mul_174, mul_175, mul_176, mul_177, mul_178, mul_179, mul_180, mul_181, mul_182, mul_183, mul_184,
  mul_185, mul_186, mul_187, mul_188, mul_189, mul_190, mul_191, mul_192, mul_193, mul_194, mul_195,
  mul_196, mul_197, mul_198, mul_199, mul_200, mul_201, mul_202, mul_203, mul_204, mul_205, mul_206,
  mul_207, mul_208, mul_209, mul_210, mul_211, mul_212, mul_213, mul_214, mul_215, mul_216, mul_217,
  mul_218, mul_219, mul_220, mul_221, mul_222, mul_223, mul_224, mul_225, mul_226, mul_227, mul_228,
  mul_229, mul_230, mul_231, mul_232, mul_233, mul_234, mul_235, mul_236, mul_237, mul_238, mul_239,
  mul_240, mul_241, mul_242, mul_243, mul_244, mul_245, mul_246, mul_247, mul_248, mul_249, mul_250,
  mul_251, mul_252, mul_253, mul_254, mul_255, mul_256, mul_257, mul_258, mul_259, mul_260, mul_261,
  mul_262, mul_263, mul_264, mul_265, mul_266, mul_267, mul_268, mul_269, mul_270, mul_271, mul_272,
  mul_273, mul_274, mul_275, mul_276, mul_277, mul_278, mul_279, mul_280, mul_281, mul_282, mul_283,
  mul_284, mul_285, mul_286, mul_287, mul_288, mul_289, mul_290, mul_291, mul_292, mul_293, mul_294,
  mul_295, mul_296, mul_297, mul_298, mul_299, mul_300, mul_301, mul_302, mul_303, mul_304, mul_305,
  mul_306, mul_307, mul_308, mul_309, mul_310, mul_311, mul_312, mul_313, mul_314, mul_315, mul_316,
  mul_317, mul_318, mul_319, mul_320, mul_321, mul_322, mul_323, mul_324, mul_325, mul_326, mul_327,
  mul_328, mul_329, mul_330, mul_331, mul_332, mul_333, mul_334, mul_335, mul_336, mul_337, mul_338,
  mul_339, mul_340, mul_341, mul_342, mul_343, mul_344, mul_345, mul_346, mul_347, mul_348, mul_349,
  mul_350, mul_351, mul_352, mul_353, mul_354, mul_355, mul_356, mul_357, mul_358, mul_359, mul_360,
  mul_361, mul_362, mul_363, mul_364, mul_365, mul_366, mul_367, mul_368, mul_369, mul_370, mul_371,
  mul_372, mul_373, mul_374, mul_375, mul_376, mul_377, mul_378, mul_379, mul_380, mul_381, mul_382,
  mul_383, mul_384, mul_385, mul_386, mul_387, mul_388, mul_389, mul_390, mul_391, mul_392, mul_393,
  mul_394, mul_395, mul_396, mul_397, mul_398, mul_399, mul_400, mul_401, mul_402, mul_403, mul_404,
  mul_405, mul_406, mul_407, mul_408, mul_409, mul_410, mul_411, mul_412, mul_413, mul_414, mul_415,
  mul_416, mul_417, mul_418, mul_419, mul_420, mul_421, mul_422, mul_423, mul_424, mul_425, mul_426,
  mul_427, mul_428, mul_429, mul_430, mul_431, mul_432
};

enum class pll_p
{
  div_2 = 2,
  div_4 = 4,
  div_6 = 6,
  div_8 = 8
};

enum class pll_q
{
  disable,
  div_2 = 2,
  div_3,
  div_4,
  div_5,
  div_6,
  div_7,
  div_8,
  div_9,
  div_10,
  div_11,
  div_12,
  div_13,
  div_14,
  div_15
};

using plli2s_n = pll_n;

enum class plli2s_r
{
  div_2 = 2,
  div_3,
  div_4,
  div_5,
  div_6,
  div_7
};

enum class i2sclk_mux { plli2s, extclk };

enum class mco1_mux
{
  disable,
  lse,
  hse,
  hsi,
  pllclk
};

enum class mco1_prediv
{
  div_1 = 1,
  div_2,
  div_3,
  div_4,
  div_5
};

enum class mco2_mux
{
  disable,
  sysclk,
  plli2s,
  hse,
  pllclk
};

using mco2_prediv = mco1_prediv;

#endif // defined(STM32F407ZG) || defined(STM32F429IG)

#include "detail/rcc.h"

} // namespace lmcu::rcc
