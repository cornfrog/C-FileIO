/*
	Steps to handle files in C
	--------------------------
	Step 1.) Open a file using fopen("filename/path", "option")
		options:
			> "r" = read file
			> "w" = write to file 
			> "a" = append to file

	Step 2.) Read from file using the following options:
		> fscanf() - reads formatted data
		> fgets() - reads line of text
	
	Step 3.) Write to file using the following options:
		> fprintf() - writes formatted data to file
		> fputs() - writes string to file 

	Step 4.) Close file - fclose()

	* ALL THESE FUNCTIONS REQUIRE A FILE* 
*/

#include <stdio.h>

void createFile();	//function to write to/create file
void readFile();	//function to read a file
FILE* file;	//file variable

int main(){
	createFile();
	readFile();
	return 0;
}


void createFile(){
	//open file to write to 
	file = fopen("testFile.txt", "w");
	//if file is unable to be opened print error message
	if(file == NULL){
		printf("Error: Failed to create file\n");
	}
	//else write data to file
	else{
		fprintf(file, "Writting to file with fprintf()\n");
		fputs("Writting to file with fputs()\n", file);
		fclose(file);
	}

}

void readFile(){
	//buffer to collect data from file
	char buffer[100];
	file = fopen("testFile.txt", "r");
	//if file cant be opened print error message
	if(file == NULL){
		printf("Error opening file");
	}
	//else read from file
	else{
		/*
			while fgets() is able to get data from file
			place string in buffer and print it
			(
			  string will be the size of buffer-1
				for '\n' character 	
			)
		*/
		while(fgets(buffer, sizeof(buffer), file) != NULL){
			printf("%s", buffer);
		}
		fclose(file);
	}
}
