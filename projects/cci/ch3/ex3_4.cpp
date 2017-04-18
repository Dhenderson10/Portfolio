#include "stack_q.h"
#include <iostream>
#include <assert.h>
#include <math.h>
//this is how many rings
#define N 6
//final 
//try to merge both functions

typedef struct tower
{
	Stack base;
} tower;

tower* init_towers()
{
	tower* t = new tower[3];
	//tower t [3];
	int index = 0;
	t[0].base._stack_height = 0;
	//t[0].st
	for(int i = N; i > 0; i--)
	{
		pushy(i, &t[0].base);
	}


	return t;
}

void move_disk(Stack* old_s, Stack* new_s)
{
	pushy(pop(old_s), new_s);
}

int scan_for(Stack* s)
{
	return 1;
}


void finish_tower(tower t[3])
{
	//3->2->1...3->2->1
	//for odd N ^^^
	//for even N go 1->2->3->4
	int current_num = 1;
	int current_stack = 0;
	int victim_stack = 2;
	//2**N - 1 is the least amount
	//of moves necessary to solve
	//this puzzle
	int moves = pow(2, N) - 1;
	int flag = 0;
	while(moves > 0)
	{
		int current_disk;
		for(int i = 0; i < 3; i++)
		{
			if(peek(&t[i].base) == current_num)
			{
				current_stack = i;
				current_disk = peek(&t[current_stack].base);
				flag = 1;
			}
			if(current_stack == 0)
			{
				victim_stack = 2;
			}
			else
			{
				victim_stack = current_stack - 1;
			}
			if(flag == 0 && i == 2)
			{
				if(current_num == N)
				{
					current_num = 1;
				}
				else
				{
					current_num++;
				}
				//learned something new
				//because i++ adds after for loop
				i = -1;
			}
		}
		flag = 0;
		int loop_two = 2;
		int flag_two = 0;
		while(loop_two > 0)
		{
			int victim_disk = peek(&t[victim_stack].base);
			if(current_disk < victim_disk || victim_disk == 0)
			{
				move_disk(&t[current_stack].base, &t[victim_stack].base);
				loop_two = 0;
				flag_two = 1;
			}
			else if (victim_stack == 0)
			{
				victim_stack = 2;//N-1;
			}
			else
			{
				victim_stack--;
			}
			loop_two--;
			if(loop_two <= 0 && flag_two == 0)
			{
				//the program couldn't find anywhere for
				//the disk to go, so a turn aka loop isn't
				//consumed, because it doesn't count as a
				//move
				moves++;
			}
		}
		flag_two = 0;
		moves--;
		if(current_num == N)
		{
			current_num = 1;
		}
		else
		{
			current_num++;
		}
	}
}


void finish_tower_even(tower t[3])
{
	//3->2->1...3->2->1
	//for odd N ^^^
	//for even N go 1->2->3->4
	int current_num = 1;
	int current_stack = 0;
	int victim_stack = 1;
	//2**N - 1 is the least amount
	//of moves necessary to solve
	//this puzzle
	int moves = pow(2, N) - 1;
	int flag = 0;
	while(moves > 0)
	{
		int current_disk;
		for(int i = 0; i < 3; i++)
		{
			if(peek(&t[i].base) == current_num)
			{
				current_stack = i;
				current_disk = peek(&t[current_stack].base);
				flag = 1;
			}
			if(current_stack == 2)
			{
				victim_stack = 0;
			}
			else
			{
				victim_stack = current_stack + 1;
			}
			if(flag == 0 && i == 2)
			{
				if(current_num == N)
				{
					current_num = 1;
				}
				else
				{
					current_num++;
				}
				//learned something new
				//because i++ adds after for loop
				i = -1;
			}
		}
		flag = 0;
		int loop_two = 2;
		int flag_two = 0;
		while(loop_two > 0)
		{
			int victim_disk = peek(&t[victim_stack].base);
			if(current_disk < victim_disk || victim_disk == 0)
			{
				move_disk(&t[current_stack].base, &t[victim_stack].base);
				loop_two = 0;
				flag_two = 1;
			}
			else if (victim_stack == 2)
			{
				victim_stack = 0;//N-1;
			}
			else
			{
				victim_stack++;
			}
			loop_two--;
			if(loop_two <= 0 && flag_two == 0)
			{
				//the program couldn't find anywhere for
				//the disk to go, so a turn aka loop isn't
				//consumed, because it doesn't count as a
				//move
				moves++;
			}
		}
		flag_two = 0;
		moves--;
		if(current_num == N)
		{
			current_num = 1;
		}
		else
		{
			current_num++;
		}
	}
}

void test(tower t[3])
{
	move_disk(&t[0].base, &t[2].base);
}


int main()
{
	//weird memory problem
	//with pop and getting rid of this
	//object
	tower* t;// = new tower[3];
	t = init_towers();
	int n = 0;
	tower* p;
	p = init_towers();
	finish_tower_even(p);
	printf("Tower A: %d\n", peek(&p[0].base));
	printf("Tower B: %d\n", peek(&p[1].base));
	printf("Tower C: %d\n", peek(&p[2].base));
	n = pop(&p[2].base);
	printf("%d\n", n);
	n = pop(&p[2].base);
	printf("%d\n", n);
	n = pop(&p[2].base);
	printf("%d\n", n);
	n = pop(&p[2].base);
	printf("%d\n", n);
	n = pop(&p[2].base);
	printf("%d\n", n);
	n = pop(&p[2].base);
	printf("%d\n", n);
}
