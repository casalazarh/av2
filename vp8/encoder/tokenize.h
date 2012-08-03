/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */


#ifndef tokenize_h
#define tokenize_h

#include "vp8/common/entropy.h"
#include "block.h"

void vp8_tokenize_initialize();

typedef struct {
  short Token;
  short Extra;
} TOKENVALUE;

typedef struct {
  const vp8_prob *context_tree;
  short           Extra;
  unsigned char   Token;
  unsigned char   skip_eob_node;
} TOKENEXTRA;

int rd_cost_mby(MACROBLOCKD *);

extern int mby_is_skippable(MACROBLOCKD *x, int has_y2_block);
extern int mbuv_is_skippable(MACROBLOCKD *x);
extern int mb_is_skippable(MACROBLOCKD *x, int has_y2_block);
extern int mby_is_skippable_8x8(MACROBLOCKD *x);
extern int mbuv_is_skippable_8x8(MACROBLOCKD *x);
extern int mb_is_skippable_8x8(MACROBLOCKD *x);

#ifdef ENTROPY_STATS
void init_context_counters();
void print_context_counters();

extern INT64 context_counters[BLOCK_TYPES] [COEF_BANDS] [PREV_COEF_CONTEXTS] [MAX_ENTROPY_TOKENS];
extern INT64 context_counters_8x8[BLOCK_TYPES_8X8] [COEF_BANDS] [PREV_COEF_CONTEXTS] [MAX_ENTROPY_TOKENS];
#if CONFIG_TX16X16
extern INT64 context_counters_16x16[BLOCK_TYPES_16X16] [COEF_BANDS] [PREV_COEF_CONTEXTS] [MAX_ENTROPY_TOKENS];
#endif
#endif

extern const int *vp8_dct_value_cost_ptr;
/* TODO: The Token field should be broken out into a separate char array to
 *  improve cache locality, since it's needed for costing when the rest of the
 *  fields are not.
 */
extern const TOKENVALUE *vp8_dct_value_tokens_ptr;

#endif  /* tokenize_h */
