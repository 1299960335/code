#include<stdio.h>
#include<assert.h>
int CompInt(const void* _xq, const void* _yq)  //ʵ������Ԫ�صıȽ�
{
	int* xq = (int*)_xq;
	int* yq = (int*)_yq;
	if (*xq > * yq) {
		return 1;
	}
	else if (*xq < *yq) {
		return -1;
	}
	else {
		return 0;
	}
}
void swup(char* srt, char* est, int size)//����ð������
{
	while (size) {
		char temp = *srt;
		*srt = *est;
		*est = temp;
		srt++;
		est++;
		size--;
	}
}
void print( int arr[] ,int size)//��ӡ����
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void my_qsort(void* arr,int set, int size, int(*comp)(const void*,const void*))//qsort������ʵ��
{
	assert(arr != NULL);//�ж�ָ���Ƿ�Ϸ�
	assert(comp != NULL);
	char* e = (char*)arr;
	for (int i = 0; i < set - 1; i++) {
		int flag = 0;
		for (int j = 0; j < set - 1 - i; j++) {
			if (comp(e + j*size ,e + (j+1)*size) > 0) {   //���ʸ����ֽڽ��н�������
					flag = 1;
					swup(e + j * size, e + (j + 1) * size,size);
			}
		}
		if (flag == 0) {   //���Ԫ���������Ƴ�ѭ��
				break;
		}
	}
}
int main()
{
	int arr[] = { 12,57,84,94,15,645,123,47 };
	int set = sizeof(arr) / sizeof(arr[0]);
	print(arr, set);
	my_qsort(arr,set,sizeof(int),CompInt);
	print(arr, set);
	return 0;
}