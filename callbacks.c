#include "callbacks.h"
#include "calculator.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

double first;
double second;

gchar* get_whole_text(GtkTextBuffer *buffer)
{
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    return gtk_text_buffer_get_text(buffer, &start, &end, TRUE);
}

void window1_destroy()
{
    gtk_main_quit();
}

void one_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "1", 1);

}

void two_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "2", 1);
}


void three_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "3", 1);
}

void four_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "4", 1);
}

void five_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "5", 1);
}

void six_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "6", 1);
}

void seven_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "7", 1);
}

void eight_clicked()
{
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "8", 1);
}

void nine_clicked()
{
//char *str = gtk_text_buffer_get_whole_text(gtk_text_view_get_buffer(widg_2));
//if (strlen(str) > 9) return;

gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "9", 1);
}



void add_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "+", 1);
}

void subtract_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "-", 1);
}

void dot_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), ".", 1);
}

void multiply_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "*", 1);
}

void mod_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "/", 1);
}

void faktorial_clicked()
{
char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
first = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "!", 1);
}

void equal_clicked()
{

char *text= get_whole_text(gtk_text_view_get_buffer(widg_2));
printf("%s",text);
//int a = strlen(str);
second = g_ascii_strtod(text, NULL);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_2), "=", 1);
gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(widg_1), text, -1);
printf("%f,%f",first,second);

double pom = ADD(first,second);
printf("%f",pom);
char b[10];
snprintf(b,10, "%f", pom);
printf("%s",b);
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




