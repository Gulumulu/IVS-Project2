/**
*@file callbacks.h
*@brief C-header file
*@date 22.4.2017
*@author Martin Minarik, Gabriel Quirschfeld, Tomas Svetlik, Jakub Zich
*/

#include <gtk/gtk.h>
#ifndef CALLBACKS_H
#define CALLBACKS_H
#define MAX_DIGITS 9

GtkTextView *widg_2;
GtkTextView *widg_1;

/**
*@fn gchar* get_whole_text(GtkTextBuffer *buffer)
*@brief loads the input of calculator
*@param buffer pointer to the text in the window of calculator
*@return string in the input of calculator
*/
gchar* get_whole_text(GtkTextBuffer *buffer);

/**
*@fn void window1_destroy()
*@brief Function that closes the calculator if [x] is pressed
*/
void window1_destroy();

/**
*@fn void one_clicked()
*@brief Function that writes 1 if 1 is pressed
*/
void one_clicked();

/**
*@fn void two_clicked()
*@brief Function that writes 2 if 2 is pressed
*/
void two_clicked();

/**
*@fn void three_clicked()
*@brief Function that writes 3 if 3 is pressed
*/
void three_clicked();

/**
*@fn void four_clicked()
*@brief Function that writes 4 if 4 is pressed
*/
void four_clicked();

/**
*@fn void five_clicked()
*@brief Function that writes 5 if 5 is pressed
*/
void five_clicked();

/**
*@fn void six_clicked()
*@brief Function that writes 6 if 6 is pressed
*/
void six_clicked();

/**
*@fn void seven_clicked()
*@brief Function that writes 7 if 7 is pressed
*/
void seven_clicked();

/**
*@fn void eight_clicked()
*@brief Function that writes 8 if 8 is pressed
*/
void eight_clicked();

/**
*@fn void nine_clicked()
*@brief Function that writes 9 if 9 is pressed
*/
void nine_clicked();

/**
*@fn void zero_clicked()
*@brief Function that writes 0 if 0 is pressed
*/
void zero_clicked();

/**
*@fn void add_clicked()
*@brief Function that uses ADD function if + is pressed
*/
void add_clicked();

/**
*@fn void subtract_clicked()
*@brief Function that uses SUB function if - is pressed
*/
void subtract_clicked();

/**
*@fn void square_clicked()
*@brief Function that uses SQRT function if square button is pressed
*/
void square_clicked();

/**
*@fn void power_clicked()
*@brief Function that uses POW function if ^ is pressed
*/
void power_clicked();

/**
*@fn void factorial_clicked()
*@brief Function that uses FCT function if n! is pressed
*/
void faktorial_clicked();

/**
*@fn void mod_clicked()
*@brief Function that uses DIV function if / is pressed
*/
void mod_clicked();

/**
*@fn void multiply_clicked()
*@brief Function that uses MUL function if * is pressed
*/
void multiply_clicked();

/**
*@fn void dot_clicked()
*@brief Function that writes . if . is pressed
*/
void dot_clicked();

/**
*@fn void clear_clicked()
*@brief Function that clears the window if the button clear is pressed
*/
void clear_clicked();

/**
*@fn void equal_clicked()
*@brief Function that equals the result if = is pressed
*/
void equal_clicked();

/**
*@fn void abs_clicked()
*@brief Function that counts absolute value if abs button is pressed
*/
void abs_clicked();

#endif
