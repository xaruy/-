#include <stdio.h>

//方法一 
int MaxSubseqSum1(int List[], int N){
	int i, j, k;
	int ThisSum, MaxSum = 0;
	for(i = 0; i<N; i++){
		for(j = i; j < N; j++){
			ThisSum = 0;
			for(k = i; k <= j; k++){
				ThisSum += List[k];
				if(ThisSum > MaxSum){
					MaxSum = ThisSum;
				}
			}
		}
	}
	return MaxSum;
} 



//方法二 
int MaxSubseqSum2(int *List, int N){
	int i, j;
	int ThisSum, MaxSum = 0;
	
	for(i = 0; i < N; i++){
		ThisSum = 0;
		for(j = i; j < N; j++){
			ThisSum += List[j];
			if(ThisSum > MaxSum){
				MaxSum = ThisSum;
			}
		}
	}
	return MaxSum;
}




//方法3 
int Max3(int A, int B, int C){
	return A>B ? A>C ? A : C : B>C ? B : C;
} 

int DivideAndConquer(int List[], int left, int right){
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	
	int LeftBorderSum, RightBorderSum;
	int center, i;
	
	if(left == right){
		if(List[left]>0){
			return List[left];
		} else{
			return 0;
		} 
	}
	
	center = (left + right)/2;
	MaxLeftSum=DivideAndConquer(List, left, center);
	MaxRightSum=DivideAndConquer(List, center + 1, right);
	
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for(i = center; i >= left; i--){
		LeftBorderSum += List[i];
		if(LeftBorderSum > MaxLeftBorderSum){
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	
	MaxRightBorderSum = 0; RightBorderSum = 0;
	for(i = center + 1; i <= right; i++){
		RightBorderSum += List[i];
		if(RightBorderSum > MaxRightBorderSum){
			MaxRightBorderSum = RightBorderSum;
		}
	}
	
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N){
	return DivideAndConquer(List, 0 , N-1);
}

int main(){
	int N = 5;
	int List[] = {4,6,-3,5,-4};
	int sum;
	
	sum = MaxSubseqSum1(List, N);
	printf("MaxSubseqSum1 %d \n",sum);
	
	sum = MaxSubseqSum2(List, N);
	printf("MaxSubseqSum2 %d \n",sum);
	
	sum = MaxSubseqSum3(List, N);
	printf("MaxSubseqSum3 %d \n",sum);
}
