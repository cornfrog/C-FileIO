all:
	@gcc fileio.c -o fileio
	@mv fileio bin
	@echo Make Success - use \'make run\' to run program

run:
	@./bin/fileio

clean:
	@rm bin/fileio
	@rm testFile.txt
	@echo Make \'Clean\' Success - use \'make\' to get program
