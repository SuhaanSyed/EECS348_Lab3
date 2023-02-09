#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Program1.h"
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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
    printf("Monthly sales report for 2022:\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    for(int i = 0; i < MONTHS; ++i) {
        printf("%-15s $%-15f\n", ALL_MONTHS[i], sales[i]);
    }
}

void min_max_avg(float *sales) {
    int min_month = 0;
    int max_month = 0;
    float min_sale = sales[0];
    float max_sale = sales[0];
    float sum = 0;
    float avg = 0;
    for(int i = 0; i < MONTHS; ++i) {
        min_sale = MIN(min_sale, sales[i]);
        min_month = ((sales[i] == min_sale)? i : min_month);
        max_sale = MAX(max_sale, sales[i]);
        max_month = ((sales[i] == max_sale)? i : max_month);
        sum += sales[i];
    }
    avg = sum / MONTHS;
    printf("Sales summary:\n");
    printf("Minimum sales: $%f (%s)\n", min_sale, ALL_MONTHS[min_month]);
    printf("Maximum sales: $%f (%s)\n", max_sale, ALL_MONTHS[max_month]);
    printf("Average sales: %f\n", avg);
}

void six_month_avg(float* sales){

    printf("Six-Month Moving Average Report: \n");
    
    for(int i = 0; i <= 6; ++i) {
        float sum = 0;
        float avg = 0;
        for(int j=i; j < i + 6; ++j){
            sum += sales[j];
        }
        avg = sum / 6;
        printf("%-15s - %-15s: $%-15f\n", ALL_MONTHS[i], ALL_MONTHS[i+5], avg);

    }
}

void print_sales_descending(float* sales){
    int temp;
    int indexes[MONTHS];
    for(int i = 0; i < MONTHS; ++i) {
        indexes[i] = i;
    }

    for(int i = 0; i < MONTHS; ++i) {
        for(int j = i + 1; j < MONTHS; ++j) {
            if(sales[indexes[i]] < sales[indexes[j]]){
                temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }
    printf("Sales Report (Highest to Lowest):\n");
    for(int i = 0; i < MONTHS; ++i) {
        printf("%-15s : $%-15f\n", ALL_MONTHS[indexes[i]], sales[indexes[i]]);
    }
}
int main(){
    float* month_sales_data = read_data_from("sales.txt");
    print_data(month_sales_data);
    printf("\n");
    min_max_avg(month_sales_data);
    printf("\n");
    six_month_avg(month_sales_data);
    printf("\n");
    print_sales_descending(month_sales_data);
    printf("\n");
    


    return 0;
}