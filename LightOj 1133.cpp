#include<stdio.h>

int main(){

    int input, i = 0, m , n, k = 0, d, y, z, opStart = 0;
    char oper;

    scanf("%d", &input);


    while(i < input){
        scanf("%d %d", &n , &m);

        int myArray[n];
        k = 0;

        while(k < n){
            scanf("%d", &myArray[k]);
            k++;
        }

        k = 0;

        while(k < m){
            scanf(" %c", &oper);


            if(oper == 'S'){
                scanf("%d", &d);
                opStart = 0;

                while(opStart < n){
                    myArray[opStart] = myArray[opStart] + d;

                    opStart++;

                }
            }

            else if(oper == 'M'){


                 scanf("%d", &d);
                opStart = 0;

                while(opStart < n){
                    myArray[opStart] = myArray[opStart] * d;

                    opStart++;

                }
            }
            else if(oper == 'D'){
                scanf("%d", &d);
                opStart = 0;


                    while(opStart < n){
                    myArray[opStart] = myArray[opStart] / d;

                    opStart++;





                }


            }
            else if(oper == 'R'){

                opStart = 0;

                int second[n];

                while(opStart < n){
                    second[opStart] = myArray[opStart];

                    opStart++;

                }
                opStart = 0;
                while(opStart < n){
                    myArray[opStart] = second[n - 1 - opStart];

                    opStart++;

                }



            }
            else{

                scanf("%d %d", &y, &z);

                opStart = myArray[y];

                myArray[y] = myArray[z];
                myArray[z] = opStart;

            }

        k++;

        }



        k = 1;
    printf("Case %d:\n", i + 1);
    printf("%d",myArray[0]);
    while(k < n){
        printf(" %d", myArray[k]);

        k++;
    }
    printf("\n");
    i++;

    }


return 0;
}
