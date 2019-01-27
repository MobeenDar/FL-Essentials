/*********************************************************************************
created:	2017/03/14   07:20PM
filename: 	Fle_Spinner.h
file base:	Fle_Spinner
file ext:	h
author:		Furqan Ullah (Post-doc, Ph.D.)
website:    http://real3d.pk
CopyRight:	All Rights Reserved

purpose:	Spinner class that allows to change the settings of Up and Down buttons.
/**********************************************************************************
FL-ESSENTIALS (FLE) - FLTK Utility Widgets
Copyright (C) 2014-2019 REAL3D

This file and its content is protected by a software license.
You should have received a copy of this license with this file.
If not, please contact Dr. Furqan Ullah immediately:
**********************************************************************************/

#include <FLE/Fle_Spinner.h>

using namespace R3D;

Fle_Spinner::Fle_Spinner(int _x, int _y, int _w, int _h, const char* _lable) :
Fl_Spinner(_x, _y, _w, _h, _lable)
{
	input_.when(FL_WHEN_ENTER_KEY | FL_WHEN_CHANGED | FL_WHEN_RELEASE);

	up_button_.box(FL_UP_BOX);
	up_button_.color(FL_LIGHT3);
	down_button_.box(FL_UP_BOX);
	down_button_.color(FL_LIGHT3);
}

void Fle_Spinner::when(uchar i)
{ 
	Fl_Spinner::when(i);
	input_.when(i); 
}
