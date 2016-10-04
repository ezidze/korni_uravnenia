#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <assert.h>

//функция для сравнения двух чисел
bool sravnenie_chisel(float a, float b){
	const float eps = pow(10.0, -6);
	if (abs(a-b) <= eps) return 1;
	else return 0;

}

//реализуем функцию для подсчета корней
bool korni (float a[3], float x, bool* logic){
	assert(a);
	assert(x);
	if ( sravnenie_chisel(0, a[0]) && sravnenie_chisel(0, a[1]) ){
		printf("уравнение выродилось из квадратного, x=");
		if ( !sravnenie_chisel(a[2],0) ){
			x[0] = -a[2];
			return true;
		}
		else{
			printf("корней бесконечное количество\n");
			return false;
		}
	}
	if ( sravnenie_chisel(0, a[0]) && !sravnenie_chisel(0, a[0]) ){
		printf("уравнение выродилось из квадратного, x=");
		x[0] = -a[2]/a[1];
		return true;
	}
	if ( !sravnenie_chisel(0, a[0]) ){
		float D = a[1]*a[1]-4*a[0]*a[2];
		if (D > 0){
			printf("корни уравнения\n");
			*logic = 1;
			x[0] = (-a[1]+sqrt(D))/(2*a[0]);
			x[1] = (-a[1]-sqrt(D))/(2*a[0]);
			return true;
			

		}
		if (sravnenie_chisel(0, D)){
			printf("корень уравнения\n");
			x[0] = -a[2]/(2*a[1]);
			return true;
		}
		if (D < 0){
			printf("корней нет\n");
			return false;
		}

	}
}

//а тут мы организуем задание коэффициентов
float pechat(char kof){
	float chislo = 0;
	printf("Введите коэффициент");
	printf(" %c\n", kof);
	scanf("%f", &chislo);
	return chislo;
}

//функция для вывода корней
void input_otv(bool opred_per, bool vtor_kor,  float x[2] ){
	if ( opred_per){
		printf("%4f ", x[0]);
		if (vtor_kor == 1){
			printf("%4f\n", x[1]);
		}
	}
}


// основное тело программы
int main(){
	setlocale(LC_ALL, "rus");
	//задаем переменные
	float x[2]; 
	float koff[3];
	char name_koff[] = {'a', 'b', 'c'};
	bool est_li_koren = 0;
	bool print_or_not_print=0;

	for (int i = 0; i < 3; ++i) koff[i] = 0;//занулим массив а
	for (int i = 0; i < 2; ++i) x[i] = 0;//занулим массив х

	for (int i = 0; i < 3; ++i){
		koff[i]=pechat(name_koff[i]);
	}
	print_or_not_print=korni(koff,x,&est_li_koren);
	input_otv(print_or_not_print,est_li_koren,x);
	
system("pause");	

return 0;
}
