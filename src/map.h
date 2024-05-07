#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef int32_t int32;
typedef int8_t  int8;

typedef struct {
    int32   row;
    int32   col;
    int32   mine;
    int8    map[];
} map_t;

typedef enum: int8 {
    SAFE        = 0,
    MINE        = -1,
    SAFE_MARK   = -2,
    MINE_MARK   = -3,
} mine_t;

#define map_arr2map(type, map, arr, col) type (*map)[col] = (type (*)[col])arr;

extern map_t*   map_init(int32 row, int32 col, int32 mine);
extern void     map_deinit(map_t* map);
extern void     map_print(const map_t* map);
extern int8     map_get_xy(const map_t* map, int32 row, int32 col);


#endif  // __MAP_H__
