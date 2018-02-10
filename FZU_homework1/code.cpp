//unpredictable situation
//First version
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define mod (1e9+7)
#define ll long long
using namespace std;
int time_for_now = 0, sum_time = 0, delta_path[5], delta_time[5];
struct passengers {
	int time, location, direction;
};
//创建五个乘客、假设有个第0个乘客
struct passengers man[6];
int main() {
	//输入每个人的时间、位置、方向(如果方向为0的话，将其赋值10）
	for (int i = 1;i <= 5;i++) {
		cin >> man[i].time >> man[i].location >> man[i].direction;
		if (man[i].direction == 0)
			man[i].direction = 10;
	}
	//得到每个人的请求时间差、路程差
	for (int i = 1;i <5;i++) {
		delta_time[i] = man[i + 1].time - man[i].time;
		delta_path[i] = man[i + 1].location - man[i].location;
	}
	//给第0个乘客的终点赋值1
	man[0].direction = 1;
	//j代表乘客次序，n是j的值，num记录loop1人数。
	int n;
	int j = 1;
	int num;
loop2:
	n = j;
	num = 0;
	if (man[j].time>time_for_now)
		time_for_now = man[j].time;
loop1://找出在第j个人到达其目的地时间段内可以搭顺风电梯的人数
	if (man[n + 1].direction == man[j].direction&&man[n + 1].direction == 10)
	{
		if (man[n + 1].location + num >= delta_time[n] && man[n + 1].time - man[j].time + 1 + num >= man[j].location ||
			man[n + 1].location + num >= delta_time[n] && delta_path[n] <= 0)
		{
			num++;
			n++;
			goto loop1;
		}
	}
	else if (man[n + 1].direction == man[j].direction&&man[n + 1].direction == 1)
	{
		if (11 - man[n + 1].location + num >= delta_time[n] && man[n + 1].time - man[j].time >= 11 - man[j].location ||
			11 - man[n + 1].location + num >= delta_time[n] && delta_path[n] >= 0)
		{
			num++;
			n++;
			goto loop1;
		}
	}
	//每趟电梯到达目的地时间
	if (man[j].direction != man[j - 1].direction)
		time_for_now += 10 + num;
	else
		if (man[j].direction == 1)
			time_for_now += 2 * man[j].location - 1 + num;
		else
			time_for_now += 2 * (10 - man[j].location) + 1 - num;
	//此段路程车内乘客总等待时间
	for (int i = j, s = num;s >= 0;s--, i++)
		sum_time += time_for_now - man[i].time;
	//输出每次决策
	cout << time_for_now << "时，停靠在" << man[j].direction << "楼" << endl;
	j += num + 1;
	//设置程序结束
	if (j >= 6)
	{
		cout << "乘客的等待时间总和:" << sum_time;
		system("pause");
		return 0;
	}
	goto loop2;

}
/*第一组测试用例
0 2 0
3 3 0
30 10 1
50 1 10
70 10 1*/
/*第二组测试用例
1 2 0
3 3 0
30 10 1
50 1 10
70 10 1*/
/*第三组测试用例
0 1 0
0 2 0
0 2 0
0 2 0
0 9 0*/
/*第四组测试用例
0 2 0
20 9 1
23 8 1
50 1 0
70 0 1*/
/*第五组测试用例
10 9 0
13 9 0
21 1 0
25 1 0
29 10 1
*/
