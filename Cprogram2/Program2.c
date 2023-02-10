#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Program2.h"

void print_output(int tdtp, int tdfg, int td, int fg, int sf){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", tdtp, tdfg, td, fg, sf);
};

int main(){
    int tdtp = 0; // TD + 2pt
    int tdfg = 0; // TD + FG
    int td = 0; // TD
    int fg = 0; // FG
    int sf = 0; // Safety

    int tdtp_pts = 8;
    int tdfg_pts = 7;
    int td_pts = 6;
    int fg_pts = 3;
    int sf_pts = 2;

    int total_pts = 0;
    while(1){
        printf("Enter 0 or 1 to STOP ");
        printf("Enter the number of points scored: ");
        scanf("%d", &total_pts);

        for(int i=0; i<=total_pts/tdtp_pts; i++){
            for(int j=0; j<=total_pts/tdfg_pts; j++){
                for(int k=0; k<=total_pts/td_pts; k++){
                    for(int l=0; l<=total_pts/fg_pts; l++){
                        for(int m=0; m<=total_pts/sf_pts; m++){
                            if((tdtp_pts*i + tdfg_pts*j + td_pts*k + fg_pts*l + sf_pts*m) == total_pts){
                                tdtp = i;
                                tdfg = j;
                                td = k;
                                fg = l;
                                sf = m;
                                print_output(tdtp, tdfg, td, fg, sf);
                            }
                        }
                    }
                }
            }
        }
        if(total_pts == 0 || total_pts == 1){
            break;
        }

    }
    return 0;
}