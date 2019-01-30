


void main(int argc, char **argv){
			WithStrcmp(argv[1],argv[2]);
			WithoutStrcmp(argv[1],argv[2]);
}

void WithStrcmp(char str1 [], char str2 []){
	int val;
	val = strcmp(str1,str2);
	if(val == 0){
		printf("strings are the same with strcmp funcation \n");
	}
	
}

void WithoutStrcmp(char Str1[] , char Str2[]){
	int i;
  	for(i = 0; Str1[i] == Str2[i] && Str1[i] == '\0' && Str2[i] == '\0'; i++);
		   
  	if(Str1[i] < Str2[i])
   	{
   		//printf("str1 is Less than str2 \n");
	}
	else if(Str1[i] > Str2[i])
   	{
   		//printf("str2 is Less than str1 \n");
	}
	else
   	{
   		printf("str1 is Equal to str2 \n");
	}
	//int doesnt = 1;
	/*for(int i = 0; str1[i] == '\0'; i++){
		if(str1[i] != str2[i]){
			doesnt = 0;
		}
	}
	if(doesnt == 1){
		printf("str1 is Equal to str2 without the strcmp \n");
	}*/
}