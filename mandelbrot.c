#include <stdio.h>

const int size_x = 2000;
const int size_y = 2000;

const double domain_x_min = -2.5;
const double domain_x_max = 1.5;
const double domain_y_min = -2.0;
const double domain_y_max = 2.0;

const int max_color_component_value = 255;

const double escape_radius_squared = 4;
const int max_iteration = 1000;

const char color_map_r[] = { 0,	50, 100, 150, 200, 255 };

double scale_x( const int x ){
	return domain_x_min + (domain_x_max - domain_x_min) * ((double)x / size_x );
}

double scale_y( const int y ){
	return domain_y_min + (domain_y_max - domain_y_min) * ((double)y / size_y );
}

void color_for_iteration( char *r, char *g, char *b, const int iteration){
		*r = iteration * 3;
		*g = iteration;
		*b = iteration * -1;
}

int main()
{
    
    int Iteration;
    const int IterationMax=200;
    
		/* write header */
		printf("P6\n%d\n%d\n%d\n",
				size_x,size_y,max_color_component_value);

    /* compute and write image data bytes to the file*/
	for(int i_y=0; i_y < size_y ;i_y++)
	{
		for(int i_x=0; i_x < size_x ;i_x++){
			double x0 = scale_x( i_x );
			double y0 = scale_y( i_y );
			double x = 0.0;
			double y = 0.0;
		//	printf("%f,%f\n",x0,y0 );
			int iteration = 0;
			while (( (x*x + y*y) < 4 )&&( iteration < max_iteration )){
				/* printf( "\nx= */
				double xtemp = x*x - y*y + x0;
				y = 2*x*y + y0;
				x = xtemp;
				++iteration;
			}
			char r,g,b;
			color_for_iteration( &r, &g, &b, iteration );
			printf( "%c%c%c", r, g, b );
		}
    }
    return 0;
 }
