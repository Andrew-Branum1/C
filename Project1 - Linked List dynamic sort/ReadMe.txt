	Drew Branum		5291638
	
	1.1) I chose to install Ubuntu on my bare hadware because it was recommended and I only had a problem with the installation after it was already installed. I've never dual-booted before so I wanted to learn how to. It was a bit tricky with a SUrface Pro 4, but I managed to figure it out with the help of youtube and google. 

	1.2) 	1: ls - lists all the files in the current directory
		2: cd - reverts back to home directory
		3: cat > filename - creates a file and allows you to edit it immediately
		4: rmdir - removes a directory
		5: mv - renames a directory
		6: pwd - displays path from root to current directory
		7: touch - creates a new file
		8: help - displays commands
		9: cp - copies a directory to another directory
		10: df - shows the available disk space in each partition
	
	1.3) 5.15.0-46-generic - located in Computer/boot
	
	1.4)	

		https://www.informit.com/articles/article.aspx?				p=1610334&seqNum=2
		1: arch - architecture source
		2: block - block I/O
		3: certs - 
		4: crypto - crypto API
		5: Documentation - kernel source documentation 
		6: drivers - device drivers
		7: fs - VFS and individual file systems
		8: include - kernel headers
		9: init - kernel boot and initialization
		10: ipc - interprocess communication code
		11: kernel - core subsystems
		12: lib - helper routines
		13: Licenses -
		14: mm - memory management
		15: net - networking 
		16: samples - sample, demonstrative code
		17: scripts - scripts used to build kernel
		18: security - linux security mode
		19: sound - sound subsystem
		20: tools - tools used to develop linux
		21: usr - early user-space code
		22: virt - virtualization infrastructure

	1.5) Name: syscall_64.tbl
	   File Location: /linux-5.15.63/arch/x86/entry/syscalls/syscall_64.tbl
	   0: read /sys_read
	   8: lseek/ sys_lseek
	   57: fork / sys_fork
	   90: chmod / sys_chmod
	   327: preadv2 / sys_preadv2
	   
	3) System Calls:
	read
	write
	close
	mmap 
	mprotect
	brk
	pread64
	access
	execve
	munmap
	arch_prctl
	set_tid_address
	openat
	exit_group
	prlimit64
	newfstatat
	getrandom
	set_robust_list
	rseq
	+++ exited with 255 +++
	
	4) Preformance Analysis:

	Easy:
	
	real	0m0.004s
	user	0m0.000s
	sys	0m0.002s
	
	Medium:
	
	real	0m0.953s
	user	0m0.812s
	sys	0m0.004s
	
	Hard:
	
	real	0m8.380s
	user	0m8.058s
	sys	0m0.092s

	


	
