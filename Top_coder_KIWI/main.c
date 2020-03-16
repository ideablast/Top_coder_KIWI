#include<stdio.h>

#define MAX_FT 5
#define MAX_BOTTLES 4

int main()
{
	int capacities[] = { 700000,800000,900000,1000000 };//병의 용량
	int bottles[] = { 478478,478478,478478,478478 };//음료수 양
	int fromId[] = { 2,3,2,0,1 };//from
	int toId[] = { 0,1,1,3,2 };//to
	int Returns[6] = { 0 };

	int i;

	for (i = 0; i < MAX_FT; i++)
	{
		//to의 용량 확인!!
		if ((bottles[fromId[i]] + bottles[toId[i]] - capacities[toId[i]]) >=0)
		{
			bottles[fromId[i]] = bottles[fromId[i]] + bottles[toId[i]] - capacities[toId[i]];
			bottles[toId[i]] = capacities[toId[i]];
		}
		else
		{
			bottles[toId[i]] = bottles[fromId[i]] + bottles[toId[i]];
			bottles[fromId[i]] = 0;
		}
	}

	for (i = 0; i < MAX_BOTTLES; i++)
	{
		Returns[i] = bottles[i];
		printf("%d ", Returns[i]);
	}


}