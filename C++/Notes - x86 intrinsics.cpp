#include <immintrin.h>

// generic format: __m<bit_width>_<data_type>
__m128d  dp;            // type for 256-bit packed double-precision (doubles)
__m128   sp;            // type for 256-bit packed single-precision (floats)
__m128bh hp;            // type for 256-bit packed brain-precision (16-bit floats)
__m128i  i;             // type for 256-bit packed integers

__m256d  dp;            // type for 256-bit packed double-precision (doubles)
__m256   sp;            // type for 256-bit packed single-precision (floats)
__m256bh hp;            // type for 256-bit packed brain-precision (16-bit floats)
__m256i  i;             // type for 256-bit packed integers

__m256d  dp;            // type for 256-bit packed double-precision (doubles)
__m256   sp;            // type for 256-bit packed single-precision (floats)
__m256bh hp;            // type for 256-bit packed brain-precision (16-bit floats)
__m256i  i;             // type for 256-bit packed integers

// generic format: _mm<bit_width>_<name>_<data_type>
// data_type: ps (packed singles), pd (packed doubles); epi8, epi16, epi32, epi64 (extended packed ints), epuXX (extended packed unsigned ints)
_mm256_set_ps(f7, ..., f0);     // set packed single-precision (32-bit) floating-point elements; dst[31:0] := e0, ..., dst[255:224] := e7
_mm256_sub_ps(sp, sp);          // performs a - b on 256-bit numbers


float *f {(float *) &sp};               // cast the __m256 into float pointer to array
float *f {static_cast<float *>(&sp)};   // cast the __m256 into float pointer to array