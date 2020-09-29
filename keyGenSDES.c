#include <stdio.h>
#include <math.h>

void keyGeneration(void);
	void p10 (int*);
	void p8 (int*,int*);
	void ls1 (int*,int*);
	void ls2 (int*);
	void inputKey (int*);

int main (void){
	keyGeneration(); // generation key1 and key2
	return 0;
}
/***********************************************************************/
void keyGeneration(void){
	int key[10],key1[8],key2[8],temp[10];
    inputKey(key);
	p10(key);
	ls1(key,temp);
	p8(key,key1);
	printf ("key1 : ");                                                      
		for (int i=0;i<8;i++)
			printf ("%d",key1[i]);
	ls2(temp);
	p8(temp,key2);
	printf ("\nkey2 : ");
		for (int i=0;i<8;i++)
			printf ("%d",key2[i]);
	printf ("\n");	
}
/*********************************************************************/
void ls1(int*key,int*temp){
	int i,j;
	int arr1[5],arr2[5],temp1[5],temp2[5];
	for (i=0,j=5;i<5;i++,j++){
		temp1[i]=arr1[i]=*(key+i);
		temp2[i]=arr2[i]=*(key+j);
	}
	arr1[0]=temp1[1];
	arr1[1]=temp1[2];
	arr1[2]=temp1[3];
	arr1[3]=temp1[4];
	arr1[4]=temp1[0];
	arr2[0]=temp2[1];
	arr2[1]=temp2[2];
	arr2[2]=temp2[3];
	arr2[3]=temp2[4];
	arr2[4]=temp2[0];
	for (int k=0;k<10;k++){
		if (k<5)
			*(temp+k)=*(key+k)=arr1[k];
		else
			*(temp+k)=*(key+k)=arr2[k%5];
	}	
}

/*********************************************************************/
void p10(int*key){
	int temp[10];
	for (int i=0;i<10;i++)
		temp[i]=*(key+i);
	*key=temp[2];
	*(key+1)=temp[4];
	*(key+2)=temp[1];
	*(key+3)=temp[6];
    *(key+4)=temp[3];
    *(key+5)=temp[9];
    *(key+6)=temp[0];
    *(key+7)=temp[8];
    *(key+8)=temp[7];
    *(key+9)=temp[5];
}
/*********************************************************************/
void p8(int*key,int*keyNumb){
	*keyNumb=*(key+5);
	*(keyNumb+1)=*(key+2);
	*(keyNumb+2)=*(key+6);
	*(keyNumb+3)=*(key+3);	
	*(keyNumb+4)=*(key+7);
	*(keyNumb+5)=*(key+4);
	*(keyNumb+6)=*(key+9);
	*(keyNumb+7)=*(key+8);
}
/**********************************************************************/
void ls2(int*key){
	int i,j;
	int arr1[5],arr2[5],temp1[5],temp2[5];
	for (i=0,j=5;i<5;i++,j++){
		temp1[i]=arr1[i]=*(key+i);
		temp2[i]=arr2[i]=*(key+j);
	}
	arr1[0]=temp1[2];
	arr1[1]=temp1[3];
	arr1[2]=temp1[4];
	arr1[3]=temp1[0];
	arr1[4]=temp1[1];
	arr2[0]=temp2[2];
	arr2[1]=temp2[3];
	arr2[2]=temp2[4];
	arr2[3]=temp2[0];
	arr2[4]=temp2[1];
	for (int k=0;k<10;k++){
		if (k<5)
			*(key+k)=arr1[k];
		else
			*(key+k)=arr2[k%5];
	}
}
/*********************************************************************/
void inputKey(int*key){
	printf ("\nEnter key(array; example : 1 0 1 0 1 1 1 1 0 1):\n");
	for (int i=0;i<10;i++)
		scanf (" %d",&*(key+i));
}
