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
//��������˿͡������и���0���˿�
struct passengers man[6];
int main() {
	//����ÿ���˵�ʱ�䡢λ�á�����(�������Ϊ0�Ļ������丳ֵ10��
	for (int i = 1;i <= 5;i++) {
		cin >> man[i].time >> man[i].location >> man[i].direction;
		if (man[i].direction == 0)
			man[i].direction = 10;
	}
	//�õ�ÿ���˵�����ʱ��·�̲�
	for (int i = 1;i <5;i++) {
		delta_time[i] = man[i + 1].time - man[i].time;
		delta_path[i] = man[i + 1].location - man[i].location;
	}
	//����0���˿͵��յ㸳ֵ1
	man[0].direction = 1;
	//j����˿ʹ���n��j��ֵ��num��¼loop1������
	int n;
	int j = 1;
	int num;
loop2:
	n = j;
	num = 0;
	if (man[j].time>time_for_now)
		time_for_now = man[j].time;
loop1://�ҳ��ڵ�j���˵�����Ŀ�ĵ�ʱ����ڿ��Դ�˳����ݵ�����
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
	//ÿ�˵��ݵ���Ŀ�ĵ�ʱ��
	if (man[j].direction != man[j - 1].direction)
		time_for_now += 10 + num;
	else
		if (man[j].direction == 1)
			time_for_now += 2 * man[j].location - 1 + num;
		else
			time_for_now += 2 * (10 - man[j].location) + 1 - num;
	//�˶�·�̳��ڳ˿��ܵȴ�ʱ��
	for (int i = j, s = num;s >= 0;s--, i++)
		sum_time += time_for_now - man[i].time;
	//���ÿ�ξ���
	cout << time_for_now << "ʱ��ͣ����" << man[j].direction << "¥" << endl;
	j += num + 1;
	//���ó������
	if (j >= 6)
	{
		cout << "�˿͵ĵȴ�ʱ���ܺ�:" << sum_time;
		system("pause");
		return 0;
	}
	goto loop2;

}
/*��һ���������
0 2 0
3 3 0
30 10 1
50 1 10
70 10 1*/
/*�ڶ����������
1 2 0
3 3 0
30 10 1
50 1 10
70 10 1*/
/*�������������
0 1 0
0 2 0
0 2 0
0 2 0
0 9 0*/
/*�������������
0 2 0
20 9 1
23 8 1
50 1 0
70 0 1*/
/*�������������
10 9 0
13 9 0
21 1 0
25 1 0
29 10 1
*/
