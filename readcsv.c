// 
// File: readcsv.c
//
// readcsv.c accepts data in the form supplied above from standard in, and produces a
// report containing the number of zip codes, the total population, and information about the
// zipcodes with the fewest and the most people
//
// @author Alex A Denny aad7700@g.rit.edu
// // // // // // // // // // // // // // // // //

#include <stdio.h>
#include <stdlib.h>

int main( ){

	//array to get stdin
	char buf[256] = "";
	
	//declaring necessary vars
	int zipcodes = 0;
	long min_pop = 2147483647;
	long max_pop = 0;
	long total_pop = 0;

	long zip_max = 0;
	long zip_min = 0;
	


	//consumes the header line so it doesn't
	//interfere with loop/computation
	fgets( buf, 256, stdin);

	///loop that reads through the entire csv file
	while( fgets( buf, 256, stdin ) ) {
		
		//vars for strtol
		char* ptr = NULL;
		long zip_num = strtol( buf, &ptr, 10 );
		

		//sets the "zipcode," to just zeros 
		//so we can get the population of 
		//the zipcode
		//For example: 99535,123456
		//is changed to 000000123456
		for( int i = 0; i < 6; i++){
		
			buf[i] = 48;
		
		}
		
		long zip_pop = strtol( buf, &ptr, 10 );
		

		//changing vars as appropriate
		zipcodes++;

		if( min_pop > zip_pop ) {
		
			min_pop = zip_pop;
			zip_min = zip_num;

		}
		if( max_pop < zip_pop ){

			max_pop = zip_pop;
			zip_max = zip_num;

		}
		
		total_pop += zip_pop;


	}	
		
	//displaying output
	printf("Total population across %d zipcodes is %ld.\n", zipcodes, total_pop);
	printf("The fewest people live in %ld, population %ld.\n", zip_min, min_pop);
	printf("The most people live in %ld, population %ld.\n", zip_max, max_pop);
	
	return 0;
}

