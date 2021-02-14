/*
	题意：n 个点，m条边，每个点要么是0，要么是1，每条边有个权值；
	两种操作：
	1）Change v，   修改v的点权，从0到1，或者从1到0；
	2）Asksum x y   询问两端分别为 x 和 y 的边权总和；  
	题解：轻重点；
	对于所有的点，如果度数 大于 sqrt(m)，则认为是重点，重点个数不会超过 sqrt(m)。
	
	建立新图：
		重点 -> 轻点 不连边
		其余三种情况都连有向边 （轻点->轻点，轻点->重点，重点->重点） ，最多 3 * sqrt(m) 条有向边； 
		
	对于 Change u 操作：
	
	a = u Change 前的点权;
	b = 1 - a;
		
	1）如果 u 是重点：
		
	
	2）如果 u 是轻点：
		
		遍历所有 u 指向的点 v，指向的点权为 c，
		(a,c) 最小化表示为 A;
		(b,c) 最小化表示为 B; 
		
		如果指向的点为重点：
			A 类权值减去、B 类权值加上
		 
		
*/ 


