int waitPid(void);

int main(int argc, char *argv[])
{
	waitPid();
	exit(0);
}


int waitPid(void)
{
	int ret_pid, status;
	int i;
	int pid_a[5] = {0,0,0,0,0};

	int mypid;
	mypid = getpid();
	printf(1, "Testing waitpid:\n");
	
	for (i = 0; i <5; i++)
	{
        	pid_a[i] = fork();

        	if (pid_a[i] == 0)
		{ 	// only the child executed this code
            		printf(1, " - The is child with PID# %d and I will exit with status %d\n", getpid(), 0);
            		exit(0);
        	}
    	}

	sleep(5);

    	printf(1, " - This is the parent: Now waiting for child with PID# %d\n",pid_a[0]);
    	ret_pid = waitpid(pid_a[0], &exit_status, 0);
    	printf(1, " - This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
    	sleep(5);
    	printf(1, " - This is the parent: Now waiting for child with PID# %d\n",pid_a[1]);
    	ret_pid = waitpid(pid_a[1], &exit_status, 0);
    	printf(1, " - This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);

	return 0;
}


