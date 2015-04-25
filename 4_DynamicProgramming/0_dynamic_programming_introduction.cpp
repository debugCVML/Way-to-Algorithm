//动态规划介绍
//dynamic programming introduction

//动态规划介绍：
//动态规划是在多次决策过程中寻找最优解的解决方法
//问题的最终决策可以分为多个相互联系的阶段，每个阶段都需要求解相同类型的最优决策
//每个阶段的决策依赖于之前各阶段的决策，又影响以后阶段的决策
//当所有阶段的决策确定之后，形成决策序列，就会确定出整个的活动序列
//
//适用动态规划的问题必须满足两个条件：
//1)最优化原理：一个最优化策略具有这样的性质，不论过去状态和决策如何，对前面的决
//策所形成的状态而言，余下的诸决策必须构成最优策略。简言之，一个最优策略的子策略也
//总是最优的，满足最优化原理的问题称其为具有最优子结构性质。
//2)无后效性：将问题的各阶段按照一定次序排列好之后，对于某一阶段的状态，它之前各
//阶段的状态无法直接影响它的未来的决策，而只能通过当前这个状态来影响。换言之，每个
//状态都是过去历史的完整总结，也称无后向性。
//
//动态规划可分为四类：
//1)线形动规：问题空间为序列
//2)背包问题：问题空间为选择集
//3)区域动规：问题空间为空间合并
//4)树形动规：问题空间为树形
//
//解题框架：
//1)
//动态规划总是可以看做具有n层决策的最优化问题
//问题的第0层是固定的初始状态，无法选择
//而从第1层开始到第n层选择，每一层选择都是在前一层的基础上来选择的
//比如第i层的选择是完全基于第i-1层选择之后的结果
//我们希望最终的第n层决策可以得到最优的答案
//即第n层在第n-1层的结果上作出的选择必须是最优的，这时第n-1层的选择已经作出而无法改变
//而当第n-1层的选择改变时，第n-1层的结果也相应改变，而第n层的最优结果也相应改变
//2)
//最为直观的想法是该类问题的选择空间是一个类似多叉树的树形空间
//但是我们并不需要使用类似深度递归的编程技术来搜索最优答案
//动态规划的性质就是：
//当第i-1层作出的选择是最优的，即它得到了最优答案时
//第i层在这个结果的基础上得到的最优答案就是整个问题到第i层为止所能得到的最优答案
//因此我们不需要去重复的深度搜索每一个分支
//而只需要从底向上保证每一层的选择都是在已知的最优结果上作出的最优结果
//最终即可得到第n层的最优结果，这个结果也是整个问题的最优解
//3)
//解决动态规划问题的核心技术是递推式与状态转移方程
//递推式是问题中相邻两层决策之间的数学关系
//状态转移方程是对递推式的数学式表达
//以上是动态规划使用的通用解法框架，本章的所有算法都使用了该框架
//
//求解步骤：
//1)建立问题模型
//2)构造状态描述
//3)确立转移方程
//4)选取初始值

//简单的介绍一些流行的动态规划的优化方法
//介绍的两类主要动态规划问题都是无差别的遍历所有决策空间
//但遍历的过程中还存在一些特殊的优化方法，使得算法在时间或空间上可以进一步的优化

//1)四边形不等式原理
//对于这样的一类状态转移方程：
//f[i][j] = | min(f[i][k-1] + f[k][j] + weight[i][j])	i < j, i < k <= j
//			| 0											i = j
//			| INF										i > j
//比如本章第3节的最小合并代价问题就符合这类状态转移方程
//假如对于i <= i' < j <= j'，有weight[i'][j] <= weight[i][j']
//则称函数weight具有关于区间包含的单调性
//另外假如有weight[i][j] + weight[i'][j'] <= weight[i'][j] + weight[i][j']
//则称函数weight满足四边形不等式
//
//在动态规划的求解中应用四边形不等式原理的条件
//在循环中当函数weight[i][j]的下标i和j超过某一临界值时
//可以跳过这个区域的循环，直接进行下一轮的决策遍历，从而达到减少时间复杂度的效果
//
//更多资料请参考“动态规划加速原理之四边形不等式”，作者“赵爽(华中师大一附中)”
//
//2)状态压缩
//状态压缩可以应用于很多问题，只要问题中每个成员的状态可以用二进制来表示
//比如一个4*4方格的棋盘，每个格子中可以摆放黑棋或白棋
//则棋盘的状态可以用一个16位的二进制数字来表示
//则可以使用short型变量，short型变量长度为2字节(byte)，16比特(bit)
//若问题中有32个可以用二进制的0和1表示状态的成员
//则可以使用int型变量，int型变量长度为4字节(byte)，32比特(bit)
//按照这样的思路推广，我们还可以得到任意的状态都可以用二进制数位来进行压缩
//当问题中每个成员有两种状态时，可以用一位二进制数字的0和1来表示
//当问题中每个成员有三到四种状态时，可以用两位二进制数字来表示，以此类推
//
//更多资料请参考“状态压缩动态规划”，作者“godfrey90”
