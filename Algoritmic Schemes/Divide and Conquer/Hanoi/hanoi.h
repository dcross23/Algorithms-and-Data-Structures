#ifndef __HANOI_H__
#define __HANOI_H__

#include <stdio.h>
#include <math.h>

#define DRAW_TOWERS

void simpleHanoi(int disks, int origen, int destination, int aux);
void hanoi(char **towers, int disks, int currentDisks, int origen, int destination, int aux);


void initTowers(char **towers, int disks);
void showTowers(char **towers, int disks);
void moveTowers(char **towers, int disks, int o, int d);

#endif
