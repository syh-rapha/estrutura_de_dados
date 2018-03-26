#include <iostream>
#define n 7
using namespace std;

void selectionDecrescente(int v[]){
	int i, j, k, aux, mini;
	for(i=0; i<(n-1); i++){
		mini = i;
		for(j=i+1; j<n; j++)
			if(v[j] > v[mini])
				mini = j;
		aux = v[mini];
		v[mini] = v[i];
		v[i] = aux;
		cout << "\n";
		for(k=0; k<n; k++)
			cout <<" " <<v[k];
	}
}

int main(){
	int v[n] = {1, 2, 4, 3, 9, 5, 15};
	selectionDecrescente(v);
	
	return 0;
}
