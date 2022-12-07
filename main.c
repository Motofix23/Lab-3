#include <math.h>
#include <time.h>
#include <stdio.h>

double f(double x) {
	double one = -10 * (pow((x - 30), 5));
	double two = 12 * (pow(x, 4));
	double three = -3 * (pow(x, 6));
	double four = (pow(x, 3)) * 5;
	double five = -10;
	double res1 = one + two + three + four + five;
	double res = res1 * (pow(10, -3));
	return res;
}

double solverprop(double a, double b, int n) {
	int start = clock();
	int counter = 0;
	double eps = 0.000001;

	unsigned int cont;

	do {
		cont = 0;
		do {
			double next = (a + b) / 2;

			double nextF = f(next);

			if (fabs(nextF) < eps) {
				printf("**********************\n");
				printf("*METHOD BY PROPORTION*\n");
				printf("**********************\n");
				printf("The root is %lf\nCalculated during %li milliseconds\n",
						next, clock() - start);
				printf("step: %i\n", counter);
				printf("======================\n");
				return next;
			}

			if (signbit(nextF) != signbit(f(a))) {
				b = next;
			} else {
				a = next;
			}

			counter++;
		} while (counter % n != 0);

		printf("Root hasn't been found after %u steps. Continue(0/1)?", n);
		fflush(stdout);
		scanf("%u", &cont);

	} while (cont == 1);
	return 0;
}

double solverhord(double a, double b, int n) {
	int start = clock();
	int counter = 0;
	double eps = 0.000001;

	unsigned int cont;

	do {
		cont = 0;
		do {
			double next = a - f(a) * (a - b) / (f(a) - f(b));

			double nextF = f(next);

			if (fabs(nextF) < eps) {
				printf("**********************\n");
				printf("*  METHOD BY HORDS   *\n");
				printf("**********************\n");
				printf("The root is %lf\nCalculated during %li milliseconds\n",
						next, clock() - start);
				printf("step: %i\n", counter);
				printf("======================\n");
				return next;
			}
			b = a;
			a = next;
			counter++;
		} while (counter % n != 0);

		printf("Root hasn't been found after %u steps. Continue(0/1)?", n);
		fflush(stdout);
		scanf("%u", &cont);

	} while (cont == 1);
	return 0;
}

int main() {
	double a;
	double b;
	double n;
	int c;
	printf("Enter argument a >>");
	fflush(stdout);
	scanf("%lf/n", &a);
	printf("Enter argument b >>");
	fflush(stdout);
	scanf("%lf/n", &b);
	printf("Enter number of steps >>");
	fflush(stdout);
	scanf("%lf/n", &n);

	printf("Choose one from this methods: 1 Proportional, 2 Hord >>");
	fflush(stdout);
	scanf("%i", &c);
	if(c != 1 && c != 2){
		printf("!!!WRONG CHOICE, RESTART PROGRAM!!!");
		return -1;
	}

	printf("----------------------------------------------------\n");
	printf("a = %lf | b = %lf | steps %lf |\n", a, b, n);
	printf("----------------------------------------------------\n");

	if(c == 1)
		solverprop(a, b, n);
	if(c == 2)
		solverhord(a, b, n);

	if (f(a) > 0 && f(b) > 0){
		printf("!!!SOMETHING PASSED WRONG, RETRY WITH ANOTHER ARGUMENTS!!!");
		return -1;
	}

	if (f(a) < 0 && f(b) < 0){
		printf("!!!SOMETHING PASSED WRONG, RETRY WITH ANOTHER ARGUMENTS!!!");
		return -1;
	}

	return 0;
}
