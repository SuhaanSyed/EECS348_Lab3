#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Program1.h"

float* read_data_from(char *file_name){
    const int months = 12;
    float* month_sales_data = (float*)malloc(sizeof(float) * months);
    
    FILE *fp = fopen(file_name, "r+");
    if(fp == NULL){
        printf("Please check your file again!\n");
    }

    for(int i = 0; i < months; i++){
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }

    return month_sales_data;
}

void print_data(float *sales){
    printf("Monthly sales report for 2022\n");
    printf("%-15s %-15s\n", "Month:", "Sales:");
    for(int i = 0; i < MONTHS; ++i) {
        printf("%-15s %-15f\n", ALL_MONTHS[i], sales[i]);
    }
}

void min_max_avg(float *sales) {

}

int main(){
    float* month_sales_data = read_data_from("sales.txt");
    print_data(month_sales_data);



    return 0;
}