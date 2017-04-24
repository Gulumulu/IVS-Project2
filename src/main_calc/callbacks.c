#include "callbacks.h"
#include "calculator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>

double first=0.0;
int firston = 0;
int secondon = 0;
double second=0.0,third=0.0;
int last_op , morelast_op;
int zero = 1;
int dot=0;

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
	dot = 0;
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
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text)>46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
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
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "1", 1);
	zero = 0;
}

void two_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "2", 1);
	zero = 0;
}

void three_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "3", 1);
	zero = 0;
}

void four_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "4", 1);
	zero = 0;
}

void five_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "5", 1);
	zero = 0;
}

void six_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "6", 1);
	zero = 0;
}

void seven_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "7", 1);
	zero = 0;
}

void eight_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "8", 1);
	zero = 0;
}

void nine_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) >= MAX_DIGITS) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "9", 1);
	zero = 0;
}

void add_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0 || !(strcmp(text,"-"))) return;

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
	if (!(strcmp(text,"-"))) return;
	if (strlen(text) == 0)
	{
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "-", 1);
	return;
	}
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
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text)>46) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0) return;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "0", 1);

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), ".", 1);
	dot=1;
}

void multiply_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0 || !(strcmp(text,"-"))) return;
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
	if (strlen(text) == 0 || !(strcmp(text,"-"))) return;
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
	dot = 1;
	last_op = '/';
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text,-1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"",-1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "/", 1);

}

void faktorial_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) != 0) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0) return;

	first = g_ascii_strtod(text, NULL);
	last_op = '!';

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "!", 1);
}

void abs_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) != 0) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	first = g_ascii_strtod(text, NULL);
	last_op = '|';
	zero = 1;
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_1), "abs(",4);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), ")", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}



void square_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) != 0) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0) return;
	first = g_ascii_strtod(text, NULL);
	last_op='o';

	dot = 1;
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1)," ^ 1/",5);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);

}


void power_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) != 0) return;
	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (strlen(text) == 0) return;
	first = g_ascii_strtod(text, NULL);
	last_op='^';

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1),"^", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}


void equal_clicked()
{
	if (last_op == '=') return;
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_1));
	if (strlen(text) > 46) return;

	text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if ((strlen(text) == 0)&&(last_op!='!')&&(last_op!='|')) return;
	zero = 1;
	unsigned long long int ffirst;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);

	int first_int;


	if (secondon==1)
		{
		third = g_ascii_strtod(text, NULL);
		second = my_switch(second,third,last_op);
		if(dot==1)
		first = my_switch(first,second,morelast_op);
		else
		first_int = my_switch(first,second,morelast_op);
		}
	else
		{
		second = g_ascii_strtod(text, NULL);
		switch(last_op)
			{
			case '+': if (dot==1) first = ADD(first, second);
					else first_int = ADD(first, second);
				break;
			case '-': if (dot==1) first = SUB(first, second);
					else  first_int = SUB(first, second);
				break;
			case '*': if (dot==1) first = MUL(first, second);
					else  first_int = MUL(first, second);
				break;
			case '/': if (second==0)
				{
				gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2),"MATH ERROR", -1);
				return;
				}
				first = DIV(first, second); dot=1;
				break;
			case '!': ffirst = FCT(first);
				break;
			case '|': if (dot==1) first = ABS(first);
					else  first_int = ABS(first);
				break;
			case '^': if (dot==1) first = POW(first, second);
					else  first_int = POW(first,second);
				break;
			case 'o':first = SQRT(first,second);
				break;

			default: if (dot==1) first = second;
					else first_int = second;
				break;
			}
		}
	char b[10];
	if (last_op=='!') snprintf(b,50, "%llu", ffirst);
	else
	{
	if (dot == 0)
	sprintf(b, "%d", first_int);
	else
	snprintf(b,48, "%f", first);
	}
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "=", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), b, -1);
	firston = 0;
	secondon = 0;
	last_op = '=';
	first = 0;
	second = 0;
	zero = 1;
	dot = 0;
}
