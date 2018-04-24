#include <stdio.h>
int saludo();

int main() {
	saludo();
}

int saludo(){
	int i;

	for (i=0; i<=10; i++){
		printf("\n hola mundo desde el hilo principal");
		sleep(1);
}
}
