#include <iostream>
using namespace std;

#include <limits> // per utilizzare INT_MIN
//Value of INT_MIN is -2147483648.

int SommaMassima1(int S[], int n){  // S contiene n elementi, almeno 1 positivo
	int _max = 0;
	int somma;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			somma = 0;
			for(int k = i; k <= j; k++)
				somma = somma + S[k];
			if (somma > _max) _max = somma;
 		}
	}
	return _max;
}

int SommaMassima2(int S[], int n){  // S contiene n elementi, almeno 1 positivo
	int _max = 0;
	int somma;
	for(int i = 0; i < n; i++) {
		somma = 0;
		for(int j = i; j < n; j++) {
			somma = somma + S[j];
			if (somma > _max) _max = somma;
 		}
	}
	return _max;
}

int SommaMassima3(int S[], int n){
	int _max = 0;
	int somma= _max;
	for(int j = 0; j < n; j++) {
		if (somma > 0) {
			 somma = somma + S[j];
		} else {
			somma = S[j];
		}
		if (somma > _max) _max = somma;
	}
	return _max;
}


// Soluzione ricorsiva
// massimo tra 2 interi
int max_of(int a, int b) { return (a > b) ? a : b; }
// massimo tra 3 interi
int max_of(int a, int b, int c) { return max_of(max_of(a, b), c); }

// Trova la somma massima in arr[] t.c. il segmento include arr[m]
int maxCrossingSum(int arr[], int l, int m, int h)
{    // Cerco nella parte sx di mid.
    int sum = 0;
    int left_sum = INT_MIN; // posso mettere anche -100000...
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Cerco nella parte dx di mid.
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // restituire direttamente left_sum + right_sum
    // fallirebbe in caso di somme parziali negative
    return max_of(left_sum + right_sum, left_sum, right_sum);
}

// Ritorna la somma del segmento con somma massima
// in arr[l....h]
int maxSubArraySum(int arr[], int l, int h)
{
    // Caso base: un solo elemento
    if (l == h)
        return arr[l];

    // middle point
    int m = (l + h) / 2;

    /* Restituisce il massimo dei tre
    a) Max somma a sx
    b) Max somma a dx
    c) Max considerando sequenze che includono arr[m] */
    return max_of(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}

int SommaMassimaRicorsiva(int S[], int n){
    return maxSubArraySum(S, 0, n - 1); }

int main(){

    int vec[] = {-7,4,-8,3,4,-2,6,-10,1,3,-3,9};
    int num = sizeof(vec)/sizeof(int);

    cout << "Somma max:\t" << SommaMassima1(vec,num) << endl;
    cout << "Somma max:\t" << SommaMassima2(vec,num) << endl;
    cout << "Somma max:\t" << SommaMassima3(vec,num) << endl;

    cout << "Somma max:\t" << SommaMassimaRicorsiva(vec,num) << endl;
    return 0;
}
