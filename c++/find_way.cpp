
创建两个表，OPEN表保存所有已生成而未考察的节点，CLOSED表中记录已访问过的节点。
算起点的估价值;
将起点放入OPEN表;

while (OPEN != NULL)
{
	从OPEN表中取估价值f(n)最小的节点n;
	if (n节点 == 目标节点)
		break;
	for (当前节点n的每个子节点X)
	{
		算X的估价值;
		if (XinOPEN)
		if (X的估价值小于OPEN表的估价值)
		{
			把n设置为X的父亲;
			更新OPEN表中的估价值;//取最小路径的估价值
		}
		if (XinCLOSE)
			continue;
		if (Xnotinboth)
		{
			把n设置为X的父亲;
			求X的估价值;
			并将X插入OPEN表中;//还没有排序
		}
	}//endfor
	将n节点插入CLOSE表中;
	按照估价值将OPEN表中的节点排序;//实际上是比较OPEN表内节点f的大小，从最小路径的节点向下进行。
}//endwhile(OPEN!=NULL)


保存路径，即从终点开始，每个节点沿着父节点移动直至起点，这就是你的路径