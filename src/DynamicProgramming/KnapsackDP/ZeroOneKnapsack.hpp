// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#pragma once

#ifndef MAX
#define MAX 1024
#endif
#include <vector>
#include <algorithm>


// 前 i 个物品重量不超过 j 的最大价值

int ZeroOneKnapsack(int *value,
                    int *weight,
                    int count,
                    int tot_weight) {

  int f[MAX][MAX];

  // 初始化
  for (int i = 0; i < MAX; i++) {
    f[0][i] = 0;
    f[i][0] = 0;
  }

  // 第 i 个物品
  for (int i = 1; i <= count; i++) {
    // 重量不超过 j
    for (int j = 0; j <= tot_weight; j++) {
      if (j >= weight[i])
        f[i][j] = std::max( f[i-1][j],
                            f[i-1][j-weight[i]] + value[i]);
      else
        f[i][j] = f[i-1][j];
    }
  }

  return f[count][tot_weight];
}
