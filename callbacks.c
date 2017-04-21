#include "callbacks.h"
#include "calculator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <gtk/gtk.h>

double first;
int firston = 0;
int firstoff = 0;
double second;
int last_op;
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
	firstoff = 0;
	last_op = 0;
	first = 0;
	second = 0;
	zero = 1;
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_1), "", -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
//	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "0", 1);
}

double my_switch(double first, double second, int last_op)
{
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
		case '!': first = FCT(first);
			break;
		case '|': first = ABS(first);
			break;
		default: break;
	}
	return first;
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
	if (firston == 0)
	{
		first = g_ascii_strtod(text, NULL);
		last_op = '+';
		firston = 1;
	}
	else
	{
		second = g_ascii_strtod(text, NULL);
		first = my_switch(first, second, last_op);
	}
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "+", 1);

}

void subtract_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (firston == 0)
	{
		first = g_ascii_strtod(text, NULL);
		last_op = '-';
		firston = 1;
	}
	else
	{
		second = g_ascii_strtod(text, NULL);
		first = my_switch(first, second, last_op);
	}
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "-", 1);
}

void dot_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), ".", 1);
}

void multiply_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (firston == 0)
	{
		first = g_ascii_strtod(text, NULL);
		last_op = '*';
		firston = 1;
	}
	else
	{
		second = g_ascii_strtod(text, NULL);
		first = my_switch(first, second, last_op);
	}
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "*", 1);
}

void mod_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	if (firston == 0)
	{
		first = g_ascii_strtod(text, NULL);
		last_op = '/';
		firston = 1;
	}
	else
	{
		second = g_ascii_strtod(text, NULL);
		first = my_switch(first, second, last_op);
	}
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "/", 1);
}

void faktorial_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	first = g_ascii_strtod(text, NULL);
	last_op = '!';
	first = my_switch(first, second, last_op);
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "!", 1);
}

void abs_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	first = g_ascii_strtod(text, NULL);
	last_op = '|';
	first = my_switch(first, second, last_op);
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "abs(", 4);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), ")", 1);
	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
}

void equal_clicked()
{
	char *text = get_whole_text(gtk_text_view_get_buffer(widg_2));
	second = g_ascii_strtod(text, NULL);
	zero = 1;

	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), "=", 1);

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
		case '!': first = FCT(first);
			break;
		case '|': first = ABS(first);
			break;
		default: break;
	}
//len
	char b[10];
	snprintf(b,10, "%f", first);

	gtk_text_buffer_set_text(gtk_text_view_get_buffer(widg_2), "", -1);
	gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), b, -1);


/*Use snprintf() from stdlib.h. Worked for me.

double num = 123412341234.123456789;
char output[50];

snprintf(output, 50, "%f", num);

printf("%s", output);
*/

}
/*
void abs_clicked()
{
char *text= gtk_text_buffer_get_whole_text(gtk_text_view_get_buffer(widg_2));

double result=ABSOL(StrToDouble(text));
char b[10];
snprintf(b,10, "%f", result);
char newb[10];
strcat(newb,b);
strcat(newb,"|");
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), newb, -1);
}

*/
