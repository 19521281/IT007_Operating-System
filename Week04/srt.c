#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pn[10], arrival[10], burst[10], wt[10], tat[10], temp[10], response[10];
	int total_wt = 0, total_tat = 0, count = 0, smallest, time, num, end;
	
	FILE *file;
	file = fopen("input.txt","r");
	
	if(file == NULL)
		exit(1);
	
	fscanf(file,"%d", &num);
	
	for(int i = 1; i <= num; i++)
	{
		fscanf(file,"%d%d%d",&pn[i-1],&arrival[i-1],&burst[i-1]);
		temp[i-1] = burst[i-1];
	}
	
	burst[9] = 9999;
	
	int flag[10];
	for(int f = 0; f < 10; f++)
		flag[f] = 0;
	
	int tmp = 0, come = 0;
	
	for(time = 0; count != num; time++)
	{
		smallest = 9;
		
		for(int i = 0; i < num; i++)
		{
			if(arrival[i] <= time && burst[i] < burst[smallest] && burst[i] > 0)
				smallest = i;
		}
		if(tmp != smallest || tmp == 0)
		{
			come = time;
			tmp = smallest;
		}
		
		burst[smallest]--;
		
		if(burst[smallest] == 0)
		{
			count++;
			end = time + 1;
			
			if(flag[smallest] == 0)
			{
				if(smallest == 0)
					response[smallest] = 0;
				else
					response[smallest] = come - arrival[smallest];
					
				flag[smallest] = 1;
			}
			
			wt[smallest] = end - arrival[smallest] - temp[smallest];
			tat[smallest] = end - arrival[smallest];
			
			total_wt = total_wt + wt[smallest];
			total_tat = total_tat + tat[smallest];
		}
	}
	
	file = fopen("output.txt", "w+");
		
	for(int i = 0; i < num; i++)
	{
		fprintf(file, "%d %d %d %d %d %d\n",pn[i], arrival[i], temp[i], response[i], wt[i], tat[i]);
	}
	
	fprintf(file, "%.2f", (float)total_wt/num);
	fprintf(file, "\n%.2f", (float)total_tat/num);
	
	fclose(file);
	
	return 0;
}
