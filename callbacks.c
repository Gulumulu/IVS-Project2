#include "callbacks.h"
#include "calculator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>

double first;
int firston = 0;
int secondon = 0;
double second,third;
int last_op , morelast_op;
int zero = 1;

gchar* get_whole_text(GtkTextBuffer *buffer)
{
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(buffer, &start, &end);
	return gtk_text_buffer_get_text(buffer, &start, &end, TRUE);
}

void clear_clicked()
{
	firston = 0;
	secondon = 0;
	last_op = 0;
	first = 0;
	second = 0;
	zero = 1;
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_1), "", -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
//	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "0", 1);
}

double my_switch(double num1, double num2, int sign)
{
	switch(sign)
	{
		case '+': num1 = ADD(num1, num2);
			break;
		case '-': num1 = SUB(num1, num2);
			break;
		case '*': num1 = MUL(num1, num2);
			break;
		case '/': num1 = DIV(num1, num2);
			break;
		case '!': num1 = FCT(num1);
			break;
		case '|': num1 = ABS(num1);
			break;
		default: break;
	}
	return num1;
}

void window1_destroy()
{
	gtk_main_quit();
}

void zero_clicked()
{
	if (zero == 1)
	{
		gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
		gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "0", 1);
	}
	else
		gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "0", 1);
}

void one_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "1", 1);
	zero = 0;
}

void two_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "2", 1);
	zero = 0;
}

void three_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "3", 1);
	zero = 0;
}

void four_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "4", 1);
	zero = 0;
}

void five_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "5", 1);
	zero = 0;
}

void six_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "6", 1);
	zero = 0;
}

void seven_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "7", 1);
	zero = 0;
}

void eight_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "8", 1);
	zero = 0;
}

void nine_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "9", 1);
	zero = 0;
}

void add_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (secondon==1)
		{
		third = g_ascii_strtod(text, NULL);
		second = my_switch(second,third,last_op);				
		last_op=morelast_op;	
		}

	if (firston==0)
		{
		first = g_ascii_strtod(text, NULL);
		firston=1;
		}
 	else
		{
		if (secondon!=1) second=g_ascii_strtod(text, NULL);
	 	else secondon=0;
		first=my_switch(first,second,last_op);
		}
 	zero = 1;
 	last_op = '+';
 	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text,-1);
 	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"",-1);
 	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "+", 1);

}

void subtract_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (secondon==1)
		{
		third = g_ascii_strtod(text, NULL);
		second = my_switch(second,third,last_op);				
		last_op=morelast_op;	
		}

	if (firston==0)
		{
		first = g_ascii_strtod(text, NULL);
		firston=1;
		}
 	else
		{
		if (secondon!=1) second=g_ascii_strtod(text, NULL);
	 	else secondon=0;
		first=my_switch(first,second,last_op);
		}
 	zero = 1;
 	last_op = '-';
 	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text,-1);
 	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"",-1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "-", 1);

}

void dot_clicked()
{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), ".", 1);
}

void multiply_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	
	if (firston==0)
		{
		first = g_ascii_strtod(text, NULL);	
		firston=1;
		}
 	else
	{
		if (secondon==1)
			{
			third = g_ascii_strtod(text, NULL);
			second = my_switch(second,third,last_op);		
			last_op=morelast_op;	
			}
		else
			{
			if ((last_op != '+')&&(last_op != '-'))
				{
				second=g_ascii_strtod(text, NULL);
				first=my_switch(first,second,last_op);	
				}
			else
	 			{
	  			second=g_ascii_strtod(text, NULL);
	 			morelast_op=last_op;
	  			secondon=1;
	 			}
			}	
	
	}
	zero = 1;
	last_op = '*';
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text,-1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"",-1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "*", 1);

}

void mod_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (firston==0)
		{
		first = g_ascii_strtod(text, NULL);	
		firston=1;
		}
 	else
	{
		if (secondon==1)
			{
			third = g_ascii_strtod(text, NULL);
			second = my_switch(second,third,last_op);		
			last_op=morelast_op;	
			}
		else
			{
			if ((last_op != '+')&&(last_op != '-'))
				{
				second=g_ascii_strtod(text, NULL);
				first=my_switch(first,second,last_op);	
				}
			else
	 			{
	  			second=g_ascii_strtod(text, NULL);
	 			morelast_op=last_op;
	  			secondon=1;
	 			}
			}	
	
	}
	zero = 1;
	last_op = '/';
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text,-1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"",-1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "/", 1);

}

void faktorial_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	first = g_ascii_strtod(text, NULL);
	last_op = '!';
	//first = my_switch(first,NULL, last_op);
	//zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "!", 1);
}

void abs_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	first = g_ascii_strtod(text, NULL);
	last_op = '|';
	first = my_switch(first, second, last_op);
	zero = 1;
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_1), "abs(",4);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), ")", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}



void square_clicked()
{
char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
last_op='o';

gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text, -1);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),"(odm ",5);
gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}


void power_clicked()
{
char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
last_op='^';

gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text, -1);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),"^", 1);
gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}


void equal_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	second = g_ascii_strtod(text, NULL);
	zero = 1;
	unsigned long long int ffirst;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	



	if (secondon==1)
		{
		third = g_ascii_strtod(text, NULL);
		second = my_switch(second,third,last_op);
		first = my_switch(first,second,morelast_op);
		}
	else
		{
		second = g_ascii_strtod(text, NULL);
		switch(last_op)
			{
			case '+': first = ADD(first, second);
				break;
			case '-': first = SUB(first, second);
				break;
			case '*': first = MUL(first, second);
				break;
			case '/': first = DIV(first, second);
				break;
			case '!': ffirst = FCT(first);
				break;
			case '|': first = ABS(first);
				break;
			case '^': first = POW(first,second);
				break;
			case 'o':first = SQRT(first,second);
				gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),")", -1);
				break;
			default: break;
			}
		}
	char b[10];
	if (last_op=='!') snprintf(b,50, "%llu", ffirst);
	else snprintf(b,50, "%f", first);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "=", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), b, -1);



}
