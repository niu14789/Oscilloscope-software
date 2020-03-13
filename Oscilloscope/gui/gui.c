/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "fos.h"
#include "gui.h"
#include "gui_dev.h"
#include "string.h"
/* Includes ------------------------------------------------------------------*/
static window_def * original_win = 0;
/* int gui draw */
int gui_static_creater(void)
{
	/* get gui type and dev */
	gui_dev_def * dev = get_gui_dev();
	/* from zero to end creating the pic */
	for( window_def * base = original_win ; base != 0 ; base = base->win_child )
	{
		/* if use the default draw function */
		if( base->msg.draw != 0 )
		{
			base->msg.draw(&base->msg);
		}
		else
		{
			/* can not supply now*/
		}
	}
	/* draw the widget */
	for( widget_def * base = original_win->wchild ; base != 0 ; base = base->peer_linker)
	{
		/* if use the default draw function */
		if( base->msg.draw != 0 )
		{
			base->msg.draw(&base->msg);
		}
		else
		{
			/* can not supply now*/
		}
	}
	/* return */
	return FS_OK;
}
/* create and init a win */
int gui_win_creater(window_def * win)
{
	/* juddge wherere it is the ORIGINAL_PARENT */
	if( win != ORIGINAL_PARENT )
	{
		/* return error . can not find the original win */
		original_win = win;
		/* ok */
		return FS_OK;
	}
	/* link with parent */
	window_def * base;
	/* same mode or */
	/* set */
	for( base = original_win ; base->win_child != 0 ; base = base->win_child )
	{
		/* find the pos . nothing to do*/
	}		
	/* set */
	base->win_child = win;
	/* return OK */
	return FS_OK;
}
/* create widget */
int gui_widget_creater(window_def * parent , widget_def * widget )
{
	/* juddge wherere it is the ORIGINAL_PARENT */
	if( parent == ORIGINAL_PARENT )
	{
		/* return error */
		return FS_ERR;
	}
	/* set the original linker */
	widget_def * base = parent->wchild;
	/* set up widget */
	for(  ; base != 0 ; base = base->peer_linker )
	{
		/* find the pos . nothing to do*/
	}
	/* set */
	base = widget;
	/* return OK */
	return FS_OK;
}






































































