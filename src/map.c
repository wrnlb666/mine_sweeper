#include "map.h"


inline map_t* map_init(int32 row, int32 col, int32 mine) {
    // get count
    int count = row * col;

    // allocate map
    map_t* res = malloc(sizeof (map_t) + sizeof (int8) * count);
    res->row = row;
    res->col = col;
    res->mine = mine;
    int8* arr = res->map;

    // initialize mines
    if (mine < count / 2) {
        memset(arr, SAFE, sizeof (int8) * (count - mine));
        for (int i = count - mine; i < count; i++) {
            int index = rand() % i;
            arr[i] = arr[index];
            arr[index] = MINE;
        }
    } else if (mine <= count) {
        memset(arr, MINE, sizeof (int8) * (mine));
        for (int i = mine; i < count; i++) {
            int index = rand() % i;
            arr[i] = arr[index];
            arr[index] = SAFE;
        }
    } else {
        // TODO: handle error
    }

    // cast 1D arr to 2D map
    map_arr2map(int8, map, arr, col);

    // calculate number for other blocks
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // skip if current node is mine
            if (map[i][j] == -1) {
                continue;
            }
            int num = 0;
            if (i != 0) {
                if (map[i-1][j] == MINE) num += 1;
            }
            if (i != (row-1)) {
                if (map[i+1][j] == MINE) num += 1;
            }
            if (j != 0) {
                if (map[i][j-1] == MINE) num += 1;
            }
            if (j != (col-1)) {
                if (map[i][j+1] == MINE) num += 1;
            }
            if (i != 0 && j != 0) {
                if (map[i-1][j-1] == MINE) num += 1;
            }
            if (i != (row-1) && j != 0) {
                if (map[i+1][j-1] == MINE) num += 1;
            }
            if (i != 0 && j != (col-1)) {
                if (map[i-1][j+1] == MINE) num += 1;
            }
            if (i != (row-1) && j != (col-1)) {
                if (map[i+1][j+1] == MINE) num += 1;
            }
            map[i][j] = num;
        }
    }

    return res;
}

inline void map_deinit(map_t* map) {
    free(map);
}

inline void map_print(const map_t* map) {
    map_arr2map(int8, tmp, map->map, map->col);
    for (int32 i = 0; i < map->row; i++) {
        for (int32 j = 0; j < map->col; j++) {
            printf("%3" PRId8, tmp[i][j]);
        }
        printf("\n");
    }
}

inline int8 map_get_xy(const map_t* map, int32 row, int32 col) {
    return map->map[map->row * row + col];
}
