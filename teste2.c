#include <stdio.h>

int main(){
	
	int menu [18][117];
	int i, k;
	
	//primeira linha
	menu[0][0] = 201;
	menu[0][116] = 187;
	
	for (i=1; i<116; i++){
		menu[0][i] = 205;
	}
	
	//segunda linha
	for(i=1; i<116; i++){
		if(i == 51){
			menu[1][51] = 77;
		}else if(i == 52){
			menu[1][52] = 69;
		}else if(i == 53){
			menu[1][53] = 78;
		}
		else if(i == 54){
			menu[1][54] = 85;
		}else{
			menu[1][i] = 32;
		}
	}
	
	//terceira linha
	menu[2][0] = 204;
	menu[2][116]=185;
	
	for (i=1; i<116; i++){
		menu[2][i] = 205;
	}
	
	//quarta, quinta e sexta linha
	for (i=3; i<6;i++){
		for(k=1; k<116; k++){
			menu[i][k] = 32;
		}	
	}
	
	//meio
	for(k=6; k<11;k++){
		for(i=1; i<116;i++){
			if(k == 6){
				if(i == 46){
					menu[6][46] = 49;
				}else if(i == 47){
					menu[6][47] = 32;
				}else if(i == 48){
					menu[6][48] = 240;
				}else if(i == 49){
					menu[6][49] = 32;
				}else if(i == 50){
					menu[6][50] = 74;
				}else if(i == 51){
					menu[6][51] = 111;
				}else if(i == 52){
					menu[6][52] = 103;
				}else if(i == 53){
					menu[6][53] = 97;
				}else if(i == 54){
					menu[6][54] = 114;
				}else{
					menu[6][i] = 32;
				}	
			}else if(k == 7){
				if(i == 46){
					menu[7][46] = 50;
				}else if(i == 47){
					menu[7][47] = 32;
				}else if(i == 48){
					menu[7][48] = 240;
				}else if(i == 49){
					menu[7][49] = 32;
				}else if(i == 50){
					menu[7][50] = 73;
				}else if(i == 51){
					menu[7][51] = 110;
				}else if(i == 52){
					menu[7][52] = 116;
				}else if(i == 53){
					menu[7][53] = 114;
				}else if(i == 54){
					menu[7][54] = 117;
				}else if(i == 55){
					menu[7][55] = 99;
				}else if(i == 56){
					menu[7][56] = 111;
				}else if(i == 57){
					menu[7][57] = 101;
				}else if(i == 58){
					menu[7][58] = 115;
				}else{
					menu[7][i] = 32;
				}
			}else if(k ==8){
				if(i == 46){
					menu[8][46] = 51;
				}else if(i == 47){
					menu[8][47] = 32;
				}else if(i == 48){
					menu[8][48] = 240;
				}else if(i == 49){
					menu[8][49] = 32;
				}else if(i == 50){
					menu[8][50] = 82;
				}else if(i == 51){
					menu[8][51] = 97;
				}else if(i == 52){
					menu[8][52] = 110;
				}else if(i == 53){
					menu[8][53] = 107;
				}else if(i == 54){
					menu[8][54] = 105;
				}else if(i == 55){
					menu[8][55] = 110;
				}else if(i == 56){
					menu[8][56] = 103;
				}else{
					menu[8][i] = 32;
				}
			}else if(k ==9){
				if(i == 46){
					menu[9][46] = 52;
				}else if(i == 47){
					menu[9][47] = 32;
				}else if(i == 48){
					menu[9][48] = 240;
				}else if(i == 49){
					menu[9][49] = 32;
				}else if(i == 50){
					menu[9][50] = 67;
				}else if(i == 51){
					menu[9][51] = 114;
				}else if(i == 52){
					menu[9][52] = 101;
				}else if(i == 53){
					menu[9][53] = 100;
				}else if(i == 54){
					menu[9][54] = 105;
				}else if(i == 55){
					menu[9][55] = 116;
				}else if(i == 56){
					menu[9][56] = 111;
				}else if(i == 57){
					menu[9][57] = 115;
				}else{
					menu[9][i] = 32;
				}
			}else if(k == 10){
				if(i == 46){
					menu[10][46] = 53;
				}else if(i == 47){
					menu[10][47] = 32;
				}else if(i == 48){
					menu[10][48] = 240;
				}else if(i == 49){
					menu[10][49] = 32;
				}else if(i == 50){
					menu[10][50] = 83;
				}else if(i == 51){
					menu[10][51] = 97;
				}else if(i == 52){
					menu[10][52] = 105;
				}else if(i == 53){
					menu[10][53] = 114;
				}else{
					menu[10][i] = 32;
				}
			}
		}
	}
	
	//depois
	for (i=11; i<17;i++){
		for(k=1; k<116; k++){
			menu[i][k] = 32;
		}	
	}
	//acabou
	menu[17][0] = 200;
	menu[17][116] = 188;
	
	for (i=1; i<116; i++){
		menu[17][i] = 205;
	}
	
	//cantos
	for(i=1; i<17; i++){
		menu[i][0] = 186;
		menu[i][116] = 186;
	}
	
	//tudo
	for(i=0; i<18; i++){
		for (k=0; k<117; k++){
			printf("%c", menu[i][k]);
		}
		printf("\n");
	}
	
	return 0;
}
