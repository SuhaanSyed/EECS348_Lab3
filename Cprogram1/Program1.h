#ifndef PROGRAM1_H
#define PROGRAM1_H

int MONTHS = 12;
char *ALL_MONTHS[] = {"January", 
                    "February", 
                    "March", 
                    "April", 
                    "May", 
                    "June", 
                    "July", 
                    "August", 
                    "September", 
                    "October", 
                    "November", 
                    "December"};
void print_data(float *sales );
void min_max_avg(float *sales); // (float sales[MONTHS]);
void six_month_avg(float* sales); // (float sales[MONTHS]);
void print_sales_descending(float* sales); // (float sales[MONTHS]);
float* read_data_from(char *file_name);

#endif