#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sum_grid(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void p_grid(int grid[3][3]);
void toppling(int grid[3][3]);

#endif
