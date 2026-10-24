#include <stdio.h>
#define MAX 1000

int main()
{
    int mem[MAX], i, j, start, size, pid;

    for(i = 0; i < MAX; i++)
        mem[i] = -1;

    for(pid = 1; pid <= 3; pid++)
    {
        printf("Enter memory size for Process %d: ", pid);
        scanf("%d", &size);

        start = -1;

        for(i = 0; i <= MAX - size; i++)
        {
            for(j = 0; j < size && mem[i+j] == -1; j++);

            if(j == size)
            {
                start = i;
                break;
            }
        }

        if(start != -1)
        {
            for(i = start; i < start + size; i++)
                mem[i] = pid;

            printf("Process %d allocated from %d to %d\n",
                   pid, start, start + size - 1);
        }
        else
            printf("Allocation failed for Process %d\n", pid);
    }

    return 0;
}
