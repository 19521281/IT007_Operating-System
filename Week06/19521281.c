#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Check_frame(int **table, int frame, int pos, int num_page)
{
	for(int row = 0; row < frame; row++)
		if(table[row][pos] == num_page || table[row][pos] == -1)
				return row;
	
	return -1;
}

void FIFO(int *Seq, int **table, char *fault, int len, int frame)
{
	int start = 0;
	table[0][0] = Seq[0];
	fault[0] = '*';
	
	for(int col = 1; col < len; col++)
	{
		int row = 0;
		while(row < frame)
		{
			table[row][col] = table[row][col - 1];
			row++;
		}
			
		int result = Check_frame(table, frame, col, Seq[col]);
		
		if(result != -1)
		{
			if(table[result][col] == -1)
			{
				table[result][col] = Seq[col];
				fault[col] = '*';
			}
			else
				fault[col] = ' ';
		}
		else
		{
			table[start][col] = Seq[col];
			fault[col] = '*';
			
			start = (start + 1) % frame;
		}
	}
	
}

void OPT(int *Seq, int **table, char *fault, int len, int frame)
{
	int *predict = (int*)calloc(frame, sizeof(int));
	int col = 1;
	table[0][0] = Seq[0];
	fault[0] = '*';
	
	for(int pos = 1; pos < len; pos++)
	{
		if(Seq[pos] == Seq[0])
		{
			predict[0] = pos;
			break;
		}
	}
	
	
	for(int col = 1; col < len; col++)
	{
		for(int row = 0; row < frame; row++)
			table[row][col] = table[row][col - 1];
			
		int result = Check_frame(table, frame, col, Seq[col]);
		
		if(result != -1)
		{
			if(table[result][col] == -1)
			{
				table[result][col] = Seq[col];
				fault[col] = '*';
			}
			else
				fault[col] = ' ';
			
			int find;
			for(find = col + 1; find < len; find++)
				if(Seq[find] == Seq[col])
					break;
			
			predict[result] = find;
		}
		else
		{
			fault[col] = '*';
			
			int bool = 0;
			for(int n = 1; n < frame; n++)
				if(predict[bool] < predict[n])
					bool = n;
			
			table[bool][col] = Seq[col];
			
			int find;
			for(find = col + 1; find < len; find++)
				if(Seq[find] == Seq[col])
					break;
			
			predict[result] = find;
		}
	}
}

void LRU(int *Seq, int **table, char*fault, int len, int frame)
{
	int *latest = (int*)calloc(frame, sizeof(int));
	table[0][0] = Seq[0];
	fault[0] = '*';
	
	for(int col = 1; col < len; col++)
	{
		for(int row = 0; row < frame; row++)
			table[row][col] = table[row][col - 1];
			
		int result = Check_frame(table, frame, col, Seq[col]);
		
		if(result != -1)
		{
			if(table[result][col] == -1)
			{
				table[result][col] = Seq[col];
				fault[col] = '*';
			}
			else
				fault[col] = ' ';
			
			latest[result] = col;
		}
		else
		{
			fault[col] = '*';
			
			int min_pos = 0;
			for(int m = 1; m < frame; m++)
				if(latest[m] < latest[min_pos])
					min_pos = m;
			
			latest[min_pos] = col;
			table[min_pos][col] = Seq[col];
		}
	}
}

void Result(int *Seq, int **table, char *fault, int len, int frame)
{
	int count = 0;
	
	printf("\t--- Page Replacement algorithm ---\n\t");
	
	for(int i = 0; i < len; i++)
		printf("%d", Seq[i]);
		
	printf("\n\t");
	
	for(int row = 0; row < frame; row++)
	{
		for(int col = 0; col < len; col++)
		{
			if(table[row][col] != -1)
				printf("%d", table[row][col]);
			else
				printf(" ");
		}
		
		printf("\n\t");
	}
	
	for(int j = 0; j < len; j++)
	{
		printf("%c", fault[j]);
		
		if(fault[j] == '*')
			count++;
	}
	
	printf("\n\tNumber of Page Fault: %d\n\n", count);
}

int main()
{
	int *Seq, len, frame, num_algor, num_seq;
	
	printf("\t--- Page Replacement algorithm ---\n");
	
	printf("\t1. 1 9 5 2 1 2 8 1 0 0 7\n");
	printf("\t2. Manual input sequence\n");
	
	printf("\tChoose: ");
	scanf("%d", &num_seq);
	
	switch(num_seq)
	{
	case 1:
		len = 11;
		int arr[11] = {1, 9, 5, 2, 1, 2, 8, 1, 0, 0, 7}, i;
		
		Seq = (int*)calloc(len, sizeof(int));
		
		for(i = 0; i < len; i++)
			Seq[i] = arr[i];
		
		break;
			
	case 2:
		printf("\tInput sequence's length: ");
		scanf("%d", &len);
		
		Seq = (int*)calloc(len, sizeof(int));
		
		for(int i = 0; i < len; i++)
		{
			printf("\tInput sequence: ");
			scanf("%d", &Seq[i]);
		}
			
		break;
	}
	
	printf("\t--- Page Replacement algorithm ---\n");
	printf("\tInput page frames: ");
	scanf("%d", &frame);
	
	char *fault = (char*)calloc((len + 1), sizeof(char));
	int **table = (int**)malloc(frame*sizeof(int*));
		
	for(int m = 0; m < frame; m++)
	{
		table[m] = (int*)malloc(len*sizeof(int));
			
		for(int n = 0; n < len; n++)
			table[m][n] = -1;
	}
		
	printf("\t--- Page Replacement algorithm\n");
		
	printf("\t1. FIFO algorithm\n");
	printf("\t2. OPT algorithm\n");
	printf("\t3. LRU algorithm\n");
	printf("\t4. All algorithm\n");
	
	printf("\tChoose an algorithm: ");
	scanf("%d", &num_algor);
	
	switch(num_algor)
	{
	case 1:
		FIFO(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		printf("\tInput new page frames for checking belady: %d\n", frame + 1);
		
		frame += 1;
		
		int **table_FIFO = (int**)malloc(frame*sizeof(int*));
		
		for(int m = 0; m < frame; m++)
		{
			table_FIFO[m] = (int*)malloc(len*sizeof(int));
			
			for(int n = 0; n < len; n++)
				table_FIFO[m][n] = -1;
		}
		
		FIFO(Seq, table_FIFO, fault, len, frame);
		Result(Seq, table_FIFO, fault, len, frame);
		
		break;
		
	case 2:
			
		OPT(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		printf("\tInput new page frames for checking belady: %d\n", frame + 1);
		
		frame += 1;
	
		int **table_OPT = (int**)malloc(frame*sizeof(int*));
		
		for(int m = 0; m < frame; m++)
		{
			table_OPT[m] = (int*)malloc(len*sizeof(int));
			
			for(int n = 0; n < len; n++)
				table_OPT[m][n] = -1;
		}
		
		OPT(Seq, table_OPT, fault, len, frame);
		Result(Seq, table_OPT, fault, len, frame);
		
		break;
		
	case 3:
		
		LRU(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		printf("\tInput new page frames for checking belady: %d\n", frame + 1);
		
		frame += 1;

		int **table_LRU = (int**)malloc(frame*sizeof(int*));
		
		for(int m = 0; m < frame; m++)
		{
			table_LRU[m] = (int*)malloc(len*sizeof(int));
			
			for(int n = 0; n < len; n++)
				table_LRU[m][n] = -1;
		}
		
		LRU(Seq, table_LRU, fault, len, frame);
		Result(Seq, table_LRU, fault, len, frame);
		
		break;
	
	case 4:
		FIFO(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
			
		OPT(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		LRU(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		printf("\tInput new page frames for checking belady: %d\n", frame + 1);
		
		frame += 1;

		int **table = (int**)malloc(frame*sizeof(int*));
		
		for(int m = 0; m < frame; m++)
		{
			table[m] = (int*)malloc(len*sizeof(int));
			
			for(int n = 0; n < len; n++)
				table[m][n] = -1;
		}
		
		FIFO(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
			
		OPT(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		LRU(Seq, table, fault, len, frame);
		Result(Seq, table, fault, len, frame);
		
		break;
		
	default:
		return 0;
	}
	
	return 0;
}
