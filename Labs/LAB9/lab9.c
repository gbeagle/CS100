#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly {
	double coeff;
	int degree;
	struct poly *next;
} Poly;

void printPoly(Poly *);
double evaluate(Poly *, double);
int terms(Poly *);

int main(void) {
	Poly *myPoly = NULL;
	printf("Enter the coefficient and degree of a term to add to the polynomial : ");
	double c;
	int d;
	scanf("%lf %d", &c, &d);
	while (  ! ( fabs(c-0.0) < 0.00001 ) || d !=0 ) {
		// add at front
		Poly *newNode = malloc( sizeof(Poly) );
		newNode->coeff = c;
		newNode->degree = d;
		newNode->next = myPoly;
		myPoly = newNode;
		printf("Enter a coefficient and degree (or 0 0 to stop adding terms) : ");
		scanf("%lf %d", &c, &d);
	}

	printf("\n\n");
	printf("The polynomial is : ");
	printPoly(myPoly);
	printf("\n\n");
	printf("The polynomial has %d terms\n\n", terms(myPoly) );
	printf("Polynomial evaluation - enter a value for x : ");
	double x;
	scanf("%lf", &x);
	printf("\tThe value of the polynomial at x=%lf is %lf\n", x, evaluate(myPoly, x) );
	return 0;
}

void printPoly(Poly *ptr){
	while( ptr != NULL){
		printf(" %lfx^%d ", ptr->coeff, ptr->degree); 
		if( ptr->next != NULL){	
			printf("+");
		}
		ptr = ptr->next;
	}
	printf("\n");
	return;
}


int terms(Poly *ptr){
	int count = 0;
	while(ptr != NULL ){	
		count++;
		ptr = ptr->next;
	}
	return count;
}

double evaluate(Poly *ptr, double x){
	double total = 0;
	while(ptr != NULL){
		double c, d;
		c = (double)(ptr->coeff);	
		d = (double)(ptr->degree); 
		total = total + (c * pow(x, d));	
		ptr = ptr->next;
	}	
	return total;

}
